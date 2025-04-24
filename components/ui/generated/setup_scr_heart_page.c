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



void setup_scr_heart_page(lv_ui *ui)
{
    //Write codes heart_page
    ui->heart_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->heart_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->heart_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for heart_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->heart_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->heart_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->heart_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->heart_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes heart_page_label_freq
    ui->heart_page_label_freq = lv_label_create(ui->heart_page);
    lv_label_set_text(ui->heart_page_label_freq, "Frequency:");
    lv_label_set_long_mode(ui->heart_page_label_freq, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->heart_page_label_freq, 10, 20);
    lv_obj_set_size(ui->heart_page_label_freq, 100, 20);

    //Write style for heart_page_label_freq, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->heart_page_label_freq, lv_color_hex(0xf6f0f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->heart_page_label_freq, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->heart_page_label_freq, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->heart_page_label_freq, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->heart_page_label_freq, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes heart_page_chart_heart
    ui->heart_page_chart_heart = lv_chart_create(ui->heart_page);
    lv_chart_set_type(ui->heart_page_chart_heart, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->heart_page_chart_heart, 3, 5);
    lv_chart_set_point_count(ui->heart_page_chart_heart, 5);
    lv_chart_set_range(ui->heart_page_chart_heart, LV_CHART_AXIS_PRIMARY_Y, 0, 200);
    lv_chart_set_range(ui->heart_page_chart_heart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_zoom_x(ui->heart_page_chart_heart, 256);
    lv_chart_set_zoom_y(ui->heart_page_chart_heart, 256);
    ui->heart_page_chart_heart_0 = lv_chart_add_series(ui->heart_page_chart_heart, lv_color_hex(0xe30000), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->heart_page_chart_heart, ui->heart_page_chart_heart_0, 90);
    lv_chart_set_next_value(ui->heart_page_chart_heart, ui->heart_page_chart_heart_0, 110);
    lv_chart_set_next_value(ui->heart_page_chart_heart, ui->heart_page_chart_heart_0, 80);
    lv_chart_set_next_value(ui->heart_page_chart_heart, ui->heart_page_chart_heart_0, 110);
    lv_chart_set_next_value(ui->heart_page_chart_heart, ui->heart_page_chart_heart_0, 90);
#endif
    lv_obj_set_pos(ui->heart_page_chart_heart, 15, 70);
    lv_obj_set_size(ui->heart_page_chart_heart, 210, 155);
    lv_obj_set_scrollbar_mode(ui->heart_page_chart_heart, LV_SCROLLBAR_MODE_OFF);

    //Write style for heart_page_chart_heart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->heart_page_chart_heart, 199, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->heart_page_chart_heart, lv_color_hex(0x1c1c1c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->heart_page_chart_heart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->heart_page_chart_heart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->heart_page_chart_heart, 116, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->heart_page_chart_heart, lv_color_hex(0xf1f1f1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->heart_page_chart_heart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->heart_page_chart_heart, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->heart_page_chart_heart, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->heart_page_chart_heart, lv_color_hex(0x6e6e6e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->heart_page_chart_heart, 213, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->heart_page_chart_heart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for heart_page_chart_heart, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->heart_page_chart_heart, lv_color_hex(0x151212), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->heart_page_chart_heart, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->heart_page_chart_heart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->heart_page_chart_heart, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->heart_page_chart_heart, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->heart_page_chart_heart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write codes heart_page_label_freq_num
    ui->heart_page_label_freq_num = lv_label_create(ui->heart_page);
    lv_label_set_text(ui->heart_page_label_freq_num, "90");
    lv_label_set_long_mode(ui->heart_page_label_freq_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->heart_page_label_freq_num, 115, 16);
    lv_obj_set_size(ui->heart_page_label_freq_num, 73, 32);

    //Write style for heart_page_label_freq_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->heart_page_label_freq_num, lv_color_hex(0xefefef), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->heart_page_label_freq_num, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->heart_page_label_freq_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->heart_page_label_freq_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->heart_page_label_freq_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes heart_page_img_xin
    ui->heart_page_img_xin = lv_img_create(ui->heart_page);
    lv_obj_add_flag(ui->heart_page_img_xin, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->heart_page_img_xin, &_heart_alpha_28x26);
    lv_img_set_pivot(ui->heart_page_img_xin, 50,50);
    lv_img_set_angle(ui->heart_page_img_xin, 0);
    lv_obj_set_pos(ui->heart_page_img_xin, 192, 21);
    lv_obj_set_size(ui->heart_page_img_xin, 28, 26);

    //Write style for heart_page_img_xin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->heart_page_img_xin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->heart_page_img_xin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->heart_page_img_xin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->heart_page_img_xin, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes heart_page_label_last_time
    ui->heart_page_label_last_time = lv_label_create(ui->heart_page);
    lv_label_set_text(ui->heart_page_label_last_time, "last time: ");
    lv_label_set_long_mode(ui->heart_page_label_last_time, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->heart_page_label_last_time, 31, 245);
    lv_obj_set_size(ui->heart_page_label_last_time, 90, 20);

    //Write style for heart_page_label_last_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->heart_page_label_last_time, lv_color_hex(0xf6f0f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->heart_page_label_last_time, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->heart_page_label_last_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->heart_page_label_last_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->heart_page_label_last_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes heart_page_label_mins
    ui->heart_page_label_mins = lv_label_create(ui->heart_page);
    lv_label_set_text(ui->heart_page_label_mins, "10 mins");
    lv_label_set_long_mode(ui->heart_page_label_mins, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->heart_page_label_mins, 121, 245);
    lv_obj_set_size(ui->heart_page_label_mins, 90, 20);

    //Write style for heart_page_label_mins, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->heart_page_label_mins, lv_color_hex(0xf6f0f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->heart_page_label_mins, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->heart_page_label_mins, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->heart_page_label_mins, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->heart_page_label_mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of heart_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->heart_page);

    //Init events for screen.
    events_init_heart_page(ui);
}
