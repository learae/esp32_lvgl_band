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



void setup_scr_light_page(lv_ui *ui)
{
    //Write codes light_page
    ui->light_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->light_page, 240, 280);
    lv_obj_set_scrollbar_mode(ui->light_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for light_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->light_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->light_page, &_OIPC_240x280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->light_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->light_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes light_page_img_sun
    ui->light_page_img_sun = lv_img_create(ui->light_page);
    lv_obj_add_flag(ui->light_page_img_sun, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->light_page_img_sun, &_o_alpha_24x24);
    lv_img_set_pivot(ui->light_page_img_sun, 50,50);
    lv_img_set_angle(ui->light_page_img_sun, 0);
    lv_obj_set_pos(ui->light_page_img_sun, 20, 177);
    lv_obj_set_size(ui->light_page_img_sun, 24, 24);

    //Write style for light_page_img_sun, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->light_page_img_sun, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->light_page_img_sun, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_img_sun, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->light_page_img_sun, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes light_page_slider_light
    ui->light_page_slider_light = lv_slider_create(ui->light_page);
    lv_slider_set_range(ui->light_page_slider_light, 0, 100);
    lv_slider_set_mode(ui->light_page_slider_light, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->light_page_slider_light, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->light_page_slider_light, 58, 185);
    lv_obj_set_size(ui->light_page_slider_light, 160, 8);

    //Write style for light_page_slider_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->light_page_slider_light, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->light_page_slider_light, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->light_page_slider_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_slider_light, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->light_page_slider_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->light_page_slider_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for light_page_slider_light, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->light_page_slider_light, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->light_page_slider_light, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->light_page_slider_light, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_slider_light, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for light_page_slider_light, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->light_page_slider_light, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->light_page_slider_light, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->light_page_slider_light, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_slider_light, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes light_page_light_ctrl
    ui->light_page_light_ctrl = lv_label_create(ui->light_page);
    lv_label_set_text(ui->light_page_light_ctrl, "brightness");
    lv_label_set_long_mode(ui->light_page_light_ctrl, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->light_page_light_ctrl, 8, 145);
    lv_obj_set_size(ui->light_page_light_ctrl, 116, 26);

    //Write style for light_page_light_ctrl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->light_page_light_ctrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_light_ctrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->light_page_light_ctrl, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->light_page_light_ctrl, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->light_page_light_ctrl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->light_page_light_ctrl, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->light_page_light_ctrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->light_page_light_ctrl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->light_page_light_ctrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->light_page_light_ctrl, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->light_page_light_ctrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->light_page_light_ctrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->light_page_light_ctrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->light_page_light_ctrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes light_page_pwm_mode
    ui->light_page_pwm_mode = lv_switch_create(ui->light_page);
    lv_obj_set_pos(ui->light_page_pwm_mode, 95, 73);
    lv_obj_set_size(ui->light_page_pwm_mode, 40, 20);

    //Write style for light_page_pwm_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->light_page_pwm_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->light_page_pwm_mode, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->light_page_pwm_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->light_page_pwm_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_pwm_mode, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->light_page_pwm_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for light_page_pwm_mode, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->light_page_pwm_mode, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->light_page_pwm_mode, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->light_page_pwm_mode, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->light_page_pwm_mode, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for light_page_pwm_mode, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->light_page_pwm_mode, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->light_page_pwm_mode, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->light_page_pwm_mode, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->light_page_pwm_mode, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_pwm_mode, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes light_page_dc_mode
    ui->light_page_dc_mode = lv_switch_create(ui->light_page);
    lv_obj_set_pos(ui->light_page_dc_mode, 95, 113);
    lv_obj_set_size(ui->light_page_dc_mode, 40, 20);

    //Write style for light_page_dc_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->light_page_dc_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->light_page_dc_mode, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->light_page_dc_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->light_page_dc_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_dc_mode, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->light_page_dc_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for light_page_dc_mode, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->light_page_dc_mode, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->light_page_dc_mode, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->light_page_dc_mode, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->light_page_dc_mode, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for light_page_dc_mode, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->light_page_dc_mode, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->light_page_dc_mode, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->light_page_dc_mode, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->light_page_dc_mode, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_dc_mode, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes light_page_label_pwm
    ui->light_page_label_pwm = lv_label_create(ui->light_page);
    lv_label_set_text(ui->light_page_label_pwm, "pwm");
    lv_label_set_long_mode(ui->light_page_label_pwm, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->light_page_label_pwm, 25, 66);
    lv_obj_set_size(ui->light_page_label_pwm, 57, 33);

    //Write style for light_page_label_pwm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->light_page_label_pwm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_label_pwm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->light_page_label_pwm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->light_page_label_pwm, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->light_page_label_pwm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->light_page_label_pwm, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->light_page_label_pwm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->light_page_label_pwm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->light_page_label_pwm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->light_page_label_pwm, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->light_page_label_pwm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->light_page_label_pwm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->light_page_label_pwm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->light_page_label_pwm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes light_page_label_dc
    ui->light_page_label_dc = lv_label_create(ui->light_page);
    lv_label_set_text(ui->light_page_label_dc, "dc");
    lv_label_set_long_mode(ui->light_page_label_dc, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->light_page_label_dc, 25, 106);
    lv_obj_set_size(ui->light_page_label_dc, 62, 29);

    //Write style for light_page_label_dc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->light_page_label_dc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_label_dc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->light_page_label_dc, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->light_page_label_dc, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->light_page_label_dc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->light_page_label_dc, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->light_page_label_dc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->light_page_label_dc, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->light_page_label_dc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->light_page_label_dc, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->light_page_label_dc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->light_page_label_dc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->light_page_label_dc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->light_page_label_dc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes light_page_label_lightmode
    ui->light_page_label_lightmode = lv_label_create(ui->light_page);
    lv_label_set_text(ui->light_page_label_lightmode, "adjustment mode");
    lv_label_set_long_mode(ui->light_page_label_lightmode, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->light_page_label_lightmode, 16, 23);
    lv_obj_set_size(ui->light_page_label_lightmode, 161, 34);

    //Write style for light_page_label_lightmode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->light_page_label_lightmode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->light_page_label_lightmode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->light_page_label_lightmode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->light_page_label_lightmode, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->light_page_label_lightmode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->light_page_label_lightmode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->light_page_label_lightmode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->light_page_label_lightmode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->light_page_label_lightmode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->light_page_label_lightmode, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->light_page_label_lightmode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->light_page_label_lightmode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->light_page_label_lightmode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->light_page_label_lightmode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of light_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->light_page);

    //Init events for screen.
    events_init_light_page(ui);
}
