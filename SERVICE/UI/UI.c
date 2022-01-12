/*
 * UI.c
 *
 *  Created on: Jan 10, 2022
 *      Author: Binary Beasts
 */

#include "UI_interface.h"
#include "UI_prv.h"

// configure 4 led as indication about mode operation 
LED_t Mode_A = {PORTB, PIN4};
LED_t Mode_B = {PORTB, PIN5};
LED_t Mode_C = {PORTB, PIN6};
LED_t Mode_D = {PORTB, PIN7};

// function to initialize Keypad and LEDs 
uint8_t UI_Init()
{
	uint8_t u8ErrorState = STD_TYPES_OK;

	LED_u8Init(Mode_A);
	LED_u8Init(Mode_B);
	LED_u8Init(Mode_C);
	LED_u8Init(Mode_D);


	KEYPAD_u8Init();
	return u8ErrorState;
}

// function to get presed key 
uint8_t UI_GetKeyPressed(uint8_t* UI_keyModuleReturn)
{
	uint8_t u8ErrorState= STD_TYPES_OK;
	u8ErrorState= KEYPAD_u8GetPressedKey(UI_keyModuleReturn);
	return u8ErrorState;
}

// function to synchronization LEDs with move modes 
uint8_t UI_SetLedModuleState(uint8_t UI_LEDModuleState)
{
	uint8_t u8ErrorState= STD_TYPES_OK;
	LED_u8Off(Mode_A);
	LED_u8Off(Mode_B);
	LED_u8Off(Mode_C);
	LED_u8Off(Mode_D);

	switch (UI_LEDModuleState)
	{
	case MODE1_ON:					// the first speed 
		LED_u8On(Mode_A);
		break;
	case MODE2_ON:					// the second speed 
		LED_u8On(Mode_B);
		break;
	case MODE3_ON:					// the third speed 
		LED_u8On(Mode_C);
		break;
	case MODE4_ON:					// backward mode 
		LED_u8On(Mode_D);
		break;
	case ALL_ON:					// stop mode 
		LED_u8On(Mode_A);
		LED_u8On(Mode_B);
		LED_u8On(Mode_C);
		LED_u8On(Mode_D);
		break;
	default:
		u8ErrorState  = STD_TYPES_NOK;
		break;
	}

	return u8ErrorState;
}
