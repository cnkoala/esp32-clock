// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: EbikeDemo

#include "../ui.h"

void ui_HomeScreen_screen_init(void)
{
ui_HomeScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_HomeScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_BG1 = lv_img_create(ui_HomeScreen);
lv_img_set_src(ui_BG1, &ui_img_ebike_bg_png);
lv_obj_set_width( ui_BG1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BG1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BG1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_BG1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_BG1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_GroupClock = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_GroupClock, 243);
lv_obj_set_height( ui_GroupClock, 107);
lv_obj_set_x( ui_GroupClock, -10 );
lv_obj_set_y( ui_GroupClock, 13 );
lv_obj_set_align( ui_GroupClock, LV_ALIGN_RIGHT_MID );
lv_obj_clear_flag( ui_GroupClock, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GroupClock, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GroupClock, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_NumberMinute = lv_label_create(ui_GroupClock);
lv_obj_set_width( ui_NumberMinute, 100);
lv_obj_set_height( ui_NumberMinute, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_NumberMinute, 70 );
lv_obj_set_y( ui_NumberMinute, 0 );
lv_obj_set_align( ui_NumberMinute, LV_ALIGN_CENTER );
lv_label_set_text(ui_NumberMinute,"00");
lv_obj_set_style_text_color(ui_NumberMinute, lv_color_hex(0x397DCD), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_NumberMinute, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_NumberMinute, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_NumberMinute, &ui_font_Number, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_NumberHour = lv_label_create(ui_GroupClock);
lv_obj_set_width( ui_NumberHour, 100);
lv_obj_set_height( ui_NumberHour, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_NumberHour, -70 );
lv_obj_set_y( ui_NumberHour, 0 );
lv_obj_set_align( ui_NumberHour, LV_ALIGN_CENTER );
lv_label_set_text(ui_NumberHour,"00");
lv_obj_set_style_text_color(ui_NumberHour, lv_color_hex(0xD58929), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_NumberHour, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_NumberHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_NumberHour, &ui_font_Number, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_NumberColon = lv_label_create(ui_GroupClock);
lv_obj_set_width( ui_NumberColon, 100);
lv_obj_set_height( ui_NumberColon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_NumberColon, 0 );
lv_obj_set_y( ui_NumberColon, -13 );
lv_obj_set_align( ui_NumberColon, LV_ALIGN_CENTER );
lv_label_set_text(ui_NumberColon,":");
lv_obj_set_style_text_color(ui_NumberColon, lv_color_hex(0x8A8A8A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_NumberColon, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_NumberColon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_NumberColon, &ui_font_Number, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SliderHour = lv_slider_create(ui_HomeScreen);
lv_slider_set_range(ui_SliderHour, 0,24);
lv_slider_set_value( ui_SliderHour, 12, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_SliderHour)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_SliderHour, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_SliderHour, 123);
lv_obj_set_height( ui_SliderHour, 244);
lv_obj_set_x( ui_SliderHour, -100 );
lv_obj_set_y( ui_SliderHour, -1 );
lv_obj_set_align( ui_SliderHour, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SliderHour, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SliderHour, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SliderHour, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_SliderHour, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SliderHour, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_SliderHour, &ui_img_speed_slider_png, LV_PART_INDICATOR | LV_STATE_DEFAULT );

lv_obj_set_style_bg_color(ui_SliderHour, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SliderHour, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_SliderMin = lv_slider_create(ui_HomeScreen);
lv_slider_set_range(ui_SliderMin, 0,60);
lv_slider_set_value( ui_SliderMin, 30, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_SliderMin)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_SliderMin, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_SliderMin, 106);
lv_obj_set_height( ui_SliderMin, 235);
lv_obj_set_x( ui_SliderMin, -147 );
lv_obj_set_y( ui_SliderMin, 1 );
lv_obj_set_align( ui_SliderMin, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SliderMin, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SliderMin, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SliderMin, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_SliderMin, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SliderMin, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_SliderMin, &ui_img_slider_battery_png, LV_PART_INDICATOR | LV_STATE_DEFAULT );

lv_obj_set_style_bg_color(ui_SliderMin, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SliderMin, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_GroupHeader = lv_obj_create(ui_HomeScreen);
lv_obj_set_height( ui_GroupHeader, 40);
lv_obj_set_width( ui_GroupHeader, lv_pct(100));
lv_obj_set_align( ui_GroupHeader, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_GroupHeader, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GroupHeader, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GroupHeader, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_GroupHeader, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_GroupHeader, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_GroupHeader, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_GroupHeader, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HeadImage = lv_img_create(ui_GroupHeader);
lv_img_set_src(ui_HeadImage, &ui_img_995809848);
lv_obj_set_width( ui_HeadImage, 64);
lv_obj_set_height( ui_HeadImage, 38);
lv_obj_set_x( ui_HeadImage, -5 );
lv_obj_set_y( ui_HeadImage, 10 );
lv_obj_set_align( ui_HeadImage, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_HeadImage, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_HeadImage, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_HeadLabel = lv_label_create(ui_GroupHeader);
lv_obj_set_width( ui_HeadLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_HeadLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_HeadLabel, 74 );
lv_obj_set_y( ui_HeadLabel, 0 );
lv_obj_set_align( ui_HeadLabel, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_HeadLabel,"Koala's Clock");
lv_obj_set_style_text_color(ui_HeadLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_HeadLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_HeadLabel, &ui_font_Medium, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HeadWifiOn = lv_img_create(ui_GroupHeader);
lv_img_set_src(ui_HeadWifiOn, &ui_img_652517623);
lv_obj_set_width( ui_HeadWifiOn, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_HeadWifiOn, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_HeadWifiOn, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_HeadWifiOn, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_HeadWifiOn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_HeadWifiOff = lv_img_create(ui_GroupHeader);
lv_img_set_src(ui_HeadWifiOff, &ui_img_1560645021);
lv_obj_set_width( ui_HeadWifiOff, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_HeadWifiOff, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_HeadWifiOff, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_HeadWifiOff, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_HeadWifiOff, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_GroupMinute = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_GroupMinute, 107);
lv_obj_set_height( ui_GroupMinute, 239);
lv_obj_set_align( ui_GroupMinute, LV_ALIGN_LEFT_MID );
lv_obj_clear_flag( ui_GroupMinute, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GroupMinute, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GroupMinute, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_Number1 = lv_label_create(ui_GroupMinute);
lv_obj_set_width( ui_Label_Number1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Number1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label_Number1, 28 );
lv_obj_set_y( ui_Label_Number1, -2 );
lv_obj_set_align( ui_Label_Number1, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label_Number1,"60 min");
lv_label_set_recolor(ui_Label_Number1,"true");
lv_obj_set_style_text_color(ui_Label_Number1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Number1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Number1, &ui_font_Small, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_Number2 = lv_label_create(ui_GroupMinute);
lv_obj_set_width( ui_Label_Number2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Number2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label_Number2, -5 );
lv_obj_set_y( ui_Label_Number2, lv_pct(22) );
lv_obj_set_align( ui_Label_Number2, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label_Number2,"45 min");
lv_label_set_recolor(ui_Label_Number2,"true");
lv_obj_set_style_text_color(ui_Label_Number2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Number2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Number2, &ui_font_Small, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_Number3 = lv_label_create(ui_GroupMinute);
lv_obj_set_width( ui_Label_Number3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Number3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label_Number3, -32 );
lv_obj_set_y( ui_Label_Number3, lv_pct(48) );
lv_obj_set_align( ui_Label_Number3, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label_Number3,"30 min");
lv_label_set_recolor(ui_Label_Number3,"true");
lv_obj_set_style_text_color(ui_Label_Number3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Number3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Number3, &ui_font_Small, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_Number4 = lv_label_create(ui_GroupMinute);
lv_obj_set_width( ui_Label_Number4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Number4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label_Number4, -4 );
lv_obj_set_y( ui_Label_Number4, lv_pct(74) );
lv_obj_set_align( ui_Label_Number4, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label_Number4,"15 min");
lv_label_set_recolor(ui_Label_Number4,"true");
lv_obj_set_style_text_color(ui_Label_Number4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Number4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Number4, &ui_font_Small, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_Number5 = lv_label_create(ui_GroupMinute);
lv_obj_set_width( ui_Label_Number5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Number5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label_Number5, 27 );
lv_obj_set_y( ui_Label_Number5, lv_pct(94) );
lv_obj_set_align( ui_Label_Number5, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label_Number5,"0 min");
lv_label_set_recolor(ui_Label_Number5,"true");
lv_obj_set_style_text_color(ui_Label_Number5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Number5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Number5, &ui_font_Small, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_GroupHour = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_GroupHour, 107);
lv_obj_set_height( ui_GroupHour, 239);
lv_obj_set_x( ui_GroupHour, 135 );
lv_obj_set_y( ui_GroupHour, 0 );
lv_obj_set_align( ui_GroupHour, LV_ALIGN_LEFT_MID );
lv_obj_clear_flag( ui_GroupHour, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GroupHour, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GroupHour, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_Number6 = lv_label_create(ui_GroupHour);
lv_obj_set_width( ui_Label_Number6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Number6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label_Number6, 28 );
lv_obj_set_y( ui_Label_Number6, -2 );
lv_obj_set_align( ui_Label_Number6, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label_Number6,"24 hour");
lv_label_set_recolor(ui_Label_Number6,"true");
lv_obj_set_style_text_color(ui_Label_Number6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Number6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Number6, &ui_font_Small, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_Number8 = lv_label_create(ui_GroupHour);
lv_obj_set_width( ui_Label_Number8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Number8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label_Number8, -32 );
lv_obj_set_y( ui_Label_Number8, lv_pct(48) );
lv_obj_set_align( ui_Label_Number8, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label_Number8,"12 hour");
lv_label_set_recolor(ui_Label_Number8,"true");
lv_obj_set_style_text_color(ui_Label_Number8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Number8, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Number8, &ui_font_Small, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_Number10 = lv_label_create(ui_GroupHour);
lv_obj_set_width( ui_Label_Number10, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Number10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label_Number10, 27 );
lv_obj_set_y( ui_Label_Number10, lv_pct(94) );
lv_obj_set_align( ui_Label_Number10, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label_Number10,"0 hour");
lv_label_set_recolor(ui_Label_Number10,"true");
lv_obj_set_style_text_color(ui_Label_Number10, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Number10, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Number10, &ui_font_Small, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_GroupDate = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_GroupDate, 258);
lv_obj_set_height( ui_GroupDate, 39);
lv_obj_set_x( ui_GroupDate, -10 );
lv_obj_set_y( ui_GroupDate, 65 );
lv_obj_set_align( ui_GroupDate, LV_ALIGN_TOP_RIGHT );
lv_obj_clear_flag( ui_GroupDate, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GroupDate, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GroupDate, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelWeek = lv_label_create(ui_GroupDate);
lv_obj_set_width( ui_LabelWeek, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelWeek, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_LabelWeek, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_LabelWeek,"Sunday");
lv_obj_set_style_text_color(ui_LabelWeek, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelWeek, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LabelWeek, &ui_font_Big, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelDate = lv_label_create(ui_GroupDate);
lv_obj_set_width( ui_LabelDate, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelDate, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_LabelDate, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_LabelDate,"2023-11-13");
lv_obj_set_style_text_color(ui_LabelDate, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelDate, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LabelDate, &ui_font_Big, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BottomGroup = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_BottomGroup, 258);
lv_obj_set_height( ui_BottomGroup, 70);
lv_obj_set_align( ui_BottomGroup, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_clear_flag( ui_BottomGroup, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_BottomGroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BottomGroup, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BottomBg = lv_img_create(ui_BottomGroup);
lv_img_set_src(ui_BottomBg, &ui_img_menu_line_png);
lv_obj_set_width( ui_BottomBg, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BottomBg, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_BottomBg, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_BottomBg, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_BottomBg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_BottomTimerImage = lv_img_create(ui_BottomGroup);
lv_img_set_src(ui_BottomTimerImage, &ui_img_clock_fill_png);
lv_obj_set_width( ui_BottomTimerImage, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BottomTimerImage, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_BottomTimerImage, -10 );
lv_obj_set_y( ui_BottomTimerImage, 0 );
lv_obj_set_align( ui_BottomTimerImage, LV_ALIGN_RIGHT_MID );
lv_obj_add_flag( ui_BottomTimerImage, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_BottomTimerImage, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_BottomLogoImage = lv_img_create(ui_BottomGroup);
lv_img_set_src(ui_BottomLogoImage, &ui_img_bmw_png);
lv_obj_set_width( ui_BottomLogoImage, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BottomLogoImage, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_BottomLogoImage, -80 );
lv_obj_set_y( ui_BottomLogoImage, 0 );
lv_obj_set_align( ui_BottomLogoImage, LV_ALIGN_RIGHT_MID );
lv_obj_add_flag( ui_BottomLogoImage, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_BottomLogoImage, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_BgSlider = lv_slider_create(ui_HomeScreen);
lv_slider_set_range(ui_BgSlider, 90,255);
lv_slider_set_value( ui_BgSlider, 230, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_BgSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_BgSlider, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_BgSlider, 206);
lv_obj_set_height( ui_BgSlider, 10);
lv_obj_set_x( ui_BgSlider, 9 );
lv_obj_set_y( ui_BgSlider, -13 );
lv_obj_set_align( ui_BgSlider, LV_ALIGN_BOTTOM_LEFT );
lv_obj_set_style_bg_color(ui_BgSlider, lv_color_hex(0x3A3A3A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BgSlider, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_BgSlider, lv_color_hex(0x397DCD), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BgSlider, 255, LV_PART_KNOB| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_BottomTimerImage, ui_event_BottomTimerImage, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_BottomLogoImage, ui_event_BottomLogoImage, LV_EVENT_ALL, NULL);

}
