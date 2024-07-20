// MQTT_driver.cpp  
#include "MQTT_driver.h "  


WiFiClient tcpClient;
PubSubClient mqttClient;

void setup_wifi(){
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    if(DEBUG_MODE) Serial.print(".");
  }
  if(DEBUG_MODE){
    Serial.println("[DEBUG]WIFI connect is ok.");
    Serial.print("[DEBUG]IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void setup_MQTT(){
  // 设置MQTT客户端
  mqttClient.setClient(tcpClient);
  mqttClient.setServer(mqtt_broker_addr, mqtt_broker_port);
  //mqttClient.setBufferSize(mqtt_client_buff_size);
  mqttClient.setCallback(mqtt_callback);
  mqtt_client_id += String(WiFi.macAddress()); // 每个客户端需要有唯一的ID，不然上线时会把其他相同ID的客户端踢下线
  if (mqttClient.connect(mqtt_client_id.c_str(), mqtt_username, mqtt_password))
  {
    mqttClient.publish("esp32/state", "online"); // 连接成功后发布状态
    if(DEBUG_MODE)Serial.println("[DEBUG]MQTT连接成功！");
  }
  if(DEBUG_MODE)Serial.println("[DEBUG]MQTT正在连接...");
}


// MQTT消息回调函数
void mqtt_callback(char *topic, byte *payload, unsigned int length)
{
    if(DEBUG_MODE){
      Serial.printf("[DEBUG]Message arrived in topic %s, length %d\n", topic, length);
      Serial.print("[DEBUG]Message:");
    }
    for (int i = 0; i < length; i++)
    {
        if(DEBUG_MODE)Serial.print((char)payload[i]);
    }
    if(DEBUG_MODE)Serial.println("\n[DEBUG]----------------END----------------");
}

int setup_iot_server(){
  if(DEBUG_MODE) Serial.printf("\n[DEBUG]WIFI Connecting to %s", wifi_ssid);
  setup_wifi();
  setup_MQTT();
  return 1;
}
