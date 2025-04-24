/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom/custom.h"



void setup_scr_shezhi(lv_ui *ui)
{
    //Write codes shezhi
    ui->shezhi = lv_obj_create(NULL);
    lv_obj_set_size(ui->shezhi, 240, 280);
    lv_obj_set_scrollbar_mode(ui->shezhi, LV_SCROLLBAR_MODE_OFF);

    //Write style for shezhi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->shezhi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes shezhi_img_3
    ui->shezhi_img_3 = lv_img_create(ui->shezhi);
    lv_obj_add_flag(ui->shezhi_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->shezhi_img_3, &_BlurMoment_Gaussian_2025_3_18_17_16_alpha_240x280);
    lv_img_set_pivot(ui->shezhi_img_3, 50,50);
    lv_img_set_angle(ui->shezhi_img_3, 0);
    lv_obj_set_pos(ui->shezhi_img_3, 0, 0);
    lv_obj_set_size(ui->shezhi_img_3, 240, 280);

    //Write style for shezhi_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->shezhi_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->shezhi_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes shezhi_cont_sethome
    ui->shezhi_cont_sethome = lv_obj_create(ui->shezhi);
    lv_obj_set_pos(ui->shezhi_cont_sethome, 0, 0);
    lv_obj_set_size(ui->shezhi_cont_sethome, 240, 120);
    lv_obj_set_scrollbar_mode(ui->shezhi_cont_sethome, LV_SCROLLBAR_MODE_OFF);

    //Write style for shezhi_cont_sethome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->shezhi_cont_sethome, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->shezhi_cont_sethome, 204, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->shezhi_cont_sethome, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->shezhi_cont_sethome, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_cont_sethome, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->shezhi_cont_sethome, 230, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->shezhi_cont_sethome, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->shezhi_cont_sethome, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->shezhi_cont_sethome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->shezhi_cont_sethome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->shezhi_cont_sethome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->shezhi_cont_sethome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->shezhi_cont_sethome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes shezhi_config_btn
    ui->shezhi_config_btn = lv_imgbtn_create(ui->shezhi_cont_sethome);
    lv_obj_add_flag(ui->shezhi_config_btn, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->shezhi_config_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_sz_alpha_40x40, NULL);
    lv_imgbtn_set_src(ui->shezhi_config_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_sz2_alpha_40x40, NULL);
    ui->shezhi_config_btn_label = lv_label_create(ui->shezhi_config_btn);
    lv_label_set_text(ui->shezhi_config_btn_label, "");
    lv_label_set_long_mode(ui->shezhi_config_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->shezhi_config_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->shezhi_config_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->shezhi_config_btn, 170, 20);
    lv_obj_set_size(ui->shezhi_config_btn, 40, 40);

    //Write style for shezhi_config_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->shezhi_config_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->shezhi_config_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->shezhi_config_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->shezhi_config_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_config_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->shezhi_config_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->shezhi_config_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for shezhi_config_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_config_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->shezhi_config_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->shezhi_config_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->shezhi_config_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->shezhi_config_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->shezhi_config_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for shezhi_config_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_config_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->shezhi_config_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->shezhi_config_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->shezhi_config_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->shezhi_config_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->shezhi_config_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for shezhi_config_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_config_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->shezhi_config_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes shezhi_bt_btn
    ui->shezhi_bt_btn = lv_imgbtn_create(ui->shezhi_cont_sethome);
    lv_obj_add_flag(ui->shezhi_bt_btn, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->shezhi_bt_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_L_alpha_45x45, NULL);
    lv_imgbtn_set_src(ui->shezhi_bt_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_l2_alpha_45x45, NULL);
    lv_imgbtn_set_src(ui->shezhi_bt_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_l2_alpha_45x45, NULL);
    lv_imgbtn_set_src(ui->shezhi_bt_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_L_alpha_45x45, NULL);
    ui->shezhi_bt_btn_label = lv_label_create(ui->shezhi_bt_btn);
    lv_label_set_text(ui->shezhi_bt_btn_label, "");
    lv_label_set_long_mode(ui->shezhi_bt_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->shezhi_bt_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->shezhi_bt_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->shezhi_bt_btn, 98, 18);
    lv_obj_set_size(ui->shezhi_bt_btn, 45, 45);

    //Write style for shezhi_bt_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->shezhi_bt_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->shezhi_bt_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->shezhi_bt_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->shezhi_bt_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_bt_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->shezhi_bt_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->shezhi_bt_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for shezhi_bt_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_bt_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->shezhi_bt_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->shezhi_bt_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->shezhi_bt_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->shezhi_bt_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->shezhi_bt_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for shezhi_bt_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_bt_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->shezhi_bt_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->shezhi_bt_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->shezhi_bt_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->shezhi_bt_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->shezhi_bt_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for shezhi_bt_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_bt_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->shezhi_bt_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes shezhi_img_li
    ui->shezhi_img_li = lv_img_create(ui->shezhi_cont_sethome);
    lv_obj_add_flag(ui->shezhi_img_li, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->shezhi_img_li, &_o_alpha_25x25);
    lv_img_set_pivot(ui->shezhi_img_li, 50,50);
    lv_img_set_angle(ui->shezhi_img_li, 0);
    lv_obj_set_pos(ui->shezhi_img_li, 27, 72);
    lv_obj_set_size(ui->shezhi_img_li, 25, 25);

    //Write style for shezhi_img_li, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_img_li, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->shezhi_img_li, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_img_li, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->shezhi_img_li, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes shezhi_slider_li
    ui->shezhi_slider_li = lv_slider_create(ui->shezhi_cont_sethome);
    lv_slider_set_range(ui->shezhi_slider_li, 0, 100);
    lv_slider_set_mode(ui->shezhi_slider_li, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->shezhi_slider_li, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->shezhi_slider_li, 52, 79);
    lv_obj_set_size(ui->shezhi_slider_li, 152, 10);

    //Write style for shezhi_slider_li, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->shezhi_slider_li, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->shezhi_slider_li, lv_color_hex(0x979a9d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->shezhi_slider_li, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_slider_li, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->shezhi_slider_li, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->shezhi_slider_li, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for shezhi_slider_li, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->shezhi_slider_li, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->shezhi_slider_li, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->shezhi_slider_li, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_slider_li, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for shezhi_slider_li, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->shezhi_slider_li, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->shezhi_slider_li, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->shezhi_slider_li, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_slider_li, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes shezhi_wifi_btn
    ui->shezhi_wifi_btn = lv_imgbtn_create(ui->shezhi_cont_sethome);
    lv_obj_add_flag(ui->shezhi_wifi_btn, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->shezhi_wifi_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_WiF01651i_alpha_40x40, NULL);
    lv_imgbtn_set_src(ui->shezhi_wifi_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_WifadasdFi_alpha_40x40, NULL);
    lv_imgbtn_set_src(ui->shezhi_wifi_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_WifadasdFi_alpha_40x40, NULL);
    lv_imgbtn_set_src(ui->shezhi_wifi_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_WiF01651i_alpha_40x40, NULL);
    ui->shezhi_wifi_btn_label = lv_label_create(ui->shezhi_wifi_btn);
    lv_label_set_text(ui->shezhi_wifi_btn_label, "");
    lv_label_set_long_mode(ui->shezhi_wifi_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->shezhi_wifi_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->shezhi_wifi_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->shezhi_wifi_btn, 30, 20);
    lv_obj_set_size(ui->shezhi_wifi_btn, 40, 40);

    //Write style for shezhi_wifi_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->shezhi_wifi_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->shezhi_wifi_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->shezhi_wifi_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->shezhi_wifi_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->shezhi_wifi_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->shezhi_wifi_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->shezhi_wifi_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for shezhi_wifi_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_wifi_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->shezhi_wifi_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->shezhi_wifi_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->shezhi_wifi_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->shezhi_wifi_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->shezhi_wifi_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for shezhi_wifi_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_wifi_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->shezhi_wifi_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->shezhi_wifi_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->shezhi_wifi_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->shezhi_wifi_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->shezhi_wifi_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for shezhi_wifi_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->shezhi_wifi_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->shezhi_wifi_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //The custom code of shezhi.


    //Update current screen layout.
    lv_obj_update_layout(ui->shezhi);

    //Init events for screen.
    events_init_shezhi(ui);
}
