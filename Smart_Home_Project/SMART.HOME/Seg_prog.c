/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  5/9/2020     *******/
/******* SWC    :  7Segment     *******/
/******* Version:    1.0        *******/
/**************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "Seg_interface.h"
#include "Seg_private.h"
#include "Seg_config.h"
#include "util/delay.h"

u8 SSD_u8NumArr[10]=
		{
				0b00111111,
				0b00000110,
				0b01011011,
				0b01001111,
				0b01100110,
				0b01101101,
				0b01111101,
				0b00000111,
				0b01111111,
				0b01101111
		};

u8 SSD_u8SetNum(u8 Copy_u8Number ,SSD_t *SSD_ptr)
{
	u8 ErrorState =0;
	if(SSD_ptr->COM_Type == Cathode)
	{
	if(SSD_ptr->DOTEnable == UNEN )
	{
		switch(Copy_u8Number)
				{
				case 0 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[0]);break;
				case 1 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[1]);break;
				case 2 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[2]);break;
				case 3 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[3]);break;
				case 4 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[4]);break;
				case 5 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[5]);break;
				case 6 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[6]);break;
				case 7 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[7]);break;
				case 8 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[8]);break;
				case 9 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[9]);break;
				default:ErrorState =1;
				}
	}
	else if(SSD_ptr->DOTEnable == EN)
	{
		switch(Copy_u8Number)
				{
				case 0 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[0]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 1 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[1]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 2 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[2]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 3 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[3]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 4 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[4]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 5 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[5]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 6 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[6]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 7 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[7]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 8 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[8]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				case 9 :
					DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[9]);
					DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,HIGH);
					break;
				default:ErrorState =1;
				}
	}
	}
	else if(SSD_ptr->COM_Type == Anode)
	{
		if(SSD_ptr->DOTEnable == UNEN )
			{
				switch(Copy_u8Number)
						{
						case 0 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[0]);break;
						case 1 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[1]);break;
						case 2 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[2]);break;
						case 3 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[3]);break;
						case 4 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[4]);break;
						case 5 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[5]);break;
						case 6 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[6]);break;
						case 7 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[7]);break;
						case 8 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[8]);break;
						case 9 :DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[9]);break;
						default:ErrorState =1;
						}
			}
			else if(SSD_ptr->DOTEnable == EN)
			{
				switch(Copy_u8Number)
						{
						case 0 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,~SSD_u8NumArr[0]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 1 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[1]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 2 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[2]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 3 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[3]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 4 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[4]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 5 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[5]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 6 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[6]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 7 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[7]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 8 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[8]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						case 9 :
							DIO_vidSetPortValue(SSD_ptr->SSD_PORT,SSD_u8NumArr[9]);
							DIO_vidSetPinValue(SSD_ptr->SSD_PORT,Pin_7,LOW);
							break;
						default:ErrorState =1;
						}
			}
	}
	return ErrorState ;
}
void SSD_VidEnable(SSD_t *SSD_ptr)
{
	if(SSD_ptr->COM_Type == Cathode)
	{
		DIO_vidSetPinValue(SSD_ptr->ENABLEPort,SSD_ptr->ENABLEPin,LOW);
	}
	else if(SSD_ptr->COM_Type == Anode)
	{
		DIO_vidSetPinValue(SSD_ptr->ENABLEPort,SSD_ptr->ENABLEPin,HIGH);
	}
}
void SSD_VidDisable(SSD_t *SSD_ptr)
{
		if(SSD_ptr->COM_Type == Cathode)
		{
			DIO_vidSetPinValue(SSD_ptr->ENABLEPort,SSD_ptr->ENABLEPin,HIGH);
		}
		else if(SSD_ptr->COM_Type == Anode)
		{
			DIO_vidSetPinValue(SSD_ptr->ENABLEPort,SSD_ptr->ENABLEPin,LOW);
		}
}


