idf_component_register(
    SRCS  "st7789_driver.c"  "cst816t_driver.c"
    INCLUDE_DIRS    "."
    REQUIRES    esp_lcd  lvgl  esp_timer
)