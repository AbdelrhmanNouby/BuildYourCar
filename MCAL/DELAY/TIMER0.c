/*
 * TIMER.c
 *
 * Created: 1/9/2022 2:41:02 AM
 *  Author: Binary Beasts
 */ 


#include "../../ECUAL/LED/LED.h"
#include "TIMER0.h"

// variable used in interrupt to compare with delay 
static uint16_t volatile counter;

// function to initialize timer0  
uint8_t TIMER0_u8Init(void){
	TCCR0_REG = (1 << WGM01) | (1<<CS01) | (1 << CS00);	
	return 1;
}

// function delay by timer0 
uint8_t TIMER0_u8Delay(uint16_t delay){
	counter=0;							// reset counter to 0 
	TIMER0_u8Init();					// initialize timer0  
	OCR0_REG = (F_CPU / PRESCALER);		// set OCR0_REG value 
	SET_BIT(TIMSK_REG, OCIE0);			// enable interrupt 
	SET_BIT(SREG_REG, I_BIT);
	while (counter <= delay);			// stop if delay not finished 
	CLR_BIT(TIMSK_REG, OCIE0);			
	return 1;
}

// increase counter eche interrupt 
void __vector_10(void){
	counter++;
}

