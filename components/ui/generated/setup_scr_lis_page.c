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



void setup_scr_lis_page(lv_ui *ui)
{
    //Write codes lis_page
    ui->lis_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->lis_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->lis_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for lis_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->lis_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->lis_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->lis_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->lis_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes lis_page_list_headset
    ui->lis_page_list_headset = lv_list_create(ui->lis_page);
    ui->lis_page_list_headset_item0 = lv_list_add_btn(ui->lis_page_list_headset, LV_SYMBOL_BLUETOOTH, "airpods3");
    lv_obj_set_pos(ui->lis_page_list_headset, 30, 60);
    lv_obj_set_size(ui->lis_page_list_headset, 180, 180);
    lv_obj_set_scrollbar_mode(ui->lis_page_list_headset, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_lis_page_list_headset_main_main_default
    static lv_style_t style_lis_page_list_headset_main_main_default;
    ui_init_style(&style_lis_page_list_headset_main_main_default);

    lv_style_set_pad_top(&style_lis_page_list_headset_main_main_default, 5);
    lv_style_set_pad_left(&style_lis_page_list_headset_main_main_default, 5);
    lv_style_set_pad_right(&style_lis_page_list_headset_main_main_default, 5);
    lv_style_set_pad_bottom(&style_lis_page_list_headset_main_main_default, 5);
    lv_style_set_bg_opa(&style_lis_page_list_headset_main_main_default, 173);
    lv_style_set_bg_color(&style_lis_page_list_headset_main_main_default, lv_color_hex(0x1d1d1d));
    lv_style_set_bg_grad_dir(&style_lis_page_list_headset_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_lis_page_list_headset_main_main_default, 1);
    lv_style_set_border_opa(&style_lis_page_list_headset_main_main_default, 0);
    lv_style_set_border_color(&style_lis_page_list_headset_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_lis_page_list_headset_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_lis_page_list_headset_main_main_default, 15);
    lv_style_set_shadow_width(&style_lis_page_list_headset_main_main_default, 3);
    lv_style_set_shadow_color(&style_lis_page_list_headset_main_main_default, lv_color_hex(0xededed));
    lv_style_set_shadow_opa(&style_lis_page_list_headset_main_main_default, 255);
    lv_style_set_shadow_spread(&style_lis_page_list_headset_main_main_default, 0);
    lv_style_set_shadow_ofs_x(&style_lis_page_list_headset_main_main_default, 1);
    lv_style_set_shadow_ofs_y(&style_lis_page_list_headset_main_main_default, 1);
    lv_obj_add_style(ui->lis_page_list_headset, &style_lis_page_list_headset_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_lis_page_list_headset_main_scrollbar_default
    static lv_style_t style_lis_page_list_headset_main_scrollbar_default;
    ui_init_style(&style_lis_page_list_headset_main_scrollbar_default);

    lv_style_set_radius(&style_lis_page_list_headset_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_lis_page_list_headset_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_lis_page_list_headset_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_lis_page_list_headset_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->lis_page_list_headset, &style_lis_page_list_headset_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_lis_page_list_headset_extra_btns_main_default
    static lv_style_t style_lis_page_list_headset_extra_btns_main_default;
    ui_init_style(&style_lis_page_list_headset_extra_btns_main_default);

    lv_style_set_pad_top(&style_lis_page_list_headset_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_lis_page_list_headset_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_lis_page_list_headset_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_lis_page_list_headset_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_lis_page_list_headset_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_lis_page_list_headset_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_lis_page_list_headset_extra_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_lis_page_list_headset_extra_btns_main_default, 255);
    lv_style_set_radius(&style_lis_page_list_headset_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_lis_page_list_headset_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_lis_page_list_headset_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_lis_page_list_headset_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->lis_page_list_headset_item0, &style_lis_page_list_headset_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_lis_page_list_headset_extra_texts_main_default
    static lv_style_t style_lis_page_list_headset_extra_texts_main_default;
    ui_init_style(&style_lis_page_list_headset_extra_texts_main_default);

    lv_style_set_pad_top(&style_lis_page_list_headset_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_lis_page_list_headset_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_lis_page_list_headset_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_lis_page_list_headset_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_lis_page_list_headset_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_lis_page_list_headset_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_lis_page_list_headset_extra_texts_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_lis_page_list_headset_extra_texts_main_default, 255);
    lv_style_set_radius(&style_lis_page_list_headset_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_lis_page_list_headset_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_lis_page_list_headset_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_lis_page_list_headset_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_lis_page_list_headset_extra_texts_main_default, LV_GRAD_DIR_NONE);

    //Write codes lis_page_label_head
    ui->lis_page_label_head = lv_label_create(ui->lis_page);
    lv_label_set_text(ui->lis_page_label_head, "headset");
    lv_label_set_long_mode(ui->lis_page_label_head, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->lis_page_label_head, 18, 13);
    lv_obj_set_size(ui->lis_page_label_head, 98, 34);

    //Write style for lis_page_label_head, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->lis_page_label_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->lis_page_label_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->lis_page_label_head, lv_color_hex(0xfdfcfc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->lis_page_label_head, &lv_font_Acme_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->lis_page_label_head, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->lis_page_label_head, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->lis_page_label_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->lis_page_label_head, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->lis_page_label_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->lis_page_label_head, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->lis_page_label_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->lis_page_label_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->lis_page_label_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->lis_page_label_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of lis_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->lis_page);

    //Init events for screen.
    events_init_lis_page(ui);
}
