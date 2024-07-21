// task_app.h
#ifndef TASK_APP_H  
#define TASK_APP_H 

#include <Arduino.h> 
#include <stdint.h>


extern const int DEBUG_MODE;

/* 系统运行数据 */
extern long rssi;
/* 传感器数据记录 */
// 常态化培养区
extern int temperature_normalization; // 常态化培养区温度
extern uint16_t humidity_normalization; // 常态化培养区湿度
extern uint16_t sh_normalization; // 常态化培养区土壤湿度
extern uint16_t co2_normalization; // 常态化培养区二氧化碳
extern uint16_t ch2o_normalization; // 常态化培养区甲醛
extern uint16_t tvoc_normalization; // 常态化培养区TVOC
extern int fan_status_normalization; // 常态化培养区通风系统状态
extern int light_status_normalization; // 常态化培养区光照系统状态

// 差异化培养区
extern int temperature_differentiation; // 差异化培养区温度
extern uint16_t humidity_differentiation; // 差异化培养区湿度
extern uint16_t sh_differentiation; // 差异化培养区土壤湿度
extern uint16_t co2_differentiation; // 差异化培养区二氧化碳
extern uint16_t ch2o_differentiation; // 差异化培养区甲醛
extern uint16_t tvoc_differentiation; // 差异化培养区TVOC
extern int fan_status_differentiation; // 差异化培养区风扇状态
extern int light_status_differentiation; // 差异化培养区光照系统状态

void State_check_app();
void MQTT_event_app();
void Iot_data_upload_app();


#endif //TASK_APP_H
