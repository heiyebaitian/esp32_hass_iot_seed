// task_app.cpp
#include "task_app.h"
#include "MQTT_driver.h"  //  MQTT驱动


// 连接状态检查任务 程序
void State_check_app(){
    connect_check();  //  连接状态检查
    // 定期发送消息
    if (mqttClient.connected())
    {
            previousPublishMillis = currentMillis;
            mqttClient.publish("esp32/state", "online");
    }
    if(DEBUG_MODE)Serial.println("[DEBUG]Connect state OK!");
}


// MQTT事物任务 程序
void MQTT_event_app(){
    mqttClient.loop(); // 处理MQTT事务
}
