/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  09/10/2020   *******/
/******* Update :            	*******/
/******* SWC    :     USART     *******/
/******* Version:     1.0       *******/
/**************************************/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/* Functions prototypes*/
void USART_VidInt(u16 Copy_u16Baud);
void USART_VidSendData(u8 Copy_u8Data);
u8   USART_u8ReciveData(void);
void USART_VidSendString(u8* Copy_pString);
void USART_VidSendHex8(u8 Copy_Val);
void USART_VidSendHex16(u16 Copy_Val);
#endif
