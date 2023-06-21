/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: HAL				  ******************/
/***************		SWC: SWITCH				  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

/*choose sink or source */
#define PullUp_connection 		    1
#define PullDown_connection 	    0

#define SWITCH_CONNECTION 			PullUp_connection
#define SWITCH_PORTA  				DIO_u8PORTA
#define SWITCH_PORTB 				DIO_u8PORTB
#define SWITCH_PORTC 				DIO_u8PORTC
#define SWITCH_PORTD 				DIO_u8PORTD

#define SWITCH_PIN0				DIO_u8PIN0
#define SWITCH_PIN1				DIO_u8PIN1
#define SWITCH_PIN2				DIO_u8PIN2
#define SWITCH_PIN3				DIO_u8PIN3
#define SWITCH_PIN4				DIO_u8PIN4
#define SWITCH_PIN5				DIO_u8PIN5
#define SWITCH_PIN6				DIO_u8PIN6
#define SWITCH_PIN7				DIO_u8PIN7

#define PRESSED					   1
#define NOT_PRESSED			       0

#endif 
