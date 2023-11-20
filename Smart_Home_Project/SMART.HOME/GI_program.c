/**************************************/
/******* Name   : Mahmoud Rajab *******/
/******* Date   :   17/09/2020  *******/
/******* SWC    :       GI      *******/
/******* Version:      1.0      *******/
/**************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GI_interface.h"

#define SREG *((volatile u8*)0x5f)

void GI_VoidEnable(void)
{
	SET_BIT(SREG,7);
}

void GI_VoidDisable(void)
{
	CLR_BIT(SREG,7);
}
