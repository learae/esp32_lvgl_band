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



void setup_scr_settings_page(lv_ui *ui)
{
    //Write codes settings_page
    ui->settings_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->settings_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->settings_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for settings_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->settings_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->settings_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->settings_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_page_btn_time_cor
    ui->settings_page_btn_time_cor = lv_btn_create(ui->settings_page);
    ui->settings_page_btn_time_cor_label = lv_label_create(ui->settings_page_btn_time_cor);
    lv_label_set_text(ui->settings_page_btn_time_cor_label, "Time correct");
    lv_label_set_long_mode(ui->settings_page_btn_time_cor_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_page_btn_time_cor_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_page_btn_time_cor, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_page_btn_time_cor_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_page_btn_time_cor, 10, 47);
    lv_obj_set_size(ui->settings_page_btn_time_cor, 220, 50);

    //Write style for settings_page_btn_time_cor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_page_btn_time_cor, 214, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_page_btn_time_cor, lv_color_hex(0x2a2a2a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_page_btn_time_cor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_page_btn_time_cor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_page_btn_time_cor, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_page_btn_time_cor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->settings_page_btn_time_cor, lv_color_hex(0xf3f3f3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->settings_page_btn_time_cor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->settings_page_btn_time_cor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->settings_page_btn_time_cor, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->settings_page_btn_time_cor, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_page_btn_time_cor, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_page_btn_time_cor, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_page_btn_time_cor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_page_btn_time_cor, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_page_btn_other
    ui->settings_page_btn_other = lv_btn_create(ui->settings_page);
    ui->settings_page_btn_other_label = lv_label_create(ui->settings_page_btn_other);
    lv_label_set_text(ui->settings_page_btn_other_label, "");
    lv_label_set_long_mode(ui->settings_page_btn_other_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_page_btn_other_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_page_btn_other, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_page_btn_other_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_page_btn_other, 10, 108);
    lv_obj_set_size(ui->settings_page_btn_other, 220, 50);

    //Write style for settings_page_btn_other, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_page_btn_other, 214, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_page_btn_other, lv_color_hex(0x2a2a2a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_page_btn_other, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_page_btn_other, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_page_btn_other, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_page_btn_other, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->settings_page_btn_other, lv_color_hex(0xf3f3f3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->settings_page_btn_other, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->settings_page_btn_other, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->settings_page_btn_other, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->settings_page_btn_other, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_page_btn_other, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_page_btn_other, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_page_btn_other, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_page_btn_other, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_page_btn_ps
    ui->settings_page_btn_ps = lv_btn_create(ui->settings_page);
    ui->settings_page_btn_ps_label = lv_label_create(ui->settings_page_btn_ps);
    lv_label_set_text(ui->settings_page_btn_ps_label, "ps: hcc");
    lv_label_set_long_mode(ui->settings_page_btn_ps_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_page_btn_ps_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_page_btn_ps, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_page_btn_ps_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_page_btn_ps, 10, 167);
    lv_obj_set_size(ui->settings_page_btn_ps, 220, 50);

    //Write style for settings_page_btn_ps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_page_btn_ps, 214, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_page_btn_ps, lv_color_hex(0x2a2a2a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_page_btn_ps, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_page_btn_ps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_page_btn_ps, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_page_btn_ps, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->settings_page_btn_ps, lv_color_hex(0xf3f3f3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->settings_page_btn_ps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->settings_page_btn_ps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->settings_page_btn_ps, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->settings_page_btn_ps, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_page_btn_ps, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_page_btn_ps, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_page_btn_ps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_page_btn_ps, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_page_btn_version
    ui->settings_page_btn_version = lv_btn_create(ui->settings_page);
    ui->settings_page_btn_version_label = lv_label_create(ui->settings_page_btn_version);
    lv_label_set_text(ui->settings_page_btn_version_label, "version: 1.0.0");
    lv_label_set_long_mode(ui->settings_page_btn_version_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_page_btn_version_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_page_btn_version, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_page_btn_version_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_page_btn_version, 10, 226);
    lv_obj_set_size(ui->settings_page_btn_version, 220, 50);

    //Write style for settings_page_btn_version, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_page_btn_version, 214, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_page_btn_version, lv_color_hex(0x2a2a2a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_page_btn_version, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_page_btn_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_page_btn_version, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_page_btn_version, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->settings_page_btn_version, lv_color_hex(0xf3f3f3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->settings_page_btn_version, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->settings_page_btn_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->settings_page_btn_version, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->settings_page_btn_version, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_page_btn_version, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_page_btn_version, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_page_btn_version, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_page_btn_version, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_page_btn_set_back
    ui->settings_page_btn_set_back = lv_btn_create(ui->settings_page);
    ui->settings_page_btn_set_back_label = lv_label_create(ui->settings_page_btn_set_back);
    lv_label_set_text(ui->settings_page_btn_set_back_label, "<-bank");
    lv_label_set_long_mode(ui->settings_page_btn_set_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_page_btn_set_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_page_btn_set_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_page_btn_set_back_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_page_btn_set_back, 10, 10);
    lv_obj_set_size(ui->settings_page_btn_set_back, 72, 30);

    //Write style for settings_page_btn_set_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_page_btn_set_back, 42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_page_btn_set_back, lv_color_hex(0x2a2a2a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_page_btn_set_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_page_btn_set_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_page_btn_set_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_page_btn_set_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_page_btn_set_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_page_btn_set_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_page_btn_set_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_page_btn_set_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of settings_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->settings_page);

    //Init events for screen.
    events_init_settings_page(ui);
}
