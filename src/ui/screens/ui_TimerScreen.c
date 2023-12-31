// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: EbikeDemo

#include "../ui.h"

void ui_TimerScreen_screen_init(void)
{
ui_TimerScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_TimerScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_TimerScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TimerScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_GroupHeader1 = lv_obj_create(ui_TimerScreen);
lv_obj_set_height( ui_GroupHeader1, 40);
lv_obj_set_width( ui_GroupHeader1, lv_pct(100));
lv_obj_set_align( ui_GroupHeader1, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_GroupHeader1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GroupHeader1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GroupHeader1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_GroupHeader1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_GroupHeader1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_GroupHeader1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_GroupHeader1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HeadImage1 = lv_img_create(ui_GroupHeader1);
lv_img_set_src(ui_HeadImage1, &ui_img_995809848);
lv_obj_set_width( ui_HeadImage1, 64);
lv_obj_set_height( ui_HeadImage1, 38);
lv_obj_set_x( ui_HeadImage1, -5 );
lv_obj_set_y( ui_HeadImage1, 10 );
lv_obj_set_align( ui_HeadImage1, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_HeadImage1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_HeadImage1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_HeadLabel1 = lv_label_create(ui_GroupHeader1);
lv_obj_set_width( ui_HeadLabel1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_HeadLabel1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_HeadLabel1, 74 );
lv_obj_set_y( ui_HeadLabel1, 0 );
lv_obj_set_align( ui_HeadLabel1, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_HeadLabel1,"Koala's Timer");
lv_obj_set_style_text_color(ui_HeadLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_HeadLabel1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_HeadLabel1, &ui_font_Medium, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HeadWifiOn1 = lv_img_create(ui_GroupHeader1);
lv_img_set_src(ui_HeadWifiOn1, &ui_img_652517623);
lv_obj_set_width( ui_HeadWifiOn1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_HeadWifiOn1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_HeadWifiOn1, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_HeadWifiOn1, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_HeadWifiOn1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_HeadWifiOff1 = lv_img_create(ui_GroupHeader1);
lv_img_set_src(ui_HeadWifiOff1, &ui_img_1560645021);
lv_obj_set_width( ui_HeadWifiOff1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_HeadWifiOff1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_HeadWifiOff1, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_HeadWifiOff1, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_HeadWifiOff1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_TImeHour = lv_label_create(ui_TimerScreen);
lv_obj_set_width( ui_TImeHour, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TImeHour, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TImeHour, -140 );
lv_obj_set_y( ui_TImeHour, 0 );
lv_obj_set_align( ui_TImeHour, LV_ALIGN_CENTER );
lv_label_set_text(ui_TImeHour,"00");
lv_obj_set_style_text_align(ui_TImeHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TImeHour, &ui_font_TimerFont, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TImeColon1 = lv_label_create(ui_TimerScreen);
lv_obj_set_width( ui_TImeColon1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TImeColon1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TImeColon1, -70 );
lv_obj_set_y( ui_TImeColon1, 0 );
lv_obj_set_align( ui_TImeColon1, LV_ALIGN_CENTER );
lv_label_set_text(ui_TImeColon1,":");
lv_obj_set_style_text_align(ui_TImeColon1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TImeColon1, &ui_font_TimerFont, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TImeMinute = lv_label_create(ui_TimerScreen);
lv_obj_set_width( ui_TImeMinute, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TImeMinute, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_TImeMinute, LV_ALIGN_CENTER );
lv_label_set_text(ui_TImeMinute,"00");
lv_obj_set_style_text_align(ui_TImeMinute, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TImeMinute, &ui_font_TimerFont, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TImeColon2 = lv_label_create(ui_TimerScreen);
lv_obj_set_width( ui_TImeColon2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TImeColon2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TImeColon2, 70 );
lv_obj_set_y( ui_TImeColon2, 0 );
lv_obj_set_align( ui_TImeColon2, LV_ALIGN_CENTER );
lv_label_set_text(ui_TImeColon2,":");
lv_obj_set_style_text_align(ui_TImeColon2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TImeColon2, &ui_font_TimerFont, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TImeSecond = lv_label_create(ui_TimerScreen);
lv_obj_set_width( ui_TImeSecond, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TImeSecond, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TImeSecond, 140 );
lv_obj_set_y( ui_TImeSecond, 0 );
lv_obj_set_align( ui_TImeSecond, LV_ALIGN_CENTER );
lv_label_set_text(ui_TImeSecond,"00");
lv_obj_set_style_text_align(ui_TImeSecond, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TImeSecond, &ui_font_TimerFont, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TimerStartBtn = lv_btn_create(ui_TimerScreen);
lv_obj_set_width( ui_TimerStartBtn, 160);
lv_obj_set_height( ui_TimerStartBtn, 70);
lv_obj_set_x( ui_TimerStartBtn, 0 );
lv_obj_set_y( ui_TimerStartBtn, 100 );
lv_obj_set_align( ui_TimerStartBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_TimerStartBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_TimerStartBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_TimerStartBtn, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TimerStartBtn, lv_color_hex(0x2971CD), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TimerStartBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_StartBtnImage = lv_img_create(ui_TimerStartBtn);
lv_img_set_src(ui_StartBtnImage, &ui_img_car_png);
lv_obj_set_width( ui_StartBtnImage, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_StartBtnImage, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_StartBtnImage, -40 );
lv_obj_set_y( ui_StartBtnImage, 0 );
lv_obj_set_align( ui_StartBtnImage, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_StartBtnImage, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_StartBtnImage, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_StartBtnLabel = lv_label_create(ui_TimerStartBtn);
lv_obj_set_width( ui_StartBtnLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_StartBtnLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_StartBtnLabel, 40 );
lv_obj_set_y( ui_StartBtnLabel, 0 );
lv_obj_set_align( ui_StartBtnLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_StartBtnLabel,"GO!");
lv_obj_set_style_text_color(ui_StartBtnLabel, lv_color_hex(0xDDDDDD), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_StartBtnLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_StartBtnLabel, &ui_font_Big, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TimerStopBtn = lv_btn_create(ui_TimerScreen);
lv_obj_set_width( ui_TimerStopBtn, 160);
lv_obj_set_height( ui_TimerStopBtn, 70);
lv_obj_set_x( ui_TimerStopBtn, 0 );
lv_obj_set_y( ui_TimerStopBtn, 100 );
lv_obj_set_align( ui_TimerStopBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_TimerStopBtn, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_TimerStopBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_TimerStopBtn, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TimerStopBtn, lv_color_hex(0xE91A00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TimerStopBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_StopBtnImage = lv_img_create(ui_TimerStopBtn);
lv_img_set_src(ui_StopBtnImage, &ui_img_stop_png);
lv_obj_set_width( ui_StopBtnImage, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_StopBtnImage, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_StopBtnImage, -40 );
lv_obj_set_y( ui_StopBtnImage, 0 );
lv_obj_set_align( ui_StopBtnImage, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_StopBtnImage, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_StopBtnImage, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_StopBtnLabel = lv_label_create(ui_TimerStopBtn);
lv_obj_set_width( ui_StopBtnLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_StopBtnLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_StopBtnLabel, 40 );
lv_obj_set_y( ui_StopBtnLabel, 0 );
lv_obj_set_align( ui_StopBtnLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_StopBtnLabel,"STOP");
lv_obj_set_style_text_color(ui_StopBtnLabel, lv_color_hex(0xDDDDDD), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_StopBtnLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_StopBtnLabel, &ui_font_Big, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TimerExitImg = lv_img_create(ui_TimerScreen);
lv_img_set_src(ui_TimerExitImg, &ui_img_400942075);
lv_obj_set_width( ui_TimerExitImg, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TimerExitImg, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TimerExitImg, 199 );
lv_obj_set_y( ui_TimerExitImg, 118 );
lv_obj_set_align( ui_TimerExitImg, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_TimerExitImg, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_TimerExitImg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_TimerStartBtn, ui_event_TimerStartBtn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TimerStopBtn, ui_event_TimerStopBtn, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TimerExitImg, ui_event_TimerExitImg, LV_EVENT_ALL, NULL);

}
