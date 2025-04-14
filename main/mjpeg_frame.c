#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mjpeg_frame.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define TAG "MJPEG_FRAME"

#define JPEG_START 0xFF
#define JPEG_END 0xD9

#define JPEG_START_STR BIT0
#define JPEG_STOP_STR BIT1

static mjpeg_frame_cfg_t s_jpeg_frame_cfg = {0};

static int mjpeg_inited = 0;
static int mjpeg_started = 0;

QueueHandle_t mjpeg_queue = NULL;
EventGroupHandle_t mjpeg_event_group = NULL;

void jpeg_frame_config(mjpeg_frame_cfg_t *cfg)
{
    if(cfg->size<4096)
    {
        ESP_LOGE(TAG, "jpeg_frame_config cfg size is too small");
        return;
    }
    memcpy(&s_jpeg_frame_cfg, cfg, sizeof(mjpeg_frame_cfg_t));
    mjpeg_inited = 1;

    mjpeg_queue = xQueueCreate(5, sizeof(mjpeg_frame_t));
    mjpeg_event_group = xEventGroupCreate();
}

void jpeg_frame_task(void *arg)
{
    char *filename = (char *)arg;
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        ESP_LOGE(TAG, "jpeg_frame_task: open file %s failed", filename);
        return;
    }
    mjpeg_started = 1;
    uint8_t *buffer = malloc(s_jpeg_frame_cfg.size);
    if(buffer == NULL) {
        ESP_LOGE(TAG, "jpeg_frame_task: malloc buffer failed");
        fclose(fp);
        return;
    }
    size_t read_bytes = 0;
    uint8_t *frame_buffer = NULL;
    size_t frame_len = 0;
    size_t total_size = 0;
    int jpeg_strat=0,g_start=0,g_end=0,g_noread=0;
    
    while ((read_bytes = fread(buffer, 1, s_jpeg_frame_cfg.size, fp)) > 0) {
        for(size_t i = 0; i < read_bytes; i++) {
            if (buffer[i] == JPEG_START && jpeg_strat == 0) {
                jpeg_strat = 1;
                g_start = i;
            }
            else if
                (buffer[i] == JPEG_END && jpeg_strat == 1 && g_noread == 0) {
                jpeg_strat = 0;
                g_end = i;
                frame_len = g_end - g_start + 1;
                if(frame_len > 0) {
                    frame_buffer = malloc(frame_len);
                    if(frame_buffer == NULL) {
                        ESP_LOGE(TAG, "jpeg_frame_task: malloc frame_buffer failed");
                        break;
                    }
                    memcpy(frame_buffer, &buffer[g_start], frame_len);
                    total_size = frame_len;
                  
                }
            }
            else if(buffer[i] == JPEG_START && jpeg_strat == 1 && g_noread == 1) {
                jpeg_strat = 0;
                g_noread = 0;
                g_end = i;
                frame_len = g_end + 1;
                if(frame_len > 0) {
                    frame_buffer = realloc(frame_buffer, frame_len+total_size);
                    if(frame_buffer == NULL) {
                        ESP_LOGE(TAG, "jpeg_frame_task: malloc frame_buffer failed");
                        break;
                    }
                    memcpy(&frame_buffer[total_size], &buffer[g_start], frame_len);
                    total_size += frame_len;

                }
            }
        
            if (jpeg_strat == 1) {
                g_noread = 1;
                frame_len = read_bytes - g_start;
                if(frame_len > 0) {
                    frame_buffer = malloc(frame_len);
                    if(frame_buffer == NULL) {
                        ESP_LOGE(TAG, "jpeg_frame_task: malloc frame_buffer failed");
                        break;
                    }
                    memcpy(frame_buffer, &buffer[g_start], frame_len);
                    total_size = frame_len;
                }
            }
            if(g_noread==0)
            {
                mjpeg_frame_t frame_date;
                frame_date.data = frame_buffer;
                frame_date.len = total_size;
                EventBits_t event = xEventGroupWaitBits(mjpeg_event_group, JPEG_START_STR|JPEG_STOP_STR, pdTRUE, pdFALSE, portMAX_DELAY);
                if(event & JPEG_START_STR) 
                {
                    xQueueSend(mjpeg_queue, &frame_date, portMAX_DELAY);  
                    frame_buffer = NULL;
                    total_size = 0;
                    g_start = 0;
                    g_end = 0;
                }
                else if(event & JPEG_STOP_STR) 
                {
                    free(frame_buffer);
                    if(fp)
                        fclose(fp);
                    vTaskDelete(NULL);
                }
            }
        }
    }
    if(fp)
            fclose(fp);
        vTaskDelete(NULL);
}


void jpeg_frame_start(const char *filename)
{
    if(!mjpeg_inited) {
        ESP_LOGE(TAG, "jpeg_frame_start: mjpeg not inited");
        return;
    }
    if(mjpeg_started) {
        ESP_LOGE(TAG, "jpeg_frame_start: mjpeg already started");
        return;
    }
    static char jpeg_file[256] = {0};
    snprintf(jpeg_file, sizeof(jpeg_file), "%s", filename);
    xTaskCreatePinnedToCore(jpeg_frame_task, "jpeg_frame_task", 4096, jpeg_file, 6, NULL, 1);
}

void jpeg_frame_stop(void)
{
    xEventGroupSetBits(&mjpeg_event_group, JPEG_STOP_STR);
}


void jpeg_frame_get_data(mjpeg_frame_t *frame)
{
    if(!mjpeg_inited) {
        ESP_LOGE(TAG, "jpeg_frame_get_data: mjpeg not inited");
        return;
    }
    if(!mjpeg_started) {
        ESP_LOGE(TAG, "jpeg_frame_get_data: mjpeg not started");
        return;
    }
    xEventGroupWaitBits(mjpeg_event_group, JPEG_START_STR, pdTRUE, pdFALSE, portMAX_DELAY);
    mjpeg_frame_t frame_date;
    if(xQueueReceive(mjpeg_queue, &frame_date, pdMS_TO_TICKS(1000)) == pdTRUE) {
        ESP_LOGI(TAG, "jpeg_frame_get_data: get data %d", frame_date.len);
       *frame = frame_date;
    } 
    else {
        ESP_LOGE(TAG, "jpeg_frame_get_data: get data failed");
        frame->data = NULL;
        frame->len = 0;
    }
}