#ifndef WIFI_TASK_H
#define WIFI_TASK_H


void wifi_task(void);

void give_temp_hum(float *temp, int16_t *hum);

void wifi_mqtt_stop(void);

void wifi_mqtt_start(void);

#endif 