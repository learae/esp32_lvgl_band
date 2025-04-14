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

static jpeg_frame_cfg_t s_jpeg_frame_cfg = {0};

static int mjpeg_inited = 0;
static int mjpeg_stared = 0;


void jpeg_frame_config(mjpeg_frame_cfg_t *cfg)
{
    if(cfg->size<4096)
    {
        ESP_LOGE(TAG, "jpeg_frame_config cfg size is too small");
        return;
    }
    memcpy(&s_jpeg_frame_cfg, cfg, sizeof(mjpeg_frame_cfg_t));
    mjpeg_inited = 1;
}

void jpeg_frame_task(void *arg)
{
    char *filename = (char *)arg;
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        ESP_LOGE(TAG, "jpeg_frame_task: open file %s failed", filename);
        return;
    }
    mjpeg_stared = 1;
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
    int jpeg_strat=0,g_strat=0,g_end=0,g_noread=0;
    
    while (read_bytes = fread(buffer, 1, s_jpeg_frame_cfg.size, fp)>0) {
        for(size_t i = 0; i < read_bytes; i++) {
            if (buffer[i] == JPEG_START & jpeg_strat == 0) {
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
                    ESP_LOGI(TAG, "jpeg_frame_task: get jpeg frame, size: %zu", total_size);
                    free(frame_buffer);
                }
            }
            else if(buffer[i] == JPEG_START && jpeg_strat == 1 && g_noread == 1) {
                g_noread = 0;
                g_end = i;
                frame_len = g_end + 1;
                if(frame_len > 0) {
                    frame_buffer = realloc(frame_buffer, frame_len+total_size);
                    if(frame_buffer == NULL) {
                        ESP_LOGE(TAG, "jpeg_frame_task: malloc frame_buffer failed");
                        break;
                    }
                    memcpy(frame_buffer, &buffer[g_start], frame_len);
                    total_size += frame_len;
                    ESP_LOGI(TAG, "jpeg_frame_task: get jpeg frame, size: %zu", total_size);
                    free(frame_buffer);
                }
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
                ESP_LOGI(TAG, "jpeg_frame_task: get jpeg frame, size: %zu", total_size);
            }
        }
        if(g_noread==0)
        {
            jpeg_frame_t frame_date;
            frame_date.data = frame_buffer;
            frame_date.len = total_size;
        }
}
}

void jpeg_frame_start(const char *filename);
{
    if(!mjpeg_inited) {
        ESP_LOGE(TAG, "jpeg_frame_start: mjpeg not inited");
        return;
    }
    if(mjpeg_stared) {
        ESP_LOGE(TAG, "jpeg_frame_start: mjpeg already started");
        return;
    }
    static char jpeg_file[256] = {0};
    snprintf(jpeg_file, sizeof(jpeg_file), "%s", filename);
    xTaskCreatepinnedToCore(jpeg_frame_task, "jpeg_frame_task", 4096, jpeg_file, 6, NULL, 1);
}

void jpeg_frame_stop(void);

void jpeg_frame_get_data(mjpeg_frame_t *frame);