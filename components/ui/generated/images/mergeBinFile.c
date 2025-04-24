/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"

#if LV_USE_FS_RAWFS

const rawfs_size_t rawfs_file_count = 9;
rawfs_file_t rawfs_files[9] = {
	0x0, 0, 6079, "/L.bin",
	0x17bf, 0, 6079, "/l2.bin",
	0x2f7e, 0, 6079, "/l2.bin",
	0x473d, 0, 6079, "/L.bin",
	0x5efc, 0, 4804, "/WiF01651i.bin",
	0x71c0, 0, 4804, "/WifadasdFi.bin",
	0x8484, 0, 4804, "/WifadasdFi.bin",
	0x9748, 0, 4804, "/WiF01651i.bin",
	0xaa0c, 0, 4804, "/temp.bin",

};

#endif  /*LV_USE_FS_RAWFS*/ 