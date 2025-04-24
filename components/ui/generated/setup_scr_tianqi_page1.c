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



void setup_scr_tianqi_page1(lv_ui *ui)
{
    //Write codes tianqi_page1
    ui->tianqi_page1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->tianqi_page1, 240, 280);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->tianqi_page1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->tianqi_page1, &_4afc305c6f5f0a5ea5b41a1f0498f5f7_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->tianqi_page1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->tianqi_page1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->tianqi_page1, 80, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_cont_1
    ui->tianqi_page1_cont_1 = lv_obj_create(ui->tianqi_page1);
    lv_obj_set_pos(ui->tianqi_page1_cont_1, 24, 68);
    lv_obj_set_size(ui->tianqi_page1_cont_1, 200, 400);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->tianqi_page1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->tianqi_page1_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->tianqi_page1_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_cont_weather2
    ui->tianqi_page1_cont_weather2 = lv_obj_create(ui->tianqi_page1_cont_1);
    lv_obj_set_pos(ui->tianqi_page1_cont_weather2, -1, 55);
    lv_obj_set_size(ui->tianqi_page1_cont_weather2, 200, 50);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1_cont_weather2, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1_cont_weather2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_cont_weather2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->tianqi_page1_cont_weather2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->tianqi_page1_cont_weather2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->tianqi_page1_cont_weather2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_cont_weather2, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_cont_weather2, 62, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tianqi_page1_cont_weather2, lv_color_hex(0xe0d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tianqi_page1_cont_weather2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_cont_weather2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_cont_weather2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_cont_weather2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_cont_weather2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_cont_weather2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_cont_weather4
    ui->tianqi_page1_cont_weather4 = lv_obj_create(ui->tianqi_page1_cont_1);
    lv_obj_set_pos(ui->tianqi_page1_cont_weather4, -2, 165);
    lv_obj_set_size(ui->tianqi_page1_cont_weather4, 200, 50);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1_cont_weather4, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1_cont_weather4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_cont_weather4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->tianqi_page1_cont_weather4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->tianqi_page1_cont_weather4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->tianqi_page1_cont_weather4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_cont_weather4, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_cont_weather4, 62, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tianqi_page1_cont_weather4, lv_color_hex(0xe0d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tianqi_page1_cont_weather4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_cont_weather4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_cont_weather4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_cont_weather4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_cont_weather4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_cont_weather4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_cont_weather3
    ui->tianqi_page1_cont_weather3 = lv_obj_create(ui->tianqi_page1_cont_1);
    lv_obj_set_pos(ui->tianqi_page1_cont_weather3, -1, 110);
    lv_obj_set_size(ui->tianqi_page1_cont_weather3, 200, 50);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1_cont_weather3, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1_cont_weather3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_cont_weather3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->tianqi_page1_cont_weather3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->tianqi_page1_cont_weather3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->tianqi_page1_cont_weather3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_cont_weather3, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_cont_weather3, 62, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tianqi_page1_cont_weather3, lv_color_hex(0xe0d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tianqi_page1_cont_weather3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_cont_weather3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_cont_weather3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_cont_weather3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_cont_weather3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_cont_weather3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_cont_weather5
    ui->tianqi_page1_cont_weather5 = lv_obj_create(ui->tianqi_page1_cont_1);
    lv_obj_set_pos(ui->tianqi_page1_cont_weather5, -1, 220);
    lv_obj_set_size(ui->tianqi_page1_cont_weather5, 200, 50);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1_cont_weather5, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1_cont_weather5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_cont_weather5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->tianqi_page1_cont_weather5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->tianqi_page1_cont_weather5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->tianqi_page1_cont_weather5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_cont_weather5, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_cont_weather5, 62, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tianqi_page1_cont_weather5, lv_color_hex(0xe0d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tianqi_page1_cont_weather5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_cont_weather5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_cont_weather5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_cont_weather5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_cont_weather5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_cont_weather5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_cont_weather6
    ui->tianqi_page1_cont_weather6 = lv_obj_create(ui->tianqi_page1_cont_1);
    lv_obj_set_pos(ui->tianqi_page1_cont_weather6, -1, 275);
    lv_obj_set_size(ui->tianqi_page1_cont_weather6, 200, 50);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1_cont_weather6, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1_cont_weather6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_cont_weather6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->tianqi_page1_cont_weather6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->tianqi_page1_cont_weather6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->tianqi_page1_cont_weather6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_cont_weather6, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_cont_weather6, 62, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tianqi_page1_cont_weather6, lv_color_hex(0xe0d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tianqi_page1_cont_weather6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_cont_weather6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_cont_weather6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_cont_weather6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_cont_weather6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_cont_weather6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_cont_weather7
    ui->tianqi_page1_cont_weather7 = lv_obj_create(ui->tianqi_page1_cont_1);
    lv_obj_set_pos(ui->tianqi_page1_cont_weather7, -1, 330);
    lv_obj_set_size(ui->tianqi_page1_cont_weather7, 200, 50);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1_cont_weather7, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1_cont_weather7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_cont_weather7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->tianqi_page1_cont_weather7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->tianqi_page1_cont_weather7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->tianqi_page1_cont_weather7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_cont_weather7, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_cont_weather7, 62, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tianqi_page1_cont_weather7, lv_color_hex(0xe0d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tianqi_page1_cont_weather7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_cont_weather7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_cont_weather7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_cont_weather7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_cont_weather7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_cont_weather7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_cont_weather1
    ui->tianqi_page1_cont_weather1 = lv_obj_create(ui->tianqi_page1_cont_1);
    lv_obj_set_pos(ui->tianqi_page1_cont_weather1, -1, 1);
    lv_obj_set_size(ui->tianqi_page1_cont_weather1, 200, 50);
    lv_obj_set_scrollbar_mode(ui->tianqi_page1_cont_weather1, LV_SCROLLBAR_MODE_OFF);

    //Write style for tianqi_page1_cont_weather1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_cont_weather1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->tianqi_page1_cont_weather1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->tianqi_page1_cont_weather1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->tianqi_page1_cont_weather1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_cont_weather1, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_cont_weather1, 62, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tianqi_page1_cont_weather1, lv_color_hex(0xe0d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tianqi_page1_cont_weather1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_cont_weather1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_cont_weather1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_cont_weather1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_cont_weather1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_cont_weather1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_img_weather5
    ui->tianqi_page1_img_weather5 = lv_img_create(ui->tianqi_page1);
    lv_obj_add_flag(ui->tianqi_page1_img_weather5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page1_img_weather5, &_tq1_alpha_40x35);
    lv_img_set_pivot(ui->tianqi_page1_img_weather5, 50,50);
    lv_img_set_angle(ui->tianqi_page1_img_weather5, 0);
    lv_obj_set_pos(ui->tianqi_page1_img_weather5, 40, 300);
    lv_obj_set_size(ui->tianqi_page1_img_weather5, 40, 35);

    //Write style for tianqi_page1_img_weather5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page1_img_weather5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page1_img_weather5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_img_weather5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page1_img_weather5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_img_weather4
    ui->tianqi_page1_img_weather4 = lv_img_create(ui->tianqi_page1);
    lv_obj_add_flag(ui->tianqi_page1_img_weather4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page1_img_weather4, &_tq1_alpha_40x35);
    lv_img_set_pivot(ui->tianqi_page1_img_weather4, 50,50);
    lv_img_set_angle(ui->tianqi_page1_img_weather4, 0);
    lv_obj_set_pos(ui->tianqi_page1_img_weather4, 40, 245);
    lv_obj_set_size(ui->tianqi_page1_img_weather4, 40, 35);

    //Write style for tianqi_page1_img_weather4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page1_img_weather4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page1_img_weather4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_img_weather4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page1_img_weather4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_img_weather2
    ui->tianqi_page1_img_weather2 = lv_img_create(ui->tianqi_page1);
    lv_obj_add_flag(ui->tianqi_page1_img_weather2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page1_img_weather2, &_tq1_alpha_40x35);
    lv_img_set_pivot(ui->tianqi_page1_img_weather2, 50,50);
    lv_img_set_angle(ui->tianqi_page1_img_weather2, 0);
    lv_obj_set_pos(ui->tianqi_page1_img_weather2, 40, 135);
    lv_obj_set_size(ui->tianqi_page1_img_weather2, 40, 35);

    //Write style for tianqi_page1_img_weather2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page1_img_weather2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page1_img_weather2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_img_weather2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page1_img_weather2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_img_weather3
    ui->tianqi_page1_img_weather3 = lv_img_create(ui->tianqi_page1);
    lv_obj_add_flag(ui->tianqi_page1_img_weather3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page1_img_weather3, &_tq1_alpha_40x35);
    lv_img_set_pivot(ui->tianqi_page1_img_weather3, 50,50);
    lv_img_set_angle(ui->tianqi_page1_img_weather3, 0);
    lv_obj_set_pos(ui->tianqi_page1_img_weather3, 40, 190);
    lv_obj_set_size(ui->tianqi_page1_img_weather3, 40, 35);

    //Write style for tianqi_page1_img_weather3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page1_img_weather3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page1_img_weather3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_img_weather3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page1_img_weather3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_img_weather1
    ui->tianqi_page1_img_weather1 = lv_img_create(ui->tianqi_page1);
    lv_obj_add_flag(ui->tianqi_page1_img_weather1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page1_img_weather1, &_tq1_alpha_40x35);
    lv_img_set_pivot(ui->tianqi_page1_img_weather1, 50,50);
    lv_img_set_angle(ui->tianqi_page1_img_weather1, 0);
    lv_obj_set_pos(ui->tianqi_page1_img_weather1, 40, 80);
    lv_obj_set_size(ui->tianqi_page1_img_weather1, 40, 35);

    //Write style for tianqi_page1_img_weather1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page1_img_weather1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page1_img_weather1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_img_weather1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page1_img_weather1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_img_weather7
    ui->tianqi_page1_img_weather7 = lv_img_create(ui->tianqi_page1);
    lv_obj_add_flag(ui->tianqi_page1_img_weather7, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page1_img_weather7, &_tq1_alpha_40x35);
    lv_img_set_pivot(ui->tianqi_page1_img_weather7, 50,50);
    lv_img_set_angle(ui->tianqi_page1_img_weather7, 0);
    lv_obj_set_pos(ui->tianqi_page1_img_weather7, 40, 410);
    lv_obj_set_size(ui->tianqi_page1_img_weather7, 40, 35);

    //Write style for tianqi_page1_img_weather7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page1_img_weather7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page1_img_weather7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_img_weather7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page1_img_weather7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_img_weather6
    ui->tianqi_page1_img_weather6 = lv_img_create(ui->tianqi_page1);
    lv_obj_add_flag(ui->tianqi_page1_img_weather6, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tianqi_page1_img_weather6, &_tq1_alpha_40x35);
    lv_img_set_pivot(ui->tianqi_page1_img_weather6, 50,50);
    lv_img_set_angle(ui->tianqi_page1_img_weather6, 0);
    lv_obj_set_pos(ui->tianqi_page1_img_weather6, 40, 355);
    lv_obj_set_size(ui->tianqi_page1_img_weather6, 40, 35);

    //Write style for tianqi_page1_img_weather6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tianqi_page1_img_weather6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tianqi_page1_img_weather6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_img_weather6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tianqi_page1_img_weather6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_weektemp1
    ui->tianqi_page1_weektemp1 = lv_label_create(ui->tianqi_page1);
    lv_label_set_text(ui->tianqi_page1_weektemp1, "16~28'C");
    lv_label_set_long_mode(ui->tianqi_page1_weektemp1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page1_weektemp1, 87, 86);
    lv_obj_set_size(ui->tianqi_page1_weektemp1, 100, 32);

    //Write style for tianqi_page1_weektemp1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page1_weektemp1, lv_color_hex(0xeae2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page1_weektemp1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page1_weektemp1, 229, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page1_weektemp1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_weektemp1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_weektemp2
    ui->tianqi_page1_weektemp2 = lv_label_create(ui->tianqi_page1);
    lv_label_set_text(ui->tianqi_page1_weektemp2, "16~28'C");
    lv_label_set_long_mode(ui->tianqi_page1_weektemp2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page1_weektemp2, 87, 140);
    lv_obj_set_size(ui->tianqi_page1_weektemp2, 100, 32);

    //Write style for tianqi_page1_weektemp2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page1_weektemp2, lv_color_hex(0xeae2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page1_weektemp2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page1_weektemp2, 229, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page1_weektemp2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_weektemp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_weektemp3
    ui->tianqi_page1_weektemp3 = lv_label_create(ui->tianqi_page1);
    lv_label_set_text(ui->tianqi_page1_weektemp3, "16~28'C");
    lv_label_set_long_mode(ui->tianqi_page1_weektemp3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page1_weektemp3, 87, 196);
    lv_obj_set_size(ui->tianqi_page1_weektemp3, 100, 32);

    //Write style for tianqi_page1_weektemp3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page1_weektemp3, lv_color_hex(0xeae2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page1_weektemp3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page1_weektemp3, 229, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page1_weektemp3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_weektemp3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_weektemp7
    ui->tianqi_page1_weektemp7 = lv_label_create(ui->tianqi_page1);
    lv_label_set_text(ui->tianqi_page1_weektemp7, "16~28'C");
    lv_label_set_long_mode(ui->tianqi_page1_weektemp7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page1_weektemp7, 87, 413);
    lv_obj_set_size(ui->tianqi_page1_weektemp7, 100, 32);

    //Write style for tianqi_page1_weektemp7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page1_weektemp7, lv_color_hex(0xeae2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page1_weektemp7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page1_weektemp7, 229, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page1_weektemp7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_weektemp7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_weektemp6
    ui->tianqi_page1_weektemp6 = lv_label_create(ui->tianqi_page1);
    lv_label_set_text(ui->tianqi_page1_weektemp6, "16~28'C");
    lv_label_set_long_mode(ui->tianqi_page1_weektemp6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page1_weektemp6, 87, 361);
    lv_obj_set_size(ui->tianqi_page1_weektemp6, 100, 32);

    //Write style for tianqi_page1_weektemp6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page1_weektemp6, lv_color_hex(0xeae2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page1_weektemp6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page1_weektemp6, 229, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page1_weektemp6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_weektemp6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_weektemp4
    ui->tianqi_page1_weektemp4 = lv_label_create(ui->tianqi_page1);
    lv_label_set_text(ui->tianqi_page1_weektemp4, "16~28'C");
    lv_label_set_long_mode(ui->tianqi_page1_weektemp4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page1_weektemp4, 87, 248);
    lv_obj_set_size(ui->tianqi_page1_weektemp4, 100, 32);

    //Write style for tianqi_page1_weektemp4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page1_weektemp4, lv_color_hex(0xeae2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page1_weektemp4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page1_weektemp4, 229, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page1_weektemp4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_weektemp4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_weektemp5
    ui->tianqi_page1_weektemp5 = lv_label_create(ui->tianqi_page1);
    lv_label_set_text(ui->tianqi_page1_weektemp5, "16~28'C");
    lv_label_set_long_mode(ui->tianqi_page1_weektemp5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page1_weektemp5, 87, 307);
    lv_obj_set_size(ui->tianqi_page1_weektemp5, 100, 32);

    //Write style for tianqi_page1_weektemp5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page1_weektemp5, lv_color_hex(0xeae2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page1_weektemp5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page1_weektemp5, 229, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page1_weektemp5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_weektemp5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tianqi_page1_week_weather
    ui->tianqi_page1_week_weather = lv_label_create(ui->tianqi_page1);
    lv_label_set_text(ui->tianqi_page1_week_weather, "Weather for the week ahead");
    lv_label_set_long_mode(ui->tianqi_page1_week_weather, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tianqi_page1_week_weather, 46, 14);
    lv_obj_set_size(ui->tianqi_page1_week_weather, 159, 47);

    //Write style for tianqi_page1_week_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tianqi_page1_week_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tianqi_page1_week_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tianqi_page1_week_weather, lv_color_hex(0xf2eeee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tianqi_page1_week_weather, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tianqi_page1_week_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tianqi_page1_week_weather, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tianqi_page1_week_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tianqi_page1_week_weather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tianqi_page1_week_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tianqi_page1_week_weather, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tianqi_page1_week_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tianqi_page1_week_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tianqi_page1_week_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tianqi_page1_week_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of tianqi_page1.


    //Update current screen layout.
    lv_obj_update_layout(ui->tianqi_page1);

    //Init events for screen.
    events_init_tianqi_page1(ui);
}
