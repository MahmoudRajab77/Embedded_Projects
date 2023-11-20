/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  19/09/2020   *******/
/******* Update :            	*******/
/******* SWC    :     ADC       *******/
/******* Version:     1.0       *******/
/**************************************/

#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H


void ADC_voidInt(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel , u8* Copy_pu8Reading ,void(*Copy_pvNotificationFunc)(void));

u8 ADC_u8StartConversionASynch(u8 Copy_u8Channel,u8 *Copy_pu8Reading,void(*Copy_pvNotificationFunc)(void));

#endif
