# esp32_hass_iot_seed

 基于Aiot-NLP的智能育种箱 代码,该存储库包含了ESP32S3控制器代码及Home Assistant(下面简称HASS)配置文件。
 该代码无法独立使用,请注意!

## 功能介绍

本项目基于 **HASS** 框架重写,添加了许多v1版本不支持的功能,并改进修复了v1版本存在的大量问题
项目采用主流Iot服务框架HASS,配合MQTT通讯协议实现,您在复现本项目时可能需要完成HASS和MQTT代理服务器的搭建,由于篇幅有限,本文档不再对此过程进行描述。

### 全新设计的仪表盘界面

基于HASS框架的现代化UI风格全新设计的界面,适合触屏、鼠标点击等多种方式交互,支持不同屏幕大小的自适应缩放适配,多主题配色自定义支持,提供用户友好型交互和客制化风格体验,拥有比上一代更加优秀的人机交互体验。

![](https://github.com/heiyebaitian/esp32_hass_iot_seed/blob/main/public/image/home-1.png)
![](https://github.com/heiyebaitian/esp32_hass_iot_seed/blob/main/public/image/home-2.png)
![](https://github.com/heiyebaitian/esp32_hass_iot_seed/blob/main/public/image/home-phone.png)


### 优雅的动效与图表数据呈现
基于WebUI设计的控件为智能化育种管理平台带来了全新流畅的优雅动效设计与丰富的控件功能,数据可以不再以单一的数字方式呈现,而是能够成为图表控件的一部分,让数据人工分析处理更加直观高效便捷。

![](https://github.com/heiyebaitian/esp32_hass_iot_seed/blob/main/public/image/chart-1.png)
![](https://github.com/heiyebaitian/esp32_hass_iot_seed/blob/main/public/image/chart-2.png)

### 多地育种基地集中化管理
由HASS提供的多地管理支持,可以远程集中化管理其他地点的设备,查看设备采集数据内容。
![](https://github.com/heiyebaitian/esp32_hass_iot_seed/blob/main/public/image/map.png)
