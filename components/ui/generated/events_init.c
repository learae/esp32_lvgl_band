/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "driver/ledc.h"
#include "temp_hum.h"
#include "esp_err.h"
#include "wifi_task.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.tianqi_page, guider_ui.tianqi_page_del, &guider_ui.screen_del, setup_scr_tianqi_page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.screen_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.shezhi, guider_ui.shezhi_del, &guider_ui.screen_del, setup_scr_shezhi, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 100, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen, screen_event_handler, LV_EVENT_ALL, ui);
}

static void tianqi_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.tianqi_page_del, setup_scr_screen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.tianqi_page1, guider_ui.tianqi_page1_del, &guider_ui.tianqi_page_del, setup_scr_tianqi_page1, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_tianqi_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->tianqi_page, tianqi_page_event_handler, LV_EVENT_ALL, ui);
}

static void shezhi_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SHORT_CLICKED:
    {
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.shezhi_del, setup_scr_screen, LV_SCR_LOAD_ANIM_OVER_TOP, 100, 200, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void shezhi_cont_sethome_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {

        break;
    }
    default:
        break;
    }
}

static void shezhi_config_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.settings_page, guider_ui.settings_page_del, &guider_ui.shezhi_del, setup_scr_settings_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void shezhi_bt_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {

        break;
    }
    case LV_EVENT_RELEASED:
    {

        break;
    }
    default:
        break;
    }
}

static void shezhi_slider_li_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        int slider_value = lv_slider_get_value(lv_event_get_target(e));
        ESP_ERROR_CHECK(ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, slider_value*5));
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0));
        break;
    }
    default:
        break;
    }
}


static void shezhi_wifi_btn_event_handler (lv_event_t *e)
{
    static TaskHandle_t wifi_task_handle = NULL;
    static bool wifi_task_started = true;
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_PRESSED:
        {
            if(wifi_task_handle == NULL)
                xTaskCreatePinnedToCore(wifi_task, "wifi_task", 8192, NULL, 5, &wifi_task_handle, 0);
            break;
        }
        case LV_EVENT_RELEASED: //除第一次外接下来每次点击都执行
        {
            if(wifi_task_handle != NULL){
                if (wifi_task_started==false)
                {
                    wifi_task_started = true;
                    wifi_mqtt_stop();
                    ESP_LOGI("WIFI_EVENT", "WiFi is OFF");
                }
                else{

                    wifi_mqtt_start();
                    wifi_task_started = false;
                    ESP_LOGI("WIFI_EVENT", "WiFi is ON");
                }
            }
            break;
        }
        default:
            break;
        }
}

void events_init_shezhi (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->shezhi, shezhi_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->shezhi_cont_sethome, shezhi_cont_sethome_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->shezhi_config_btn, shezhi_config_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->shezhi_bt_btn, shezhi_bt_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->shezhi_slider_li, shezhi_slider_li_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->shezhi_wifi_btn, shezhi_wifi_btn_event_handler, LV_EVENT_ALL, ui);
}

static void duogongneng_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.duogongneng_del, setup_scr_screen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void duogongneng_heart_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.heart_page, guider_ui.heart_page_del, &guider_ui.duogongneng_del, setup_scr_heart_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_temp_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.temp_page, guider_ui.temp_page_del, &guider_ui.duogongneng_del, setup_scr_temp_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        temp_hum_timer_create(guider_ui.temp_page_label_temp, guider_ui.temp_page_label_hum);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_btn_tianq_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.tianqi_page, guider_ui.tianqi_page_del, &guider_ui.duogongneng_del, setup_scr_tianqi_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_phone_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.lis_page, guider_ui.lis_page_del, &guider_ui.duogongneng_del, setup_scr_lis_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_music_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.music_list, guider_ui.music_list_del, &guider_ui.duogongneng_del, setup_scr_music_list, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_load_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.load_page, guider_ui.load_page_del, &guider_ui.duogongneng_del, setup_scr_load_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_btn_lis_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void duogongneng_vol_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.vol_page, guider_ui.vol_page_del, &guider_ui.duogongneng_del, setup_scr_vol_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_light_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.light_page, guider_ui.light_page_del, &guider_ui.duogongneng_del, setup_scr_light_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_heart_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.heart_page, guider_ui.heart_page_del, &guider_ui.duogongneng_del, setup_scr_heart_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_temp_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.temp_page, guider_ui.temp_page_del, &guider_ui.duogongneng_del, setup_scr_temp_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        temp_hum_timer_create(guider_ui.temp_page_label_temp, guider_ui.temp_page_label_hum);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_tinq_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.tianqi_page, guider_ui.tianqi_page_del, &guider_ui.duogongneng_del, setup_scr_tianqi_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_load_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.load_page, guider_ui.load_page_del, &guider_ui.duogongneng_del, setup_scr_load_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_music_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.music_list, guider_ui.music_list_del, &guider_ui.duogongneng_del, setup_scr_music_list, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_phone_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.lis_page, guider_ui.lis_page_del, &guider_ui.duogongneng_del, setup_scr_lis_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_light_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.light_page, guider_ui.light_page_del, &guider_ui.duogongneng_del, setup_scr_light_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 400, false, false);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_vol_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.vol_page, guider_ui.vol_page_del, &guider_ui.duogongneng_del, setup_scr_vol_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_img_lis_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.lis_page, guider_ui.lis_page_del, &guider_ui.duogongneng_del, setup_scr_lis_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_btn_txt_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.txt_page, guider_ui.txt_page_del, &guider_ui.duogongneng_del, setup_scr_txt_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_config_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.settings_page, guider_ui.settings_page_del, &guider_ui.duogongneng_del, setup_scr_settings_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_connect_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.connect_page, guider_ui.connect_page_del, &guider_ui.duogongneng_del, setup_scr_connect_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_math_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.math_page, guider_ui.math_page_del, &guider_ui.duogongneng_del, setup_scr_math_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_connect_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.connect_page, guider_ui.connect_page_del, &guider_ui.duogongneng_del, setup_scr_connect_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_config_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.settings_page, guider_ui.settings_page_del, &guider_ui.duogongneng_del, setup_scr_settings_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_txt_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.txt_page, guider_ui.txt_page_del, &guider_ui.duogongneng_del, setup_scr_txt_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

static void duogongneng_math_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.math_page, guider_ui.math_page_del, &guider_ui.duogongneng_del, setup_scr_math_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_duogongneng (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->duogongneng, duogongneng_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_heart_btn, duogongneng_heart_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_temp_btn, duogongneng_temp_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_btn_tianq, duogongneng_btn_tianq_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_phone_btn, duogongneng_phone_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_music_btn, duogongneng_music_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_load_btn, duogongneng_load_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_btn_lis, duogongneng_btn_lis_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_vol_btn, duogongneng_vol_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_light_btn, duogongneng_light_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_heart_img, duogongneng_heart_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_temp_img, duogongneng_temp_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_tinq_img, duogongneng_tinq_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_load_img, duogongneng_load_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_music_img, duogongneng_music_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_phone_img, duogongneng_phone_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_light_img, duogongneng_light_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_vol_img, duogongneng_vol_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_img_lis, duogongneng_img_lis_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_btn_txt, duogongneng_btn_txt_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_config_btn, duogongneng_config_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_connect_btn, duogongneng_connect_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_math_btn, duogongneng_math_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_connect_img, duogongneng_connect_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_config_img, duogongneng_config_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_txt_img, duogongneng_txt_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->duogongneng_math_img, duogongneng_math_img_event_handler, LV_EVENT_ALL, ui);
}

static void tianqi_page1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.tianqi_page1_del, setup_scr_screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.tianqi_page, guider_ui.tianqi_page_del, &guider_ui.tianqi_page1_del, setup_scr_tianqi_page, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.tianqi_page1_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_tianqi_page1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->tianqi_page1, tianqi_page1_event_handler, LV_EVENT_ALL, ui);
}

static void temp_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.temp_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            temp_hum_timer_delete();
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.temp_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            temp_hum_timer_delete();
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_temp_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->temp_page, temp_page_event_handler, LV_EVENT_ALL, ui);
}

static void light_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.light_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.light_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void light_page_slider_light_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        int slider_value = lv_slider_get_value(lv_event_get_target(e));
        ESP_ERROR_CHECK(ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, slider_value * 5));
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0));
        break;
    }
    default:
        break;
    }
}

static void light_page_pwm_mode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        lv_obj_clear_state(guider_ui.light_page_dc_mode, LV_STATE_CHECKED);
        break;
    }
    default:
        break;
    }
}

static void light_page_dc_mode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        lv_obj_clear_state(guider_ui.light_page_pwm_mode, LV_STATE_CHECKED);
        break;
    }
    default:
        break;
    }
}

void events_init_light_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->light_page, light_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->light_page_slider_light, light_page_slider_light_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->light_page_pwm_mode, light_page_pwm_mode_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->light_page_dc_mode, light_page_dc_mode_event_handler, LV_EVENT_ALL, ui);
}

static void txt_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.txt_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.txt_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void txt_page_list_txt_item0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.txt_veiw, guider_ui.txt_veiw_del, &guider_ui.txt_page_del, setup_scr_txt_veiw, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_txt_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->txt_page, txt_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->txt_page_list_txt_item0, txt_page_list_txt_item0_event_handler, LV_EVENT_ALL, ui);
}

static void connect_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.connect_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.connect_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void connect_page_wifi_sw_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;

        break;
    }
    default:
        break;
    }
}

static void connect_page_AP_sw_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;

        break;
    }
    default:
        break;
    }
}

static void connect_page_smratconfig_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void connect_page_mqtt_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

void events_init_connect_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->connect_page, connect_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->connect_page_wifi_sw, connect_page_wifi_sw_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->connect_page_AP_sw, connect_page_AP_sw_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->connect_page_smratconfig_btn, connect_page_smratconfig_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->connect_page_mqtt_btn, connect_page_mqtt_btn_event_handler, LV_EVENT_ALL, ui);
}

static void music_list_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.music_list_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.music_list_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_music_list (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->music_list, music_list_event_handler, LV_EVENT_ALL, ui);
}

static void txt_veiw_btn_txt_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.txt_page, guider_ui.txt_page_del, &guider_ui.txt_veiw_del, setup_scr_txt_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void txt_veiw_btn_last_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void txt_veiw_btn_next_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

void events_init_txt_veiw (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->txt_veiw_btn_txt_back, txt_veiw_btn_txt_back_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->txt_veiw_btn_last, txt_veiw_btn_last_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->txt_veiw_btn_next, txt_veiw_btn_next_event_handler, LV_EVENT_ALL, ui);
}

static void settings_page_btn_time_cor_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void settings_page_btn_other_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void settings_page_btn_version_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void settings_page_btn_set_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.settings_page_del, setup_scr_screen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_settings_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->settings_page_btn_time_cor, settings_page_btn_time_cor_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->settings_page_btn_other, settings_page_btn_other_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->settings_page_btn_version, settings_page_btn_version_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->settings_page_btn_set_back, settings_page_btn_set_back_event_handler, LV_EVENT_ALL, ui);
}

static void heart_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.heart_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.heart_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_heart_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->heart_page, heart_page_event_handler, LV_EVENT_ALL, ui);
}

static void vol_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.vol_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.vol_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void vol_page_list_device_item0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void vol_page_slider_volu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {

        break;
    }
    default:
        break;
    }
}

void events_init_vol_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->vol_page, vol_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->vol_page_list_device_item0, vol_page_list_device_item0_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->vol_page_slider_volu, vol_page_slider_volu_event_handler, LV_EVENT_ALL, ui);
}

static void lis_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.lis_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.lis_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void lis_page_list_headset_item0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

void events_init_lis_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->lis_page, lis_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->lis_page_list_headset_item0, lis_page_list_headset_item0_event_handler, LV_EVENT_ALL, ui);
}

static void math_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.math_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.math_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void math_page_btnm_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * obj = lv_event_get_target(e);
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);

        switch (id) {
        case (0):
        {

            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_math_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->math_page, math_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->math_page_btnm_1, math_page_btnm_1_event_handler, LV_EVENT_ALL, ui);
}

static void load_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.load_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.duogongneng, guider_ui.duogongneng_del, &guider_ui.load_page_del, setup_scr_duogongneng, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_load_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->load_page, load_page_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
