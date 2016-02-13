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

int main(void) {
	//u8 Local_u8Index;
	//u8 Local_u8Value;
	DIO_voidInit();
	SSD_voidInit();
	u8 local_u8Counter=0;
	SSD_u8TurnOff(SSD_u8DISP1);
	SSD_u8TurnOff(SSD_u8DISP2);
	while (1) {
		//Assign Data then Turn on the Display1
		SSD_u8Display(SSD_u8DISP1, local_u8Counter%10);
		SSD_u8TurnOn(SSD_u8DISP1);
		voidDELAY_MS(10);
		SSD_u8TurnOff(SSD_u8DISP1);
		//Assign Data then Turn on the Display2
		SSD_u8Display(SSD_u8DISP2, (local_u8Counter/10)%10);
		SSD_u8TurnOn(SSD_u8DISP2);
		voidDELAY_MS(10);
		SSD_u8TurnOff(SSD_u8DISP2);
		local_u8Counter++;
	}
	return 0;
}
