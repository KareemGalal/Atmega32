#include "..\..\Utilities\Types.h"
#include "..\..\Utilities\Delay.h"
#include "..\..\MCAL\DIO\DIO_interface.h"
#include "74HC595_Interface.h"
#include "74HC595_Config.h"
#include "74HC595_Private.h"

/*Comment!: change data to high (DS)lines*/
extern void HC595_voidDataHigh() {
	DIO_u8WritePinVal(HC595_DS, DIO_u8HIGH);
}
/*Comment!: change data to low (DS)lines*/
extern void HC595_voidDataLow() {
	DIO_u8WritePinVal(HC595_DS, DIO_u8LOW);
}
/*Comment!: Sends a clock pulse on SH_CP line*/
extern u8 HC595_u8ShiftPulse(void) {
	u8 Local_u8RetrunStatus;
	DIO_u8WritePinVal(HC595_SH_CP, DIO_u8HIGH);
	DIO_u8WritePinVal(HC595_SH_CP, DIO_u8LOW);
	Local_u8RetrunStatus = u8OK;
	return Local_u8RetrunStatus;
}
/*Comment!: Sends a clock pulse on ST_CP line*/
extern u8 HC595_u8LatchPulse(void) {
	u8 Local_u8RetrunStatus;
	DIO_u8WritePinVal(HC595_ST_CP, DIO_u8HIGH);
	// Delay_ms(1);
	DIO_u8WritePinVal(HC595_ST_CP, DIO_u8LOW);
	Local_u8RetrunStatus = u8OK;
	return Local_u8RetrunStatus;
}
/*Comment!: write a single byte to Output shift register 74HC595.*/
extern u8 HC595_u8WriteByte(u8 Copy_u8data) { //Send each 8 bits serially
	u8 Local_u8RetrunStatus;
	u8 Local_u8Loop;
	//Order is MSB first
	for (Local_u8Loop = 0; Local_u8Loop < 8; Local_u8Loop++) {
		//Output the data on DS line according to the Value of MSB
		if (Copy_u8data & 0b10000000) {
			HC595DataHigh(); //MSB is 1 so output high
		} else {
			HC595DataLow();	//MSB is 0 so output high
		}

		HC595Pulse();  //Pulse the Clock line
		Copy_u8data = Copy_u8data << 1;  //Now bring next bit at MSB position
	}
	//Now all 8 bits have been transferred to shift register
	//HC595Latch();//Move them to output latch at one
	Local_u8RetrunStatus = u8OK;
	return Local_u8RetrunStatus;
}
/*Comment!: Initialize HC595 System*/
extern void HC595_voidInit(void) {
	DIO_u8WritePinDir(HC595_DS, DIO_u8OUTPUT);
	DIO_u8WritePinDir(HC595_SH_CP, DIO_u8OUTPUT);
	DIO_u8WritePinDir(HC595_ST_CP, DIO_u8OUTPUT);
}

