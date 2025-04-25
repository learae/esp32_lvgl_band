#include "cJSON.h"
#include "esp_log.h"
#include "esp_err.h"
#include "string.h"
#include "cjson_text.h"
#include "esp_ota_ops.h"

const char *get_ota_version(void)
{
    static char version[32] = {0}; // Static buffer to hold the version string
    if(version[0] == '\0') {
        esp_app_desc_t desc;
        esp_err_t ret = esp_ota_get_partition_description(esp_ota_get_running_partition(), &desc);
        if (ret != ESP_OK) {
            ESP_LOGE("OTA", "Failed to get OTA version");
            return NULL;
        }
        snprintf(version, sizeof(version), "%s", desc.version); // Copy the version string to the static buffer
    }
    return version;
}

void cjson_print_key(cJSON *json)
{
    cJSON *item = NULL;
    cJSON_ArrayForEach(item, json)
    {
        if (cJSON_IsObject(item))
        {
            cjson_print_key(item); // Recursively call the function for nested objects
        }
        else if (cJSON_IsArray(item))
        {
            cJSON *array_item = NULL;
            cJSON_ArrayForEach(array_item, item)
            {
                if (cJSON_IsObject(array_item))
                {
                    cjson_print_key(array_item); // Recursively call the function for nested objects
                }
                else if (cJSON_IsString(array_item))
                {
                    ESP_LOGI("cJSON", "Array Item: %s", array_item->valuestring);
                }
                else if (cJSON_IsNumber(array_item))
                {
                    ESP_LOGI("cJSON", "Array Item: %d", array_item->valueint);
                }
                else if (cJSON_IsBool(array_item))
                {
                    ESP_LOGI("cJSON", "Array Item: %s", array_item->valueint ? "true" : "false");
                }
            }
        }
        else
        {
            if (cJSON_IsString(item))
            {
                ESP_LOGI("cJSON", " %s: %s", item->string, item->valuestring);
            }
            else if (cJSON_IsNumber(item))
            {
                ESP_LOGI("cJSON", " %s: %d", item->string, item->valueint);
            }
            else if (cJSON_IsBool(item))
            {
                ESP_LOGI("cJSON", " %s: %s", item->string, item->valueint ? "true" : "false");
            }
        }
    }
    cJSON_Delete(json); // Free the cJSON object
}

void cjson_create(void)
{

    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json, "name", "John Doe");
    cJSON_AddNumberToObject(json, "age", 30);
    cJSON_AddBoolToObject(json, "is_student", 0);
    cJSON *address = cJSON_CreateObject();
    cJSON_AddStringToObject(address, "street", "123 Main St");
    cJSON_AddStringToObject(address, "city", "Anytown");
    cJSON_AddItemToObject(json, "address", address);
    cJSON *phone_numbers = cJSON_CreateArray();
    cJSON_AddItemToArray(phone_numbers, cJSON_CreateString("123-456-7890"));
    cJSON_AddArrayToObject(json, "phone_numbers");
    if (json == NULL)
    {
        ESP_LOGE("cJSON", "Failed to parse JSON");
        return;
    }
    cjson_print_key(json);
}

/// @brief ///

static int s_aliot_id = 0;

ALIOT_DM_DES *aliot_malloc_des(AliotMethod method)
{
    ALIOT_DM_DES *des = malloc(sizeof(ALIOT_DM_DES));
    if (des == NULL)
    {
        ESP_LOGE("ALIOT_DM_DES", "Failed to allocate memory for ALIOT_DM_DES");
        return NULL;
    }
    memset(des, 0, sizeof(ALIOT_DM_DES));
    des->dm_json = cJSON_CreateObject();
    char id[10];
    snprintf(id, sizeof(id), "%d", s_aliot_id); 
    cJSON_AddStringToObject(des->dm_json, "id", id);
    
    const char *version = get_ota_version();

    if(method == POST){
        cJSON_AddStringToObject(des->dm_json, "version", version);
        cJSON_AddStringToObject(des->dm_json, "method", "thing.event.property.post");
        cJSON *params = cJSON_CreateObject();
        cJSON_AddItemToObject(des->dm_json, "params", params);
    }
    else if(method == SET){
        cJSON_AddStringToObject(des->dm_json, "version", version);
        cJSON_AddStringToObject(des->dm_json, "method", "thing.event.property.set");
        cJSON *params = cJSON_CreateObject();
        cJSON_AddItemToObject(des->dm_json, "params", params);
    }
    else if(method == ACK_SUCCESS){
        cJSON_AddStringToObject(des->dm_json, "version", version);
        cJSON_AddItemToObject(des->dm_json, "data", NULL);
        cJSON_AddStringToObject(des->dm_json, "message", "success");
        cJSON_AddNumberToObject(des->dm_json, "code", 200);
    }
    else if(method == ACK_FAIL){
        cJSON_AddStringToObject(des->dm_json, "version", version);
        cJSON_AddItemToObject(des->dm_json, "data", NULL);
        cJSON_AddStringToObject(des->dm_json, "message", "device offline");
        cJSON_AddNumberToObject(des->dm_json, "code", 9201);
    }
    else if(method == OTA_VERSION)
    {
        cJSON *params = cJSON_CreateObject();
        cJSON_AddStringToObject(params, "version", version);
        cJSON_AddItemToObject(des->dm_json, "params", params);
    }
    else if(method == OTA_FILE)
    {
        cJSON_AddNumberToObject(des->dm_json, "code", 200);
        cJSON_AddItemToObject(des->dm_json, "data", NULL);
    }
    else if(method == OTA_GET)
    {
        cJSON_AddItemToObject(des->dm_json, "params", NULL);
        cJSON_AddStringToObject(des->dm_json, "method", "thing.ota.firmware.get");
    }
    else if(method == OTA_PROGRESS)
    {
        cJSON *params = cJSON_CreateObject();
        cJSON_AddStringToObject(params, "step", "-1");
        cJSON_AddItemToObject(des->dm_json, "params", params);
    }
    else{
        ESP_LOGE("ALIOT_DM_DES", "Invalid method type");
        free(des);
        return NULL;
    }
    return des;
}

void aliot_set_dm_int(ALIOT_DM_DES *dm, const char *params, const char *key, int value)
{
    if(dm)
    {
        cJSON *params_json = cJSON_GetObjectItem(dm->dm_json, params);
        if (params_json)
        {
            cJSON_AddNumberToObject(params_json, key, value);
        }
    }
}

void aliot_set_dm_string(ALIOT_DM_DES *dm, const char *params, const char *key, const char *value)
{
    if(dm)
    {
        cJSON *params_json = cJSON_GetObjectItem(dm->dm_json, params);
        if (params_json)
        {
            cJSON_AddStringToObject(params_json, key, value);
        }
    }
}

void aliot_set_dm_bool(ALIOT_DM_DES *dm, const char *params, const char *key, int value)
{
    if(dm)
    {
        cJSON *params_json = cJSON_GetObjectItem(dm->dm_json, params);
        if (params_json)
        {
            cJSON_AddBoolToObject(params_json, key, value);
        }
    }
}

void aliot_set_dm_float(ALIOT_DM_DES *dm, const char *params, const char *key, float value)
{
    if(dm)
    {
        cJSON *params_json = cJSON_GetObjectItem(dm->dm_json, params);
        if (params_json)
        {
            cJSON_AddNumberToObject(params_json, key, value);
        }
    }
}

void aliot_free_dm(ALIOT_DM_DES *dm)
{
    if (dm)
    {
        if (dm->dm_json)
        {
            cJSON_Delete(dm->dm_json);
            dm->dm_json = NULL;
        }
        if (dm->dm_json_str)
        {
            free(dm->dm_json_str);
            dm->dm_json_str = NULL;
        }
        free(dm);
    }
    dm = NULL;
}

void aliot_serialize_dm(ALIOT_DM_DES *dm) // 将JSON对象序列化为字符串
{
    if (dm)
    {
        if(dm->dm_json_str)
        {
            free(dm->dm_json_str);
            dm->dm_json_str = NULL;
        }
        dm->dm_json_str = cJSON_PrintUnformatted(dm->dm_json);
        if (dm->dm_json_str == NULL)
        {
            ESP_LOGE("ALIOT_DM_DES", "Failed to serialize JSON");
            return;
        }
    }
}