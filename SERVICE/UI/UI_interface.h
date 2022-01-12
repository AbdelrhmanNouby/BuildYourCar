/*
 * UI.h
 *
 *  Created on: Jan 10, 2022
 *      Author: Binary Beasts
 */

#ifndef UI_H_
#define UI_H_

#include "../../LIB/BIT_Math.h"
#include "../../LIB/Typedef.h"
#include "../../ECUAL/LED/LED.h"
#include "../../ECUAL/KEYPAD/KEYPAD_interface.h"

// function to get presed key 
uint8_t UI_GetKeyPressed(uint8_t* UI_keyModuleReturn);

// function to initialize UI
uint8_t UI_Init(void);

// function to synchronization LEDs with move modes 
uint8_t UI_SetLedModuleState(uint8_t UI_LEDModuleState);



#endif /* UI_H_ */
