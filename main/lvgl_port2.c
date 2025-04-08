#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "lvgl.h"
#include "lv_port.h"
#include "lv_demos.h"
#include "st7789_driver.h"
#include "uiled.h"
#include "driver/gpio.h"

void app_main(void)
{
    lv_port_init();
    st7789_lcd_backlight(1);
    ui_led_create();
    gpio_config_t led_cfg={
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pin_bit_mask = (1<<GPIO_NUM_27),
        .intr_type =GPIO_INTR_DISABLE,
    };
    gpio_config(&led_cfg);
    gpio_set_level(GPIO_NUM_27, 0);
    
    while(1)
    {
        lv_task_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
