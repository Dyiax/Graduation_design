#ifndef __USART_H
#define __USART_H

#include "stdio.h"	
#include "stm32f10x.h"                  // Device header




#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收
#define USART2_MAX_RECV_LEN		600					//最大接收缓存字节数
#define USART2_MAX_SEND_LEN		600					//最大发送缓存字节数
#define USART2_RX_EN 			1					//0,不接收;1,接收.
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         				//接收状态标记	
extern u8  USART2_RX_BUF[USART2_MAX_RECV_LEN]; 		//接收缓冲,最大USART3_MAX_RECV_LEN字节
extern u16 USART2_RX_STA;   						//接收数据状态
//如果想串口中断接收，请不要注释以下宏定义
void Uart1_Init(u32 bound);
void Uart2_Init(u32 bound);
void u2_printf(char* fmt,...);
#endif
  
