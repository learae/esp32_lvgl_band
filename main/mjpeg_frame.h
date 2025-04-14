#ifndef _MJPEG_FRAME_H_
#define _MJPEG_FRAME_H_
//jepg图像数据
#include <string.h>
#include <stdint.h>
typedef struct {
    uint8_t *data; // 图像数据
    size_t len;   // 图像数据长度
} mjpeg_frame_t;

typedef struct mjpeg_frame_cfg_t {
    size_t size;   // 图像数据大小
} mjpeg_frame_cfg_t;
{
    /* data */
};

void jpeg_frame_config(mjpeg_frame_cfg_t *cfg);

void jpeg_frame_start(const char *filename);

void jpeg_frame_stop(void);

void jpeg_frame_get_data(mjpeg_frame_t *frame);

#endif 