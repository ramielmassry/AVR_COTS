/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: HAL				  ******************/
/***************		SWC: SWITCH				  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SWITCH_config.h"

u8 SWITCH_u8GetPin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Value, Local_u8State;
	DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Local_u8Value);
	
	switch (SWITCH_CONNECTION)
	{
	case PullUp_connection:
		if(Local_u8Value==DIO_u8PIN_HIGH){
			Local_u8State= NOT_PRESSED;
		}
		if(Local_u8Value==DIO_u8PIN_LOW){
			Local_u8State= PRESSED;
		}
		break;
	case PullDown_connection:
		if(Local_u8Value==DIO_u8PIN_LOW){
			Local_u8State= NOT_PRESSED;
		}
		if(Local_u8Value==DIO_u8PIN_HIGH){
			Local_u8State=PRESSED;
		}
		break;
	}
	return Local_u8State;


}