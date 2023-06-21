/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: MCAL	    		  ******************/
/***************		SWC: ADC    			  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16* Copy_pu16Result);

/* Preconditions : Enable the global interrupt before calling this function */
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16* Copy_pu16Result,void(*Copy_pvNotificationFunc)(void));

#endif
