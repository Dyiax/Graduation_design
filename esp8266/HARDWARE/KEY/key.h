#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"


#define KEY0 PBin(0) //LED KEY
#define KEY1 PBin(1) //BEEP KEY
 

//#define KEY0  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)//��ȡ����0
//#define KEY1  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)//��ȡ����1
//#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����2 
 

#define KEY0_PRES	1		//KEY0  
#define KEY1_PRES	2		//KEY1 

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��					    
#endif
