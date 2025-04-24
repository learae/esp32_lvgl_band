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



void setup_scr_txt_page(lv_ui *ui)
{
    //Write codes txt_page
    ui->txt_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->txt_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->txt_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for txt_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->txt_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->txt_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->txt_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->txt_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes txt_page_label_txt
    ui->txt_page_label_txt = lv_label_create(ui->txt_page);
    lv_label_set_text(ui->txt_page_label_txt, "txt");
    lv_label_set_long_mode(ui->txt_page_label_txt, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->txt_page_label_txt, 49, 6);
    lv_obj_set_size(ui->txt_page_label_txt, 150, 23);

    //Write style for txt_page_label_txt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->txt_page_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->txt_page_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->txt_page_label_txt, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->txt_page_label_txt, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->txt_page_label_txt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->txt_page_label_txt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->txt_page_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->txt_page_label_txt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->txt_page_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->txt_page_label_txt, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->txt_page_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->txt_page_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->txt_page_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->txt_page_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes txt_page_list_txt
    ui->txt_page_list_txt = lv_list_create(ui->txt_page);
    ui->txt_page_list_txt_item0 = lv_list_add_btn(ui->txt_page_list_txt, LV_SYMBOL_SAVE, "name.txt");
    lv_obj_set_pos(ui->txt_page_list_txt, 20, 38);
    lv_obj_set_size(ui->txt_page_list_txt, 200, 267);
    lv_obj_set_scrollbar_mode(ui->txt_page_list_txt, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_txt_page_list_txt_main_main_default
    static lv_style_t style_txt_page_list_txt_main_main_default;
    ui_init_style(&style_txt_page_list_txt_main_main_default);

    lv_style_set_pad_top(&style_txt_page_list_txt_main_main_default, 5);
    lv_style_set_pad_left(&style_txt_page_list_txt_main_main_default, 0);
    lv_style_set_pad_right(&style_txt_page_list_txt_main_main_default, 0);
    lv_style_set_pad_bottom(&style_txt_page_list_txt_main_main_default, 0);
    lv_style_set_bg_opa(&style_txt_page_list_txt_main_main_default, 89);
    lv_style_set_bg_color(&style_txt_page_list_txt_main_main_default, lv_color_hex(0x282294));
    lv_style_set_bg_grad_dir(&style_txt_page_list_txt_main_main_default, LV_GRAD_DIR_VER);
    lv_style_set_bg_grad_color(&style_txt_page_list_txt_main_main_default, lv_color_hex(0x0b0b0b));
    lv_style_set_bg_main_stop(&style_txt_page_list_txt_main_main_default, 0);
    lv_style_set_bg_grad_stop(&style_txt_page_list_txt_main_main_default, 255);
    lv_style_set_border_width(&style_txt_page_list_txt_main_main_default, 2);
    lv_style_set_border_opa(&style_txt_page_list_txt_main_main_default, 0);
    lv_style_set_border_color(&style_txt_page_list_txt_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_txt_page_list_txt_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_txt_page_list_txt_main_main_default, 15);
    lv_style_set_shadow_width(&style_txt_page_list_txt_main_main_default, 0);
    lv_obj_add_style(ui->txt_page_list_txt, &style_txt_page_list_txt_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_txt_page_list_txt_main_scrollbar_default
    static lv_style_t style_txt_page_list_txt_main_scrollbar_default;
    ui_init_style(&style_txt_page_list_txt_main_scrollbar_default);

    lv_style_set_radius(&style_txt_page_list_txt_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_txt_page_list_txt_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_txt_page_list_txt_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_txt_page_list_txt_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->txt_page_list_txt, &style_txt_page_list_txt_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_txt_page_list_txt_extra_btns_main_default
    static lv_style_t style_txt_page_list_txt_extra_btns_main_default;
    ui_init_style(&style_txt_page_list_txt_extra_btns_main_default);

    lv_style_set_pad_top(&style_txt_page_list_txt_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_txt_page_list_txt_extra_btns_main_default, 10);
    lv_style_set_pad_right(&style_txt_page_list_txt_extra_btns_main_default, 0);
    lv_style_set_pad_bottom(&style_txt_page_list_txt_extra_btns_main_default, 10);
    lv_style_set_border_width(&style_txt_page_list_txt_extra_btns_main_default, 1);
    lv_style_set_border_opa(&style_txt_page_list_txt_extra_btns_main_default, 255);
    lv_style_set_border_color(&style_txt_page_list_txt_extra_btns_main_default, lv_color_hex(0x6f6969));
    lv_style_set_border_side(&style_txt_page_list_txt_extra_btns_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_txt_page_list_txt_extra_btns_main_default, lv_color_hex(0xfef6ea));
    lv_style_set_text_font(&style_txt_page_list_txt_extra_btns_main_default, &lv_font_montserratMedium_18);
    lv_style_set_text_opa(&style_txt_page_list_txt_extra_btns_main_default, 255);
    lv_style_set_radius(&style_txt_page_list_txt_extra_btns_main_default, 0);
    lv_style_set_bg_opa(&style_txt_page_list_txt_extra_btns_main_default, 0);
    lv_obj_add_style(ui->txt_page_list_txt_item0, &style_txt_page_list_txt_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_txt_page_list_txt_extra_texts_main_default
    static lv_style_t style_txt_page_list_txt_extra_texts_main_default;
    ui_init_style(&style_txt_page_list_txt_extra_texts_main_default);

    lv_style_set_pad_top(&style_txt_page_list_txt_extra_texts_main_default, 6);
    lv_style_set_pad_left(&style_txt_page_list_txt_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_txt_page_list_txt_extra_texts_main_default, 0);
    lv_style_set_pad_bottom(&style_txt_page_list_txt_extra_texts_main_default, 0);
    lv_style_set_border_width(&style_txt_page_list_txt_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_txt_page_list_txt_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_txt_page_list_txt_extra_texts_main_default, &lv_font_montserratMedium_18);
    lv_style_set_text_opa(&style_txt_page_list_txt_extra_texts_main_default, 255);
    lv_style_set_radius(&style_txt_page_list_txt_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_txt_page_list_txt_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_txt_page_list_txt_extra_texts_main_default, 0);

    //The custom code of txt_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->txt_page);

    //Init events for screen.
    events_init_txt_page(ui);
}
