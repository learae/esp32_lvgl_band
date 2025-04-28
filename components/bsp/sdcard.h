#ifndef SDCARD_H
#define SDCARD_H



int sdcard_filelist(char flie[][50]);
int sdcard_init(void);
char* read_dir(const char *name, int readflow);

#endif // SDCARD_H