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



void setup_scr_temp_page(lv_ui *ui)
{
    //Write codes temp_page
    ui->temp_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->temp_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->temp_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for temp_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->temp_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->temp_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->temp_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->temp_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->temp_page, 80, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temp_page_img_temp
    ui->temp_page_img_temp = lv_img_create(ui->temp_page);
    lv_obj_add_flag(ui->temp_page_img_temp, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->temp_page_img_temp, &_temp_alpha_61x70);
    lv_img_set_pivot(ui->temp_page_img_temp, 50,50);
    lv_img_set_angle(ui->temp_page_img_temp, 0);
    lv_obj_set_pos(ui->temp_page_img_temp, 31, 150);
    lv_obj_set_size(ui->temp_page_img_temp, 61, 70);

    //Write style for temp_page_img_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->temp_page_img_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->temp_page_img_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temp_page_img_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->temp_page_img_temp, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temp_page_img_hum
    ui->temp_page_img_hum = lv_img_create(ui->temp_page);
    lv_obj_add_flag(ui->temp_page_img_hum, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->temp_page_img_hum, &_water_alpha_61x70);
    lv_img_set_pivot(ui->temp_page_img_hum, 50,50);
    lv_img_set_angle(ui->temp_page_img_hum, 0);
    lv_obj_set_pos(ui->temp_page_img_hum, 31, 44);
    lv_obj_set_size(ui->temp_page_img_hum, 61, 70);

    //Write style for temp_page_img_hum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->temp_page_img_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->temp_page_img_hum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temp_page_img_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->temp_page_img_hum, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temp_page_label_hum
    ui->temp_page_label_hum = lv_label_create(ui->temp_page);
    lv_label_set_text(ui->temp_page_label_hum, "80%");
    lv_label_set_long_mode(ui->temp_page_label_hum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->temp_page_label_hum, 103, 67);
    lv_obj_set_size(ui->temp_page_label_hum, 104, 37);

    //Write style for temp_page_label_hum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temp_page_label_hum, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temp_page_label_hum, &lv_font_montserratMedium_36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temp_page_label_hum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temp_page_label_hum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temp_page_label_hum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temp_page_label_temp
    ui->temp_page_label_temp = lv_label_create(ui->temp_page);
    lv_label_set_text(ui->temp_page_label_temp, "37.5'C");
    lv_label_set_long_mode(ui->temp_page_label_temp, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->temp_page_label_temp, 98, 166);
    lv_obj_set_size(ui->temp_page_label_temp, 122, 37);

    //Write style for temp_page_label_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temp_page_label_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temp_page_label_temp, &lv_font_montserratMedium_36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temp_page_label_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temp_page_label_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temp_page_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of temp_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->temp_page);

    //Init events for screen.
    events_init_temp_page(ui);
}
