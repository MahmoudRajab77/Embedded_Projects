/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  25/8/2020    *******/
/******* SWC    :    DIO        *******/
/******* Version:    1.0        *******/
/**************************************/
#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H

#define PORTA *((volatile u8*)0x3B)
#define PINA  *((volatile u8*)0x39)

#define PORTB *((volatile u8*)0x38)
#define PINB  *((volatile u8*)0x36)

#define PORTC *((volatile u8*)0x35)
#define PINC  *((volatile u8*)0x33)

#define PORTD *((volatile u8*)0x32)
#define PIND  *((volatile u8*)0x30)

#endif
