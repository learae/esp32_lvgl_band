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



void setup_scr_tianqi_page(lv_ui *ui)
{
    //Write codes tianqi_page
    ui->tianqi_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->tianqi_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->tianqi_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->tianqi_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page_img_tianq
    ui->tianqi_page_img_tianq = lv_img_create(ui->tianqi_page);
    lv_obj_add_flag(ui->tianqi_page_img_tianq, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page_img_tianq, &_4afc305c6f5f0a5ea5b41a1f0498f5f7_alpha_240x280);
    lv_img_set_pivot(ui->tianqi_page_img_tianq, 50,50);
    lv_img_set_angle(ui->tianqi_page_img_tianq, 0);
    lv_obj_set_pos(ui->tianqi_page_img_tianq, 0, 0);
    lv_obj_set_size(ui->tianqi_page_img_tianq, 240, 280);

    //Write style for tianqi_page_img_tianq, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page_img_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page_img_tianq, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page_img_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page_img_tianq, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page_img_2
    ui->tianqi_page_img_2 = lv_img_create(ui->tianqi_page);
    lv_obj_add_flag(ui->tianqi_page_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page_img_2, &_tq1_alpha_123x119);
    lv_img_set_pivot(ui->tianqi_page_img_2, 50,50);
    lv_img_set_angle(ui->tianqi_page_img_2, 0);
    lv_obj_set_pos(ui->tianqi_page_img_2, 3, 0);
    lv_obj_set_size(ui->tianqi_page_img_2, 123, 119);

    //Write style for tianqi_page_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page_img_2, 197, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page_label_tianq
    ui->tianqi_page_label_tianq = lv_label_create(ui->tianqi_page);
    lv_label_set_text(ui->tianqi_page_label_tianq, "25'C");
    lv_label_set_long_mode(ui->tianqi_page_label_tianq, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page_label_tianq, 31, 88);
    lv_obj_set_size(ui->tianqi_page_label_tianq, 143, 77);

    //Write style for tianqi_page_label_tianq, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page_label_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page_label_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page_label_tianq, lv_color_hex(0xf8f8f9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page_label_tianq, &lv_font_Acme_Regular_60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page_label_tianq, 184, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page_label_tianq, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page_label_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page_label_tianq, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page_label_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page_label_tianq, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page_label_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page_label_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page_label_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page_label_tianq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of tianqi_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->tianqi_page);

    //Init events for screen.
    events_init_tianqi_page(ui);
}
