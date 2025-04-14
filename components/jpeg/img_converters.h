// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef _IMG_CONVERTERS_H_
#define _IMG_CONVERTERS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "esp_jpg_decode.h"

typedef size_t (* jpg_out_cb)(void * arg, size_t index, const void* data, size_t len);

bool jpg2rgb565(const uint8_t *src, size_t src_len, uint8_t ** out,uint16_t* width,uint16_t* height, jpg_scale_t scale);

#ifdef __cplusplus
}
#endif

#endif /* _IMG_CONVERTERS_H_ */
