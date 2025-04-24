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



void setup_scr_vol_page(lv_ui *ui)
{
    //Write codes vol_page
    ui->vol_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->vol_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->vol_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for vol_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->vol_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->vol_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->vol_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->vol_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes vol_page_label_volume
    ui->vol_page_label_volume = lv_label_create(ui->vol_page);
    lv_label_set_text(ui->vol_page_label_volume, "Volume");
    lv_label_set_long_mode(ui->vol_page_label_volume, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->vol_page_label_volume, 15, 18);
    lv_obj_set_size(ui->vol_page_label_volume, 99, 26);

    //Write style for vol_page_label_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->vol_page_label_volume, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->vol_page_label_volume, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->vol_page_label_volume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->vol_page_label_volume, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->vol_page_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes vol_page_list_device
    ui->vol_page_list_device = lv_list_create(ui->vol_page);
    ui->vol_page_list_device_item0 = lv_list_add_btn(ui->vol_page_list_device, LV_SYMBOL_CALL, "phone");
    lv_obj_set_pos(ui->vol_page_list_device, 30, 80);
    lv_obj_set_size(ui->vol_page_list_device, 180, 120);
    lv_obj_set_scrollbar_mode(ui->vol_page_list_device, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_vol_page_list_device_main_main_default
    static lv_style_t style_vol_page_list_device_main_main_default;
    ui_init_style(&style_vol_page_list_device_main_main_default);

    lv_style_set_pad_top(&style_vol_page_list_device_main_main_default, 5);
    lv_style_set_pad_left(&style_vol_page_list_device_main_main_default, 5);
    lv_style_set_pad_right(&style_vol_page_list_device_main_main_default, 5);
    lv_style_set_pad_bottom(&style_vol_page_list_device_main_main_default, 5);
    lv_style_set_bg_opa(&style_vol_page_list_device_main_main_default, 157);
    lv_style_set_bg_color(&style_vol_page_list_device_main_main_default, lv_color_hex(0x474747));
    lv_style_set_bg_grad_dir(&style_vol_page_list_device_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_vol_page_list_device_main_main_default, 1);
    lv_style_set_border_opa(&style_vol_page_list_device_main_main_default, 255);
    lv_style_set_border_color(&style_vol_page_list_device_main_main_default, lv_color_hex(0xf2f2f2));
    lv_style_set_border_side(&style_vol_page_list_device_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_vol_page_list_device_main_main_default, 15);
    lv_style_set_shadow_width(&style_vol_page_list_device_main_main_default, 0);
    lv_obj_add_style(ui->vol_page_list_device, &style_vol_page_list_device_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_vol_page_list_device_main_scrollbar_default
    static lv_style_t style_vol_page_list_device_main_scrollbar_default;
    ui_init_style(&style_vol_page_list_device_main_scrollbar_default);

    lv_style_set_radius(&style_vol_page_list_device_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_vol_page_list_device_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_vol_page_list_device_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_vol_page_list_device_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->vol_page_list_device, &style_vol_page_list_device_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_vol_page_list_device_extra_btns_main_default
    static lv_style_t style_vol_page_list_device_extra_btns_main_default;
    ui_init_style(&style_vol_page_list_device_extra_btns_main_default);

    lv_style_set_pad_top(&style_vol_page_list_device_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_vol_page_list_device_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_vol_page_list_device_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_vol_page_list_device_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_vol_page_list_device_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_vol_page_list_device_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_vol_page_list_device_extra_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_vol_page_list_device_extra_btns_main_default, 255);
    lv_style_set_radius(&style_vol_page_list_device_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_vol_page_list_device_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_vol_page_list_device_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_vol_page_list_device_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->vol_page_list_device_item0, &style_vol_page_list_device_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_vol_page_list_device_extra_texts_main_default
    static lv_style_t style_vol_page_list_device_extra_texts_main_default;
    ui_init_style(&style_vol_page_list_device_extra_texts_main_default);

    lv_style_set_pad_top(&style_vol_page_list_device_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_vol_page_list_device_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_vol_page_list_device_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_vol_page_list_device_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_vol_page_list_device_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_vol_page_list_device_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_vol_page_list_device_extra_texts_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_vol_page_list_device_extra_texts_main_default, 255);
    lv_style_set_radius(&style_vol_page_list_device_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_vol_page_list_device_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_vol_page_list_device_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_vol_page_list_device_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_vol_page_list_device_extra_texts_main_default, LV_GRAD_DIR_NONE);

    //Write codes vol_page_label_2
    ui->vol_page_label_2 = lv_label_create(ui->vol_page);
    lv_label_set_text(ui->vol_page_label_2, "your connect device:");
    lv_label_set_long_mode(ui->vol_page_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->vol_page_label_2, 15, 54);
    lv_obj_set_size(ui->vol_page_label_2, 150, 16);

    //Write style for vol_page_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->vol_page_label_2, lv_color_hex(0xfdfdfd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->vol_page_label_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->vol_page_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->vol_page_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->vol_page_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes vol_page_slider_volu
    ui->vol_page_slider_volu = lv_slider_create(ui->vol_page);
    lv_slider_set_range(ui->vol_page_slider_volu, 0, 100);
    lv_slider_set_mode(ui->vol_page_slider_volu, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->vol_page_slider_volu, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->vol_page_slider_volu, 55, 226);
    lv_obj_set_size(ui->vol_page_slider_volu, 160, 8);

    //Write style for vol_page_slider_volu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->vol_page_slider_volu, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->vol_page_slider_volu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->vol_page_slider_volu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->vol_page_slider_volu, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->vol_page_slider_volu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->vol_page_slider_volu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for vol_page_slider_volu, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->vol_page_slider_volu, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->vol_page_slider_volu, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->vol_page_slider_volu, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->vol_page_slider_volu, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for vol_page_slider_volu, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->vol_page_slider_volu, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->vol_page_slider_volu, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->vol_page_slider_volu, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->vol_page_slider_volu, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes vol_page_img_volu
    ui->vol_page_img_volu = lv_img_create(ui->vol_page);
    lv_obj_add_flag(ui->vol_page_img_volu, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->vol_page_img_volu, &_voll_alpha_21x23);
    lv_img_set_pivot(ui->vol_page_img_volu, 50,50);
    lv_img_set_angle(ui->vol_page_img_volu, 0);
    lv_obj_set_pos(ui->vol_page_img_volu, 27, 218);
    lv_obj_set_size(ui->vol_page_img_volu, 21, 23);

    //Write style for vol_page_img_volu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->vol_page_img_volu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->vol_page_img_volu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->vol_page_img_volu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->vol_page_img_volu, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of vol_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->vol_page);

    //Init events for screen.
    events_init_vol_page(ui);
}
