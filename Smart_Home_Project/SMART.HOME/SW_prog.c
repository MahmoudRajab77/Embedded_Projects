#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SW_interface.h"
#include <util/delay.h>

u8 SW_u8Getstate(SW_t *SW_ptr)
{
	u8 State=0;
	if(SW_ptr->SW_Type == SW_u8PER)
	{
		if(SW_ptr->SW_PullType == SW_u8PullUP)
		{
			State = DIO_u8GetPinValue(SW_ptr->SW_PORT,SW_ptr->SW_PIN);
			if(State == LOW)
			{
				State=  SW_u8PRESSED ;
			}
			else
			{
				State = SW_u8NPRESSED;
			}
		}
		else if(SW_ptr->SW_PullType == SW_u8PullDOWN)
		{
			State = DIO_u8GetPinValue(SW_ptr->SW_PORT,SW_ptr->SW_PIN);
			if(State == HIGH)
			{
				State = SW_u8PRESSED ;
			}
			else
			{
				State = SW_u8NPRESSED;
			}
		}
	}
	else if(SW_ptr->SW_Type == SW_u8TEM)
	{
		if(SW_ptr->SW_PullType == SW_u8PullUP)
				{
					State = DIO_u8GetPinValue(SW_ptr->SW_PORT,SW_ptr->SW_PIN);
					if(State == LOW)
					{
						State = SW_u8PRESSED ;
					}
					else
					{
						State = SW_u8NPRESSED;
					}
					_delay_us(250);
				}
				else if(SW_ptr->SW_PullType == SW_u8PullDOWN)
				{
					State = DIO_u8GetPinValue(SW_ptr->SW_PORT,SW_ptr->SW_PIN);
					if(State == HIGH)
					{
						State = SW_u8PRESSED ;
					}
					else
					{
						State = SW_u8NPRESSED;
					}
					_delay_us(250);
				}
	}
	return State ;
}
