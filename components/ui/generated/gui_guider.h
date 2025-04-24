/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_img_home;
	lv_obj_t *screen_digital_clock_home;
	lv_obj_t *tianqi_page;
	bool tianqi_page_del;
	lv_obj_t *tianqi_page_img_tianq;
	lv_obj_t *tianqi_page_img_2;
	lv_obj_t *tianqi_page_label_tianq;
	lv_obj_t *shezhi;
	bool shezhi_del;
	lv_obj_t *shezhi_img_3;
	lv_obj_t *shezhi_cont_sethome;
	lv_obj_t *shezhi_config_btn;
	lv_obj_t *shezhi_config_btn_label;
	lv_obj_t *shezhi_bt_btn;
	lv_obj_t *shezhi_bt_btn_label;
	lv_obj_t *shezhi_img_li;
	lv_obj_t *shezhi_slider_li;
	lv_obj_t *shezhi_wifi_btn;
	lv_obj_t *shezhi_wifi_btn_label;
	lv_obj_t *duogongneng;
	bool duogongneng_del;
	lv_obj_t *duogongneng_cont_all;
	lv_obj_t *duogongneng_heart_btn;
	lv_obj_t *duogongneng_heart_btn_label;
	lv_obj_t *duogongneng_temp_btn;
	lv_obj_t *duogongneng_temp_btn_label;
	lv_obj_t *duogongneng_btn_tianq;
	lv_obj_t *duogongneng_btn_tianq_label;
	lv_obj_t *duogongneng_phone_btn;
	lv_obj_t *duogongneng_phone_btn_label;
	lv_obj_t *duogongneng_music_btn;
	lv_obj_t *duogongneng_music_btn_label;
	lv_obj_t *duogongneng_load_btn;
	lv_obj_t *duogongneng_load_btn_label;
	lv_obj_t *duogongneng_btn_lis;
	lv_obj_t *duogongneng_btn_lis_label;
	lv_obj_t *duogongneng_vol_btn;
	lv_obj_t *duogongneng_vol_btn_label;
	lv_obj_t *duogongneng_light_btn;
	lv_obj_t *duogongneng_light_btn_label;
	lv_obj_t *duogongneng_heart_img;
	lv_obj_t *duogongneng_temp_img;
	lv_obj_t *duogongneng_tinq_img;
	lv_obj_t *duogongneng_load_img;
	lv_obj_t *duogongneng_music_img;
	lv_obj_t *duogongneng_phone_img;
	lv_obj_t *duogongneng_light_img;
	lv_obj_t *duogongneng_vol_img;
	lv_obj_t *duogongneng_img_lis;
	lv_obj_t *duogongneng_btn_txt;
	lv_obj_t *duogongneng_btn_txt_label;
	lv_obj_t *duogongneng_config_btn;
	lv_obj_t *duogongneng_config_btn_label;
	lv_obj_t *duogongneng_connect_btn;
	lv_obj_t *duogongneng_connect_btn_label;
	lv_obj_t *duogongneng_math_btn;
	lv_obj_t *duogongneng_math_btn_label;
	lv_obj_t *duogongneng_connect_img;
	lv_obj_t *duogongneng_config_img;
	lv_obj_t *duogongneng_txt_img;
	lv_obj_t *duogongneng_math_img;
	lv_obj_t *tianqi_page1;
	bool tianqi_page1_del;
	lv_obj_t *tianqi_page1_cont_1;
	lv_obj_t *tianqi_page1_cont_weather2;
	lv_obj_t *tianqi_page1_cont_weather4;
	lv_obj_t *tianqi_page1_cont_weather3;
	lv_obj_t *tianqi_page1_cont_weather5;
	lv_obj_t *tianqi_page1_cont_weather6;
	lv_obj_t *tianqi_page1_cont_weather7;
	lv_obj_t *tianqi_page1_cont_weather1;
	lv_obj_t *tianqi_page1_img_weather5;
	lv_obj_t *tianqi_page1_img_weather4;
	lv_obj_t *tianqi_page1_img_weather2;
	lv_obj_t *tianqi_page1_img_weather3;
	lv_obj_t *tianqi_page1_img_weather1;
	lv_obj_t *tianqi_page1_img_weather7;
	lv_obj_t *tianqi_page1_img_weather6;
	lv_obj_t *tianqi_page1_weektemp1;
	lv_obj_t *tianqi_page1_weektemp2;
	lv_obj_t *tianqi_page1_weektemp3;
	lv_obj_t *tianqi_page1_weektemp7;
	lv_obj_t *tianqi_page1_weektemp6;
	lv_obj_t *tianqi_page1_weektemp4;
	lv_obj_t *tianqi_page1_weektemp5;
	lv_obj_t *tianqi_page1_week_weather;
	lv_obj_t *temp_page;
	bool temp_page_del;
	lv_obj_t *temp_page_img_temp;
	lv_obj_t *temp_page_img_hum;
	lv_obj_t *temp_page_label_hum;
	lv_obj_t *temp_page_label_temp;
	lv_obj_t *light_page;
	bool light_page_del;
	lv_obj_t *light_page_img_sun;
	lv_obj_t *light_page_slider_light;
	lv_obj_t *light_page_light_ctrl;
	lv_obj_t *light_page_pwm_mode;
	lv_obj_t *light_page_dc_mode;
	lv_obj_t *light_page_label_pwm;
	lv_obj_t *light_page_label_dc;
	lv_obj_t *light_page_label_lightmode;
	lv_obj_t *txt_page;
	bool txt_page_del;
	lv_obj_t *txt_page_label_txt;
	lv_obj_t *txt_page_list_txt;
	lv_obj_t *txt_page_list_txt_item0;
	lv_obj_t *connect_page;
	bool connect_page_del;
	lv_obj_t *connect_page_label_wifi_mode;
	lv_obj_t *connect_page_label_mqtt_set;
	lv_obj_t *connect_page_wifi_sw;
	lv_obj_t *connect_page_AP_sw;
	lv_obj_t *connect_page_label_wifi;
	lv_obj_t *connect_page_label_A_P;
	lv_obj_t *connect_page_label_smartconfig;
	lv_obj_t *connect_page_smratconfig_btn;
	lv_obj_t *connect_page_smratconfig_btn_label;
	lv_obj_t *connect_page_label_mqtt_client;
	lv_obj_t *connect_page_mqtt_btn;
	lv_obj_t *connect_page_mqtt_btn_label;
	lv_obj_t *music_list;
	bool music_list_del;
	lv_obj_t *music_list_list_music;
	lv_obj_t *music_list_list_music_item0;
	lv_obj_t *music_list_label_music;
	lv_obj_t *txt_veiw;
	bool txt_veiw_del;
	lv_obj_t *txt_veiw_btn_txt_back;
	lv_obj_t *txt_veiw_btn_txt_back_label;
	lv_obj_t *txt_veiw_cont_txt;
	lv_obj_t *txt_veiw_btn_last;
	lv_obj_t *txt_veiw_btn_last_label;
	lv_obj_t *txt_veiw_btn_next;
	lv_obj_t *txt_veiw_btn_next_label;
	lv_obj_t *txt_veiw_label_txt;
	lv_obj_t *settings_page;
	bool settings_page_del;
	lv_obj_t *settings_page_btn_time_cor;
	lv_obj_t *settings_page_btn_time_cor_label;
	lv_obj_t *settings_page_btn_other;
	lv_obj_t *settings_page_btn_other_label;
	lv_obj_t *settings_page_btn_ps;
	lv_obj_t *settings_page_btn_ps_label;
	lv_obj_t *settings_page_btn_version;
	lv_obj_t *settings_page_btn_version_label;
	lv_obj_t *settings_page_btn_set_back;
	lv_obj_t *settings_page_btn_set_back_label;
	lv_obj_t *heart_page;
	bool heart_page_del;
	lv_obj_t *heart_page_label_freq;
	lv_obj_t *heart_page_chart_heart;
	lv_chart_series_t *heart_page_chart_heart_0;
	lv_obj_t *heart_page_label_freq_num;
	lv_obj_t *heart_page_img_xin;
	lv_obj_t *heart_page_label_last_time;
	lv_obj_t *heart_page_label_mins;
	lv_obj_t *vol_page;
	bool vol_page_del;
	lv_obj_t *vol_page_label_volume;
	lv_obj_t *vol_page_list_device;
	lv_obj_t *vol_page_list_device_item0;
	lv_obj_t *vol_page_label_2;
	lv_obj_t *vol_page_slider_volu;
	lv_obj_t *vol_page_img_volu;
	lv_obj_t *lis_page;
	bool lis_page_del;
	lv_obj_t *lis_page_list_headset;
	lv_obj_t *lis_page_list_headset_item0;
	lv_obj_t *lis_page_label_head;
	lv_obj_t *math_page;
	bool math_page_del;
	lv_obj_t *math_page_btnm_1;
	lv_obj_t *math_page_label_result;
	lv_obj_t *load_page;
	bool load_page_del;
	lv_obj_t *load_page_label_tips;
	lv_obj_t *load_page_cont_1;
	lv_obj_t *load_page_label_load;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
void setup_scr_tianqi_page(lv_ui *ui);
void setup_scr_shezhi(lv_ui *ui);
void setup_scr_duogongneng(lv_ui *ui);
void setup_scr_tianqi_page1(lv_ui *ui);
void setup_scr_temp_page(lv_ui *ui);
void setup_scr_light_page(lv_ui *ui);
void setup_scr_txt_page(lv_ui *ui);
void setup_scr_connect_page(lv_ui *ui);
void setup_scr_music_list(lv_ui *ui);
void setup_scr_txt_veiw(lv_ui *ui);
void setup_scr_settings_page(lv_ui *ui);
void setup_scr_heart_page(lv_ui *ui);
void setup_scr_vol_page(lv_ui *ui);
void setup_scr_lis_page(lv_ui *ui);
void setup_scr_math_page(lv_ui *ui);
void setup_scr_load_page(lv_ui *ui);
LV_IMG_DECLARE(_Goh5hdWXoAAeyeG_alpha_240x280);
LV_IMG_DECLARE(_4afc305c6f5f0a5ea5b41a1f0498f5f7_alpha_240x280);
LV_IMG_DECLARE(_tq1_alpha_123x119);
LV_IMG_DECLARE(_BlurMoment_Gaussian_2025_3_18_17_16_alpha_240x280);
LV_IMG_DECLARE(_sz_alpha_40x40);
LV_IMG_DECLARE(_sz2_alpha_40x40);
LV_IMG_DECLARE(_L_alpha_45x45);
LV_IMG_DECLARE(_l2_alpha_45x45);
LV_IMG_DECLARE(_l2_alpha_45x45);
LV_IMG_DECLARE(_L_alpha_45x45);
LV_IMG_DECLARE(_o_alpha_25x25);
LV_IMG_DECLARE(_WiF01651i_alpha_40x40);
LV_IMG_DECLARE(_WifadasdFi_alpha_40x40);
LV_IMG_DECLARE(_WifadasdFi_alpha_40x40);
LV_IMG_DECLARE(_WiF01651i_alpha_40x40);

LV_IMG_DECLARE(_OIPC_240x280);
LV_IMG_DECLARE(_heart_alpha_35x38);
LV_IMG_DECLARE(_temp_alpha_40x40);
LV_IMG_DECLARE(_cloud_alpha_40x40);
LV_IMG_DECLARE(_nouth_alpha_45x45);
LV_IMG_DECLARE(_music_alpha_40x40);
LV_IMG_DECLARE(_iphone_alpha_40x40);
LV_IMG_DECLARE(_o_alpha_40x40);
LV_IMG_DECLARE(_volu_alpha_40x40);
LV_IMG_DECLARE(_ear_alpha_35x35);
LV_IMG_DECLARE(_conncet_alpha_38x37);
LV_IMG_DECLARE(_sz_alpha_50x50);
LV_IMG_DECLARE(_text_alpha_38x40);
LV_IMG_DECLARE(_math_alpha_35x35);

LV_IMG_DECLARE(_4afc305c6f5f0a5ea5b41a1f0498f5f7_240x280);
LV_IMG_DECLARE(_tq1_alpha_40x35);
LV_IMG_DECLARE(_tq1_alpha_40x35);
LV_IMG_DECLARE(_tq1_alpha_40x35);
LV_IMG_DECLARE(_tq1_alpha_40x35);
LV_IMG_DECLARE(_tq1_alpha_40x35);
LV_IMG_DECLARE(_tq1_alpha_40x35);
LV_IMG_DECLARE(_tq1_alpha_40x35);

LV_IMG_DECLARE(_OIPC_240x280);
LV_IMG_DECLARE(_temp_alpha_61x70);
LV_IMG_DECLARE(_water_alpha_61x70);

LV_IMG_DECLARE(_OIPC_240x280);
LV_IMG_DECLARE(_o_alpha_24x24);

LV_IMG_DECLARE(_OIPC_240x280);

LV_IMG_DECLARE(_OIPC_240x280);

LV_IMG_DECLARE(_OIPC_240x280);

LV_IMG_DECLARE(_OIPC_240x280);

LV_IMG_DECLARE(_OIPC_240x280);

LV_IMG_DECLARE(_OIPC_240x280);
LV_IMG_DECLARE(_heart_alpha_28x26);

LV_IMG_DECLARE(_OIPC_240x280);
LV_IMG_DECLARE(_voll_alpha_21x23);

LV_IMG_DECLARE(_OIPC_240x280);

LV_IMG_DECLARE(_OIPC_240x280);

LV_IMG_DECLARE(_OIPC_240x280);

LV_FONT_DECLARE(lv_font_montserratMedium_28)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Acme_Regular_60)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_AlexBrush_Regular_20)
LV_FONT_DECLARE(lv_font_montserratMedium_36)
LV_FONT_DECLARE(lv_font_montserratMedium_10)
LV_FONT_DECLARE(lv_font_montserratMedium_32)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_Acme_Regular_26)
LV_FONT_DECLARE(lv_font_Abel_regular_20)


#ifdef __cplusplus
}
#endif
#endif
