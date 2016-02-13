/*
 * main.c
 *
 *  Created on: Feb 1, 2016
 *      Author: KiMo
 */

#include "Utilities\Types.h"
#include "MCAL\DIO\DIO_Interface.h"
#include "MCAL\DIO\DIO_Delay.h"
#include "HAL\SSD\SSD_Interface.h"

#define SWITCHPIN			DIO_u8PIN15
#define TRUE				1
#define	FALSE				0
#define	CONFIDENCE_LEVEL	200
int main(void) {
	//u8 Local_u8Index;
	//u8 Local_u8Value;
	DIO_voidInit();
	SSD_voidInit();
	u16 local_u8Counter = 123;
	u8 local_u8SwitchValue = 0;
	u8 local_u8SwitchPressed = FALSE;
	u16 Pressed_Confidence_Level = 0;
	u16 Released_Confidence_Level = 0;
	SSD_u8TurnOff(SSD_u8DISP1);
	SSD_u8TurnOff(SSD_u8DISP2);
	SSD_u8TurnOff(SSD_u8DISP3);
	SSD_u8TurnOff(SSD_u8DISP4);
	while (1) {
		//Assign Data then Turn on the Display1
		SSD_u8Display(SSD_u8DISP1, ((local_u8Counter % 1000) % 100) % 10);	//3
		SSD_u8TurnOn(SSD_u8DISP1);
		voidDELAY_MS(5);
		SSD_u8TurnOff(SSD_u8DISP1);
		//Assign Data then Turn on the Display2
		SSD_u8Display(SSD_u8DISP2, ((local_u8Counter % 1000) % 100) / 10);	//2
		SSD_u8TurnOn(SSD_u8DISP2);
		voidDELAY_MS(5);
		SSD_u8TurnOff(SSD_u8DISP2);
		//Assign Data then Turn on the Display3
		SSD_u8Display(SSD_u8DISP3, (local_u8Counter % 1000) / 100);	//1
		SSD_u8TurnOn(SSD_u8DISP3);
		voidDELAY_MS(5);
		SSD_u8TurnOff(SSD_u8DISP3);
		//Assign Data then Turn on the Display4
		SSD_u8Display(SSD_u8DISP4, (local_u8Counter / 1000) % 10);	//0
		SSD_u8TurnOn(SSD_u8DISP4);
		voidDELAY_MS(5);
		SSD_u8TurnOff(SSD_u8DISP4);
		DIO_u8ReadPinVal(SWITCHPIN, &local_u8SwitchValue);
		if (!local_u8SwitchValue) {
			Pressed_Confidence_Level++; //Increase Pressed Confidence
			Released_Confidence_Level = 0; //Reset released button confidence since there is a button press
			if (Pressed_Confidence_Level > CONFIDENCE_LEVEL) { //Indicator of good button press
				if (!local_u8SwitchPressed) {
					local_u8Counter++;
					local_u8SwitchPressed = TRUE;
				}
				//Zero it so a new pressed condition can be evaluated
				Pressed_Confidence_Level = 0;
			}
		} else {
			Released_Confidence_Level++; //This works just like the pressed
			Pressed_Confidence_Level = 0; //Reset pressed button confidence since the button is released
			if (Released_Confidence_Level > CONFIDENCE_LEVEL) { //Indicator of good button release
				local_u8SwitchPressed = FALSE;
				Released_Confidence_Level = 0;
			}
		}
	}
	return 0;
}
