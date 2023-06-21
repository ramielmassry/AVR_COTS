/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: MCAL				  ******************/
/***************		SWC: TIMER				  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

/*Global pointer to function to hold the callback function address*/
static void (*Timer0_pvOverflowCallBackFunc)(void) = NULL;

static void (*Timer0_pvCompMatchCallBackFunc)(void) = NULL;

void Timer0_voidInit(void)
{

	/*Initialize waveform generation mode to work as normal mode*/
	//CLR_BIT(TCCR0,TCCR0_WGM00);
	//CLR_BIT(TCCR0,TCCR0_WGM01);

	/*Initialize waveform generation mode to work as CTC mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Set the required preload value*/
	//TCNT0 = TIMER0_u8PRELOAD_VAL;

	/*Set the required compare match value*/
	OCR0 = TIMER0_u8COMPARE_MATCH_VAL;

	/*Timer0 overflow interrupt enable*/
	//SET_BIT(TIMSK,TIMSK_TOIE0);

	/*Timer0 compare match interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*Set the required prescaler*/
	TCCR0 &= TIMER0_PRESCALER_MASK;
	TCCR0 |= TIMER0_u8PRESCALER;
}

u8 Timer0_u8OverflowSetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_pvCallBackFunc != NULL)
	{
		Timer0_pvOverflowCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

u8 Timer0_u8CompMatchSetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		Timer0_pvCompMatchCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;

}

void Timer0_voidSetPreload(u8 Copy_u8PRELOAD)
{
	TCNT0 = Copy_u8PRELOAD;
}


/*TIMER0 overflow ISR*/
void __vector_11 (void)    __attribute__((signal));
void __vector_11 (void)
{
	if(Timer0_pvOverflowCallBackFunc != NULL)
	{
		Timer0_pvOverflowCallBackFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*TIMER0 Compare <Match ISR*/
void __vector_10 (void)    __attribute__((signal));
void __vector_10 (void)
{
	if(Timer0_pvCompMatchCallBackFunc != NULL)
	{
		Timer0_pvCompMatchCallBackFunc();
	}
	else
	{
		/*Do Nothing*/
	}
}
