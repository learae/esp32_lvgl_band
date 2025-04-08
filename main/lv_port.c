#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "lvgl.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "bsp/cst816t_driver.h"
#include "st7789_driver.h"
/*
1.初始化和注册显示驱动
2.触摸驱动
3.初始化st7789的硬件接口
4.初始化cst816t的硬件接口
5.提供一个定时器给lvgl
*/

#define LCD_WIDTH 240
#define LCD_HEIGHT 280

//1
static lv_disp_drv_t draw_drv;

void disp_flush(struct _lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    st7789_flush(area->x1,area->x2+1,area->y1+20,area->y2+1+20,color_p);
}

void lv_disp_init(void)
{
    
    static lv_disp_draw_buf_t draw_buf;
    const size_t draw_buf_size = LCD_HEIGHT*LCD_WIDTH/7;
    lv_color_t *draw1 = heap_caps_malloc(draw_buf_size*sizeof(lv_color_t),MALLOC_CAP_INTERNAL|MALLOC_CAP_DMA);
    lv_color_t *draw2 = heap_caps_malloc(draw_buf_size*sizeof(lv_color_t),MALLOC_CAP_INTERNAL|MALLOC_CAP_DMA);
    if(!draw1||!draw2)
    {
        ESP_LOGE("buf_init", "draw buff malloc fail");
        return;
    }
    lv_disp_draw_buf_init(&draw_buf, draw1, draw2, draw_buf_size);

    lv_disp_drv_init(&draw_drv);

    draw_drv.hor_res = LCD_WIDTH;
    draw_drv.ver_res = LCD_HEIGHT;
    draw_drv.draw_buf = &draw_buf;
    draw_drv.flush_cb = disp_flush;

    lv_disp_drv_register(&draw_drv);
}

//2
void IRAM_ATTR indev_rdcb(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    int16_t x,y;
    int state;
    cst816t_read(&x,&y,&state);
    data->point.x=x;
    data->point.y=y;
    data->state = state;
}

void lv_indev_init(void)
{
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = indev_rdcb;
    lv_indev_drv_register(&indev_drv);
}

//3
void lv_flush_done_cb(void* param)
{
    lv_disp_flush_ready(&draw_drv);
}

void st7789_hw_init(void)
{
    st7789_cfg_t st7789_cfg={
    .bl = GPIO_NUM_26,
    .clk = GPIO_NUM_18,
    .cs = GPIO_NUM_5,
    .dc = GPIO_NUM_17,
    .mosi = GPIO_NUM_19,
    .rst = GPIO_NUM_21,
    .spi_fre = 40*1000*1000,
    .height =LCD_HEIGHT,
    .width = LCD_WIDTH,
    .spin = 0,
    .done_cb = lv_flush_done_cb,
   };

    st7789_driver_hw_init(&st7789_cfg);
}

//4
void cst816t_hw_init(void)
{
    cst816t_cfg_t cst816t_cfg={
        .scl = GPIO_NUM_22,
        .sda = GPIO_NUM_23,
        .fre = 300,
        .x_limit =LCD_WIDTH,
        .y_limit = LCD_HEIGHT,
    };
    cst816t_init(&cst816t_cfg);
}

//5
void lv_timer_cb(void* arg)
{
    uint32_t tick_interval = (uint32_t)arg;
    lv_tick_inc(tick_interval);
}

void lv_timer_tick_init(void)
{
    static uint32_t tick_interval = 5;
    const esp_timer_create_args_t timegive = {
        .arg = &tick_interval,
        .callback = lv_timer_cb,
        .name = "",
        .dispatch_method =  ESP_TIMER_TASK,
        .skip_unhandled_events = true,
    };

    esp_timer_handle_t lv_timer_handle;
    esp_timer_create(&timegive, &lv_timer_handle);
    esp_timer_start_periodic(lv_timer_handle, tick_interval*1000);
}

void lv_port_init(void)
{
    lv_init();
    st7789_hw_init();
    cst816t_hw_init();
    lv_disp_init();
    lv_indev_init();
    lv_timer_tick_init();
}