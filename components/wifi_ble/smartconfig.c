#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_smartconfig.h" // Include header for SmartConfig events
#include "wifi_task.h"

extern SemaphoreHandle_t wifi_semaphore;

void wifi_event_handler(void* event_handler_arg,esp_event_base_t event_base,int32_t event_id,void* event_data)
    {
        if(event_base == WIFI_EVENT)
        {
            switch(event_id)
            {
                case WIFI_EVENT_STA_START:
                    ESP_LOGI("WIFI_EVENT","WIFI_EVENT_STA_START");
                    ESP_ERROR_CHECK(esp_wifi_connect());
                    break;
                case WIFI_EVENT_STA_STOP:
                    ESP_LOGI("WIFI_EVENT","WIFI_EVENT_STA_STOP");
                    break;
                case WIFI_EVENT_STA_DISCONNECTED:
                    ESP_LOGI("WIFI_EVENT","WIFI_EVENT_STA_DISCONNECTED");
                    ESP_ERROR_CHECK(esp_wifi_connect());
                    break;
                case WIFI_EVENT_STA_CONNECTED:
                    ESP_LOGI("WIFI_EVENT","WIFI_EVENT_STA_CONNECTED");
                    if(wifi_semaphore == NULL)
                    {
                        wifi_semaphore = xSemaphoreCreateBinary();
                    }
                    xSemaphoreGive(wifi_semaphore);
                    break;
                default:
                    break;
            }
        }
        else if(event_base == IP_EVENT)
        {
            switch(event_id)
            {
                case IP_EVENT_STA_GOT_IP:
                    ESP_LOGI("IP_EVENT","IP_EVENT_STA_GOT_IP");
                    break;
                default:
                    break;
            }
        }
        else if(event_base == SC_EVENT)
        {
            switch(event_id)
            {
                case SC_EVENT_SCAN_DONE:
                    ESP_LOGI("SC_EVENT","SC_EVENT_SCAN_DONE");
                    break;
                case SC_EVENT_FOUND_CHANNEL:
                    ESP_LOGI("SC_EVENT","SC_EVENT_FOUND_CHANNEL");
                    break;
                case SC_EVENT_GOT_SSID_PSWD:
                    ESP_LOGI("SC_EVENT","SC_EVENT_GOT_SSID_PSWD");
                    smartconfig_event_got_ssid_pswd_t *event = (smartconfig_event_got_ssid_pswd_t *) event_data;
                    wifi_config_t wifi_config = {0};
                    memset(&wifi_config, 0, sizeof(wifi_config));
                    snprintf((char*)wifi_config.sta.ssid, sizeof(wifi_config.sta.ssid), "%s",(char*) event->ssid);
                    snprintf((char*)wifi_config.sta.password, sizeof(wifi_config.sta.password), "%s",(char*) event->password);
                    wifi_config.sta.bssid_set = event->bssid_set;
                    if (event->bssid_set) {
                        memcpy(wifi_config.sta.bssid, event->bssid, sizeof(event->bssid));
                    }
                    nvs_handle_t nvs_handle;
                    ESP_ERROR_CHECK(nvs_open("wifi_config", NVS_READWRITE, &nvs_handle));
                    ESP_ERROR_CHECK(nvs_set_str(nvs_handle, "ssid", (char*)wifi_config.sta.ssid));
                    ESP_ERROR_CHECK(nvs_set_str(nvs_handle, "password", (char*)wifi_config.sta.password));
                    ESP_ERROR_CHECK(nvs_commit(nvs_handle));
                    ESP_LOGI("SC_EVENT", "SSID and password written to NVS successfully");
                    nvs_close(nvs_handle);
                    esp_wifi_disconnect();
                    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
                    esp_wifi_connect();
                    break;
                case SC_EVENT_SEND_ACK_DONE: //通知手机端配置完成
                    ESP_LOGI("SC_EVENT","SC_EVENT_SEND_ACK_DONE");
                    esp_smartconfig_stop(); // Stop SmartConfig
                    break;
                default:
                    break;
            }
        }
    }

void smartconfig_init(void)
{
    static bool init_flag = 0;
    if(init_flag == 0){
        init_flag = 1;
        ESP_ERROR_CHECK(nvs_flash_init());
        ESP_ERROR_CHECK(esp_netif_init());
        
        ESP_ERROR_CHECK(esp_event_loop_create_default()); 
        esp_netif_create_default_wifi_sta(); // Create default Wi-Fi station interface

        wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
        ESP_ERROR_CHECK(esp_wifi_init(&cfg)); // Initialize Wi-Fi with the default configuration

        esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL); // Register Wi-Fi event handler
        esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifi_event_handler, NULL); // Register IP event handler
        esp_event_handler_register(SC_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL); // Register SmartConfig event handler

        ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA)); // Set Wi-Fi mode to station
        ESP_ERROR_CHECK(esp_wifi_start()); // Start Wi-Fi
        esp_smartconfig_set_type(SC_TYPE_ESPTOUCH_AIRKISS); // Set SmartConfig type to ESPTouch     
    }
    smartconfig_start_config_t config = SMARTCONFIG_START_CONFIG_DEFAULT();
    esp_smartconfig_start(&config); // Start SmartConfig
}

