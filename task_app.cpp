// task_app.cpp
#include "task_app.h"
#include "MQTT_driver.h"  //  MQTT驱动


/* 连接状态检查任务程序 */
void State_check_app(){
    connect_check();  //  连接状态检查
    // 定期发送消息
    if (mqttClient.connected())
    {
            previousPublishMillis = currentMillis;
            mqttClient.publish("esp32/state", "online");
            mqttClient.publish("esp32/normalization/state", "online");
            mqttClient.publish("esp32/differentiation/state", "online");
            mqttClient.publish("esp32/mechanical_arm/state", "online");
    }
    if(DEBUG_MODE)Serial.println("[DEBUG]Connect state OK!");
}


/* MQTT事物任务程序 */
void MQTT_event_app(){
    mqttClient.loop(); // 处理MQTT事务
}


/* Iot数据上传任务程序 */
void Iot_data_upload_app(){
  // WIFI状态 RSSI值
  String rssi_string = "{\"RSSI\":" + String(rssi) + "}";
  mqttClient.publish("esp32/system/wifi",rssi_string.c_str());
  if(DEBUG_MODE)Serial.println("[DEBUG]Iot data upload finish！");
}
