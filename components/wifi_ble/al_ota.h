#ifndef _al_ota_h
#define _al_ota_h

#include "esp_err.h"

typedef void (*ota_callback_t)(int code);

void al_ota_init(const char *url, ota_callback_t callback);

void al_ota_start(void);

#endif