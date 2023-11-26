// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: EbikeDemo

#ifndef _EBIKEDEMO_UI_H
#define _EBIKEDEMO_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_HomeScreen
void ui_HomeScreen_screen_init(void);
extern lv_obj_t *ui_HomeScreen;
extern lv_obj_t *ui_BG1;
extern lv_obj_t *ui_GroupClock;
extern lv_obj_t *ui_NumberMinute;
extern lv_obj_t *ui_NumberHour;
extern lv_obj_t *ui_NumberColon;
extern lv_obj_t *ui_SliderHour;
extern lv_obj_t *ui_SliderMin;
extern lv_obj_t *ui_GroupHeader;
extern lv_obj_t *ui_HeadImage;
extern lv_obj_t *ui_HeadLabel;
extern lv_obj_t *ui_HeadWifiOn;
extern lv_obj_t *ui_HeadWifiOff;
extern lv_obj_t *ui_GroupMinute;
extern lv_obj_t *ui_Label_Number1;
extern lv_obj_t *ui_Label_Number2;
extern lv_obj_t *ui_Label_Number3;
extern lv_obj_t *ui_Label_Number4;
extern lv_obj_t *ui_Label_Number5;
extern lv_obj_t *ui_GroupHour;
extern lv_obj_t *ui_Label_Number6;
extern lv_obj_t *ui_Label_Number8;
extern lv_obj_t *ui_Label_Number10;
extern lv_obj_t *ui_GroupDate;
extern lv_obj_t *ui_LabelWeek;
extern lv_obj_t *ui_LabelDate;
extern lv_obj_t *ui_BottomGroup;
extern lv_obj_t *ui_BottomBg;
void ui_event_BottomTimerImage( lv_event_t * e);
extern lv_obj_t *ui_BottomTimerImage;
void ui_event_BottomLogoImage( lv_event_t * e);
extern lv_obj_t *ui_BottomLogoImage;
extern lv_obj_t *ui_BgSlider;
// SCREEN: ui_TimerScreen
void ui_TimerScreen_screen_init(void);
extern lv_obj_t *ui_TimerScreen;
extern lv_obj_t *ui_GroupHeader1;
extern lv_obj_t *ui_HeadImage1;
extern lv_obj_t *ui_HeadLabel1;
extern lv_obj_t *ui_HeadWifiOn1;
extern lv_obj_t *ui_HeadWifiOff1;
extern lv_obj_t *ui_TImeHour;
extern lv_obj_t *ui_TImeColon1;
extern lv_obj_t *ui_TImeMinute;
extern lv_obj_t *ui_TImeColon2;
extern lv_obj_t *ui_TImeSecond;
void ui_event_TimerStartBtn( lv_event_t * e);
extern lv_obj_t *ui_TimerStartBtn;
extern lv_obj_t *ui_StartBtnImage;
extern lv_obj_t *ui_StartBtnLabel;
void ui_event_TimerStopBtn( lv_event_t * e);
extern lv_obj_t *ui_TimerStopBtn;
extern lv_obj_t *ui_StopBtnImage;
extern lv_obj_t *ui_StopBtnLabel;
void ui_event_TimerExitImg( lv_event_t * e);
extern lv_obj_t *ui_TimerExitImg;
// SCREEN: ui_LogoScreen
void ui_LogoScreen_screen_init(void);
extern lv_obj_t *ui_LogoScreen;
void ui_event_LogoNextBtn( lv_event_t * e);
extern lv_obj_t *ui_LogoNextBtn;
extern lv_obj_t *ui_LogoBtnImage;
extern lv_obj_t *ui_LogoBtnLabel;
void ui_event_LogoExitImg( lv_event_t * e);
extern lv_obj_t *ui_LogoExitImg;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_ebike_bg_png);   // assets\ebike_bg.png
LV_IMG_DECLARE( ui_img_speed_slider_png);   // assets\speed_slider.png
LV_IMG_DECLARE( ui_img_slider_battery_png);   // assets\slider_battery.png
LV_IMG_DECLARE( ui_img_995809848);   // assets\kaola-fill.png
LV_IMG_DECLARE( ui_img_652517623);   // assets\wifi-on.png
LV_IMG_DECLARE( ui_img_1560645021);   // assets\wifi-off.png
LV_IMG_DECLARE( ui_img_menu_line_png);   // assets\menu_line.png
LV_IMG_DECLARE( ui_img_clock_fill_png);   // assets\clock_fill.png
LV_IMG_DECLARE( ui_img_bmw_png);   // assets\BMW.png
LV_IMG_DECLARE( ui_img_car_png);   // assets\car.png
LV_IMG_DECLARE( ui_img_stop_png);   // assets\stop.png
LV_IMG_DECLARE( ui_img_400942075);   // assets\Exit-2.png
LV_IMG_DECLARE( ui_img_next_png);   // assets\next.png
LV_IMG_DECLARE( ui_img_exitblack_png);   // assets\ExitBlack.png

LV_FONT_DECLARE( ui_font_Big);
LV_FONT_DECLARE( ui_font_Medium);
LV_FONT_DECLARE( ui_font_Number);
LV_FONT_DECLARE( ui_font_Small);
LV_FONT_DECLARE( ui_font_TimerFont);

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
