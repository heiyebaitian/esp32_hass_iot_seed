#include <WiFi.h>
#include <PubSubClient.h>
#include "MQTT_driver.h"

const int DEBUG_MODE=1;

// WiFi相关配置信息
const char *wifi_ssid = "iotgateway";
const char *wifi_password = "guoxilin";
// MQTT相关配置信息
const char *mqtt_broker_addr = "192.168.1.101"; // MQTT服务器地址
const uint16_t mqtt_broker_port = 1883; // MQTT服务器端口            
const char *mqtt_username = "esp32"; // 账号（非必须）
const char *mqtt_password = "12345678"; // 密码（非必须）
const uint16_t mqtt_client_buff_size = 4096; // 客户端缓存大小（非必须）
String mqtt_client_id = "esp32_client"; // 客户端ID
const char *mqtt_topic_pub = "esp32/test"; // 需要发布到的主题
const char *mqtt_topic_sub = "esp32/test"; // 需要订阅的主题

unsigned long previousConnectMillis = 0; // 毫秒时间记录
const long intervalConnectMillis = 5000; // 时间间隔
unsigned long previousPublishMillis = 0; // 毫秒时间记录
const long intervalPublishMillis = 5000; // 时间间隔

extern WiFiClient tcpClient;
extern PubSubClient mqttClient;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println();
    setup_iot_server();

}

void loop() {
  // put your main code here, to run repeatedly:
    unsigned long currentMillis = millis(); // 读取当前时间
    // 定期发送消息
    if (mqttClient.connected())
    {
        if (currentMillis - previousPublishMillis >= intervalPublishMillis) // 如果和前次时间大于等于时间间隔
        {
            previousPublishMillis = currentMillis;
            mqttClient.publish("esp32/test", "naisu 233~~~");
        }
    }
    Serial.println("OK");
    mqttClient.loop(); // 处理MQTT事务

}
