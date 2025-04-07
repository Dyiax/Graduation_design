#include "stm32f10x.h"                  // Device header
#include "adcx.h"
#include "ldr.h"
#include "oled.h"
#include "dht11.h"
#include "pwm.h"
#include "led.h"
#include "key.h"
#include "tim2.h"   
#include "tim3.h"   
#include "hc_sr501.h"
#include "hc_sr04.h"
#include "sensormodules.h"
#include "usart.h"
#include "gizwits_product.h"
#include "myrtc.h"
#include "flash.h"
#include "iwdg.h"

#define KEY_Long1	11

#define KEY_1	1
#define KEY_2	2
#define KEY_3	3
#define KEY_4	4

#define FLASH_START_ADDR	0x0801f000	//д�����ʼ��ַ

uint8_t hc501;						//�洢�����ź�
uint8_t systemModel = 0;				//�洢ϵͳ��ǰģʽ

uint8_t hour,minute,second;			//ʱ �� ��
uint8_t menu = 1;					//��ʾ�˵�����



SensorModules sensorData;	//�������������ݽṹ�����
SensorThresholdValue Sensorthreshold;	//������������ֵ�ṹ�����

enum 
{
	display_page = 1,
	settingsPage,
	timeSettingsPage
	
}MenuPages;

/**
  * @brief  ��ʾ��ҳ��̶�����
  * @param  ��
  * @retval ��
  */
void OLED_Menu(void)
{
	//��ʾ��Time����
	OLED_ShowString(1, 1, "Time");
	OLED_ShowChar(1, 5, ':');
	
	//��ʾ���¶ȣ���
	OLED_ShowChinese(2,1, 0);
	OLED_ShowChinese(2,2, 1);
	OLED_ShowChar(2, 5, ':');
	//��ʾ��ʪ�ȣ���
	OLED_ShowChinese(2,5, 2);
	OLED_ShowChinese(2,6, 1);
	OLED_ShowChar(2, 13, ':');	
	
	//��ʾ����ǿ����
	OLED_ShowChinese(3,1, 4);
	OLED_ShowChinese(3,2, 5);
	OLED_ShowChar(3, 5, ':');
	//��ʾ�����룺��
	OLED_ShowChinese(3,5, 17);
	OLED_ShowChinese(3,6, 18);
	OLED_ShowChar(3, 13, ':');
		
	//��ʾ�����ȣ���
	OLED_ShowChinese(4,1, 6);
	OLED_ShowChinese(4,2, 1);
	OLED_ShowChar(4, 5, ':');
}

/**
  * @brief  ��ʾ��ҳ��Ĵ��������ݵ���Ϣ
  * @param  ��
  * @retval ��
  */
void OLED_Menu_SensorData(void)
{
		//��ʾʱ������
		OLED_ShowNum(1,6,MyRTC_Time[3],2);
		OLED_ShowChar(1,8,':');
		OLED_ShowNum(1,9,MyRTC_Time[4],2);
		OLED_ShowChar(1,11,':');
		OLED_ShowNum(1,12,MyRTC_Time[5],2);
	
	
		//��ʾ�¶�����
		OLED_ShowNum(2, 6, sensorData.temp, 2);
		OLED_ShowChar(2, 8, 'C');	

		//��ʾʪ������
		OLED_ShowNum(2, 14, sensorData.humi, 2);	
		OLED_ShowChar(2, 16, '%');	

		//��ʾ��ǿ����
		OLED_ShowNum(3, 6, sensorData.lux, 3);	

		//��ʾ��������
		OLED_ShowNum(3, 14, sensorData.distance, 2);

		//��ʾ���ȵȼ�
		OLED_ShowNum(4, 6, ledDutyRatio, 3);
		OLED_ShowChar(4, 9, '%');	
	
		//��ʾ�Ƿ�����
		if (sensorData.people)
		{
			OLED_ShowChinese(1, 8, 19);
		}
		else
		{
			OLED_ShowString(1, 15, "  ");	
		}	
		
		//��ʾϵͳ��ǰģʽ �ֶ�ģʽ or �Զ�ģʽ
		if (systemModel)
		{
			//��ʾ���Զ���
			OLED_ShowChinese(4, 7, 9);
			OLED_ShowChinese(4, 8, 10);					
		}
		else
		{
			//��ʾ���ֶ���
			OLED_ShowChinese(4, 7, 11);
			OLED_ShowChinese(4, 8, 12);			
		}
}

/**
  * @brief  ��ʾϵͳ���ý���
  * @param  ��
  * @retval ��
  */
void OLED_SetInterfacevoid(void)
{
	//��ʾ��ϵͳ���ý��桱
	OLED_ShowChinese(1, 2, 20);
	OLED_ShowChinese(1, 3, 21);
	OLED_ShowChinese(1, 4, 22);
	OLED_ShowChinese(1, 5, 23);
	OLED_ShowChinese(1, 6, 24);
	OLED_ShowChinese(1, 7, 25);	
	
	//��ʾ��ϵͳʱ�䡱
	OLED_ShowChinese(2, 2, 20);
	OLED_ShowChinese(2, 3, 21);	
	OLED_ShowChinese(2, 4, 28);
	OLED_ShowChinese(2, 5, 29);	
	OLED_ShowChar(2, 11, ':');	
	OLED_ShowString(2, 13, "xxx");
	
	//��ʾ��������ֵ��
	OLED_ShowChinese(3, 2, 4);
	OLED_ShowChinese(3, 3, 5);	
	OLED_ShowChinese(3, 4, 26);
	OLED_ShowChinese(3, 5, 27);	
	OLED_ShowChar(3, 11, ':');

	//��ʾ��������ֵ��
	OLED_ShowChinese(4, 2, 17);
	OLED_ShowChinese(4, 3, 18);	
	OLED_ShowChinese(4, 4, 26);
	OLED_ShowChinese(4, 5, 27);	
	OLED_ShowChar(4, 11, ':');
	
	//��ʾ������ֵ��ֵ
	OLED_ShowNum(3, 13, Sensorthreshold.Illumination_threshold, 3);

	//��ʾ������ֵ��ֵ
	OLED_ShowNum(4, 14, Sensorthreshold.Distance_threshold, 2);
}

/**
  * @brief  ��¼��ֵ�����°�KEY1�Ĵ���
  * @param  ��
  * @retval ���ش���
  */
uint8_t SetSelection(void)
{
	static uint8_t count = 1;
	if(KeyNum == KEY_1)
	{
		KeyNum = 0;
		count++;
		if (count >= 4)
		{
			count = 1;
		}
	}
	return count;
}

/**
  * @brief  ��ʾ��ֵ�����ѡ�����
  * @param  num Ϊ��ʾ��λ��
  * @retval ��
  */
void OLED_Option(uint8_t num)
{
	switch(num)
	{
		case 1:	
			OLED_ShowChar(1,1,' ');
			OLED_ShowChar(2,1,'>');
			OLED_ShowChar(3,1,' ');
			OLED_ShowChar(4,1,' ');
			break;
		case 2:	
			OLED_ShowChar(1,1,' ');
			OLED_ShowChar(2,1,' ');
			OLED_ShowChar(3,1,'>');
			OLED_ShowChar(4,1,' ');
			break;
		case 3:	
			OLED_ShowChar(1,1,' ');
			OLED_ShowChar(2,1,' ');
			OLED_ShowChar(3,1,' ');
			OLED_ShowChar(4,1,'>');
			break;
		default: break;
	}
}

/**
  * @brief  ��ʾʱ����ڽ����ѡ�����
  * @param  num Ϊ��ʾ��λ��
  * @retval ��
  */
void OLED_Time_Option(u8 num)
{
	switch(num)
	{
		case 1:	

			OLED_ShowChar(2,6,'v');
			OLED_ShowChar(2,9,' ');
			OLED_ShowChar(2,12,' ');
			break;
		case 2:	
			OLED_ShowChar(2,6,' ');
			OLED_ShowChar(2,9,'v');
			OLED_ShowChar(2,12,' ');
			break;
		case 3:	
			OLED_ShowChar(2,6,' ');
			OLED_ShowChar(2,9,' ');
			OLED_ShowChar(2,12,'v');
			break;
		default: break;
	}
}

/**
  * @brief  ��ʾʱ����ڽ��������
  * @param  ��
  * @retval ��
  */
void OLED_ThresholdTime(void)
{
	//ϵͳʱ�䣺
	OLED_ShowChinese(1, 3, 20); 
	OLED_ShowChinese(1, 4, 21); 
	OLED_ShowChinese(1, 5, 28); 
	OLED_ShowChinese(1, 6, 29); 
	OLED_ShowChar(1, 13, ':');

	OLED_ShowNum(3,5,hour,2);
	OLED_ShowChar(3,7,':');
	OLED_ShowNum(3,8,minute,2);
	OLED_ShowChar(3,10,':');
	OLED_ShowNum(3,11,second,2);
}

/**
  * @brief  ����ֵ����Ĵ�������ֵ�����޸�
  * @param  num Ϊ��ǰ�û���Ҫ���ĵĴ�������ֵλ��
  * @retval ��
  */
void ThresholdModification(uint8_t num)
{
	switch (num)
	{
		case 1:
			if (KeyNum == KEY_3)
			{
				KeyNum = 0;
				OLED_Clear();
				menu = timeSettingsPage;
				
				hour = MyRTC_Time[3];
				minute = MyRTC_Time[4];
				second = MyRTC_Time[5];	
			}
			else if (KeyNum == KEY_4)
			{
				KeyNum = 0;
				OLED_Clear();
				menu = timeSettingsPage;
				
				hour = MyRTC_Time[3];
				minute = MyRTC_Time[4];
				second = MyRTC_Time[5];
			}			
			break;		

		case 2:
			if (KeyNum == KEY_3)
			{
				KeyNum = 0;
				Sensorthreshold.Illumination_threshold += 10;
				if (Sensorthreshold.Illumination_threshold > 999)
				{
					Sensorthreshold.Illumination_threshold = 1;
				}
			}
			else if (KeyNum == KEY_4)
			{
				KeyNum = 0;
				Sensorthreshold.Illumination_threshold -= 10;
				if (Sensorthreshold.Illumination_threshold < 1)
				{
					Sensorthreshold.Illumination_threshold = 999;
				}				
			}			
			break;
		case 3:
			if (KeyNum == KEY_3)
			{
				KeyNum = 0;
				Sensorthreshold.Distance_threshold++;
				if (Sensorthreshold.Distance_threshold > 99)
				{
					Sensorthreshold.Distance_threshold = 1;
				}
			}
			else if (KeyNum == KEY_4)
			{
				KeyNum = 0;
				Sensorthreshold.Distance_threshold--;
				if (Sensorthreshold.Distance_threshold < 1)
				{
					Sensorthreshold.Distance_threshold = 99;
				}				
			}
			break;
		default: break;		
	}
}

/**
  * @brief  ��ϵͳʱ������޸�
  * @param  num Ϊ��ǰ�û���Ҫ���ĵ�ʱ����λ��
  * @retval ��
  */
void TimeModification(uint8_t num)
{
	switch (num)
	{
		case 1:
			if (KeyNum == KEY_3)
			{
				KeyNum = 0;
				hour++;
				if (hour > 24)
				{
					hour = 0;
				}
			}
			else if (KeyNum == KEY_4)
			{
				KeyNum = 0;
				hour --;
				if (hour > 24)
				{
					hour = 24;
				}				
			}		
			break;		

		case 2:
			if (KeyNum == KEY_3)
			{
				KeyNum = 0;
				minute++;
				if (minute > 60)
				{
					minute = 0;
				}
			}
			else if (KeyNum == KEY_4)
			{
				KeyNum = 0;
				minute --;
				if (minute > 60)
				{
					minute = 60;
				}				
			}					
			break;
		case 3:
			if (KeyNum == KEY_3)
			{
				KeyNum = 0;
				second++;
				if (second > 60)
				{
					second = 0;
				}
			}
			else if (KeyNum == KEY_4)
			{
				KeyNum = 0;
				second --;
				if (second > 60)
				{
					second = 60;
				}				
			}		
			break;
		default: break;		
	}
}

/**
  * @brief  ��ȡ������������
  * @param  ��
  * @retval ��
  */
void sensorScan(void)
{
		DHT11_Read_Data(&sensorData.humi, &sensorData.temp);
		HC_SR04_Deboanle(&sensorData.distance);
		LDR_LuxData(&sensorData.lux);
		HC_SR501_Input(&sensorData.people);		
}


int main(void)
{
	ADCX_Init();
	PWM_Init(100 - 1, 720 - 1);
	Timer2_Init(9,14398);
	Uart2_Init(9600);
	Uart1_Init(115200);
	IWDG_Init();	//��ʼ�����Ź�
	
	LDR_Init();
	OLED_Init();
	DHT11_Init();
	LED_Init();
	Key_Init();
	HC_SR501_Init();
	HC_SR04_Init();
	//Buzzer_Init();
  MyRTC_Init();

	Sensorthreshold.Illumination_threshold = FLASH_R(FLASH_START_ADDR);	//��ָ��ҳ�ĵ�ַ��FLASH
	Sensorthreshold.Distance_threshold = FLASH_R(FLASH_START_ADDR+2);	//��ָ��ҳ�ĵ�ַ��FLASH
	
	GENERAL_TIM_Init();
	userInit();		//��ɻ����Ƴ�ʼ��ֵ
	gizwitsInit();	//����һ�����λ�����
//	GPIO_SetBits(Buzzer_PROT, Buzzer);
//	Delay_ms(1200);
	
	while (1)
	{
		
		IWDG_ReloadCounter(); //���¼��ؼ���ֵ ι��
		sensorScan();	//��ȡ����������

		switch (menu)
		{
			case display_page:

				MyRTC_ReadTime();	//���ô˺�����RTCӲ����·��ʱ��ֵ��ˢ�µ�ȫ������
				OLED_Menu_SensorData();	//��ʾ��ҳ�洫�������ݡ�ϵͳģʽ������
				OLED_Menu();	//��ʾ��ҳ��Ĺ̶�����
				if (!systemModel)
				{
					LED_PWM_KEY();	//��������LED��PWM			
				}

				//�л�ϵͳģʽ
				if (KeyNum == KEY_1)
				{
					KeyNum = 0;
					systemModel = ~systemModel;
					if (systemModel)
					{
						currentDataPoint.valueModel = 1;
					}
					else
					{
						currentDataPoint.valueModel = 0;
					}
				}				
				
				//�ж��Ƿ������ֵ���ý���
				if (KeyNum == KEY_Long1)
				{
					KeyNum = 0;
					OLED_Clear();	//����
					menu = settingsPage;	//��ת����ֵ���ý���
				}
				break;
			case settingsPage:
				OLED_SetInterfacevoid();	//��ʾ��ֵ���ý���Ĺ̶�����
				OLED_Option(SetSelection());	//ʵ����ֵ����ҳ���ѡ����
				ThresholdModification(SetSelection());	//ʵ����ֵ���ڹ���	
			
				//�ж��Ƿ��˳���ֵ���ý���
				if (KeyNum == KEY_2)
				{
					KeyNum = 0;
					OLED_Clear();	//����
					menu = display_page;	//��ת��������

					//�洢�޸ĵĴ�������ֵ��flash��				
					FLASH_W(FLASH_START_ADDR, Sensorthreshold.Illumination_threshold, Sensorthreshold.Distance_threshold);
					currentDataPoint.valueIllumination_threshold = Sensorthreshold.Illumination_threshold;
					currentDataPoint.valueDistance_threshold = Sensorthreshold.Distance_threshold;
				}
				break;
			case timeSettingsPage:
				OLED_ThresholdTime();	//��ʾʱ�����ý��������
				OLED_Time_Option(SetSelection());	//ʵ�ּ����ý����ѡ����
				TimeModification(SetSelection());	//ʵ��ʱ����ڹ���	
				
				//�ж��Ƿ��˳�ʱ�����ý���
				if (KeyNum == KEY_2)
				{
					KeyNum = 0;
					//�����ĵ����ݸ�ֵ��RTC������
					MyRTC_Time[3] = hour;	
					MyRTC_Time[4] = minute;
					MyRTC_Time[5] = second;		
					MyRTC_SetTime();	//���ô˺�����ȫ��������ʱ��ֵ��ˢ�µ�RTCӲ����·	
		
					OLED_Clear();	//����
					menu = settingsPage;	//�ص���ֵ���ý���
				}
				break;
		}	
		//�ж���λ���Ƿ������ֵ��������򱣴���flash��
		if (valueFlashflag)
		{
			valueFlashflag = 0;
			//�洢�޸ĵĴ�������ֵ��flash��				
			FLASH_W(FLASH_START_ADDR, Sensorthreshold.Illumination_threshold, Sensorthreshold.Distance_threshold);
		}

		userHandle();	//���»��������ݵ�����洢��ֵ
		gizwitsHandle((dataPoint_t *)&currentDataPoint);	//�����ϴ���������					
	}
}
