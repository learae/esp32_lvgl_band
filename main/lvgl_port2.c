#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "lvgl.h"
#include "lv_port.h"
#include "lv_demos.h"
#include "st7789_driver.h"
#include "uiled.h"
#include "ui_temp_hum.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_spiffs.h"
#include "ui.mjpeg.h"
#include "esp_vfs_fat.h"

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

void lv_mjpeg_tack(void *params)
{
    while(1)
    {
        lv_task_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}


void app_main(void)
{
    spiffs_init("ui_img","/main/img");
    lv_port_init();
    st7789_lcd_backlight(1);
    ui_mjpeg_create();
    xTaskCreatePinnedToCore(lv_mjpeg_tack, "lv_mjpeg_tack", 4096, NULL, 5, NULL, 1);
}
