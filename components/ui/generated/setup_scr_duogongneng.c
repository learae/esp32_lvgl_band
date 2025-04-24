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



void setup_scr_duogongneng(lv_ui *ui)
{
    //Write codes duogongneng
    ui->duogongneng = lv_obj_create(NULL);
    lv_obj_set_size(ui->duogongneng, 240, 280);
    lv_obj_set_scrollbar_mode(ui->duogongneng, LV_SCROLLBAR_MODE_OFF);

    //Write style for duogongneng, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng, lv_color_hex(0x121212), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->duogongneng, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->duogongneng, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->duogongneng, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_cont_all
    ui->duogongneng_cont_all = lv_obj_create(ui->duogongneng);
    lv_obj_set_pos(ui->duogongneng_cont_all, 10, 21);
    lv_obj_set_size(ui->duogongneng_cont_all, 220, 400);
    lv_obj_set_scrollbar_mode(ui->duogongneng_cont_all, LV_SCROLLBAR_MODE_OFF);

    //Write style for duogongneng_cont_all, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->duogongneng_cont_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_cont_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->duogongneng_cont_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->duogongneng_cont_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->duogongneng_cont_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->duogongneng_cont_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->duogongneng_cont_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_cont_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_heart_btn
    ui->duogongneng_heart_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_heart_btn_label = lv_label_create(ui->duogongneng_heart_btn);
    lv_label_set_text(ui->duogongneng_heart_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_heart_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_heart_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_heart_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_heart_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_heart_btn, 155, 20);
    lv_obj_set_size(ui->duogongneng_heart_btn, 50, 50);

    //Write style for duogongneng_heart_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_heart_btn, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_heart_btn, lv_color_hex(0xe94760), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_heart_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_heart_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_heart_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_heart_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_heart_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_heart_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_heart_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_heart_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_heart_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_heart_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_heart_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_heart_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_heart_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_temp_btn
    ui->duogongneng_temp_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_temp_btn_label = lv_label_create(ui->duogongneng_temp_btn);
    lv_label_set_text(ui->duogongneng_temp_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_temp_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_temp_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_temp_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_temp_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_temp_btn, 85, 19);
    lv_obj_set_size(ui->duogongneng_temp_btn, 50, 50);

    //Write style for duogongneng_temp_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_temp_btn, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_temp_btn, lv_color_hex(0x1242ed), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_temp_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_temp_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_temp_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_temp_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_temp_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_temp_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_temp_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_temp_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_temp_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_temp_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_temp_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_temp_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_temp_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_btn_tianq
    ui->duogongneng_btn_tianq = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_btn_tianq_label = lv_label_create(ui->duogongneng_btn_tianq);
    lv_label_set_text(ui->duogongneng_btn_tianq_label, "");
    lv_label_set_long_mode(ui->duogongneng_btn_tianq_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_btn_tianq_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_btn_tianq, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_btn_tianq_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_btn_tianq, 15, 20);
    lv_obj_set_size(ui->duogongneng_btn_tianq, 50, 50);

    //Write style for duogongneng_btn_tianq, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_btn_tianq, 227, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_btn_tianq, lv_color_hex(0xdeeb77), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_btn_tianq, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_btn_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_btn_tianq, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_btn_tianq, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_btn_tianq, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_btn_tianq, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_btn_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_btn_tianq, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_btn_tianq, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_btn_tianq, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_btn_tianq, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_btn_tianq, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_btn_tianq, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_phone_btn
    ui->duogongneng_phone_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_phone_btn_label = lv_label_create(ui->duogongneng_phone_btn);
    lv_label_set_text(ui->duogongneng_phone_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_phone_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_phone_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_phone_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_phone_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_phone_btn, 155, 100);
    lv_obj_set_size(ui->duogongneng_phone_btn, 50, 50);

    //Write style for duogongneng_phone_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_phone_btn, 226, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_phone_btn, lv_color_hex(0x1b78d6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_phone_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_phone_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_phone_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_phone_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_phone_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_phone_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_phone_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_phone_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_phone_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_phone_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_phone_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_phone_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_phone_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_music_btn
    ui->duogongneng_music_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_music_btn_label = lv_label_create(ui->duogongneng_music_btn);
    lv_label_set_text(ui->duogongneng_music_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_music_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_music_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_music_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_music_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_music_btn, 85, 100);
    lv_obj_set_size(ui->duogongneng_music_btn, 50, 50);

    //Write style for duogongneng_music_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_music_btn, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_music_btn, lv_color_hex(0x1bd630), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_music_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_music_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_music_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_music_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_music_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_music_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_music_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_music_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_music_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_music_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_music_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_music_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_music_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_load_btn
    ui->duogongneng_load_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_load_btn_label = lv_label_create(ui->duogongneng_load_btn);
    lv_label_set_text(ui->duogongneng_load_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_load_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_load_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_load_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_load_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_load_btn, 15, 100);
    lv_obj_set_size(ui->duogongneng_load_btn, 50, 50);

    //Write style for duogongneng_load_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_load_btn, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_load_btn, lv_color_hex(0xfefefc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_load_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_load_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_load_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_load_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_load_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_load_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_load_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_load_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_load_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_load_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_load_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_load_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_load_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_btn_lis
    ui->duogongneng_btn_lis = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_btn_lis_label = lv_label_create(ui->duogongneng_btn_lis);
    lv_label_set_text(ui->duogongneng_btn_lis_label, "");
    lv_label_set_long_mode(ui->duogongneng_btn_lis_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_btn_lis_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_btn_lis, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_btn_lis_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_btn_lis, 155, 180);
    lv_obj_set_size(ui->duogongneng_btn_lis, 50, 50);

    //Write style for duogongneng_btn_lis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_btn_lis, 212, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_btn_lis, lv_color_hex(0x64fa69), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_btn_lis, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_btn_lis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_btn_lis, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_btn_lis, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_btn_lis, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_btn_lis, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_btn_lis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_btn_lis, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_btn_lis, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_btn_lis, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_btn_lis, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_btn_lis, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_btn_lis, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_vol_btn
    ui->duogongneng_vol_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_vol_btn_label = lv_label_create(ui->duogongneng_vol_btn);
    lv_label_set_text(ui->duogongneng_vol_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_vol_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_vol_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_vol_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_vol_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_vol_btn, 84, 180);
    lv_obj_set_size(ui->duogongneng_vol_btn, 50, 50);

    //Write style for duogongneng_vol_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_vol_btn, 205, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_vol_btn, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_vol_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_vol_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_vol_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_vol_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_vol_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_vol_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_vol_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_vol_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_vol_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_vol_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_vol_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_vol_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_vol_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_light_btn
    ui->duogongneng_light_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_light_btn_label = lv_label_create(ui->duogongneng_light_btn);
    lv_label_set_text(ui->duogongneng_light_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_light_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_light_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_light_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_light_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_light_btn, 15, 180);
    lv_obj_set_size(ui->duogongneng_light_btn, 50, 50);

    //Write style for duogongneng_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_light_btn, 223, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_light_btn, lv_color_hex(0xf2dd00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_light_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_light_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_light_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_light_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_light_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_light_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_light_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_light_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_heart_img
    ui->duogongneng_heart_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_heart_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_heart_img, &_heart_alpha_35x38);
    lv_img_set_pivot(ui->duogongneng_heart_img, 50,50);
    lv_img_set_angle(ui->duogongneng_heart_img, 0);
    lv_obj_set_pos(ui->duogongneng_heart_img, 162, 26);
    lv_obj_set_size(ui->duogongneng_heart_img, 35, 38);

    //Write style for duogongneng_heart_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_heart_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_heart_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_heart_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_heart_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_temp_img
    ui->duogongneng_temp_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_temp_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_temp_img, &_temp_alpha_40x40);
    lv_img_set_pivot(ui->duogongneng_temp_img, 50,50);
    lv_img_set_angle(ui->duogongneng_temp_img, 0);
    lv_obj_set_pos(ui->duogongneng_temp_img, 90, 25);
    lv_obj_set_size(ui->duogongneng_temp_img, 40, 40);

    //Write style for duogongneng_temp_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_temp_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_temp_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_temp_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_temp_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_tinq_img
    ui->duogongneng_tinq_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_tinq_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_tinq_img, &_cloud_alpha_40x40);
    lv_img_set_pivot(ui->duogongneng_tinq_img, 50,50);
    lv_img_set_angle(ui->duogongneng_tinq_img, 0);
    lv_obj_set_pos(ui->duogongneng_tinq_img, 19, 23);
    lv_obj_set_size(ui->duogongneng_tinq_img, 40, 40);

    //Write style for duogongneng_tinq_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_tinq_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_tinq_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_tinq_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_tinq_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_load_img
    ui->duogongneng_load_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_load_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_load_img, &_nouth_alpha_45x45);
    lv_img_set_pivot(ui->duogongneng_load_img, 50,50);
    lv_img_set_angle(ui->duogongneng_load_img, 0);
    lv_obj_set_pos(ui->duogongneng_load_img, 18, 102);
    lv_obj_set_size(ui->duogongneng_load_img, 45, 45);

    //Write style for duogongneng_load_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_load_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_load_img, 223, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_load_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_load_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_music_img
    ui->duogongneng_music_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_music_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_music_img, &_music_alpha_40x40);
    lv_img_set_pivot(ui->duogongneng_music_img, 50,50);
    lv_img_set_angle(ui->duogongneng_music_img, 0);
    lv_obj_set_pos(ui->duogongneng_music_img, 86, 103);
    lv_obj_set_size(ui->duogongneng_music_img, 40, 40);

    //Write style for duogongneng_music_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_music_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_music_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_music_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_music_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_phone_img
    ui->duogongneng_phone_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_phone_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_phone_img, &_iphone_alpha_40x40);
    lv_img_set_pivot(ui->duogongneng_phone_img, 50,50);
    lv_img_set_angle(ui->duogongneng_phone_img, 0);
    lv_obj_set_pos(ui->duogongneng_phone_img, 160, 106);
    lv_obj_set_size(ui->duogongneng_phone_img, 40, 40);

    //Write style for duogongneng_phone_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_phone_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_phone_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_phone_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_phone_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_light_img
    ui->duogongneng_light_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_light_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_light_img, &_o_alpha_40x40);
    lv_img_set_pivot(ui->duogongneng_light_img, 50,50);
    lv_img_set_angle(ui->duogongneng_light_img, 0);
    lv_obj_set_pos(ui->duogongneng_light_img, 19, 185);
    lv_obj_set_size(ui->duogongneng_light_img, 40, 40);

    //Write style for duogongneng_light_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_light_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_light_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_light_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_light_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_vol_img
    ui->duogongneng_vol_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_vol_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_vol_img, &_volu_alpha_40x40);
    lv_img_set_pivot(ui->duogongneng_vol_img, 50,50);
    lv_img_set_angle(ui->duogongneng_vol_img, 0);
    lv_obj_set_pos(ui->duogongneng_vol_img, 90, 184);
    lv_obj_set_size(ui->duogongneng_vol_img, 40, 40);

    //Write style for duogongneng_vol_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_vol_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_vol_img, 197, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_vol_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_vol_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_img_lis
    ui->duogongneng_img_lis = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_img_lis, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_img_lis, &_ear_alpha_35x35);
    lv_img_set_pivot(ui->duogongneng_img_lis, 50,50);
    lv_img_set_angle(ui->duogongneng_img_lis, 0);
    lv_obj_set_pos(ui->duogongneng_img_lis, 165, 192);
    lv_obj_set_size(ui->duogongneng_img_lis, 35, 35);

    //Write style for duogongneng_img_lis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_img_lis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_img_lis, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_img_lis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_img_lis, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_btn_txt
    ui->duogongneng_btn_txt = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_btn_txt_label = lv_label_create(ui->duogongneng_btn_txt);
    lv_label_set_text(ui->duogongneng_btn_txt_label, "");
    lv_label_set_long_mode(ui->duogongneng_btn_txt_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_btn_txt_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_btn_txt, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_btn_txt_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_btn_txt, 155, 260);
    lv_obj_set_size(ui->duogongneng_btn_txt, 50, 50);

    //Write style for duogongneng_btn_txt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_btn_txt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_btn_txt, lv_color_hex(0xc0639f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_btn_txt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_btn_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_btn_txt, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_btn_txt, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_btn_txt, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_btn_txt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_btn_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_btn_txt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_btn_txt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_btn_txt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_btn_txt, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_btn_txt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_btn_txt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_config_btn
    ui->duogongneng_config_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_config_btn_label = lv_label_create(ui->duogongneng_config_btn);
    lv_label_set_text(ui->duogongneng_config_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_config_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_config_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_config_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_config_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_config_btn, 85, 260);
    lv_obj_set_size(ui->duogongneng_config_btn, 50, 50);

    //Write style for duogongneng_config_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_config_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_config_btn, lv_color_hex(0xdbdfe5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_config_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_config_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_config_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_config_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_config_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_config_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_config_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_config_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_config_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_config_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_config_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_config_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_config_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_connect_btn
    ui->duogongneng_connect_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_connect_btn_label = lv_label_create(ui->duogongneng_connect_btn);
    lv_label_set_text(ui->duogongneng_connect_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_connect_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_connect_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_connect_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_connect_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_connect_btn, 15, 260);
    lv_obj_set_size(ui->duogongneng_connect_btn, 50, 50);

    //Write style for duogongneng_connect_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_connect_btn, 214, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_connect_btn, lv_color_hex(0xf7f8f8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_connect_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_connect_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_connect_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_connect_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_connect_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_connect_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_connect_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_connect_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_connect_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_connect_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_connect_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_connect_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_connect_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_math_btn
    ui->duogongneng_math_btn = lv_btn_create(ui->duogongneng_cont_all);
    ui->duogongneng_math_btn_label = lv_label_create(ui->duogongneng_math_btn);
    lv_label_set_text(ui->duogongneng_math_btn_label, "");
    lv_label_set_long_mode(ui->duogongneng_math_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->duogongneng_math_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->duogongneng_math_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->duogongneng_math_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->duogongneng_math_btn, 12, 333);
    lv_obj_set_size(ui->duogongneng_math_btn, 50, 50);

    //Write style for duogongneng_math_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->duogongneng_math_btn, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->duogongneng_math_btn, lv_color_hex(0xdcd8dc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->duogongneng_math_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->duogongneng_math_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_math_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->duogongneng_math_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->duogongneng_math_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->duogongneng_math_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->duogongneng_math_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->duogongneng_math_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->duogongneng_math_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->duogongneng_math_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->duogongneng_math_btn, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->duogongneng_math_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->duogongneng_math_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_connect_img
    ui->duogongneng_connect_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_connect_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_connect_img, &_conncet_alpha_38x37);
    lv_img_set_pivot(ui->duogongneng_connect_img, 50,50);
    lv_img_set_angle(ui->duogongneng_connect_img, 0);
    lv_obj_set_pos(ui->duogongneng_connect_img, 21, 268);
    lv_obj_set_size(ui->duogongneng_connect_img, 38, 37);

    //Write style for duogongneng_connect_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_connect_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_connect_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_connect_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_connect_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_config_img
    ui->duogongneng_config_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_config_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_config_img, &_sz_alpha_50x50);
    lv_img_set_pivot(ui->duogongneng_config_img, 50,50);
    lv_img_set_angle(ui->duogongneng_config_img, 0);
    lv_obj_set_pos(ui->duogongneng_config_img, 85, 260);
    lv_obj_set_size(ui->duogongneng_config_img, 50, 50);

    //Write style for duogongneng_config_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_config_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_config_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_config_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_config_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_txt_img
    ui->duogongneng_txt_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_txt_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_txt_img, &_text_alpha_38x40);
    lv_img_set_pivot(ui->duogongneng_txt_img, 50,50);
    lv_img_set_angle(ui->duogongneng_txt_img, 0);
    lv_obj_set_pos(ui->duogongneng_txt_img, 161, 264);
    lv_obj_set_size(ui->duogongneng_txt_img, 38, 40);

    //Write style for duogongneng_txt_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_txt_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_txt_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_txt_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_txt_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes duogongneng_math_img
    ui->duogongneng_math_img = lv_img_create(ui->duogongneng_cont_all);
    lv_obj_add_flag(ui->duogongneng_math_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->duogongneng_math_img, &_math_alpha_35x35);
    lv_img_set_pivot(ui->duogongneng_math_img, 50,50);
    lv_img_set_angle(ui->duogongneng_math_img, 0);
    lv_obj_set_pos(ui->duogongneng_math_img, 19, 341);
    lv_obj_set_size(ui->duogongneng_math_img, 35, 35);

    //Write style for duogongneng_math_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->duogongneng_math_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->duogongneng_math_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->duogongneng_math_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->duogongneng_math_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of duogongneng.


    //Update current screen layout.
    lv_obj_update_layout(ui->duogongneng);

    //Init events for screen.
    events_init_duogongneng(ui);
}
