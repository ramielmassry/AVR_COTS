/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: MCAL				  ******************/
/***************		SWC: TIMER				  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer0_voidInit(void);

u8 Timer0_u8OverflowSetCallBack(void(*Copy_pvCallBackFunc)(void));

u8 Timer0_u8CompMatchSetCallBack(void(*Copy_pvCallBackFunc)(void));

void Timer0_voidSetPreload(u8 Copy_u8PRELOAD);

#endif
