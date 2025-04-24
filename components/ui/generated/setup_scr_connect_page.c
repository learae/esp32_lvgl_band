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



void setup_scr_connect_page(lv_ui *ui)
{
    //Write codes connect_page
    ui->connect_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->connect_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->connect_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for connect_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connect_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->connect_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->connect_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->connect_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connect_page_label_wifi_mode
    ui->connect_page_label_wifi_mode = lv_label_create(ui->connect_page);
    lv_label_set_text(ui->connect_page_label_wifi_mode, "wifi-mode");
    lv_label_set_long_mode(ui->connect_page_label_wifi_mode, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->connect_page_label_wifi_mode, 5, 5);
    lv_obj_set_size(ui->connect_page_label_wifi_mode, 109, 31);

    //Write style for connect_page_label_wifi_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connect_page_label_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_label_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connect_page_label_wifi_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connect_page_label_wifi_mode, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connect_page_label_wifi_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connect_page_label_wifi_mode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connect_page_label_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connect_page_label_wifi_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connect_page_label_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connect_page_label_wifi_mode, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connect_page_label_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connect_page_label_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connect_page_label_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_label_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connect_page_label_mqtt_set
    ui->connect_page_label_mqtt_set = lv_label_create(ui->connect_page);
    lv_label_set_text(ui->connect_page_label_mqtt_set, "mqtt-setting");
    lv_label_set_long_mode(ui->connect_page_label_mqtt_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->connect_page_label_mqtt_set, 12, 173);
    lv_obj_set_size(ui->connect_page_label_mqtt_set, 107, 31);

    //Write style for connect_page_label_mqtt_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connect_page_label_mqtt_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_label_mqtt_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connect_page_label_mqtt_set, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connect_page_label_mqtt_set, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connect_page_label_mqtt_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connect_page_label_mqtt_set, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connect_page_label_mqtt_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connect_page_label_mqtt_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connect_page_label_mqtt_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connect_page_label_mqtt_set, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connect_page_label_mqtt_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connect_page_label_mqtt_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connect_page_label_mqtt_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_label_mqtt_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connect_page_wifi_sw
    ui->connect_page_wifi_sw = lv_switch_create(ui->connect_page);
    lv_obj_set_pos(ui->connect_page_wifi_sw, 95, 44);
    lv_obj_set_size(ui->connect_page_wifi_sw, 40, 20);

    //Write style for connect_page_wifi_sw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connect_page_wifi_sw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connect_page_wifi_sw, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connect_page_wifi_sw, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connect_page_wifi_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_wifi_sw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_wifi_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for connect_page_wifi_sw, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->connect_page_wifi_sw, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->connect_page_wifi_sw, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->connect_page_wifi_sw, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->connect_page_wifi_sw, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for connect_page_wifi_sw, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connect_page_wifi_sw, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connect_page_wifi_sw, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connect_page_wifi_sw, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connect_page_wifi_sw, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_wifi_sw, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes connect_page_AP_sw
    ui->connect_page_AP_sw = lv_switch_create(ui->connect_page);
    lv_obj_set_pos(ui->connect_page_AP_sw, 95, 86);
    lv_obj_set_size(ui->connect_page_AP_sw, 40, 20);

    //Write style for connect_page_AP_sw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connect_page_AP_sw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connect_page_AP_sw, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connect_page_AP_sw, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connect_page_AP_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_AP_sw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_AP_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for connect_page_AP_sw, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->connect_page_AP_sw, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->connect_page_AP_sw, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->connect_page_AP_sw, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->connect_page_AP_sw, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for connect_page_AP_sw, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connect_page_AP_sw, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connect_page_AP_sw, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connect_page_AP_sw, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connect_page_AP_sw, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_AP_sw, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes connect_page_label_wifi
    ui->connect_page_label_wifi = lv_label_create(ui->connect_page);
    lv_label_set_text(ui->connect_page_label_wifi, "wifi");
    lv_label_set_long_mode(ui->connect_page_label_wifi, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->connect_page_label_wifi, 12, 44);
    lv_obj_set_size(ui->connect_page_label_wifi, 75, 14);

    //Write style for connect_page_label_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connect_page_label_wifi, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connect_page_label_wifi, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connect_page_label_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connect_page_label_wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connect_page_label_A_P
    ui->connect_page_label_A_P = lv_label_create(ui->connect_page);
    lv_label_set_text(ui->connect_page_label_A_P, "AP");
    lv_label_set_long_mode(ui->connect_page_label_A_P, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->connect_page_label_A_P, 12, 86);
    lv_obj_set_size(ui->connect_page_label_A_P, 75, 14);

    //Write style for connect_page_label_A_P, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connect_page_label_A_P, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connect_page_label_A_P, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connect_page_label_A_P, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connect_page_label_A_P, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_label_A_P, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connect_page_label_smartconfig
    ui->connect_page_label_smartconfig = lv_label_create(ui->connect_page);
    lv_label_set_text(ui->connect_page_label_smartconfig, "smartconfig");
    lv_label_set_long_mode(ui->connect_page_label_smartconfig, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->connect_page_label_smartconfig, 12, 129);
    lv_obj_set_size(ui->connect_page_label_smartconfig, 108, 17);

    //Write style for connect_page_label_smartconfig, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connect_page_label_smartconfig, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connect_page_label_smartconfig, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connect_page_label_smartconfig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connect_page_label_smartconfig, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_label_smartconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connect_page_smratconfig_btn
    ui->connect_page_smratconfig_btn = lv_btn_create(ui->connect_page);
    ui->connect_page_smratconfig_btn_label = lv_label_create(ui->connect_page_smratconfig_btn);
    lv_label_set_text(ui->connect_page_smratconfig_btn_label, "open");
    lv_label_set_long_mode(ui->connect_page_smratconfig_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connect_page_smratconfig_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connect_page_smratconfig_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connect_page_smratconfig_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->connect_page_smratconfig_btn, 142, 125);
    lv_obj_set_size(ui->connect_page_smratconfig_btn, 36, 32);

    //Write style for connect_page_smratconfig_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connect_page_smratconfig_btn, 125, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connect_page_smratconfig_btn, lv_color_hex(0x818181), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connect_page_smratconfig_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connect_page_smratconfig_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_smratconfig_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_smratconfig_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->connect_page_smratconfig_btn, lv_color_hex(0xcecaca), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->connect_page_smratconfig_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->connect_page_smratconfig_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->connect_page_smratconfig_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->connect_page_smratconfig_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connect_page_smratconfig_btn, lv_color_hex(0xf2f1f1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connect_page_smratconfig_btn, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connect_page_smratconfig_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connect_page_smratconfig_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connect_page_label_mqtt_client
    ui->connect_page_label_mqtt_client = lv_label_create(ui->connect_page);
    lv_label_set_text(ui->connect_page_label_mqtt_client, "mqtt-client");
    lv_label_set_long_mode(ui->connect_page_label_mqtt_client, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->connect_page_label_mqtt_client, 12, 219);
    lv_obj_set_size(ui->connect_page_label_mqtt_client, 100, 19);

    //Write style for connect_page_label_mqtt_client, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connect_page_label_mqtt_client, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connect_page_label_mqtt_client, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connect_page_label_mqtt_client, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connect_page_label_mqtt_client, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_label_mqtt_client, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connect_page_mqtt_btn
    ui->connect_page_mqtt_btn = lv_btn_create(ui->connect_page);
    ui->connect_page_mqtt_btn_label = lv_label_create(ui->connect_page_mqtt_btn);
    lv_label_set_text(ui->connect_page_mqtt_btn_label, "open");
    lv_label_set_long_mode(ui->connect_page_mqtt_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connect_page_mqtt_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connect_page_mqtt_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connect_page_mqtt_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->connect_page_mqtt_btn, 142, 215);
    lv_obj_set_size(ui->connect_page_mqtt_btn, 36, 32);

    //Write style for connect_page_mqtt_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connect_page_mqtt_btn, 125, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connect_page_mqtt_btn, lv_color_hex(0x818181), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connect_page_mqtt_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connect_page_mqtt_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connect_page_mqtt_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connect_page_mqtt_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->connect_page_mqtt_btn, lv_color_hex(0xcecaca), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->connect_page_mqtt_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->connect_page_mqtt_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->connect_page_mqtt_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->connect_page_mqtt_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connect_page_mqtt_btn, lv_color_hex(0xf2f1f1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connect_page_mqtt_btn, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connect_page_mqtt_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connect_page_mqtt_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of connect_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->connect_page);

    //Init events for screen.
    events_init_connect_page(ui);
}
