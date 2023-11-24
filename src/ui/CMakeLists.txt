SET(SOURCES screens/ui_Driving.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_ebike_bg_png.c
    images/ui_img_speed_slider_png.c
    images/ui_img_slider_battery_png.c
    images/ui_img_995809848.c
    images/ui_img_652517623.c
    images/ui_img_1560645021.c
    images/ui_img_particle_1_png.c
    fonts/ui_font_Big.c
    fonts/ui_font_Medium.c
    fonts/ui_font_Number.c
    fonts/ui_font_Small.c)

add_library(ui ${SOURCES})
