#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "lvgl.h"
#include "lv_port.h"
#include "lv_demos.h"
#include "st7789_driver.h"
#include "uiled.h"
#include "temp_hum.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_spiffs.h"
#include "ui.mjpeg.h"
#include "esp_vfs_fat.h"
#include "esp_err.h"
#include "driver/ledc.h"
#include "ui/generated/gui_guider.h"
#include "wifi_ble/wifi_task.h"
#include "nvs_flash.h"
#include "sdcard.h"

lv_ui guider_ui;

void spiffs_init(char *partition_label,char*mount)
{
    esp_vfs_spiffs_conf_t conf = {
        .base_path = mount, 
        .partition_label = partition_label,
        .max_files = 5,
        .format_if_mount_failed = false,
    };
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE("spiffs", "Failed to mount or format filesystem");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            ESP_LOGE("spiffs", "Failed to find SPIFFS partition");
        } else {
            ESP_LOGE("spiffs", "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
        }
        return;
    }
}

void lv_ui_tack(void *params)
{
    while(1)
    {
        lv_task_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}


void app_main(void)
{
    lv_port_init();
    if (sdcard_init() != ESP_OK) {
        ESP_LOGE("sdcard", "SD card initialization failed");
        return;
    }
    ESP_ERROR_CHECK(ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 250));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0));
    setup_ui(&guider_ui);
    xTaskCreatePinnedToCore(lv_ui_tack, "lv_ui_tack", 8192*2, NULL, 5, NULL, 1);
}
