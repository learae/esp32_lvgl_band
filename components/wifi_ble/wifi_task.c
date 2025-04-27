#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_err.h"
#include "mqtt_client.h"
#include "freertos/semphr.h"
#include "mbedtls/md5.h"
#include "mbedtls/md.h"
#include "cjson_text.h"
#include "al_ota.h"
#include "smartconfig.h"



#define MQTT_PORT 1883
#define MQTT_HOST "mqtt://iot-06z00aum8d7gatw.mqtt.iothub.aliyuncs.com"
#define MQTT_USER "esp01&k1xujoU2Xot"
#define MQTT_PASS "b3494dd044d3350ea1c2f61029654cb5c5aff1602c0b5472263a9caf58fea02d"
#define MQTT_CLIENT_ID "k1xujoU2Xot.esp01|securemode=2,signmethod=hmacsha256,timestamp=1744808842488|"

#define PRODUCT_KEY "k1xujoU2Xot"
#define DEVICE_NAME "esp01"
#define DEVICE_SECRET "4a215c5dfa76bcf8e45a730265800c01"

#define MQTT_TOPIC_TEST "k1xujoU2Xot/esp01/user/update"
#define MQTT_TOPIC_TH "/sys/k1xujoU2Xot/esp01/thing/event/property/post"
#define MQTT_TOPIC_OTA_VERSION "/ota/device/inform/k1xujoU2Xot/esp01"
#define MQTT_TOPIC_OTA "/ota/device/upgrade/k1xujoU2Xot/esp01"
#define MQTT_TOPIC_OTA_PROGRESS "/ota/device/progress/k1xujoU2Xot/esp01"
#define MQTT_TOPIC_OTA_GET "/sys/k1xujoU2Xot/esp01/thing/ota/firmware/get"

SemaphoreHandle_t wifi_semaphore = NULL;

static SemaphoreHandle_t smartconfig_semaphore = NULL;

QueueHandle_t temp_hum_queue = NULL;

static esp_mqtt_client_handle_t client = NULL;

static float temp_hum_data[2] = {0};
/*void wifi_event_handler(void* event_handler_arg,esp_event_base_t event_base,int32_t event_id,void* event_data)
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
    }*/
    
extern void wifi_event_handler(void* event_handler_arg,esp_event_base_t event_base,int32_t event_id,void* event_data);

void wifi_simple_config(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    
    ESP_ERROR_CHECK(esp_event_loop_create_default()); 
    esp_netif_create_default_wifi_sta(); // Create default Wi-Fi station interface

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg)); // Initialize Wi-Fi with the default configuration

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL); // Register Wi-Fi event handler
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifi_event_handler, NULL); // Register IP event handler

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = "hcc.",
            .password = "12345hcc",

            .pmf_cfg = {
                .capable = true,   //是否启用保护管理帧
                .required = false, //是否只和支持保护管理帧的设备连接
            },
            .threshold = {
                .authmode = WIFI_AUTH_WPA2_PSK,
            },
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA)); // Set Wi-Fi mode to station
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config)); // 第一个参数是接口类型（网卡），第二个参数是配置
    ESP_ERROR_CHECK(esp_wifi_start()); // Start Wi-Fi
}

void al_ota_callback(int code)
{
    ESP_LOGI("OTA", "OTA callback executed");
    ALIOT_DM_DES *dm = aliot_malloc_des(OTA_PROGRESS);
    if (code == 0)
    {
        aliot_set_dm_string(dm, "params", "desc", "success");
    }
    else
    {
        aliot_set_dm_string(dm, "params", "desc", "fail");
    }
    aliot_serialize_dm(dm);
    esp_mqtt_client_publish(client, MQTT_TOPIC_OTA_PROGRESS, dm->dm_json_str, 0, 1, 0);
    aliot_free_dm(dm);
}


void   mqtt_event_handler(void* event_handler_arg,esp_event_base_t event_base,int32_t event_id,void* event_data)
{
    esp_mqtt_event_handle_t data = (esp_mqtt_event_handle_t)event_data;
    switch (event_id) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI("MQTT_EVENT", "MQTT_EVENT_CONNECTED");
            esp_mqtt_client_subscribe(client, MQTT_TOPIC_TEST, 0); // Subscribe to a topic
            esp_mqtt_client_subscribe(client, MQTT_TOPIC_TH, 0); // Subscribe to another topic
            esp_mqtt_client_subscribe(client, MQTT_TOPIC_OTA_VERSION, 0); // Subscribe to OTA version topic
            esp_mqtt_client_subscribe(client, MQTT_TOPIC_OTA, 0); // Subscribe to OTA topic
            esp_mqtt_client_subscribe(client, MQTT_TOPIC_OTA_PROGRESS, 0); // Subscribe to OTA progress topic
            esp_mqtt_client_subscribe(client, MQTT_TOPIC_OTA_GET, 0); // Subscribe to OTA get topic
            char hello[64];
            snprintf(hello, sizeof(hello), "Hello from ESP32 %s", get_ota_version());
            esp_mqtt_client_publish(client, MQTT_TOPIC_TEST, hello, 0, 0, 0); // Publish a message
            break;
            case MQTT_EVENT_DISCONNECTED:
            ESP_LOGI("MQTT_EVENT", "MQTT_EVENT_DISCONNECTED");
            esp_mqtt_client_reconnect(client); // Reconnect to the MQTT broker
            break;
        case MQTT_EVENT_SUBSCRIBED:
            ESP_LOGI("MQTT_EVENT", "MQTT_EVENT_SUBSCRIBED");
            break;
        case MQTT_EVENT_UNSUBSCRIBED:
            ESP_LOGI("MQTT_EVENT", "MQTT_EVENT_UNSUBSCRIBED");
            break;
        case MQTT_EVENT_PUBLISHED:
            ESP_LOGI("MQTT_EVENT", "MQTT_EVENT_PUBLISHED");
            break;
        case MQTT_EVENT_DATA:
            ESP_LOGI("MQTT_EVENT", "MQTT_EVENT_DATA");
            ESP_LOGI("MQTT_EVENT", "Topic: %.*s", data->topic_len, data->topic);
            ESP_LOGI("MQTT_EVENT", "Data: %.*s", data->data_len, data->data);
            if(strstr(data->topic, MQTT_TOPIC_OTA) != NULL)
            {
                ESP_LOGI("MQTT_EVENT", "Received OTA message");
                cJSON *json = cJSON_Parse(data->data);
                cJSON *params = cJSON_GetObjectItem(json, "data");
                cJSON *url = cJSON_GetObjectItem(params, "url");
                if (params == NULL) {
                    ESP_LOGE("MQTT_EVENT", "Failed to get 'date' from JSON");
                    cJSON_Delete(json);
                    return;
                }
                if(url)
                {
                    ESP_LOGI("MQTT_EVENT", "OTA URL: %s", cJSON_GetStringValue(url));
                    al_ota_init(cJSON_GetStringValue(url), al_ota_callback);
                    al_ota_start();
                }
            }
            break;
        default:
            break;
    }
}

void mqtt_start(void)
{
    if (xSemaphoreTake(wifi_semaphore, portMAX_DELAY) == pdTRUE) {
        ESP_LOGI("MQTT_EVENT", "Wi-Fi connected");
    } else {
        ESP_LOGE("MQTT_EVENT", "Wi-Fi connection failed");
        return;
    }
    esp_mqtt_client_config_t mqtt_cfg = {0};
    mqtt_cfg.broker.address.uri = MQTT_HOST;
    mqtt_cfg.broker.address.port = MQTT_PORT;
    mqtt_cfg.credentials.client_id = MQTT_CLIENT_ID;
    mqtt_cfg.credentials.username = MQTT_USER;
    mqtt_cfg.credentials.authentication.password = MQTT_PASS;

    client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, MQTT_EVENT_ANY, mqtt_event_handler, client);
    esp_mqtt_client_start(client);
}

void give_temp_hum(float *temp, int16_t *hum)
{
    float temp_hum[2] = {0};
    temp_hum[0] = *temp;
    temp_hum[1] = (float)*hum;
    if(temp_hum_queue == NULL) {
        ESP_LOGE("WIFI_EVENT", "Temperature and humidity queue is not initialized");
        return;
    }
    if (xQueueSend(temp_hum_queue, temp_hum, 0) != pdTRUE) {
        ESP_LOGE("WIFI_EVENT", "Failed to send temperature and humidity data to queue");
    }
}

//上报温度
void push_temp_hum(float temp, int16_t hum)
{
    ALIOT_DM_DES *dm = aliot_malloc_des(POST);
    if (dm == NULL) {
        ESP_LOGE("MQTT_EVENT", "Failed to allocate memory for ALIOT_DM_DES");
        return;
    }
    aliot_set_dm_float(dm,"params", "temp", temp);
    aliot_set_dm_int(dm,"params", "hum", hum);
    aliot_serialize_dm(dm);
    esp_mqtt_client_publish(client, MQTT_TOPIC_TH, dm->dm_json_str, 0, 0, 0);
    aliot_free_dm(dm);
}

//上报版本号
void ota_version_imform(void)
{
    ALIOT_DM_DES *dm = aliot_malloc_des(OTA_VERSION);
    if (dm == NULL) {
        ESP_LOGE("MQTT_EVENT", "Failed to allocate memory for ALIOT_DM_DES");
        return;
    }
    aliot_serialize_dm(dm);
    esp_mqtt_client_publish(client, MQTT_TOPIC_OTA_VERSION, dm->dm_json_str, 0, 0, 0);
    aliot_free_dm(dm);
}

void wifi_task(void)
{
    if (wifi_semaphore == NULL) {
        wifi_semaphore = xSemaphoreCreateBinary();
    }
    if (smartconfig_semaphore == NULL) {
        smartconfig_semaphore = xSemaphoreCreateBinary();
    }
    if (temp_hum_queue == NULL) {
        temp_hum_queue = xQueueCreate(10, sizeof(temp_hum_data)); // Create a queue for temperature and humidity data
    }
    wifi_simple_config();
    mqtt_start();

    while (1) {
        wifi_mode_t mode;
        if (esp_wifi_get_mode(&mode) == ESP_OK) {
            if (mode == WIFI_MODE_NULL) {
                ESP_LOGI("WIFI_EVENT", "WiFi is OFF");
                vTaskDelay(pdMS_TO_TICKS(100));
                continue;
            } else {
                
            }
        } else {
            ESP_LOGE("WIFI_EVENT", "Failed to get WiFi mode");
            vTaskDelay(pdMS_TO_TICKS(100));
            continue;
        }

        if (xSemaphoreTake(smartconfig_semaphore, pdMS_TO_TICKS(100)) == pdTRUE) {
            ESP_LOGI("WIFI_EVENT", "SmartConfig started");
            smartconfig_init();
        }

        if (xQueueReceive(temp_hum_queue, temp_hum_data, pdMS_TO_TICKS(100)) == pdTRUE) {
            float temp = temp_hum_data[0];
            int16_t hum = (int16_t)temp_hum_data[1];
            push_temp_hum(temp, hum);
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void wifi_mqtt_stop(void)
{
    if(esp_mqtt_client_stop(client)==1)
    {
        vTaskDelay(pdMS_TO_TICKS(10));
        esp_wifi_stop();
    }
}

void wifi_mqtt_start(void)
{
    esp_mqtt_client_start(client);
    esp_wifi_start();
}