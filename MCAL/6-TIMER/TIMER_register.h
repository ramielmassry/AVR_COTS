/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: MCAL				  ******************/
/***************		SWC: TIMER				  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define OCR0              *((volatile u8*)0x5C)       /*Output compare match register*/

#define TIMSK             *((volatile u8*)0x59)       /*Timer mask register*/
#define TIMSK_TOIE0       0                           /*Timer0 overflow interrupt enable*/
#define TIMSK_OCIE0       1                           /*Timer0 compare match interrupt enable*/

#define TCCR0             *((volatile u8*)0x53)       /*Timer counter control register 0*/
#define TCCR0_WGM00       6                           /*Waveform generation mode bit 0*/
#define TCCR0_WGM01       3                           /*Waveform generation mode bit 1*/

#define TCNT0             *((volatile u8*)0x52)       /*Timer Counter 0 register*/

#endif
