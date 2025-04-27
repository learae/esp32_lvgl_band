file(GLOB_RECURSE srcs *.c
                    )

idf_component_register(
    SRCS   ${srcs}
    INCLUDE_DIRS "."
    REQUIRES  app_update esp_https_ota esp_partition mbedtls driver freertos esp_wifi nvs_flash
                mqtt json ui
)
