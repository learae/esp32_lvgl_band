#ifndef SDCARD_H
#define SDCARD_H



int sdcard_filelist(char (**file)[256]);
int sdcard_init(void);

#endif // SDCARD_H