/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  28/8/2020    *******/
/******* SWC    :    LED        *******/
/******* Version:    1.0        *******/
/**************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef struct
{
	u8 LEDPORT;
	u8 LEDPIN;
	u8 ConnType;
}LED_t;

#define LED_u8SOURCE 1
#define LED_u8SINK   0

void LED_VidTurnON(LED_t *LED);
void LED_VidTurnOFF(LED_t *LED);

#endif
