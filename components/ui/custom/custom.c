/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom/custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

void clock_count_12(int *hour, int *min, int *sec, char *meridiem) {
    static int last_hour = 0;
    if(++last_hour==30){ *sec += 1;last_hour=0; }
    if (*sec >= 60) { *sec = 0; *min += 1; }
    if (*min >= 60) { *min = 0; *hour += 1; }
    if (*hour > 12) {
        *hour = 1;
    }
    // AM/PM 切换逻辑
    if (*hour == 12 && *min == 0 && *sec == 0) {
        if (strcmp(meridiem, "AM") == 0) {
            strcpy(meridiem, "PM");
        } else {
            strcpy(meridiem, "AM");
        }
    }
}


lv_obj_t *lv_dclock_create(lv_obj_t *parent, const char *init_text)
{
    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, init_text ? init_text : "00:00:00");
    // 可根据需要设置样式
    return label;
}

void lv_dclock_set_text_fmt(lv_obj_t *obj, const char *fmt, ...)
{
    char buf[32];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    lv_label_set_text(obj, buf);
}
