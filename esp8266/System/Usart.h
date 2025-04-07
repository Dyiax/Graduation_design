#ifndef __USART_H
#define __USART_H

#include "stdio.h"	
#include "stm32f10x.h"                  // Device header




#define USART_REC_LEN  			200  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
#define USART2_MAX_RECV_LEN		600					//�����ջ����ֽ���
#define USART2_MAX_SEND_LEN		600					//����ͻ����ֽ���
#define USART2_RX_EN 			1					//0,������;1,����.
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         				//����״̬���	
extern u8  USART2_RX_BUF[USART2_MAX_RECV_LEN]; 		//���ջ���,���USART3_MAX_RECV_LEN�ֽ�
extern u16 USART2_RX_STA;   						//��������״̬
//����봮���жϽ��գ��벻Ҫע�����º궨��
void Uart1_Init(u32 bound);
void Uart2_Init(u32 bound);
void u2_printf(char* fmt,...);
#endif
  
