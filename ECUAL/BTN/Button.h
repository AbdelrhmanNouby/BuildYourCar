/*
 * Button.h
 *
 * Created: 1/10/2022 12:13:12 AM
 *  Author: Binary Beasts
 */ 

#ifndef __Button_H_
#define __Button_H_

#include "../../LIB/Typedef.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"

// struct to configure button connection 
typedef struct 
{
	uint8_t port ;
	uint8_t pin ;	
}BTN_t;

#define BTN_PRESSED 	1
#define BTN_NOT_PRESSED 0

// function to initialize button 
uint8_t BTN_u8Init ( BTN_t button );

// function to check button preesed or not 
uint8_t BTN_u8IsPressed ( BTN_t button , uint8_t * pressed );

#endif 	/* Button.h */