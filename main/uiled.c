#include "lvgl.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "driver/gpio.h"

static lv_obj_t *s_led_button = NULL;

static lv_obj_t *s_led_label = NULL;

void lv_led_button_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    static int led_state = 0;
    switch (code)
    {
    case LV_EVENT_CLICKED:
        led_state = ~led_state;
        gpio_set_level(GPIO_NUM_27, led_state);
        break;
    
    default:
        break;
    }
}

void ui_led_create(void)
{
    lv_obj_set_style_bg_color(lv_scr_act(),lv_color_black(),0); //设置背景为黑色
  
    s_led_button = lv_btn_create(lv_scr_act()); //基于整个屏幕创建按钮
    lv_obj_align(s_led_button,LV_ALIGN_CENTER,0,0);      //让按钮居中
    lv_obj_set_style_bg_color(s_led_button,lv_palette_main(LV_PALETTE_RED),0); //用调色板设置按钮颜色
    lv_obj_set_size(s_led_button, 80, 40);

    s_led_label = lv_label_create(s_led_button);   //基于按钮创建文字
    lv_obj_align(s_led_label,LV_ALIGN_CENTER,0,0);  
    lv_label_set_text(s_led_label,"LED");

    lv_obj_set_style_text_font(s_led_label,&lv_font_montserrat_20,LV_STATE_DEFAULT);//设置字体大小，需要在menuconfig里面开启字体型号

    lv_obj_add_event_cb(s_led_button,lv_led_button_cb,LV_EVENT_CLICKED,0);//设置事件（触发对象，触发回调函数，触发方式，触发传入参数）
}