/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: HAL				  ******************/
/***************		SWC: DC Motor			  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DC_Motor_interface.h"
#include "DC_Motor_config.h"

void DC_Motor_RotCW(void)
{
	DIO_u8SetPinValue(DC_Motor_PORT,DC_Motor_PINB,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_Motor_PORT,DC_Motor_PINA,DIO_u8PIN_HIGH);
}
void DC_Motor_RotCCW(void)
{
	DIO_u8SetPinValue(DC_Motor_PORT,DC_Motor_PINA,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_Motor_PORT,DC_Motor_PINB,DIO_u8PIN_HIGH);
}
void DC_Motor_Stop(void)
{
	DIO_u8SetPinValue(DC_Motor_PORT,DC_Motor_PINA,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_Motor_PORT,DC_Motor_PINB,DIO_u8PIN_LOW);
}
