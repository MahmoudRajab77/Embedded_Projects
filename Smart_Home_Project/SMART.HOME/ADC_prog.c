/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  19/09/2020   *******/
/******* Update :            	*******/
/******* SWC    :     ADC       *******/
/******* Version:     1.0       *******/
/**************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_register.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void (*ADC_pvCallBackNotificationFunc)(void) = NULL;

u8* ADC_pu8Reading = NULL ;
u8 ADC_u8State = IDLE ;

void ADC_voidInt(void)
{
	/* AVCC as Reference voltage */
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/* Activate Left adjust result */
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/* Set Prescaler to divide by 128 */
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

	/* Enable peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel , u8* Copy_pu8Reading ,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u32Counter =0 ;
	u8 Local_u8ErrorState =OK ;

	if(ADC_u8State  == IDLE)
	{
		if ((Copy_pu8Reading == NULL )  ||  (Copy_pvNotificationFunc  == NULL))
		{
			Local_u8ErrorState = NULL_POINTER ;
		}
		else
		{
			/*Initialize the reading variable globally*/
			ADC_pu8Reading =Copy_pu8Reading ;
			/*Initialize the CallBack notification function globally*/
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc ;
			/*Clear the MUX bits in ADMUX register*/
			ADMUX &= 0b11100000;

			/*Set the required channel into the MUX bits*/
			ADMUX |= Copy_u8Channel ;

			/*Start convertion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Polling (busy waiting) until the conversion complete flag is set */
			while (((GET_BIT(ADCSRA,ADCSRA_ADIF)) == 0) && (Local_u32Counter != ADC_u32TIMEOUT) )
			{
				Local_u32Counter ++ ;
			}
			if(Local_u32Counter == ADC_u32TIMEOUT)
			{
				/* Loop is broken because the timeout is reached*/
				Local_u8ErrorState = Not_OK ;
			}
			else
			{
				/*Loop is broken because flag is raised*/
				/*Clear the conversion complete flag*/
				SET_BIT(ADCSRA, ADCSRA_ADIF);
				/*Return the reading */
				*Copy_pu8Reading = ADCH ;
				/*Invoke the callback notifcation function*/
				ADC_pvCallBackNotificationFunc();
			}
	}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC ;
	}
	return Local_u8ErrorState ;
}
u8 ADC_u8StartConversionASynch(u8 Copy_u8Channel,u8 *Copy_pu8Reading,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8Errorstate = OK ;

	if(ADC_u8State  == IDLE)
	{

		if ((Copy_pu8Reading == NULL )  ||  (Copy_pvNotificationFunc  == NULL))
		{
			Local_u8Errorstate = NULL_POINTER ;
		}
		else
		{
			/*make ADC busy in order not to work until being idle*/
			ADC_u8State = BUSY;
			/*Initialize the reading variable globally*/
			ADC_pu8Reading =Copy_pu8Reading ;

			/*Initialize the CallBack notification function globally*/
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc ;

			/*Clear the MUX bits in ADMUX register*/
			ADMUX &= 0b11100000;

			/*Set the required channel into the MUX bits*/
			ADMUX |= Copy_u8Channel ;

			/*Start convertion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC inturrupt enable */
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	/*else
	{
		Local_u8Errorstate = BUSY_FUNC ;
	}*/

	return Local_u8Errorstate ;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/*Read ADC result*/
	*ADC_pu8Reading = ADCH ;
	/*	Make ADC state be idle because it finished*/
	ADC_u8State = IDLE ;

	/*Invoke the callback notifcation function*/
	ADC_pvCallBackNotificationFunc();

	/*Disable ADC CONVERSION complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
