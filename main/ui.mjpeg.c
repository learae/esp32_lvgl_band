#include "lvgl.h"
#include "esp_log.h"
#include "string.h"
#include "sdcard.h"
#include "mjpeg_frame.h" // Ensure this header defines jpeg_frame_t
#include "../components/jpeg/img_converters.h"
#include "../components/jpeg/esp_jpg_decode.h"

static lv_obj_t *s_lv_file_title = NULL;

static lv_obj_t *s_lv_file_lists = NULL;

static lv_obj_t *s_lv_file_page = NULL;

static lv_obj_t *s_lv_player_page = NULL;

static lv_obj_t *s_lv_player_ctrl = NULL;

static lv_obj_t *s_lv_player_back = NULL;

static lv_obj_t *s_lv_player_play = NULL;

static lv_timer_t *s_lv_player_timer = NULL;

static bool s_lv_player_stop = false;

void lv_timer_playback_cb(lv_timer_t *timer)
{
    if(s_lv_player_stop)
    {
        return;
    }
    static mjpeg_frame_t frame_data;
    if(frame_data.data)
    {
        free(frame_data.data);
        frame_data.data = NULL;
        frame_data.len = 0;
    }
    jpeg_frame_get_data(&frame_data);
    if(frame_data.len)
    {
        static lv_img_dsc_t img_dsc;
        memset(&img_dsc, 0, sizeof(lv_img_dsc_t));
        static uint8_t *rgb565_data = NULL;
        uint16_t width = 0;
        uint16_t height = 0;
        if(rgb565_data)
        {
            free(rgb565_data);
            rgb565_data = NULL;
        }
        if(jpg2rgb565(frame_data.data, frame_data.len, &rgb565_data, &width, &height,JPG_SCALE_NONE))
        {
            img_dsc.data = rgb565_data;
            img_dsc.header.always_zero = 0;
            img_dsc.header.cf = LV_IMG_CF_TRUE_COLOR;
            img_dsc.header.w = width;
            img_dsc.header.h = height;
            img_dsc.data_size = width * height * 2;
            lv_img_set_src(s_lv_player_play, &img_dsc);
        }
        else
        {
            lv_timer_del(s_lv_player_timer);
            ESP_LOGE("MJPEG", "jpg2rgb565 failed");
        }
    }
}

void file_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    switch (code) {
        case LV_EVENT_CLICKED:{
            if(s_lv_player_timer)
                return;
            
            lv_list_get_btn_text(s_lv_file_lists, btn);
            const char *file_name = lv_list_get_btn_text(s_lv_file_lists, btn);
            if(file_name)
            {
                if(strstr(file_name,"mjpeg")||strstr(file_name,"MJPEG")||strstr(file_name,"MJP"))
                {
                    jpeg_frame_start(file_name);
                    s_lv_player_timer = lv_timer_create(lv_timer_playback_cb, 20, NULL);
                    lv_scr_load(s_lv_player_page);
                }
                else if(strstr(file_name,"mp4")||strstr(file_name,"MP4"))
                {
                    ESP_LOGI("MJPEG", "file name is %s", file_name);
                    
                }
            }
            break;
        }
        default:
            break;
    }   
}

void play_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    switch (code) {
        case LV_EVENT_CLICKED:{
            if(btn==s_lv_player_ctrl)
            {
                s_lv_player_stop = !s_lv_player_stop;
            }
            else if(btn==s_lv_player_back)
            {
                if(s_lv_player_timer)
                {
                    lv_timer_del(s_lv_player_timer);
                    s_lv_player_timer = NULL;
                }
                jpeg_frame_stop();
                lv_scr_load(s_lv_file_page);
            }
        }
        default:
            break;
    }   
}

void ui_mjpeg_create(void)
{
   lv_obj_set_style_bg_color(lv_scr_act(),lv_color_black(),0);
   
   //创建文件列表页面
   s_lv_file_page = lv_obj_create(NULL);
   lv_obj_set_style_bg_color(s_lv_file_page,lv_color_black(),0);

    //创建标题
    s_lv_file_title = lv_label_create(s_lv_file_page);
    lv_obj_set_size(s_lv_file_title, 200, 30);
    lv_obj_align(s_lv_file_title, LV_ALIGN_TOP_MID, 0, 10);
    lv_label_set_text(s_lv_file_title, "MJPEG File");
    lv_obj_set_style_text_font(s_lv_file_title, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(s_lv_file_title, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(s_lv_file_title, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(s_lv_file_title, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);

    //创建文件列表
    s_lv_file_lists = lv_list_create(s_lv_file_page);
    lv_obj_set_size(s_lv_file_lists, 200, 210);
    lv_obj_align(s_lv_file_lists, LV_ALIGN_BOTTOM_MID, 0, -10);
    lv_obj_set_style_bg_color(s_lv_file_lists, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(s_lv_file_lists, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(s_lv_file_lists, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(s_lv_file_lists, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    //sdcard_init();
    char file[10][50] = {};
    strcpy(file[0], "1234");
    strcpy(file[1], "5678");
    //int file_num = sdcard_filelist(&file);
    for (int i = 0; i < 2; i++) {
        lv_obj_t *btn = lv_list_add_btn(s_lv_file_lists, LV_SYMBOL_FILE, file[i]);
        lv_obj_add_event_cb(btn, file_btn_event_cb, LV_EVENT_CLICKED, NULL);
    }

    s_lv_player_page = lv_obj_create(NULL); //加载播放器页面
    lv_obj_set_style_bg_color(s_lv_player_page, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);


    s_lv_player_ctrl = lv_imgbtn_create(s_lv_player_page);
    lv_obj_set_size(s_lv_player_ctrl, 48, 40);
    lv_obj_align(s_lv_player_ctrl, LV_ALIGN_BOTTOM_RIGHT, -30, -30);
    lv_imgbtn_set_src(s_lv_player_ctrl, LV_IMGBTN_STATE_RELEASED,  NULL, "/main/img/pause_img_48.png",NULL);// 播放按钮
    lv_obj_add_event_cb(s_lv_player_ctrl, play_btn_event_cb, LV_EVENT_CLICKED, NULL);

    s_lv_player_back = lv_imgbtn_create(s_lv_player_page);
    lv_obj_set_size(s_lv_player_back, 48, 40);
    lv_obj_align(s_lv_player_back, LV_ALIGN_BOTTOM_LEFT, 30, -30);
    lv_imgbtn_set_src(s_lv_player_back, LV_IMGBTN_STATE_RELEASED,  NULL, "/main/img/back_img_48.png",NULL);// 返回按钮
    lv_obj_add_event_cb(s_lv_player_back, play_btn_event_cb, LV_EVENT_CLICKED, NULL);
    
    s_lv_player_play = lv_img_create(s_lv_player_page);
    lv_obj_align(s_lv_player_play, LV_ALIGN_TOP_MID, 0,30);
    
    lv_scr_load(s_lv_file_page);
}
