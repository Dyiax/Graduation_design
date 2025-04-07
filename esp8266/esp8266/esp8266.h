#ifndef	__ESP8266_H
#define	__ESP8266_H
#include "sys.h"
/*MQTT 连接参数*/
//#define clientId "a1Zw81YmcId.ESP8266|securemode=2\\,signmethod=hmacsha256\\,timestamp=1694524012615|"
//#define username "ESP8266&a1Zw81YmcId"
//#define passwd "a8bed5d35c6c689437c6ef2fa8d360044879460f6e6647fb4b8f985180ad42ca"
//#define mqttHostUrl "a1Zw81YmcId.iot-as-mqtt.cn-shanghai.aliyuncs.com"
//#define port "1883"
#define post "/a1KXCyQfMKC/ESP8266DUAN/user/ESP8266DUAN"
#define post_name "LightSwitch"

#define MQTT_set	"AT+MQTTUSERCFG=0,1,\"NULL\",\"ESP8266DUAN&a1KXCyQfMKC\",\"80b1190d9bc84008395cc1a723b87437b4c589e3d4f3fc56b984234b21907452\",0,0,\"\""
#define MQTT_Client "AT+MQTTCLIENTID=0,\"a1KXCyQfMKC.ESP8266DUAN|securemode=2\\,signmethod=hmacsha256\\,timestamp=1694874748758|\""
#define MQTT_Pass "AT+MQTTCONN=0,\"a1KXCyQfMKC.iot-as-mqtt.cn-shanghai.aliyuncs.com\",1883,1"

#define WIFI_Name "TP-LINK_3104"
#define WIFI_Pass "123456789000"
extern unsigned char Property_Data[];		//数据保存数组
void ESP8266_Init(void);
unsigned char ESP8266_Re(unsigned char *ACK_AT);
void ESP8266_Send(char *property,int Data);
void ESP8266_Received(char *PRO);
u8 esp8266_send_cmd(char *cmd,char *ack,u16 waittime);
u8* esp8266_check_cmd(char *str);
#endif

