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



void setup_scr_txt_veiw(lv_ui *ui)
{
    //Write codes txt_veiw
    ui->txt_veiw = lv_obj_create(NULL);
    lv_obj_set_size(ui->txt_veiw, 240, 280);
    lv_obj_set_scrollbar_mode(ui->txt_veiw, LV_SCROLLBAR_MODE_OFF);

    //Write style for txt_veiw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->txt_veiw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->txt_veiw, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->txt_veiw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->txt_veiw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes txt_veiw_btn_txt_back
    ui->txt_veiw_btn_txt_back = lv_btn_create(ui->txt_veiw);
    ui->txt_veiw_btn_txt_back_label = lv_label_create(ui->txt_veiw_btn_txt_back);
    lv_label_set_text(ui->txt_veiw_btn_txt_back_label, "<-bank");
    lv_label_set_long_mode(ui->txt_veiw_btn_txt_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->txt_veiw_btn_txt_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->txt_veiw_btn_txt_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->txt_veiw_btn_txt_back_label, LV_PCT(100));
    lv_obj_set_pos(ui->txt_veiw_btn_txt_back, 10, 10);
    lv_obj_set_size(ui->txt_veiw_btn_txt_back, 68, 24);

    //Write style for txt_veiw_btn_txt_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->txt_veiw_btn_txt_back, 42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->txt_veiw_btn_txt_back, lv_color_hex(0x2a2a2a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->txt_veiw_btn_txt_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->txt_veiw_btn_txt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->txt_veiw_btn_txt_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->txt_veiw_btn_txt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->txt_veiw_btn_txt_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->txt_veiw_btn_txt_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->txt_veiw_btn_txt_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->txt_veiw_btn_txt_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes txt_veiw_cont_txt
    ui->txt_veiw_cont_txt = lv_obj_create(ui->txt_veiw);
    lv_obj_set_pos(ui->txt_veiw_cont_txt, 20, 40);
    lv_obj_set_size(ui->txt_veiw_cont_txt, 200, 200);
    lv_obj_set_scrollbar_mode(ui->txt_veiw_cont_txt, LV_SCROLLBAR_MODE_OFF);

    //Write style for txt_veiw_cont_txt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->txt_veiw_cont_txt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->txt_veiw_cont_txt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->txt_veiw_cont_txt, lv_color_hex(0xc6c7c7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->txt_veiw_cont_txt, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->txt_veiw_cont_txt, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->txt_veiw_cont_txt, 223, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->txt_veiw_cont_txt, lv_color_hex(0x191919), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->txt_veiw_cont_txt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->txt_veiw_cont_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->txt_veiw_cont_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->txt_veiw_cont_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->txt_veiw_cont_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->txt_veiw_cont_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes txt_veiw_btn_last
    ui->txt_veiw_btn_last = lv_btn_create(ui->txt_veiw);
    ui->txt_veiw_btn_last_label = lv_label_create(ui->txt_veiw_btn_last);
    lv_label_set_text(ui->txt_veiw_btn_last_label, "<-last");
    lv_label_set_long_mode(ui->txt_veiw_btn_last_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->txt_veiw_btn_last_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->txt_veiw_btn_last, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->txt_veiw_btn_last_label, LV_PCT(100));
    lv_obj_set_pos(ui->txt_veiw_btn_last, 10, 247);
    lv_obj_set_size(ui->txt_veiw_btn_last, 61, 21);

    //Write style for txt_veiw_btn_last, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->txt_veiw_btn_last, 42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->txt_veiw_btn_last, lv_color_hex(0x2a2a2a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->txt_veiw_btn_last, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->txt_veiw_btn_last, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->txt_veiw_btn_last, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->txt_veiw_btn_last, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->txt_veiw_btn_last, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->txt_veiw_btn_last, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->txt_veiw_btn_last, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->txt_veiw_btn_last, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes txt_veiw_btn_next
    ui->txt_veiw_btn_next = lv_btn_create(ui->txt_veiw);
    ui->txt_veiw_btn_next_label = lv_label_create(ui->txt_veiw_btn_next);
    lv_label_set_text(ui->txt_veiw_btn_next_label, "next->");
    lv_label_set_long_mode(ui->txt_veiw_btn_next_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->txt_veiw_btn_next_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->txt_veiw_btn_next, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->txt_veiw_btn_next_label, LV_PCT(100));
    lv_obj_set_pos(ui->txt_veiw_btn_next, 168, 247);
    lv_obj_set_size(ui->txt_veiw_btn_next, 61, 21);

    //Write style for txt_veiw_btn_next, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->txt_veiw_btn_next, 42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->txt_veiw_btn_next, lv_color_hex(0x2a2a2a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->txt_veiw_btn_next, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->txt_veiw_btn_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->txt_veiw_btn_next, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->txt_veiw_btn_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->txt_veiw_btn_next, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->txt_veiw_btn_next, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->txt_veiw_btn_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->txt_veiw_btn_next, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes txt_veiw_label_txt
    ui->txt_veiw_label_txt = lv_label_create(ui->txt_veiw);
    lv_label_set_text(ui->txt_veiw_label_txt, "Label");
    lv_label_set_long_mode(ui->txt_veiw_label_txt, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->txt_veiw_label_txt, 30, 50);
    lv_obj_set_size(ui->txt_veiw_label_txt, 180, 180);

    //Write style for txt_veiw_label_txt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->txt_veiw_label_txt, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->txt_veiw_label_txt, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->txt_veiw_label_txt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->txt_veiw_label_txt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->txt_veiw_label_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of txt_veiw.


    //Update current screen layout.
    lv_obj_update_layout(ui->txt_veiw);

    //Init events for screen.
    events_init_txt_veiw(ui);
}
