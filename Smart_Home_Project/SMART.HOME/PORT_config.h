/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :  25/8/2020    *******/
/******* SWC    :    PORT       *******/
/******* Version:    1.0        *******/
/**************************************/
#ifndef PORT_CONFIG_H
#define PORT_CONFIG_H

/* DETERMINE : OUTPUT
        OR     INPUT
		               */
#define PORTA_PIN0_DIR      OUTPUT
#define PORTA_PIN1_DIR      OUTPUT
#define PORTA_PIN2_DIR      OUTPUT
#define PORTA_PIN3_DIR      OUTPUT
#define PORTA_PIN4_DIR      OUTPUT
#define PORTA_PIN5_DIR      OUTPUT
#define PORTA_PIN6_DIR      OUTPUT
#define PORTA_PIN7_DIR      INPUT      //LM35 Reading (out pin)
                            
#define PORTB_PIN0_DIR      OUTPUT     //KeyPAD column3
#define PORTB_PIN1_DIR      OUTPUT     //KeyPAD column2
#define PORTB_PIN2_DIR      OUTPUT     //KeyPAD column1
#define PORTB_PIN3_DIR      OUTPUT     //KeyPAD column0
#define PORTB_PIN4_DIR      INPUT      //KeyPAD raw0
#define PORTB_PIN5_DIR      INPUT      //KeyPAD raw1
#define PORTB_PIN6_DIR      INPUT      //KeyPAD raw2
#define PORTB_PIN7_DIR      INPUT      //KeyPAD raw3
                            
#define PORTC_PIN0_DIR      OUTPUT     //Stpper coil pink
#define PORTC_PIN1_DIR      OUTPUT     //Stpper coil blue
#define PORTC_PIN2_DIR      OUTPUT     //Stpper coil Yellow
#define PORTC_PIN3_DIR      OUTPUT     //Stpper coil Orange
#define PORTC_PIN4_DIR      OUTPUT     //RED LED (Temp Indicator)
#define PORTC_PIN5_DIR      OUTPUT     //Green LED (Fan Indicator)
#define PORTC_PIN6_DIR      OUTPUT
#define PORTC_PIN7_DIR      OUTPUT
                            
#define PORTD_PIN0_DIR      OUTPUT     //FAN CONTROL PIN
#define PORTD_PIN1_DIR      OUTPUT     //CLCD D7
#define PORTD_PIN2_DIR      OUTPUT     //CLCD D6
#define PORTD_PIN3_DIR      OUTPUT     //CLCD D5
#define PORTD_PIN4_DIR      OUTPUT     //CLCD D4
#define PORTD_PIN5_DIR      OUTPUT     //CLCD E
#define PORTD_PIN6_DIR      OUTPUT     //CLCD RW
#define PORTD_PIN7_DIR      OUTPUT     //CLCD RS
/* LOW : for floating if INPUT , LOW  if OUTPUT
   HIGH: for PULLUP if INPUT   , HIGH if OUTPUT */
#define PORTA_PIN0_INTIAL_VALUE    LOW
#define PORTA_PIN1_INTIAL_VALUE    LOW
#define PORTA_PIN2_INTIAL_VALUE    LOW
#define PORTA_PIN3_INTIAL_VALUE    LOW
#define PORTA_PIN4_INTIAL_VALUE    LOW
#define PORTA_PIN5_INTIAL_VALUE    LOW
#define PORTA_PIN6_INTIAL_VALUE    LOW
#define PORTA_PIN7_INTIAL_VALUE    LOW

#define PORTB_PIN0_INTIAL_VALUE    HIGH
#define PORTB_PIN1_INTIAL_VALUE    HIGH
#define PORTB_PIN2_INTIAL_VALUE    HIGH
#define PORTB_PIN3_INTIAL_VALUE    HIGH
#define PORTB_PIN4_INTIAL_VALUE    HIGH    //PULLUP
#define PORTB_PIN5_INTIAL_VALUE    HIGH    //PULLUP
#define PORTB_PIN6_INTIAL_VALUE    HIGH    //PULLUP
#define PORTB_PIN7_INTIAL_VALUE    HIGH    //PULLUP

#define PORTC_PIN0_INTIAL_VALUE    LOW
#define PORTC_PIN1_INTIAL_VALUE    LOW
#define PORTC_PIN2_INTIAL_VALUE    LOW
#define PORTC_PIN3_INTIAL_VALUE    LOW
#define PORTC_PIN4_INTIAL_VALUE    LOW
#define PORTC_PIN5_INTIAL_VALUE    LOW
#define PORTC_PIN6_INTIAL_VALUE    LOW
#define PORTC_PIN7_INTIAL_VALUE    LOW

#define PORTD_PIN0_INTIAL_VALUE    LOW
#define PORTD_PIN1_INTIAL_VALUE    LOW
#define PORTD_PIN2_INTIAL_VALUE    LOW
#define PORTD_PIN3_INTIAL_VALUE    LOW
#define PORTD_PIN4_INTIAL_VALUE    LOW
#define PORTD_PIN5_INTIAL_VALUE    LOW
#define PORTD_PIN6_INTIAL_VALUE    LOW
#define PORTD_PIN7_INTIAL_VALUE    LOW

#endif
