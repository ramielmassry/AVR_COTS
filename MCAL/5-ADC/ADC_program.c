/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: MCAL	    		  ******************/
/***************		SWC: ADC    			  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"
#include "ADC_config.h"

/*Global pointer to carry the conversion result in the asynchronous execution*/
static u16* ADC_pu16ConversionResult = NULL;

/*Global pointer to function to carry the notification function called by ISR*/
static void (*ADC_pvNotificationFunc)(void) = NULL;

/*Global flag to indicate for the ADC busy state*/
static u8 ADC_u8State= IDLE;

void ADC_voidInit(void)
{
	/*Select AVCC reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*Activate Left adjust result (8 bit resolution)*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	ADCSRA &= 0b11111000;             /*Clear first 3 bits in ADCSRA register*/
	ADCSRA |= ADC_u8PRESCALER ;       /*Set the required configuration*/

	/*Enable ADC peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16* Copy_pu16Result)
{
	u32 Local_u32Counter=0;
    u8 Local_u8ErrorState=OK;

    if(Copy_pu16Result != NULL)
    {
    	if(ADC_u8State == IDLE)
    	{
    		/*ADC is now busy*/
    		ADC_u8State = BUSY;

    		/*Clear first 5 bits in ADMUX register*/
    		ADMUX &= 0b11100000;

	    	/*set required channel*/
	    	ADMUX |= Copy_u8Channel;

	    	/*Start conversion*/
	    	SET_BIT(ADCSRA,ADCSRA_ADSC);

	    	/*Busy waiting (polling) until the conversion is complete or until timeout is reached*/
	    	while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0) && (Local_u32Counter < ADC_u32TIMEOUT))
	    	{
	    		Local_u32Counter++;
	    	}
		    if(Local_u32Counter==ADC_u32TIMEOUT)
		    {
		    	/*Loop is broken because timeout is reached*/
		    	Local_u8ErrorState = TIMEOUT_STATE;
		    }
		    else
		    {
		    	/*Loop is broken because flag is raised*/
		    	/*clear the interrupt flag*/
		    	SET_BIT(ADCSRA,ADCSRA_ADIF);

		    	*Copy_pu16Result = ADCH;
		    }
		   /*ADC is finished and is now Idle*/
		   ADC_u8State = IDLE;
	    }
	    else
	    {
	    	Local_u8ErrorState = BUSY_STATE;
	    }
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;

}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16* Copy_pu16Result,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if((Copy_pu16Result!= NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if(ADC_u8State == IDLE)
		{
			/*ADC is now busy*/
			ADC_u8State = BUSY;

			/*Initialize the global result pointer*/
			ADC_pu16ConversionResult = Copy_pu16Result;

			/*Initialize the global notification function pointer*/
			ADC_pvNotificationFunc= Copy_pvNotificationFunc;

			/*Clear first 5 bits in ADMUX register*/
			ADMUX &= ADC_u8CHANNEL_MASK;

			/*set required channel*/
			ADMUX |= Copy_u8Channel;

			/*Start the conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC conversion complete interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;

}

void __vector_16 (void)			__attribute__((signal));
void __vector_16 (void)
{
	/*Read the result*/
	ADC_pu16ConversionResult = ADCH;

	/*ADC is now IDLE*/
	ADC_u8State= IDLE;

	/*Invoke the callback notification function*/
	ADC_pvNotificationFunc();

	/*Disable the ADC conversion complete Interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}


