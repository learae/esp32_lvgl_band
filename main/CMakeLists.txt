idf_component_register(SRCS "mjpeg_frame.c" "ui.mjpeg.c" "lvgl_port2.c" "lv_port.c" "uiled.c" "ui_temp_hum.c" "ui.mjpeg.c" 
                            "humidity_img.c" "temp_img.c" "mjpeg_frame.c"
                    INCLUDE_DIRS ".")

spiffs_create_partition_image(ui_img ../main/img FLASH_IN_PROJECT)