// task_app.h
#ifndef TASK_APP_H  
#define TASK_APP_H 

#include <Arduino.h> 
#include <stdint.h>


extern const int DEBUG_MODE;

extern long rssi;

void State_check_app();
void MQTT_event_app();
void Iot_data_upload_app();


#endif //TASK_APP_H
