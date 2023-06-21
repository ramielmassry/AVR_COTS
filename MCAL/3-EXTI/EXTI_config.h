/*******************************************************************/
/*******************************************************************/
/***************		Author: RAMI EL MASSRY	  ******************/
/***************		Layer: MCAL	    		  ******************/
/***************		SWC: EXTI   			  ******************/
/***************		Version: 1.00			  ******************/
/*******************************************************************/
/*******************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H_

/*
 * Choose INT0 Sense Control (trigger sense)
 * Options: 1- LOW_LEVEL
 * 			2- ON_CHANGE
 * 			3- FALLING_EDGE
 * 			4- RISING_EDGE
 */
#define EXTI_INT0_SENSE				FALLING_EDGE

/*
 * choose INT0 peripheral interrupt enable initial state
 * Options : 1-ENABLED
 * 			 2-DISABLED
 */
#define EXTI_INT0_INITIAL_STATE		ENABLED

#endif
