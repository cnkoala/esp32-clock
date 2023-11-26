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

#include <esp_heap_caps.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <SD.h>

// insert your wifi name
const char *ssid = "";
// insert your wifi password
const char *password = "";

const char *ntpServer1 = "cn.pool.ntp.org";
const char *ntpServer2 = "asia.pool.ntp.org";
const char *ntpServer3 = "ntp.aliyun.com";
const long gmtOffset_sec = 8 * 60 * 60;
const int daylightOffset_sec = 0;

// define log level
#define LOG_LEVEL 5

// define SD pin
#define SD_CS 41
#define SD_MOSI 40
#define SD_CLK 39
#define SD_MISO 38

// define SD file params
SPIClass sdSpi = SPIClass(HSPI);
uint32_t currentMills;
char SDFileName[100];
File root;
File myfile;

// LGFX define
#define LGFX_USE_V1
#include <LovyanGFX.hpp>

// LVGL define
#include <lvgl.h>
#include "ui/ui.h"

#define screenWidth 480
#define screenHeight 320

uint8_t screenBackLight = 230;
bool isBgadjusted = false;

// create buffer for display
static lv_disp_draw_buf_t draw_buf;
lv_color_t *buf;
// assert(buf != NULL);

lv_color_t *buf2;
// assert(buf2 != NULL);

// SETUP LGFX PARAMETERS FOR WT32-SC01-PLUS
class LGFX : public lgfx::LGFX_Device
{

  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_Parallel8 _bus_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_FT5x06 _touch_instance; // FT5206, FT5306, FT5406, FT6206, FT6236, FT6336, FT6436

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();

      cfg.freq_write = 20000000;
      cfg.pin_wr = 47; // pin number connecting WR
      cfg.pin_rd = -1; // pin number connecting RD
      cfg.pin_rs = 0;  // Pin number connecting RS(D/C)
      cfg.pin_d0 = 9;  // pin number connecting D0
      cfg.pin_d1 = 46; // pin number connecting D1
      cfg.pin_d2 = 3;  // pin number connecting D2
      cfg.pin_d3 = 8;  // pin number connecting D3
      cfg.pin_d4 = 18; // pin number connecting D4
      cfg.pin_d5 = 17; // pin number connecting D5
      cfg.pin_d6 = 16; // pin number connecting D6
      cfg.pin_d7 = 15; // pin number connecting D7
      // cfg.i2s_port = I2S_NUM_0; // (I2S_NUM_0 or I2S_NUM_1)

      _bus_instance.config(cfg);              // Apply the settings to the bus.
      _panel_instance.setBus(&_bus_instance); // Sets the bus to the panel.
    }

    {                                      // Set display panel control.
      auto cfg = _panel_instance.config(); // Get the structure for display panel settings.

      cfg.pin_cs = -1;   // Pin number to which CS is connected (-1 = disable)
      cfg.pin_rst = 4;   // pin number where RST is connected (-1 = disable)
      cfg.pin_busy = -1; // pin number to which BUSY is connected (-1 = disable)

      // * The following setting values ​​are set to general default values ​​for each panel, and the pin number (-1 = disable) to which BUSY is connected, so please try commenting out any unknown items.

      cfg.memory_width = 320;  // Maximum width supported by driver IC
      cfg.memory_height = 480; // Maximum height supported by driver IC
      cfg.panel_width = 320;   // actual displayable width
      cfg.panel_height = 480;  // actual displayable height
      cfg.offset_x = 0;        // Panel offset in X direction
      cfg.offset_y = 0;        // Panel offset in Y direction
      cfg.offset_rotation = 1; // was 2
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = true; // was false
      cfg.invert = true;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = true; // was false something to do with SD?

      _panel_instance.config(cfg);
    }

    {                                      // Set backlight control. (delete if not necessary)
      auto cfg = _light_instance.config(); // Get the structure for backlight configuration.

      cfg.pin_bl = 45;     // pin number to which the backlight is connected
      cfg.invert = false;  // true to invert backlight brightness
      cfg.freq = 44100;    // backlight PWM frequency
      cfg.pwm_channel = 0; // PWM channel number to use (7??)

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance); // Sets the backlight to the panel.
    }

    //*
    { // Configure settings for touch screen control. (delete if not necessary)
      auto cfg = _touch_instance.config();

      cfg.x_min = 0;          // Minimum X value (raw value) obtained from the touchscreen
      cfg.x_max = 319;        // Maximum X value (raw value) obtained from the touchscreen
      cfg.y_min = 0;          // Minimum Y value obtained from touchscreen (raw value)
      cfg.y_max = 479;        // Maximum Y value (raw value) obtained from the touchscreen
      cfg.pin_int = 7;        // pin number to which INT is connected
      cfg.bus_shared = false; // set true if you are using the same bus as the screen
      cfg.offset_rotation = 0;

      // For I2C connection
      cfg.i2c_port = 0;    // Select I2C to use (0 or 1)
      cfg.i2c_addr = 0x38; // I2C device address number
      cfg.pin_sda = 6;     // pin number where SDA is connected
      cfg.pin_scl = 5;     // pin number to which SCL is connected
      cfg.pin_int = 7;     // pin number for interrupt
      cfg.freq = 400000;   // set I2C clock

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance); // Set the touchscreen to the panel.
    }
    //*/
    setPanel(&_panel_instance); // Sets the panel to use.
  }
};

LGFX tft;

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  tft.endWrite();
  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
void my_touch_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;
  bool touched = tft.getTouch(&touchX, &touchY);
  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = touchX;
    data->point.y = touchY;

#if DEBUG_TOUCH != 0
    Serial0.print("Data x ");
    Serial0.println(touchX);
    Serial0.print("Data y ");
    Serial0.println(touchY);
#endif
  }
}

// lv debugging can be set in lv_conf.h
#if LV_USE_LOG != 0
/* Serial0 debugging */
void my_print(const char *buf)
{
  Serial0.printf(buf);
  Serial0.flush();
}
#endif

char *fileNameList[100];
uint8_t fileNumber = 0;

// sd test
void SdInit()
{
  if (!SD.begin(SD_CS, sdSpi))
  {
    Serial0.print(".");
  }
  Serial0.println("\r\nSD card Ready!");
  if (!SD.begin())
  {
    Serial0.println("Card Mount Failed");
    return;
  }
  else
  {
    Serial0.println("Card Mount Success");
  }
  uint8_t cardType = SD.cardType();

  if (cardType == CARD_NONE)
  {
    Serial0.println("No SD card attached");
    return;
  }
  Serial0.print("SD Card Type: ");
  if (cardType == CARD_MMC)
  {
    Serial0.println("MMC");
  }
  else if (cardType == CARD_SD)
  {
    Serial0.println("SDSC");
  }
  else if (cardType == CARD_SDHC)
  {
    Serial0.println("SDHC");
  }
  else
  {
    Serial0.println("UNKNOWN");
  }

  lv_fs_fatfs_init();
}

void sd1Test(void)
{
  lv_fs_file_t f;
  lv_fs_res_t res;
  res = lv_fs_open(&f, "S:1.jpg", LV_FS_MODE_RD);
  if (res != LV_FS_RES_OK)
  {
    Serial0.println("Open fail");
  }
  else
  {
    Serial0.println("Open OK");
    uint32_t read_num;
    uint8_t buf[8];
    res = lv_fs_read(&f, buf, 8, &read_num);
    Serial0.printf("read:%s", buf);
    lv_fs_close(&f);
  }
}

void sdSearch(void)
{
  lv_fs_file_t f;
  lv_fs_res_t res;
  res = lv_fs_open(&f, "S:1.jpg", LV_FS_MODE_RD);
  if (res != LV_FS_RES_OK)
  {
    Serial0.println("Open fail");
  }
  else
  {
    Serial0.println("Open OK");
    uint32_t read_num;
    uint8_t buf[8];
    res = lv_fs_read(&f, buf, 8, &read_num);
    Serial0.printf("read:%s", buf);
    lv_fs_close(&f);
  }
}

// period set
static uint32_t lastMillis1 = 0;
static uint32_t lastMillis2 = 0;

// time char
char timeHour[3];
char timeMinute[3];
char timeSecond[3];
char timeWeekDay[10];
char timeDate[50];

// wifi set
static bool isWifiConnected = false;
static bool isGotTime = false;
static bool isColonHidden = false;

// timer number set
uint8_t timerSecond = 0;
uint8_t timerMintue = 0;
uint8_t timerHour = 0;

// init picture
uint8_t btnShowTime = 0;
bool isShow = false;
char fileName[20];
int picNum;
lv_obj_t *wp;
