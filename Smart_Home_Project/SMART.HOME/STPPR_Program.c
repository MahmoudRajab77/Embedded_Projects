/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  09/09/2020   *******/
/******* SWC    :    STPPR      *******/
/******* Version:    1.0        *******/
/**************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "STPPR_interface.h"
#include "STPPR_Config.h"
#include "STPPR_Private.h"

#include <util/delay.h>

void STPPR_RotateCW(void)
{
	DIO_vidSetPinValue(STPPR_PORT,Coil_Pink,HIGH);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Blue,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Yellow,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Orange,LOW);
	_delay_ms(STPPR_DELAY);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Pink,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Blue,HIGH);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Yellow,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Orange,LOW);
	_delay_ms(STPPR_DELAY);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Pink,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Blue,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Yellow,HIGH);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Orange,LOW);
	_delay_ms(STPPR_DELAY);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Pink,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Blue,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Yellow,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Orange,HIGH);
	_delay_ms(STPPR_DELAY);
}
void STPPR_RotateACW(void)
{
	DIO_vidSetPinValue(STPPR_PORT,Coil_Pink,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Blue,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Yellow,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Orange,HIGH);
	_delay_ms(STPPR_DELAY);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Pink,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Blue,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Yellow,HIGH);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Orange,LOW);
	_delay_ms(STPPR_DELAY);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Pink,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Blue,HIGH);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Yellow,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Orange,LOW);
	_delay_ms(STPPR_DELAY);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Pink,HIGH);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Blue,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Yellow,LOW);
	DIO_vidSetPinValue(STPPR_PORT,Coil_Orange,LOW);
	_delay_ms(STPPR_DELAY);
}
