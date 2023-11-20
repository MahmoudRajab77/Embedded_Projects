#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_Interface.h"
#include "GI_interface.h"
#include "USART_interface.h"
#include "ADC_interface.h"

#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "LED_interface.h"
#include "Seg_interface.h"
#include "SW_interface.h"
#include "STPPR_interface.h"

#include "util/delay.h"

#define DOOR_OPEN_TIME 2000  //In ms
#define TEMP    (Millivolt/10)
void APP_EntrancePassword();
void TempReading(void);
void ADCNotification (void);

LED_t APP_TempIndicator = {PORT_C,4,LED_u8SINK};
LED_t APP_FanIndicator = {PORT_C,5,LED_u8SINK};

u8 Celisos[8]={0b00000000,0b00001100,0b00010010,0b00010010,0b00001100,0b00000000,0b00000000,0b00000000};

u32 APP_u32Password = 22222 ;

u8 *APP_u8ADCReading =NULL;
u16 Millivolt ;

u8 APP_u8DoorStatus=0 ;
u8 APP_u8KPDStatus =0xff ;

void APP_VidSystemInt(void)
{

	PORT_VidInit();

	/*LCD Initialize */
	CLCD_VidInit();

	ADC_voidInt();

	GI_VoidEnable();

	/*Write Welcome in screen for 1sec. */
	CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
	CLCD_VidGoToXY(0,0);
	CLCD_VidSendString("    Welcome");
	_delay_ms(1000);

	CLCD_VidGoToXY(0,0);
	CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
	APP_EntrancePassword();
}

void APP_EntrancePassword()
{
	static u8 Local_u8PressedKey = 0xff ;
	u32 Local_u32EnteredPassword = 0;

	u8 Local_u8Counter =0 ;
	do
	{
		CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
		CLCD_VidGoToXY(0,0);
		CLCD_VidSendString("Password:");
		CLCD_VidGoToXY(0,1);

		for(u8 i = 0 ; i < 6 ; i++)
		{
				do
				{
					Local_u8PressedKey=KPD_u8GetPressedKey();

					_delay_ms(250);

				}
				while(0xff==Local_u8PressedKey);


				Local_u32EnteredPassword *= 10 ;
				Local_u32EnteredPassword += Local_u8PressedKey ;

				CLCD_VidWriteNum(Local_u8PressedKey);

		}

		if(Local_u32EnteredPassword == APP_u32Password)
		{
			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			CLCD_VidGoToXY(0,0);
			CLCD_VidSendString("Correct");
			_delay_ms(2000);
			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			CLCD_VidGoToXY(0,0);
			CLCD_VidSendString("Door_Opened");
			for(u8 k =0 ; k <200 ; k++)
			{
				APP_u8DoorStatus =1 ;
				STPPR_RotateCW();
			}
			_delay_ms(DOOR_OPEN_TIME);
			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			CLCD_VidSendString("Door_Closed");
			for(u8 k =0 ; k <200 ; k++)
			{
				APP_u8DoorStatus =0 ;
				STPPR_RotateACW();
			}
			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			return;
		}
		else
		{
				CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
				CLCD_VidGoToXY(0,0);
				CLCD_VidSendString("Wrong");
				_delay_ms(1500);


		}
		Local_u8Counter++ ;
	}while(Local_u8Counter != 3);

	if(Local_u8Counter == 3)
	{
		CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
		CLCD_VidGoToXY(0,0);
		CLCD_VidSendString("Forget Password?");
		CLCD_VidGoToXY(0,1);
		CLCD_VidSendString("Enter reset number");

		do
		{
			Local_u8PressedKey=KPD_u8GetPressedKey();
		}while(0xff==Local_u8PressedKey);

		if(Local_u8PressedKey == 2)    // reset number
		{
			Local_u32EnteredPassword =0 ;
			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			CLCD_VidGoToXY(0,0);
			CLCD_VidSendString("New Password:");
			_delay_ms(1000);
			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			CLCD_VidGoToXY(0,0);
			CLCD_VidSendString(" :");


			for(u8 m = 0 ; m < 6 ; m++)
			{
					do
					{
						Local_u8PressedKey=KPD_u8GetPressedKey();
					}while(0xff==Local_u8PressedKey);


					Local_u32EnteredPassword *= 10 ;
					Local_u32EnteredPassword += Local_u8PressedKey ;

					CLCD_VidWriteNum(Local_u8PressedKey);

			}
			APP_u32Password = Local_u32EnteredPassword ;

			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			CLCD_VidGoToXY(0,0);
			CLCD_VidSendString("Pass--> ");
			CLCD_VidWriteNum(APP_u32Password);
			_delay_ms(2000);
			do
			{
				Local_u8PressedKey=KPD_u8GetPressedKey();
			}while(0xff==Local_u8PressedKey);

			APP_EntrancePassword();
		}
	}


}


void TempReading(void)
{
	ADC_u8StartConversionASynch(7,&APP_u8ADCReading,&ADCNotification);
	Millivolt = ((u32) APP_u8ADCReading * 5000UL )/256UL ;
}
void ADCNotification (void)
{
	CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
	CLCD_VidGoToXY(13,0);
	CLCD_VidWriteNum(Millivolt/10);
	CLCD_VidWriteSpecialChar(Celisos,0,15,0);
	_delay_ms(500);
}

void FanControl(void)
{
	u8 Local_u8PressedKey ;
	static u8 Local_u8FanStatus =0;
	Local_u8PressedKey = KPD_u8GetPressedKey();

	if(Local_u8PressedKey == 3) Local_u8FanStatus^=1 ;

	if( TEMP > 26 || ( Local_u8FanStatus == 1) )
	{
		CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
		CLCD_VidGoToXY(0,0);
		CLCD_VidSendString("Fan_On");
		DIO_vidSetPinValue(PORT_D,Pin_0,HIGH);
		LED_VidTurnON(&APP_FanIndicator);
	}
	else if ((Local_u8PressedKey == 3) && (Local_u8FanStatus == 0))
	{
		CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
		CLCD_VidGoToXY(0,0);
		CLCD_VidSendString("Fan_Off");
		DIO_vidSetPinValue(PORT_D,Pin_0,LOW);
		LED_VidTurnOFF(&APP_FanIndicator);
	}

	if(TEMP > 50 )LED_VidTurnON(&APP_TempIndicator);
	else LED_VidTurnOFF(&APP_TempIndicator);

}
void DoorControl(void)
{
	u8 Local_u8PressedKey =0xff ;
	Local_u8PressedKey =KPD_u8GetPressedKey();
	if(Local_u8PressedKey!= 0xff)
	{
		switch (Local_u8PressedKey)
		{
		case 1 :
			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			CLCD_VidGoToXY(0,0);
			CLCD_VidSendString("Door_Opened");
			for(u8 k =0 ; k <200 ; k++)
			{
				APP_u8DoorStatus =1 ;
				STPPR_RotateCW();

			}
			break;
		case 2 :
			CLCD_VidSendCommand(CLCD_CLEAR_DISPLAY);
			CLCD_VidGoToXY(0,0);
			CLCD_VidSendString("Door_Closed");
			for(u8 k =0 ; k <200 ; k++)
			{
				STPPR_RotateACW();
			}
			break;
		default: return ;
		}
	}
}
void main()
{
	APP_VidSystemInt();
	while(1)
	{
		TempReading();

		DoorControl();
		FanControl();


	}
}

