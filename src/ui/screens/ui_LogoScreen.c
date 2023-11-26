// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: EbikeDemo

#include "../ui.h"

void ui_LogoScreen_screen_init(void)
{
    ui_LogoScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_LogoScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_LogoNextBtn = lv_btn_create(ui_LogoScreen);
    lv_obj_set_width(ui_LogoNextBtn, 160);
    lv_obj_set_height(ui_LogoNextBtn, 70);
    lv_obj_set_x(ui_LogoNextBtn, 0);
    lv_obj_set_y(ui_LogoNextBtn, 100);
    lv_obj_set_align(ui_LogoNextBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_LogoNextBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_LogoNextBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_LogoNextBtn, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LogoNextBtn, lv_color_hex(0x2971CD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LogoNextBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LogoBtnImage = lv_img_create(ui_LogoNextBtn);
    lv_img_set_src(ui_LogoBtnImage, &ui_img_next_png);
    lv_obj_set_width(ui_LogoBtnImage, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_LogoBtnImage, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_LogoBtnImage, -40);
    lv_obj_set_y(ui_LogoBtnImage, 0);
    lv_obj_set_align(ui_LogoBtnImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_LogoBtnImage, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_LogoBtnImage, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_LogoBtnLabel = lv_label_create(ui_LogoNextBtn);
    lv_obj_set_width(ui_LogoBtnLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_LogoBtnLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_LogoBtnLabel, 40);
    lv_obj_set_y(ui_LogoBtnLabel, 0);
    lv_obj_set_align(ui_LogoBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LogoBtnLabel, "NEXT");
    lv_obj_set_style_text_color(ui_LogoBtnLabel, lv_color_hex(0xDDDDDD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LogoBtnLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LogoBtnLabel, &ui_font_Big, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LogoExitImg = lv_img_create(ui_LogoScreen);
    lv_img_set_src(ui_LogoExitImg, &ui_img_exitblack_png);
    lv_obj_set_width(ui_LogoExitImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_LogoExitImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_LogoExitImg, 199);
    lv_obj_set_y(ui_LogoExitImg, 118);
    lv_obj_set_align(ui_LogoExitImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_LogoExitImg, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST); /// Flags
    lv_obj_clear_flag(ui_LogoExitImg, LV_OBJ_FLAG_SCROLLABLE);                        /// Flags

    lv_obj_add_event_cb(ui_LogoNextBtn, ui_event_LogoNextBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LogoExitImg, ui_event_LogoExitImg, LV_EVENT_ALL, NULL);
}
