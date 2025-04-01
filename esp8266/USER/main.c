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

u8 alarmFlag = 0; //�Ƿ񱨾�
u8 alarm_is_free=10;//�������Ƿ��ֶ��������ֶ�-0
u8 humidityH;  //ʪ��
u8 humidityL;
u8 temperatureH; //�¶�
u8 temperatureL;
u8 buffer[5];
extern char oledBuf[20];
//u8 ESP8266_INIT_OK = 0;//esp8266��ʼ����ɱ�־
//const char *topics[] = {"/mysmarthome/sub"};

//const char *devSubTopic[] = {"/mysmarthome/sub"};
//const char devPubTopic[] = "/mysmarthome/pub";

int main(void)
{
	BEEP_Init();
	delay_init();	    	 //��ʱ������ʼ��	
	BEEP = 0;            //������ʾ����ɹ�
	delay_ms(250);
	BEEP = 1;            //����������ɹ�
	Usart1_Init(115200);//debug����
//	DEBUG_LOG("\r\n");
//	DEBUG_LOG("UART1��ʼ��			[OK]");//���ڽ���ɹ�
	/////////////////////////
	OLED_Init();
	sprintf(oledBuf,"Waiting For");
	///////////////
	LED_Init();
	LED0 = 0;//PA4���ŵ�С�ƣ�LED0=1,С����
	
	
	
	while(1){
//	DEBUG_LOG("\r\n");
//	DEBUG_LOG("UART1��ʼ��			[OK]");
//	BEEP = 0;//������ʾ����ɹ�
//	delay_ms(250);
//	BEEP = 1;
	}
	
	
}
//	unsigned short timeCount = 0;	//���ͼ������
//	unsigned char *dataPtr = NULL;
//	static u8 lineNow;
//	Usart1_Init(115200);//debug����
//		DEBUG_LOG("\r\n");
//		DEBUG_LOG("UART1��ʼ��			[OK]");
//	delay_init();	    	 //��ʱ������ʼ��	
//		DEBUG_LOG("��ʱ������ʼ��			[OK]");
//	OLED_Init();
//	OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
//  	OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
//	OLED_Clear();
//	 	DEBUG_LOG("OLED1��ʼ��			[OK]");
//		OLED_Refresh_Line("OLED");

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
//		DEBUG_LOG("�ж����ȳ�ʼ��			[OK]");
//		OLED_Refresh_Line("NVIC");
//	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
//		DEBUG_LOG("LED��ʼ��			[OK]");
//		OLED_Refresh_Line("Led");
//	KEY_Init();          	//��ʼ���밴�����ӵ�Ӳ���ӿ�
//		DEBUG_LOG("������ʼ��			[OK]");
//		OLED_Refresh_Line("Key");
//	EXTIX_Init();		//�ⲿ�жϳ�ʼ��
//		DEBUG_LOG("�ⲿ�жϳ�ʼ��			[OK]");
//		OLED_Refresh_Line("EXIT");
//	BEEP_Init();
//		DEBUG_LOG("��������ʼ��			[OK]");
//		OLED_Refresh_Line("Beep");
//	DHT11_Init();
//		DEBUG_LOG("DHT11��ʼ��			[OK]");
//		OLED_Refresh_Line("DHT11");
//	Usart2_Init(115200);//stm32-8266ͨѶ����
//		DEBUG_LOG("UART2��ʼ��			[OK]");
//		OLED_Refresh_Line("Uart2");
//	
//		DEBUG_LOG("Ӳ����ʼ��			[OK]");
//		
//	DEBUG_LOG("��ʼ��ESP8266 WIFIģ��...");
//	if(!ESP8266_INIT_OK){
//		OLED_Clear();
//		sprintf(oledBuf,"Waiting For");
//		OLED_ShowString(16,0,(u8*)oledBuf,16);//8*16 ��ABC��
//		sprintf(oledBuf,"WiFi");
//		OLED_ShowString(48,18,(u8*)oledBuf,16);//8*16 ��ABC��
//		sprintf(oledBuf,"Connection");
//		OLED_ShowString(24,36,(u8*)oledBuf,16);//8*16 ��ABC��
//		OLED_Refresh();
//	}
//	ESP8266_Init();					//��ʼ��ESP8266
//	OLED_Clear();
//	sprintf(oledBuf,"Waiting For");
//	OLED_ShowString(16,0,(u8*)oledBuf,16);//8*16 ��ABC��
//	sprintf(oledBuf,"MQTT Server");
//	OLED_ShowString(16,18,(u8*)oledBuf,16);//8*16 ��ABC��
//	sprintf(oledBuf,"Connection");
//	OLED_ShowString(24,36,(u8*)oledBuf,16);//8*16 ��ABC��
//	OLED_Refresh();	
//	while(OneNet_DevLink()){//����OneNET
//		delay_ms(500);
//	}		
//	
//	OLED_Clear();	
//	
//	TIM2_Int_Init(4999,7199);
//	TIM3_Int_Init(2499,7199);
//	
//	BEEP = 0;//������ʾ����ɹ�
//	delay_ms(250);
//	BEEP = 1;
//	
//	OneNet_Subscribe(devSubTopic, 1);
//	
//	while(1)
//	{
//		if(timeCount%40 == 0){ //1000/25ms
//				//��ʪ�ȴ���������
//				DHT11_Read_Data(&temperatureH,&temperatureL,&humidityH,&humidityL);
//			  DEBUG_LOG(" | ʪ�ȣ�%d.%d C | �¶ȣ�%d.%d %% | ���նȣ�%.1f lx | ָʾ�ƣ�%s | ��������%s | ",humidityH,humidityL,temperatureH,temperatureL);
//			if(alarm_is_free == 10)//alarm...>0
//			{
//				if(humidityH<80 && temperatureH<40)
//					alarmFlag=0; //�����㱨������
//				else
//					alarmFlag=1;
//			}
//			if(alarm_is_free < 10)
//				alarm_is_free++;
//				UsartPrintf(USART_DEBUG,"alarmFlag_is_free = %d\r\n",alarm_is_free);
//				UsartPrintf(USART_DEBUG,"alarmFlag = %d\r\n",alarmFlag);
//				delay_ms(1000);//1s���һ��
//	
//			}
//	if(++timeCount >= 200)									//���ͼ��5s,5000ms/25ms
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
