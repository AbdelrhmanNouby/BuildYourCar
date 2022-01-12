/*
 * Timer.h
 *
 * Created: 1/9/2022 12:20:30 AM
 *  Author: Binary Beasts
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../LIB/atmega32.h"
#include "../../LIB/Typedef.h"
#include "../../LIB/BIT_Math.h"

#define F_CPU 8000U
#define PRESCALER 64U

/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0


/* SREG */
#define I_BIT 7

// enum to describe Delay state 
typedef enum{
	DELAY_OFF,
	DELAY_ON
}DELAY;

// function to initialize timer0 
uint8_t TIMER0_u8Init(void);

// function delay by timer0 
uint8_t TIMER0_u8Delay(uint16_t delay);

//ISR for TIMER0 COMP
void __vector_10(void) __attribute__ ((signal, used));

#endif /* TIMER_H_ */
