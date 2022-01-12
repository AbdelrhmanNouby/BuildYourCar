/*
 * main.c
 *
 *  Created on: Jan 11, 2022
 *      Author: Binary Beasts
 */

#include "LIB/Typedef.h"
#include "LIB/BIT_Math.h"
#include "ECUAL/BTN/Button.h"
#include "ECUAL/LED/LED.h"
#include "ECUAL/KEYPAD/KEYPAD_interface.h"
#include "MCAL/DELAY/TIMER0.h"
#include "SERVICE/DRIVE/DRIVE.h"
#include "SERVICE/UI/UI_interface.h"
#define OFF 0
#define ON  1

int main ()
{
	uint8_t KeyState;
	uint8_t MOTION_STATE = MODE1;
	LED_t LED0 = {PORTB, PIN5};
	LED_u8Init(LED0);
	DRIVE_u8Init();
	UI_Init();
	KEYPAD_u8Init();

	while (1)
	{
		UI_GetKeyPressed(&KeyState);    // get which key is pressed 
		if (KeyState==2)				// if move button pressed 
		{
			DRIVE_u8Mode(MOTION_STATE);			// move with last motion mode 
			while (KeyState==2)					// stay here if still pressed 
			{
				UI_GetKeyPressed(&KeyState);
			}
		}

		else if(KeyState==6)		// if right button pressed 
		{
			DRIVE_u8Right();		// rotate right 
		}

		else if (KeyState==4)		// if left button pressed 
		{
			DRIVE_u8Left();			// rotate left 
		}

		else if (KeyState==5)		// change mode button pressed 
		{
			MOTION_STATE++;			// update mode 
			while (KeyState==5)		// stay here if still pressed 
			{
				UI_GetKeyPressed(&KeyState);
			}
			if (MOTION_STATE==5)	// if car reached to the last mode 
			{
				MOTION_STATE = MODE2;		// back to  this mode 
			}
			UI_SetLedModuleState(MOTION_STATE);	   // turn led indicator about motion mode 

		}

		else{
			DRIVE_u8Mode(MODE1);		// stop the car  
		}


	}
	return 0;
}
