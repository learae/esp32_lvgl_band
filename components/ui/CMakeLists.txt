file(GLOB_RECURSE srcs *.c
                    ui/custom/*.c
                    ui/generated/*.c
                    ui/generated/guider_customer_fonts/*.c
                    ui/generated/guider_fonts/*.c
                    ui/generated/images/*.c
                    )
 
set(include_dirs 
    . 
    )
 
idf_component_register(
    SRC_DIRS .
    SRCS ${srcs}
    INCLUDE_DIRS ${include_dirs}
    REQUIRES lvgl
)