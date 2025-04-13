#include "lvgl.h"
#include "esp_log.h"
#include "string.h"
#include "sdcard.h"

static lv_obj_t *s_lv_file_title = NULL;

static lv_obj_t *s_lv_file_lists = NULL;

static lv_obj_t *s_lv_file_page = NULL;

static lv_obj_t *s_lv_player_page = NULL;

static lv_obj_t *s_lv_player_ctrl = NULL;

static lv_obj_t *s_lv_player_back = NULL;

static lv_obj_t *s_lv_player_play = NULL;

void file_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t *code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    switch (*code) {
    {
    case LV_EVENT_CLICKED:
        ESP_LOGI("file_btn_event_cb", "Clicked");
        lv_scr_load(s_lv_player_page);//跳转播放器页面
        break;
    
    default:
        break;
    }

void ui_mjpeg_create(void)
{
    s_lv_file_page = lv_obj_create(lv_scr_act());
    lv_obj_set_style_bg_color(s_lv_file_page, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_scr_load(s_lv_file_page);//加载文件页面

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

    sdcard_init();
    char file[20][256] = {0};
    int file_num = sdcard_filelist(&file);
    for (int i = 0; i < file_num; i++) {
        lv_obj_t *btn = lv_list_add_btn(s_lv_file_lists, LV_SYMBOL_FILE, file[i]);
        lv_obj_add_event_cb(btn, file_btn_event_cb, LV_EVENT_CLICKED, NULL);
    }

    s_lv_player_page = lv_obj_create(lv_scr_act()); //加载播放器页面
    lv_obj_set_style_bg_color(s_lv_player_page, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);

    s_lv_player_ctrl = lv_list_create(s_lv_player_page);
    lv_obj_set_size(s_lv_player_ctrl, 40, 40);
    lv_obj_align(s_lv_player_ctrl, LV_ALIGN_BOTTOM_RIGHT, -30, 10);
    lv_imgbtn_set_src(s_lv_player_ctrl, LV_IMGBTN_STATE_RELEASED,  NULL, "/main/img/pause_img_48.png",NULL);// 播放按钮

    s_lv_player_back = lv_btn_create(s_lv_player_page);
    lv_obj_set_size(s_lv_player_back, 40, 40);
    lv_obj_align(s_lv_player_back, LV_ALIGN_BOTTOM_LEFT, 30, 10);
    lv_imgbtn_set_src(s_lv_player_back, LV_IMGBTN_STATE_RELEASED,  NULL, "/main/img/back_img_48.png",NULL);// 返回按钮
    
    
    s_lv_player_play = lv_btn_create(s_lv_player_page);
    lv_obj_align(s_lv_player_play, LV_ALIGN_TOP_MID, 0,30);
    
}
