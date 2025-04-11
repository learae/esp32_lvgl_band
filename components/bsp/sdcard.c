#include "esp_err.h"
#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"
#include "esp_log.h"
#include "driver/sdmmc_host.h"
#include "driver/gpio.h"
#include "dirent.h"

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
    //注意：传入的指针必须是一个二维数组，第一维大小足够大，第二维大小为256
int sdcard_filelist(char (**file)[256])
    
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
        if (entry->d_type == DT_REG) { //如果是文件
            snprintf((*file)[count], 256, "%s", entry->d_name); //将文件名存入数组
            count++;
        }
    }

    closedir(dir);
    return count;

}