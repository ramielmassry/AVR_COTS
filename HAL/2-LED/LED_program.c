/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: HAL				  ******************/
/***************		SWC: LED				  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_config.h"
#include "DIO_interface.h"

void LED_ON(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	if(LED_CONNECTION == source_connection)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin, DIO_u8PIN_HIGH);
	}
	if(LED_CONNECTION == sink_connection)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin, DIO_u8PIN_LOW);
	}
}

void LED_OFF(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	if(LED_CONNECTION == source_connection)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin, DIO_u8PIN_LOW);
		}
	if(LED_CONNECTION == sink_connection)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin, DIO_u8PIN_HIGH);
	}
}


void LED_Toggle(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	DIO_u8TogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin);
}

