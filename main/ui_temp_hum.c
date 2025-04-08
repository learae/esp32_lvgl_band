#include "lvgl.h"
#include "led_ws2812.h"
#include "dht11.h"
#include "esp_log.h"


LV_IMG_DECLARE(temp_img)
LV_IMG_DECLARE(humidity_img)

static lv_timer_t *s_dht11_timer;

static lv_obj_t *s_temp_img;
static lv_obj_t *s_hum_img;

static lv_obj_t *s_temp_label;
static lv_obj_t *s_hum_label;

static lv_obj_t *s_light_slider;

ws2812_strip_handle_t light_handle;

void light_slider_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
        {
            lv_obj_t* slider_obj = lv_event_get_target(e);
            int32_t value = lv_slider_get_value(slider_obj);
            uint32_t rgb_value = 150*value/100;
            for(int led_index = 0 ;led_index < 12;led_index++)
            {
                ws2812_write(light_handle,led_index,rgb_value,rgb_value,rgb_value);
            }
            break;
        }
    default:
        break;
    }
}

void dht11_timer_cb(struct _lv_timer_t *)
{
    int temp,hum;
    if(DHT11_StartGet(&temp, &hum))
    {
       
        char disp_buf[32];
        snprintf(disp_buf,sizeof(disp_buf),"%.1f",(float)temp/10.0);
        lv_label_set_text(s_temp_label, disp_buf);
     
        snprintf(disp_buf,sizeof(disp_buf),"%d%%",hum);
        lv_label_set_text(s_hum_label, disp_buf);

    }
}

void ui_thp_create(void)
{
    lv_obj_set_style_bg_color(lv_scr_act(),lv_color_black(),0); //设置背景为黑色

    s_light_slider = lv_slider_create(lv_scr_act());//创建滑块
    lv_obj_set_pos(s_light_slider,60,200);//设置位置
    lv_obj_set_size(s_light_slider,150,15);//设置大小
    lv_slider_set_range(s_light_slider, 0,100);//设置值的范围
    lv_obj_add_event_cb(s_light_slider,light_slider_event_cb,LV_EVENT_VALUE_CHANGED,NULL);

    //创建温度图片
    s_temp_img = lv_img_create(lv_scr_act());
    lv_img_set_src(s_temp_img,&temp_img);
    lv_obj_set_pos(s_temp_img,40,40);

    s_hum_img = lv_img_create(lv_scr_act());
    lv_img_set_src(s_hum_img,&humidity_img);
    lv_obj_set_pos(s_hum_img,40,110);

    s_temp_label = lv_label_create(lv_scr_act());
    lv_obj_set_pos(s_temp_label,100, 40);
    lv_obj_set_style_text_font(s_temp_label,&lv_font_montserrat_38,LV_STATE_DEFAULT);
    
    s_hum_label = lv_label_create(lv_scr_act());
    lv_obj_set_pos(s_hum_label,100, 110);
    lv_obj_set_style_text_font(s_hum_label,&lv_font_montserrat_38,LV_STATE_DEFAULT);

    //创建定时器
    s_dht11_timer = lv_timer_create(dht11_timer_cb,2000,NULL);

    //初始化ws2812
    ws2812_init(GPIO_NUM_33,12,&light_handle);

    //初始化dht11
    DHT11_Init(GPIO_NUM_25);

}