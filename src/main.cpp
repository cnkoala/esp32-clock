//*********************************************************************************************************/
//  WT32-SC01-PLUS template for platform.io
//  created by Frits Jan / productbakery on 11 oktober 2022
//
//
// When working with the squareline editor from lvgl, set the project in squareline to:
// - Arduino, with TFT_eSPI (which we cannot use, but will replace with LovyanGFX in this main.cpp file)
// - 480 x 320, 16 bit display
//
// Export the template project AND export the UI Files
// You will get a project directory with two directories inside, 'ui' and 'libraries'
// From the libraries directory, copy the lv_conf.h to this projects /src/ directory (overwrite the old one)
// From the ui directory, copy all files to this projects src/ui/ directory (you can empty the ui directory first if needed)
// The ui.ino file can/should be deleted because this main.cpp files takes over.
//
//*********************************************************************************************************/

#include "main.h"
#include "time.h"

const char *ssid = "ChinaNet_5G";
const char *password = "87842950";

const char *ntpServer1 = "cn.pool.ntp.org";
const char *ntpServer2 = "asia.pool.ntp.org";
const char *ntpServer3 = "ntp.aliyun.com";
const long gmtOffset_sec = 8 * 60 * 60;
const int daylightOffset_sec = 0;

/* function */
void printLocalTime()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial0.println("Failed to obtain time");
    return;
  }
  // Serial0.println(&timeinfo, "%A, %B %d %Y %H:%M:%S zone %Z %z");
  // Serial0.print("Day of week: ");
  // Serial0.println(&timeinfo, "%A");
  // Serial0.print("Month: ");
  // Serial0.println(&timeinfo, "%B");
  // Serial0.print("Day of Month: ");
  // Serial0.println(&timeinfo, "%d");
  // Serial0.print("Year: ");
  // Serial0.println(&timeinfo, "%Y");
  // Serial0.print("Hour: ");
  // Serial0.println(&timeinfo, "%H");
  // Serial0.print("Hour (12 hour format): ");
  // Serial0.println(&timeinfo, "%I");
  // Serial0.print("Minute: ");
  // Serial0.println(&timeinfo, "%M");
  // Serial0.print("Second: ");
  // Serial0.println(&timeinfo, "%S");

  Serial0.println("Time variables");
  char timeHour[3];
  char timeMinute[3];
  char timeWeekDay[10];
  char timeDate[50];
  strftime(timeHour, 3, "%H", &timeinfo);
  strftime(timeMinute, 3, "%M", &timeinfo);
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

  // AS5600 init
  // Wire1.begin(AS5600_SDA, AS5600_SCL, AS5600_BAUD);
  // as5600.begin();

  tft.begin();
  tft.setRotation(0);
  tft.setBrightness(screenBackLight255);

  lv_init();

#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

  // lv_disp_draw_buf_init(&draw_buf, buf, buf2, screenWidth * 100);
  buf = (lv_color_t *)heap_caps_aligned_calloc(64, 1, screenWidth * screenHeight * 2, MALLOC_CAP_SPIRAM);
  buf2 = (lv_color_t *)heap_caps_aligned_calloc(64, 1, screenWidth * screenHeight * 2, MALLOC_CAP_SPIRAM);
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

  printLocalTime();

  // disconnect WiFi as it's no longer needed
  // WiFi.disconnect(true);
  // WiFi.mode(WIFI_OFF);
}

void loop()
{
  lv_timer_handler();

  static uint32_t lastMillis1 = 0;
  static uint32_t lastMillis2 = 0;
  static bool isWifiConnected = false;
  static bool isGotTime = false;
  static bool isColonHidden = false;

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

  /* delay 1s */
  if (millis() - lastMillis1 > 1000)
  {
    lastMillis1 = millis();

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
  }

  /* delay 3s */
  if (millis() - lastMillis2 > 5000)
  {
    lastMillis2 = millis();

    printLocalTime();
  }

  delay(10);
}