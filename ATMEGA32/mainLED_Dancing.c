/*
 * main.c
 *
 *  Created on: Feb 1, 2016
 *      Author: KiMo
 */

#include "Utilities\Types.h"
#include "Utilities\Delay.h"
#include "MCAL\DIO\DIO_Interface.h"

int main(void) {
	u8 Local_u8Index;
	u8 Local_u8Value;
	DIO_voidInit();
	while (1) {
		DIO_u8WritePortVal(DIO_u8PORT2, 0xFF); /*All the 8 LEDs of LED array are On*/
		voidDELAY_MS(200);
		DIO_u8WritePortVal(DIO_u8PORT2, 0x00); /*All the 8 LEDs of LED array are Off*/
		voidDELAY_MS(200);

		/*For loop for LED pattern 1*/
		for (Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++) {
			Local_u8Value = 0x01 << Local_u8Index;
			DIO_u8WritePortVal(DIO_u8PORT2, Local_u8Value);
			voidDELAY_MS(200);
		}

		DIO_u8WritePortVal(DIO_u8PORT2, 0x00); /*All the 8 LEDs of LED array are Off*/
		voidDELAY_MS(200);

		/*For loop for LED pattern 2*/
		for (Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++) {
			Local_u8Value = 0x80 >> Local_u8Index;
			DIO_u8WritePortVal(DIO_u8PORT2, Local_u8Value);
			voidDELAY_MS(200);
		}

		DIO_u8WritePortVal(DIO_u8PORT2, 0x00); /*All the 8 LEDs of LED array are Off*/
		voidDELAY_MS(200);

		/*For loop for LED pattern 3*/
		for (Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++) {
			DIO_u8ReadPortVal(DIO_u8PORT2, &Local_u8Value);
			Local_u8Value = (0x01 << Local_u8Index) | Local_u8Value;
			DIO_u8WritePortVal(DIO_u8PORT2, Local_u8Value);
			voidDELAY_MS(200);
		}

		DIO_u8WritePortVal(DIO_u8PORT2, 0x00); /*All the 8 LEDs of LED array are Off*/
		voidDELAY_MS(200);

		/*For loop for LED pattern 4*/
		for (Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++) {
			DIO_u8ReadPortVal(DIO_u8PORT2, &Local_u8Value);
			Local_u8Value = (0x80 >> Local_u8Index) | Local_u8Value;
			DIO_u8WritePortVal(DIO_u8PORT2, Local_u8Value);
			voidDELAY_MS(200);
		}

		DIO_u8WritePortVal(DIO_u8PORT2, 0x00); /*All the 8 LEDs of LED array are Off*/
		voidDELAY_MS(200);

		/*For loop for LED pattern 5*/
		for (Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++) {
			Local_u8Value = (0x10 << Local_u8Index) | (0x08 >> Local_u8Index);
			DIO_u8WritePortVal(DIO_u8PORT2, Local_u8Value);
			voidDELAY_MS(200);
		}

		DIO_u8WritePortVal(DIO_u8PORT2, 0x00); /*All the 8 LEDs of LED array are Off*/
		voidDELAY_MS(200);

		/*For loop for LED pattern 6*/
		for (Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++) {
			Local_u8Value = (0x80 >> Local_u8Index) | (0x01 << Local_u8Index);
			DIO_u8WritePortVal(DIO_u8PORT2, Local_u8Value);
			voidDELAY_MS(200);
		}

		DIO_u8WritePortVal(DIO_u8PORT2, 0x00); /*All the 8 LEDs of LED array are Off*/
		voidDELAY_MS(200);

		/*For loop for LED pattern 7*/
		for (Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++) {
			DIO_u8ReadPortVal(DIO_u8PORT2, &Local_u8Value);
			Local_u8Value = (0x10 << Local_u8Index) | (0x08 >> Local_u8Index) | Local_u8Value;
			DIO_u8WritePortVal(DIO_u8PORT2, Local_u8Value);
			voidDELAY_MS(200);
		}

		DIO_u8WritePortVal(DIO_u8PORT2, 0x00); /*All the 8 LEDs of LED array are Off*/
		voidDELAY_MS(200);

		/*For loop for LED pattern 8*/
		for (Local_u8Index = 0; Local_u8Index < 8; Local_u8Index++) {
			DIO_u8ReadPortVal(DIO_u8PORT2, &Local_u8Value);
			Local_u8Value = (0x01 << Local_u8Index) | (0x80 >> Local_u8Index) | Local_u8Value;
			DIO_u8WritePortVal(DIO_u8PORT2, Local_u8Value);
			voidDELAY_MS(200);
		}
	}
	return 0;
}
