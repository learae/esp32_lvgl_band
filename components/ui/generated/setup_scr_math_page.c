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



void setup_scr_math_page(lv_ui *ui)
{
    //Write codes math_page
    ui->math_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->math_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->math_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for math_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->math_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->math_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->math_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->math_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes math_page_btnm_1
    ui->math_page_btnm_1 = lv_btnmatrix_create(ui->math_page);
    static const char *math_page_btnm_1_text_map[] = {"1", "2", "3", "=", "\n", "4", "5", "6", "+", "\n", "7", "8", "9", "-", "\n", "del", "0", "/", "*", "",};
    lv_btnmatrix_set_map(ui->math_page_btnm_1, math_page_btnm_1_text_map);
    lv_obj_set_pos(ui->math_page_btnm_1, 15, 79);
    lv_obj_set_size(ui->math_page_btnm_1, 210, 180);

    //Write style for math_page_btnm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->math_page_btnm_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->math_page_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->math_page_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->math_page_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->math_page_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui->math_page_btnm_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui->math_page_btnm_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->math_page_btnm_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->math_page_btnm_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->math_page_btnm_1, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->math_page_btnm_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for math_page_btnm_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->math_page_btnm_1, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->math_page_btnm_1, lv_color_hex(0x0c2b49), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->math_page_btnm_1, &lv_font_Abel_regular_20, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->math_page_btnm_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->math_page_btnm_1, 4, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->math_page_btnm_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->math_page_btnm_1, lv_color_hex(0x93e3ff), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->math_page_btnm_1, LV_GRAD_DIR_NONE, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->math_page_btnm_1, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style for math_page_btnm_1, Part: LV_PART_ITEMS, State: LV_STATE_PRESSED.
    lv_obj_set_style_border_width(ui->math_page_btnm_1, 0, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->math_page_btnm_1, lv_color_hex(0xffffff), LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->math_page_btnm_1, &lv_font_Abel_regular_20, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->math_page_btnm_1, 255, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->math_page_btnm_1, 4, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui->math_page_btnm_1, 255, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->math_page_btnm_1, lv_color_hex(0x93e3ff), LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->math_page_btnm_1, LV_GRAD_DIR_NONE, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->math_page_btnm_1, 2, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui->math_page_btnm_1, lv_color_hex(0x93e3ff), LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui->math_page_btnm_1, 255, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui->math_page_btnm_1, 2, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_x(ui->math_page_btnm_1, 0, LV_PART_ITEMS|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_y(ui->math_page_btnm_1, 1, LV_PART_ITEMS|LV_STATE_PRESSED);

    //Write codes math_page_label_result
    ui->math_page_label_result = lv_label_create(ui->math_page);
    lv_label_set_text(ui->math_page_label_result, "0");
    lv_label_set_long_mode(ui->math_page_label_result, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->math_page_label_result, 20, 22);
    lv_obj_set_size(ui->math_page_label_result, 194, 47);

    //Write style for math_page_label_result, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->math_page_label_result, lv_color_hex(0xf2f2f2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->math_page_label_result, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->math_page_label_result, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->math_page_label_result, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->math_page_label_result, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of math_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->math_page);

    //Init events for screen.
    events_init_math_page(ui);
}
