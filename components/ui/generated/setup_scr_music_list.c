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
#include "sdcard.h"
#include "string.h"


void setup_scr_music_list(lv_ui *ui)
{
    //Write codes music_list
    ui->music_list = lv_obj_create(NULL);
    lv_obj_set_size(ui->music_list, 240, 280);
    lv_obj_set_scrollbar_mode(ui->music_list, LV_SCROLLBAR_MODE_OFF);

    //Write style for music_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->music_list, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->music_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->music_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_list_list_music
    ui->music_list_list_music = lv_list_create(ui->music_list);
    int i = 0;
    char name[10][50] = {0};
    i = sdcard_filelist(name);
    for(int j = 0; j < i; j++)
    {
        if (strstr(name[j], ".mp3") || strstr(name[j], ".MP3")) {
            ui->music_list_list_music_item0 = lv_list_add_btn(ui->music_list_list_music, LV_SYMBOL_AUDIO, name[j]);
            lv_obj_set_style_pad_top(ui->music_list_list_music_item0, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(ui->music_list_list_music_item0, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(ui->music_list_list_music_item0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(ui->music_list_list_music_item0, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(ui->music_list_list_music_item0, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(ui->music_list_list_music_item0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(ui->music_list_list_music_item0, lv_color_hex(0x6f6969), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(ui->music_list_list_music_item0, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui->music_list_list_music_item0, lv_color_hex(0xfef6ea), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(ui->music_list_list_music_item0, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(ui->music_list_list_music_item0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_radius(ui->music_list_list_music_item0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui->music_list_list_music_item0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
        }
    }
    ui->music_list_list_music_item0 = lv_list_add_btn(ui->music_list_list_music, LV_SYMBOL_AUDIO, "music.mp3");
    lv_obj_set_pos(ui->music_list_list_music, 20, 38);
    lv_obj_set_size(ui->music_list_list_music, 200, 267);
    lv_obj_set_scrollbar_mode(ui->music_list_list_music, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_music_list_list_music_main_main_default
    static lv_style_t style_music_list_list_music_main_main_default;
    ui_init_style(&style_music_list_list_music_main_main_default);

    lv_style_set_pad_top(&style_music_list_list_music_main_main_default, 5);
    lv_style_set_pad_left(&style_music_list_list_music_main_main_default, 0);
    lv_style_set_pad_right(&style_music_list_list_music_main_main_default, 0);
    lv_style_set_pad_bottom(&style_music_list_list_music_main_main_default, 0);
    lv_style_set_bg_opa(&style_music_list_list_music_main_main_default, 89);
    lv_style_set_bg_color(&style_music_list_list_music_main_main_default, lv_color_hex(0x282294));
    lv_style_set_bg_grad_dir(&style_music_list_list_music_main_main_default, LV_GRAD_DIR_VER);
    lv_style_set_bg_grad_color(&style_music_list_list_music_main_main_default, lv_color_hex(0x0f0f0f));
    lv_style_set_bg_main_stop(&style_music_list_list_music_main_main_default, 0);
    lv_style_set_bg_grad_stop(&style_music_list_list_music_main_main_default, 255);
    lv_style_set_border_width(&style_music_list_list_music_main_main_default, 2);
    lv_style_set_border_opa(&style_music_list_list_music_main_main_default, 0);
    lv_style_set_border_color(&style_music_list_list_music_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_music_list_list_music_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_music_list_list_music_main_main_default, 15);
    lv_style_set_shadow_width(&style_music_list_list_music_main_main_default, 0);
    lv_obj_add_style(ui->music_list_list_music, &style_music_list_list_music_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_music_list_list_music_main_scrollbar_default
    static lv_style_t style_music_list_list_music_main_scrollbar_default;
    ui_init_style(&style_music_list_list_music_main_scrollbar_default);

    lv_style_set_radius(&style_music_list_list_music_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_music_list_list_music_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_music_list_list_music_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_music_list_list_music_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->music_list_list_music, &style_music_list_list_music_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_music_list_list_music_extra_btns_main_default
    static lv_style_t style_music_list_list_music_extra_btns_main_default;
    ui_init_style(&style_music_list_list_music_extra_btns_main_default);

    lv_style_set_pad_top(&style_music_list_list_music_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_music_list_list_music_extra_btns_main_default, 10);
    lv_style_set_pad_right(&style_music_list_list_music_extra_btns_main_default, 0);
    lv_style_set_pad_bottom(&style_music_list_list_music_extra_btns_main_default, 10);
    lv_style_set_border_width(&style_music_list_list_music_extra_btns_main_default, 1);
    lv_style_set_border_opa(&style_music_list_list_music_extra_btns_main_default, 255);
    lv_style_set_border_color(&style_music_list_list_music_extra_btns_main_default, lv_color_hex(0x6f6969));
    lv_style_set_border_side(&style_music_list_list_music_extra_btns_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_music_list_list_music_extra_btns_main_default, lv_color_hex(0xfef6ea));
    lv_style_set_text_font(&style_music_list_list_music_extra_btns_main_default, &lv_font_montserratMedium_18);
    lv_style_set_text_opa(&style_music_list_list_music_extra_btns_main_default, 255);
    lv_style_set_radius(&style_music_list_list_music_extra_btns_main_default, 0);
    lv_style_set_bg_opa(&style_music_list_list_music_extra_btns_main_default, 0);
    lv_obj_add_style(ui->music_list_list_music_item0, &style_music_list_list_music_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_music_list_list_music_extra_texts_main_default
    static lv_style_t style_music_list_list_music_extra_texts_main_default;
    ui_init_style(&style_music_list_list_music_extra_texts_main_default);

    lv_style_set_pad_top(&style_music_list_list_music_extra_texts_main_default, 6);
    lv_style_set_pad_left(&style_music_list_list_music_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_music_list_list_music_extra_texts_main_default, 0);
    lv_style_set_pad_bottom(&style_music_list_list_music_extra_texts_main_default, 0);
    lv_style_set_border_width(&style_music_list_list_music_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_music_list_list_music_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_music_list_list_music_extra_texts_main_default, &lv_font_montserratMedium_18);
    lv_style_set_text_opa(&style_music_list_list_music_extra_texts_main_default, 255);
    lv_style_set_radius(&style_music_list_list_music_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_music_list_list_music_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_music_list_list_music_extra_texts_main_default, 0);

    //Write codes music_list_label_music
    ui->music_list_label_music = lv_label_create(ui->music_list);
    lv_label_set_text(ui->music_list_label_music, "music");
    lv_label_set_long_mode(ui->music_list_label_music, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->music_list_label_music, 49, 6);
    lv_obj_set_size(ui->music_list_label_music, 150, 23);

    //Write style for music_list_label_music, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->music_list_label_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_list_label_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_list_label_music, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_list_label_music, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_list_label_music, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->music_list_label_music, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->music_list_label_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_list_label_music, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_list_label_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_list_label_music, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_list_label_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_list_label_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_list_label_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_list_label_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of music_list.


    //Update current screen layout.
    lv_obj_update_layout(ui->music_list);

    //Init events for screen.
    events_init_music_list(ui);
}
