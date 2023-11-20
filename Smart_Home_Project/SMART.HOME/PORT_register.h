/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  25/8/2020    *******/
/******* SWC    :    PORT       *******/
/******* Version:    1.0        *******/
/**************************************/
#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H

#define DDRA  *((volatile u8*)0x3A)
#define DDRB  *((volatile u8*)0x37)
#define DDRC  *((volatile u8*)0x34)
#define DDRD  *((volatile u8*)0x31)

#define PORTA *((volatile u8*)0x3B)
#define PINA  *((volatile u8*)0x39)

#define PORTB *((volatile u8*)0x38)
#define PINB  *((volatile u8*)0x36)

#define PORTC *((volatile u8*)0x35)
#define PINC  *((volatile u8*)0x33)

#define PORTD *((volatile u8*)0x32)
#define PIND  *((volatile u8*)0x30)
#endif
