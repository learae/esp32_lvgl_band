#ifndef CJSON_TEXT_H
#define CJSON_TEXT_H

#include "cJSON.h"

typedef enum {
    POST = 0,
    SET = 1,
    ACK_SUCCESS = 2,
    ACK_FAIL = 3,
    OTA_PROGRESS = 4,
    OTA_VERSION = 5,
    OTA_FILE = 6,
    OTA_GET = 7,
    NTP_TIME_GET = 8,
} AliotMethod;

typedef struct {
    cJSON *dm_json;
    char *dm_json_str;
} ALIOT_DM_DES;

void cjson_create(void);

void cjson_print_key(cJSON *json);

ALIOT_DM_DES *aliot_malloc_des(AliotMethod method);

void aliot_set_dm_int(ALIOT_DM_DES *dm, const char *params, const char *key, int value);
void aliot_set_dm_string(ALIOT_DM_DES *dm, const char *params, const char *key, const char *value);
void aliot_set_dm_bool(ALIOT_DM_DES *dm, const char *params, const char *key, int value);
void aliot_set_dm_float(ALIOT_DM_DES *dm, const char *params, const char *key, float value);

void aliot_free_dm(ALIOT_DM_DES *dm);

void aliot_serialize_dm(ALIOT_DM_DES *dm);

const char *get_ota_version(void);



#endif // CJSON_TEXT_H