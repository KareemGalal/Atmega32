/*
 * main.c
 *
 *  Created on: Feb 1, 2016
 *      Author: KiMo
 */

#include "Utilities\Types.h"
#include "Utilities\Delay.h"
#include "MCAL\DIO\DIO_Interface.h"
#include "HAL\74HC595\74HC595_Interface.h"
#include "HAL\TSW\TSW_Interface.h"

#define	RAWS		HC595_u8NUM1
#define	COLUMNS		HC595_u8NUM2

static const u8 MyName[6][8] = { { 0x42, 0x44, 0x48, 0x70, 0x70, 0x48, 0x44,
		0x42 }, { 0x3C, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42 }, { 0x78,
		0x44, 0x48, 0x70, 0x70, 0x48, 0x44, 0x42 }, { 0x78, 0x40, 0x40, 0x78,
		0x40, 0x40, 0x40, 0x78 }, { 0x78, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40,
		0x78 }, { 0x42, 0x66, 0x5A, 0x42, 0x42, 0x42, 0x42, 0x42 } };//KAREEM
int main(void) {
	u8 Local_u8Row;	//Row Number ?
	u16 Local_u8Counter = 0; //counter for delay
	u8 Local_u8SwitchValue;	//To store the switch value
	u8 local_u8SwitchPressed = FALSE; //flag to run the SW in the single mode
	DIO_voidInit();
	HC595_voidInit();
	TSW_voidInit();
	// For Testing, Turn on all Leds
	HC595_u8WriteByte(RAWS, DIO_u8PORTHIGH);/*All ROWS are ON*/
	HC595_u8WriteByte(COLUMNS, DIO_u8PORTLOW); /*All Columns are Off*/
	voidDELAY_MS(1000);	// Delay 1 Sec
	// Turn off all Leds
	HC595_u8WriteByte(RAWS, DIO_u8PORTLOW); /*All ROWS are Off*/
	HC595_u8WriteByte(COLUMNS, DIO_u8PORTLOW); /*All Columns are Off*/
	voidDELAY_MS(1000);	//Delay 1 Sec
	while (1) {

		for (Local_u8Row = 0; Local_u8Row < 8; Local_u8Row++) {
			HC595_u8WriteByte(RAWS, DIO_u8PORTLOW); //turn off all Rows
			HC595_u8WriteByte(COLUMNS, ~MyName[(Local_u8Counter / 800) % 6][Local_u8Row]); // assign the specific row's data to the corresponded columns
			HC595_u8WriteByte(RAWS, (1 << Local_u8Row)); //Turn on the specific Row
		}
		TSW_u8CheckSwitch(TSW_u8NUM1, &Local_u8SwitchValue);
		if (Local_u8SwitchValue == TSW_u8PRESSED) {
			if (!local_u8SwitchPressed) {
				Local_u8Counter++; // increment the counter
				local_u8SwitchPressed = TRUE;
			}
		} else {
			local_u8SwitchPressed = FALSE;
		}
	}
	return 0;
}
