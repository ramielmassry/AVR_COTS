/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: MCAL	    		  ******************/
/***************		SWC: ADC    			  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX             *((volatile u8*)0x27) 	    // ADC Multiplexer Register
#define ADMUX_REFS1       7                             // Reference select bit1
#define ADMUX_REFS0       6                             // Reference select bit0
#define ADMUX_ADLAR       5                             // Left adjust result


#define ADCSRA            *((volatile u8*)0x26) 	    // ADC Control And Status Register
#define ADCSRA_ADEN       7                             // Enable
#define ADCSRA_ADSC       6                             // Start Conversion
#define ADCSRA_ADATE      5                             // Auto trigger enable
#define ADCSRA_ADIF       4                             // Interrupt flag
#define ADCSRA_ADIE       3                             // Interrupt enable


#define ADCH 	          *((volatile u8*)0x25) 		// ADC High Register
#define ADCL 	          *((volatile u8*)0x24) 		// ADC Low Register

#endif 
