#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "OLED.h"
#include "dht11.h"
#include "timer.h"
#include "beep.h"
#include "stdio.h"
#include "key.h"
#include "usart.h"
#include "exti.h"
//#include "esp8266.h"
//#include "onenet.h"

u8 alarmFlag = 0; //是否报警
u8 alarm_is_free=10;//报警器是否被手动操作，手动-0
u8 humidityH;  //湿度
u8 humidityL;
u8 temperatureH; //温度
u8 temperatureL;
u8 buffer[5];
extern char oledBuf[20];
//u8 ESP8266_INIT_OK = 0;//esp8266初始化完成标志
//const char *topics[] = {"/mysmarthome/sub"};

//const char *devSubTopic[] = {"/mysmarthome/sub"};
//const char devPubTopic[] = "/mysmarthome/pub";

int main(void)
{
	BEEP_Init();
	delay_init();	    	 //延时函数初始化	
	BEEP = 0;            //鸣叫提示接入成功
	delay_ms(250);
	BEEP = 1;            //蜂鸣器接入成功
	Usart1_Init(115200);//debug串口
//	DEBUG_LOG("\r\n");
//	DEBUG_LOG("UART1初始化			[OK]");//串口接入成功
	/////////////////////////
	OLED_Init();
	sprintf(oledBuf,"Waiting For");
	///////////////
	LED_Init();
	LED0 = 0;//PA4引脚的小灯，LED0=1,小灯亮
	
	
	
	while(1){
//	DEBUG_LOG("\r\n");
//	DEBUG_LOG("UART1初始化			[OK]");
//	BEEP = 0;//鸣叫提示接入成功
//	delay_ms(250);
//	BEEP = 1;
	}
	
	
}
//	unsigned short timeCount = 0;	//发送间隔变量
//	unsigned char *dataPtr = NULL;
//	static u8 lineNow;
//	Usart1_Init(115200);//debug串口
//		DEBUG_LOG("\r\n");
//		DEBUG_LOG("UART1初始化			[OK]");
//	delay_init();	    	 //延时函数初始化	
//		DEBUG_LOG("延时函数初始化			[OK]");
//	OLED_Init();
//	OLED_ColorTurn(0);//0正常显示，1 反色显示
//  	OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
//	OLED_Clear();
//	 	DEBUG_LOG("OLED1初始化			[OK]");
//		OLED_Refresh_Line("OLED");

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
//		DEBUG_LOG("中断优先初始化			[OK]");
//		OLED_Refresh_Line("NVIC");
//	LED_Init();		  	//初始化与LED连接的硬件接口
//		DEBUG_LOG("LED初始化			[OK]");
//		OLED_Refresh_Line("Led");
//	KEY_Init();          	//初始化与按键连接的硬件接口
//		DEBUG_LOG("按键初始化			[OK]");
//		OLED_Refresh_Line("Key");
//	EXTIX_Init();		//外部中断初始化
//		DEBUG_LOG("外部中断初始化			[OK]");
//		OLED_Refresh_Line("EXIT");
//	BEEP_Init();
//		DEBUG_LOG("蜂鸣器初始化			[OK]");
//		OLED_Refresh_Line("Beep");
//	DHT11_Init();
//		DEBUG_LOG("DHT11初始化			[OK]");
//		OLED_Refresh_Line("DHT11");
//	Usart2_Init(115200);//stm32-8266通讯串口
//		DEBUG_LOG("UART2初始化			[OK]");
//		OLED_Refresh_Line("Uart2");
//	
//		DEBUG_LOG("硬件初始化			[OK]");
//		
//	DEBUG_LOG("初始化ESP8266 WIFI模块...");
//	if(!ESP8266_INIT_OK){
//		OLED_Clear();
//		sprintf(oledBuf,"Waiting For");
//		OLED_ShowString(16,0,(u8*)oledBuf,16);//8*16 “ABC”
//		sprintf(oledBuf,"WiFi");
//		OLED_ShowString(48,18,(u8*)oledBuf,16);//8*16 “ABC”
//		sprintf(oledBuf,"Connection");
//		OLED_ShowString(24,36,(u8*)oledBuf,16);//8*16 “ABC”
//		OLED_Refresh();
//	}
//	ESP8266_Init();					//初始化ESP8266
//	OLED_Clear();
//	sprintf(oledBuf,"Waiting For");
//	OLED_ShowString(16,0,(u8*)oledBuf,16);//8*16 “ABC”
//	sprintf(oledBuf,"MQTT Server");
//	OLED_ShowString(16,18,(u8*)oledBuf,16);//8*16 “ABC”
//	sprintf(oledBuf,"Connection");
//	OLED_ShowString(24,36,(u8*)oledBuf,16);//8*16 “ABC”
//	OLED_Refresh();	
//	while(OneNet_DevLink()){//接入OneNET
//		delay_ms(500);
//	}		
//	
//	OLED_Clear();	
//	
//	TIM2_Int_Init(4999,7199);
//	TIM3_Int_Init(2499,7199);
//	
//	BEEP = 0;//鸣叫提示接入成功
//	delay_ms(250);
//	BEEP = 1;
//	
//	OneNet_Subscribe(devSubTopic, 1);
//	
//	while(1)
//	{
//		if(timeCount%40 == 0){ //1000/25ms
//				//温湿度传感器数据
//				DHT11_Read_Data(&temperatureH,&temperatureL,&humidityH,&humidityL);
//			  DEBUG_LOG(" | 湿度：%d.%d C | 温度：%d.%d %% | 光照度：%.1f lx | 指示灯：%s | 报警器：%s | ",humidityH,humidityL,temperatureH,temperatureL);
//			if(alarm_is_free == 10)//alarm...>0
//			{
//				if(humidityH<80 && temperatureH<40)
//					alarmFlag=0; //不满足报警条件
//				else
//					alarmFlag=1;
//			}
//			if(alarm_is_free < 10)
//				alarm_is_free++;
//				UsartPrintf(USART_DEBUG,"alarmFlag_is_free = %d\r\n",alarm_is_free);
//				UsartPrintf(USART_DEBUG,"alarmFlag = %d\r\n",alarmFlag);
//				delay_ms(1000);//1s检查一次
//	
//			}
//	if(++timeCount >= 200)									//发送间隔5s,5000ms/25ms
//		{
//			UsartPrintf(USART_DEBUG, "OneNet_Publish\r\n");
//			OneNet_Publish("pcTopic", "MQTT Publish Test");		
//			timeCount = 0;
//			ESP8266_Clear();
//		}
//		dataPtr = ESP8266_GetIPD(3); //*
//		if(dataPtr != NULL)
//			OneNet_RevPro(dataPtr);		
//		delay_ms(10);
//	}
