/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: MCAL	    		  ******************/
/***************		SWC: PORT   			  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define DDRA 	 	*((volatile u8*)0x3A)    
#define PORTA	 	*((volatile u8*)0x3B)	 

#define DDRB 		*((volatile u8*)0x37)  
#define PORTB		*((volatile u8*)0x38)  

#define DDRC 		*((volatile u8*)0x34)  
#define PORTC		*((volatile u8*)0x35)    

#define DDRD 		*((volatile u8*)0x31)  
#define PORTD		*((volatile u8*)0x32)

#endif