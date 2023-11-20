/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  25/8/2020    *******/
/******* SWC    :    PORT       *******/
/******* Version:    1.0        *******/
/**************************************/

#include "STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"

void PORT_VidInit(void)
{
	DDRA =PORTA_DIR;
	DDRB =PORTB_DIR;
	DDRC =PORTC_DIR;
	DDRD =PORTD_DIR;
	
	PORTA = PORTA_INTIAL_VALUE;
	PORTB = PORTA_INTIAL_VALUE;
	PORTC = PORTA_INTIAL_VALUE;
	PORTD = PORTA_INTIAL_VALUE;

}
