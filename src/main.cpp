//*********************************************************************************************************/
//  WT32-SC01-PLUS template for platform.io
//*********************************************************************************************************/

#include "main.h"
#include "time.h"

/* function */
void printLocalTime()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial0.println("Failed to obtain time");
    return;
  }

  // Serial0.println("Time variables");

  strftime(timeHour, 3, "%H", &timeinfo);
  strftime(timeMinute, 3, "%M", &timeinfo);
  strftime(timeSecond, 3, "%S", &timeinfo);
  strftime(timeWeekDay, 10, "%A", &timeinfo);
  strftime(timeDate, 50, "%B-%d-%Y", &timeinfo);

  // Serial0.println(timeWeekDay);
  // Serial0.println();

  // dj's part
  lv_label_set_text(ui_LabelWeek, timeWeekDay);
  lv_label_set_text(ui_LabelDate, timeDate);
  lv_label_set_text(ui_NumberHour, timeHour);
  lv_label_set_text(ui_NumberMinute, timeMinute);

  lv_slider_set_value(ui_SliderHour, atoi(timeHour), LV_ANIM_OFF);
  lv_slider_set_value(ui_SliderMin, atoi(timeMinute), LV_ANIM_OFF);
}

//************************************************************************************
//  SETUP AND LOOP
//************************************************************************************

void setup()
{
  // debug Serial0 init
  Serial0.begin(115200);

  tft.begin();
  tft.setRotation(0);
  tft.setBrightness(screenBackLight);

  sdSpi.begin(SD_CLK, SD_MISO, SD_MOSI, SD_CS);
  SdInit();

  lv_init();

#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

  // lv_disp_draw_buf_init(&draw_buf, buf, buf2, screenWidth * 100);
  buf = (lv_color_t *)heap_caps_calloc(1, screenWidth * screenHeight * 2, MALLOC_CAP_SPIRAM);
  buf2 = (lv_color_t *)heap_caps_calloc(1, screenWidth * screenHeight * 2, MALLOC_CAP_SPIRAM);
  lv_disp_draw_buf_init(&draw_buf, buf, buf2, screenWidth * screenHeight * 2);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touch_read;
  lv_indev_drv_register(&indev_drv);

  // start the UI
  ui_init();

  // delay(100);

  // Connect to Wi-Fi
  Serial0.print("Connecting to ");
  Serial0.println(ssid);
  WiFi.begin(ssid, password);
  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   delay(500);
  //   Serial0.print(".");
  // }
  // Serial0.println("");
  // Serial0.println("WiFi connected.");

  // Init and get the time

  // printLocalTime();

  // disconnect WiFi as it's no longer needed
  // WiFi.disconnect(true);
  // WiFi.mode(WIFI_OFF);
}

void loop()
{
  lv_timer_handler();

  screenBackLight = lv_slider_get_value(ui_BgSlider);
  tft.setBrightness(screenBackLight);

  if (isWifiConnected && !isGotTime)
  {
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2, ntpServer3);
    struct tm timeinfo;
    if (getLocalTime(&timeinfo))
    {
      isGotTime = true;
      return;
    }
  }

  if (isTimerReset)
  {
    isTimerRunning = false;
    timerSecond = 0;
    timerMintue = 0;
    timerHour = 0;
    lv_label_set_text_fmt(ui_TImeSecond, "%02d", timerSecond);
    lv_label_set_text_fmt(ui_TImeMinute, "%02d", timerMintue);
    lv_label_set_text_fmt(ui_TImeHour, "%02d", timerHour);
    isTimerReset = false;
  }

  if (isLogoReset)
  {
    btnShowTime = 0;
    isShow = false;
    if (wp)
    {
      lv_obj_del(wp);
    }
    isLogoReset = false;
  }

  /* delay 1s */
  if (millis() - lastMillis1 > 1000)
  {
    lastMillis1 = millis();

    printLocalTime();

    if (WiFi.status() == WL_CONNECTED)
    {
      lv_obj_add_flag(ui_HeadWifiOff, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_HeadWifiOn, LV_OBJ_FLAG_HIDDEN);
      isWifiConnected = true;

      if (isColonHidden)
      {
        lv_obj_clear_flag(ui_NumberColon, LV_OBJ_FLAG_HIDDEN);
        isColonHidden = false;
      }
      else
      {
        lv_obj_add_flag(ui_NumberColon, LV_OBJ_FLAG_HIDDEN);
        isColonHidden = true;
      }
    }
    else
    {
      lv_obj_add_flag(ui_HeadWifiOn, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_HeadWifiOff, LV_OBJ_FLAG_HIDDEN);
    }

    // timer caculate
    if (isTimerRunning)
    {
      if (timerSecond < 59)
      {
        timerSecond++;
      }
      else
      {
        timerMintue++;
        timerSecond = 0;
      }
      if (timerMintue >= 60)
      {
        timerHour++;
        timerMintue = 0;
      }

      lv_label_set_text_fmt(ui_TImeSecond, "%02d", timerSecond);
      lv_label_set_text_fmt(ui_TImeMinute, "%02d", timerMintue);
      lv_label_set_text_fmt(ui_TImeHour, "%02d", timerHour);
    }

    // brightness adjust
    if (!isBgadjusted)
    {
      if (atoi(timeHour) == 7 && atoi(timeMinute) == 0 && atoi(timeSecond) == 0)
      {
        lv_slider_set_value(ui_BgSlider, 230, LV_ANIM_ON);
        isBgadjusted = true;
      }
      else if (atoi(timeHour) == 22 && atoi(timeMinute) == 10 && atoi(timeSecond) == 0)
      {
        lv_slider_set_value(ui_BgSlider, 10, LV_ANIM_ON);
        isBgadjusted = true;
      }
      else
      {
        isBgadjusted = false;
      }
    }

    // show picture

    if (isLogoNext)
    {
      wp = lv_img_create(ui_LogoScreen);
      picNum = random(1, 50);
      sprintf(fileName, "S:%d.jpg", picNum);
      log_i("Random File name is: %s.", fileName);
      lv_img_set_src(wp, fileName);
      lv_obj_center(wp);
      lv_obj_set_y(wp, -30);
      isShow = true;
      isLogoNext = false;
      lv_obj_add_flag(ui_LogoNextBtn, LV_OBJ_FLAG_HIDDEN);
    }
    if (isShow)
    {
      btnShowTime++;
    }
    if (btnShowTime >= 5)
    {
      lv_obj_clear_flag(ui_LogoNextBtn, LV_OBJ_FLAG_HIDDEN);
      isShow = false;
      btnShowTime = 0;
    }
  }

  /* delay 3s */
  if (millis() - lastMillis2 > 5000)
  {
    lastMillis2 = millis();

    // wp = lv_img_create(lv_scr_act());
    // lv_img_set_src(wp, "S:1.jpg");
    // lv_obj_center(wp);
    // picNum = random(1, 50);
    // sprintf(fileName, "S:%d.jpg", picNum);
    // log_i("Random File name is: %s.", fileName);
  }

  delay(10);
}