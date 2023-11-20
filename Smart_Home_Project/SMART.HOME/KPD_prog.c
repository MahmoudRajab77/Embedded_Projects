/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  28/8/2020    *******/
/******* SWC    :    KPD        *******/
/******* Version:    1.0        *******/
/**************************************/

#include "STD_TYPES.h"

#include "DIO_Interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY,Local_u8ColumnIdx,Local_u8RowIdx,Local_u8KPDState;
	static u8 Local_u8KPDArr[4][4]=KPD_ARR_VAL;
	static u8 Local_u8KPDColumnArr[COLUM_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRawArr   [ROW_NUM]  ={KPD_RAW0_PIN,KPD_RAW1_PIN,KPD_RAW2_PIN,KPD_RAW3_PIN};

	for(Local_u8ColumnIdx=0;Local_u8ColumnIdx<COLUM_NUM;Local_u8ColumnIdx++)
	{
		/*Activate current Column*/
		DIO_vidSetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],LOW);
		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
		{
			/*Read the current Row*/
			Local_u8KPDState=DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRawArr[Local_u8RowIdx]);
			/*check if switch is pressed*/
			if (0xff  != Local_u8KPDState)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];
				/*Polling (busy waiting) until the key is released*/
			/*	while(LOW  == Local_u8KPDState)
				{
					Local_u8KPDState=DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRawArr[Local_u8RowIdx]);
				}*/
				return Local_u8PressedKey;
			}
		}
		/*Deactivate current Column*/
		DIO_vidSetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],HIGH);
	}
	return Local_u8PressedKey;
}
