#include "esp_log.h"
#include "esp_err.h"
#include "esp_https_ota.h"
#include "string.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "al_ota.h"
#include "esp_http_client.h"
#include "esp_crt_bundle.h"

static char aliot_ota_url[256] = {0};

static ota_callback_t ota_callback = NULL;

static bool ota_progress = false;

void ota_task(void *param)
{
    esp_err_t ota_finish_err =ESP_OK;
    //http配置初始化
    ESP_LOGI("OTA", "Starting OTA update");
    esp_http_client_config_t config = {
        .url = aliot_ota_url,
        .timeout_ms = 100000,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .keep_alive_enable =true,
    };

    //ota配置初始化
    esp_https_ota_config_t ota_config = {
        .http_config = &config,
    };

    ota_finish_err = esp_https_ota(&ota_config);

    if(ota_finish_err == ESP_OK)
    {
        ESP_LOGI("OTA", "OTA update successful");
        if(ota_callback)
        {
            ota_callback(0);
        
        vTaskDelay(pdMS_TO_TICKS(1500));
        esp_restart();
        }
        else
        {
            if(ota_callback)
            {
                ota_callback(-1);
            }
        }
        ota_progress = false;
    }

    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void al_ota_init(const char *url, ota_callback_t callback)
{
    snprintf(aliot_ota_url, sizeof(aliot_ota_url), "%s", url);
    ota_callback = callback;
}

void al_ota_start(void)
{
    if(ota_progress)
    {
        ESP_LOGE("OTA", "OTA is already in progress");
        return;
    }
    ota_progress = true;

    xTaskCreatePinnedToCore(ota_task, "ota_task", 8192, NULL, 4, NULL, 1);
}