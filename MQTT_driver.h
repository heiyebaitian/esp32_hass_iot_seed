// MQTT_driver.h  
#ifndef MQTT_DRIVER_H  
#define MQTT_DRIVER_H 

#include <Arduino.h> 
#include <stdint.h>
#include <WiFi.h>
#include <PubSubClient.h>

extern const int DEBUG_MODE;

// WiFi相关配置信息
extern const char *wifi_ssid;
extern const char *wifi_password;

// MQTT相关配置信息
extern const char *mqtt_broker_addr; // MQTT服务器地址
extern const uint16_t mqtt_broker_port; // MQTT服务器端口
extern const char *mqtt_username; // 账号（非必须）
extern const char *mqtt_password; // 密码（非必须）
extern const uint16_t mqtt_client_buff_size; // 客户端缓存大小（非必须）
extern String mqtt_client_id; // 客户端ID
extern const char *mqtt_topic_pub; // 需要发布到的主题
extern const char *mqtt_topic_sub; // 需要订阅的主题

extern unsigned long previousConnectMillis; // 毫秒时间记录
extern const long intervalConnectMillis; // 时间间隔
extern unsigned long previousPublishMillis; // 毫秒时间记录
extern const long intervalPublishMillis; // 时间间隔

void setup_wifi();
void setup_MQTT();
void mqtt_callback(char *topic, byte *payload, unsigned int length);
int setup_iot_server();

#endif //MQTT_DRIVER_H
