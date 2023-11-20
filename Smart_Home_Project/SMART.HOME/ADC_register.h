/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  19/09/2020   *******/
/******* Update :            	*******/
/******* SWC    :     ADC       *******/
/******* Version:     1.0       *******/
/**************************************/
#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define ADCH     *(volatile u8*)0x25    //The ADC Data Register
#define ADMUX    *(volatile u8*)0x27    //ADC Multiplexer Selection Register
#define ADCSRA   *(volatile u8*)0x26    //ADC Control and Status Register  

/*ADMUX BITS*/
#define ADMUX_REFS1  7       //Reference Selection Bit1
#define ADMUX_REFS0  6       //Reference Selection Bit0
#define ADMUX_ADLAR  5       //ADC Left Adjust Result

/*ADCSRA BITS*/
#define ADCSRA_ADEN   7       //ADC Enable
#define ADCSRA_ADSC   6       //ADC Start Conversion
#define ADCSRA_ADATE  5       //ADC Auto Trigger Enable
#define ADCSRA_ADIF   4       //ADC Interrupt Flag
#define ADCSRA_ADIE   3       //ADC Interrupt Enable
#define ADCSRA_ADPS2  2       //ADC Prescaler Select Bit2
#define ADCSRA_ADPS1  1       //ADC Prescaler Select Bit1
#define ADCSRA_ADPS0  0       //ADC Prescaler Select Bit0


#endif
