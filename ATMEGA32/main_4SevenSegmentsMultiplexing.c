/*
 * main.c
 *
 *  Created on: Feb 1, 2016
 *      Author: KiMo
 */

#include "Utilities\Types.h"
#include "Utilities\Delay.h"
#include "MCAL\DIO\DIO_Interface.h"
#include "HAL\SSD\SSD_Interface.h"

int main(void) {
	//u8 Local_u8Index;
	//u8 Local_u8Value;
	DIO_voidInit();
	SSD_voidInit();
	u16 local_u8Counter = 123;
	u8 local_u8flag = 0;
	SSD_u8TurnOff(SSD_u8DISP1);
	SSD_u8TurnOff(SSD_u8DISP2);
	SSD_u8TurnOff(SSD_u8DISP3);
	SSD_u8TurnOff(SSD_u8DISP4);
	while (1) {
		//Assign Data then Turn on the Display1
		SSD_u8Display(SSD_u8DISP1, (u16) ((local_u8Counter % 1000) % 100) % 10);//3
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
		if (local_u8flag != 0) {
			local_u8flag--;
		} else {
			local_u8flag = 50;
			local_u8Counter++;
		}
	}
	return 0;
}
