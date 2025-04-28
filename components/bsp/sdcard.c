#include "esp_err.h"
#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"
#include "esp_log.h"
#include "driver/sdmmc_host.h"
#include "driver/gpio.h"
#include "dirent.h"
#include "string.h"

int sdcard_init(void)
{
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 8 * 1024,
    };
    sdmmc_card_t *card;
    sdmmc_host_t host = SDMMC_HOST_DEFAULT(); // 主机默认配置
    host.max_freq_khz = SDMMC_FREQ_HIGHSPEED; // 最高频率

    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT(); // 插槽
    slot_config.width = 4; // 4 位数据线

    esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card); // 挂载 SD 卡
    if (ret == ESP_OK) {
        ESP_LOGI("SDCARD", "SD Card mounted successfully");
        return ESP_OK; // 返回成功
    } else {
        ESP_LOGE("SDCARD", "Failed to mount SD Card: %s", esp_err_to_name(ret));
        return ESP_FAIL; // 返回失败
    }
}

//列出SD卡中的文件
    //传入的指针是一个二维数组，第一维是文件数量，第二维是文件名长度
    //返回值是文件数量
    //注意：传入的指针必须是一个二维数组，第一维大小足够大，第二维大小为50
int sdcard_filelist(char file[][50])
{
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir("/sdcard");
    if (dir == NULL) {
        ESP_LOGE("SDCARD", "Failed to open directory");
        return -1;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            snprintf(file[count], 50, "%.49s", entry->d_name);
            count++;
        }
    }
    closedir(dir);
    return count;
}


char* read_dir(const char *name, int readflow)
{
    static int i = 1;
    static char flie_name[50] = {0}; 
    char *buffer = malloc(101); // Allocate memory dynamically
    ESP_LOGI("TXT_PAGE", "Button clicked: %s", name);
    if (strstr(name, "flow") && readflow == 1)
    {
        i+=100;
    }
    else if(strstr(name, "flow") && readflow == -1)
    {
        i-=100;
        if (i < 1) {
            i = 1; // Reset to 1 if it goes below 1
        }
    }
    else if(strstr(name, "flow")==NULL&&readflow == 1)
    {
        i = 1;
        strncpy(flie_name, name, sizeof(flie_name) - 1);
        flie_name[sizeof(flie_name) - 1] = '\0'; // Ensure null termination
        ESP_LOGI("TXT_PAGE", "flie: %s", flie_name);
    }
    

    if (buffer == NULL) {
        ESP_LOGE("SDCARD", "Failed to allocate memory");
        return "NULL";
    }
    memset(buffer, 0, 101); // Initialize memory
    char filepath[101];
    snprintf(filepath, sizeof(filepath), "/sdcard/%s", flie_name);
    FILE *file = fopen(filepath, "r");
    if (file) {
        fseek(file, i, SEEK_SET); // Move the file pointer to the specified position
        size_t bytesRead = fread(buffer, 1, 100, file);
        buffer[bytesRead] = '\0'; // Ensure null termination
        ESP_LOGI("SDCARD", "Read content: %s", buffer);
        fclose(file);
    } else {
        ESP_LOGE("SDCARD", "Failed to open file: %s", filepath);
        free(buffer); // Free allocated memory in case of failure
        return "NULL";
    }
    return buffer;
}