#include "..\..\Utilities\Types.h"
#include "..\..\Utilities\Delay.h"
#include "..\..\MCAL\DIO\DIO_interface.h"
#include "74HC595_Interface.h"
#include "74HC595_Config.h"
#include "74HC595_Private.h"

/*Comment!: change data to high (DS)lines*/
extern u8 HC595_u8DataHigh(u8 Copy_u8DeviceIdx) {
	u8 Local_u8RetrunStatus;
	switch (Copy_u8DeviceIdx) {
	case HC595_u8NUM1:
#if (HC595_IC1_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_DS1, DIO_u8HIGH);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM2:
#if (HC595_IC2_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_DS2, DIO_u8HIGH);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM3:
#if (HC595_IC3_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_DS3, DIO_u8HIGH);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM4:
#if (HC595_IC4_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_DS4, DIO_u8HIGH);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	default:
		Local_u8RetrunStatus = u8ERROR;
		break;
	}
	return Local_u8RetrunStatus;
}
/*Comment!: change data to low (DS)lines*/
extern u8 HC595_u8DataLow(u8 Copy_u8DeviceIdx) {
	u8 Local_u8RetrunStatus;
	switch (Copy_u8DeviceIdx) {
	case HC595_u8NUM1:
#if (HC595_IC1_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_DS1, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM2:
#if (HC595_IC2_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_DS2, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM3:
#if (HC595_IC3_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_DS3, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM4:
#if (HC595_IC4_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_DS4, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	default:
		Local_u8RetrunStatus = u8ERROR;
		break;
	}
	return Local_u8RetrunStatus;
}
/*Comment!: Sends a clock pulse on SH_CP line*/
extern u8 HC595_u8ShiftPulse(u8 Copy_u8DeviceIdx) {
	u8 Local_u8RetrunStatus;
	switch (Copy_u8DeviceIdx) {
	case HC595_u8NUM1:
#if (HC595_IC1_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_SH_CP1, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_SH_CP1, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM2:
#if (HC595_IC2_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_SH_CP2, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_SH_CP2, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM3:
#if (HC595_IC3_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_SH_CP3, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_SH_CP3, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM4:
#if (HC595_IC4_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_SH_CP4, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_SH_CP4, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	default:
		Local_u8RetrunStatus = u8ERROR;
		break;
	}
	return Local_u8RetrunStatus;
}
/*Comment!: Sends a clock pulse on ST_CP line*/
extern u8 HC595_u8LatchPulse(u8 Copy_u8DeviceIdx) {
	u8 Local_u8RetrunStatus;
	switch (Copy_u8DeviceIdx) {
	case HC595_u8NUM1:
#if (HC595_IC1_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_ST_CP1, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ST_CP1, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM2:
#if (HC595_IC2_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_ST_CP2, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ST_CP2, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM3:
#if (HC595_IC3_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_ST_CP3, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ST_CP3, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	case HC595_u8NUM4:
#if (HC595_IC4_INITSTATE == HC595_u8ONSTATE)
		DIO_u8WritePinVal(HC595_ST_CP4, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ST_CP4, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
#endif
		break;
	default:
		Local_u8RetrunStatus = u8ERROR;
		break;
	}
	return Local_u8RetrunStatus;
}
/*Comment!: write a single byte to Output shift register 74HC595.*/
extern u8 HC595_u8WriteByte(u8 Copy_u8DeviceIdx, u8 Copy_u8DataOneByte) { //Send each 8 bits serially
	u8 Local_u8RetrunStatus;
	if (Copy_u8DeviceIdx>HC595_u8NUMOFCONNECTED) {
		Local_u8RetrunStatus = u8ERROR;
	} else {
		u8 Local_u8LoopIndex;
		for (Local_u8LoopIndex = HC595_u8NUM_BITS_EACH_BYTE; Local_u8LoopIndex >= HC595_u8NUM_ZERO; Local_u8LoopIndex--) {
			if (!(Copy_u8DataOneByte & (HC595_u8NUM_ONE << Local_u8LoopIndex))) {//Output the data on DS line according to the Value of MSB
				HC595_u8DataLow(Copy_u8DeviceIdx);	//MSB is 0 so output high
			} else {
				HC595_u8DataHigh(Copy_u8DeviceIdx); //MSB is 1 so output high
			}
			HC595_u8ShiftPulse(Copy_u8DeviceIdx);  //Pulse the Clock line
		}//Now all 8 bits have been transferred to shift register
		Local_u8RetrunStatus = u8OK;
		HC595_u8ShiftPulse(Copy_u8DeviceIdx);//Move them to output latch at one
	}
	return Local_u8RetrunStatus;
	/*	switch (Copy_u8DeviceIdx) {
	 case HC595_u8NUM1:
	 #if (HC595_IC1_INITSTATE == HC595_u8ONSTATE)
	 for (Local_u8LoopIndex = HC595_u8NUM_BITS_EACH_BYTE; Local_u8LoopIndex >= HC595_u8NUM_ZERO; Local_u8LoopIndex--) {
	 //Output the data on DS line according to the Value of MSB
	 if (!(Copy_u8DataOneByte & (HC595_u8NUM_ONE << Local_u8LoopIndex))) {
	 HC595DataLow(Copy_u8DeviceIdx);	//MSB is 0 so output low
	 } else {
	 HC595DataHigh(Copy_u8DeviceIdx); //MSB is 1 so output high
	 }
	 HC595Pulse(Copy_u8DeviceIdx);  //Pulse the Clock line
	 }
	 Local_u8RetrunStatus = u8OK;
	 #endif
	 break;
	 case HC595_u8NUM2:
	 #if (HC595_IC2_INITSTATE == HC595_u8ONSTATE)
	 for (Local_u8LoopIndex = HC595_u8NUM_BITS_EACH_BYTE; Local_u8LoopIndex >= HC595_u8NUM_ZERO; Local_u8LoopIndex--) {
	 //Output the data on DS line according to the Value of MSB
	 if (!(Copy_u8DataOneByte & (HC595_u8NUM_ONE << Local_u8LoopIndex))) {
	 HC595DataLow(Copy_u8DeviceIdx);	//MSB is 0 so output low
	 } else {
	 HC595DataHigh(Copy_u8DeviceIdx); //MSB is 1 so output high
	 }
	 HC595Pulse(Copy_u8DeviceIdx);  //Pulse the Clock line
	 }
	 Local_u8RetrunStatus = u8OK;
	 #endif
	 break;
	 case HC595_u8NUM3:
	 #if (HC595_IC3_INITSTATE == HC595_u8ONSTATE)
	 for (Local_u8LoopIndex = HC595_u8NUM_BITS_EACH_BYTE; Local_u8LoopIndex >= HC595_u8NUM_ZERO; Local_u8LoopIndex--) {
	 //Output the data on DS line according to the Value of MSB
	 if (!(Copy_u8DataOneByte & (HC595_u8NUM_ONE << Local_u8LoopIndex))) {
	 HC595DataLow(Copy_u8DeviceIdx);	//MSB is 0 so output low
	 } else {
	 HC595DataHigh(Copy_u8DeviceIdx); //MSB is 1 so output high
	 }
	 HC595Pulse(Copy_u8DeviceIdx);  //Pulse the Clock line
	 }
	 Local_u8RetrunStatus = u8OK;
	 #endif
	 break;
	 case HC595_u8NUM4:
	 #if (HC595_IC4_INITSTATE == HC595_u8ONSTATE)
	 for (Local_u8LoopIndex = HC595_u8NUM_BITS_EACH_BYTE; Local_u8LoopIndex >= HC595_u8NUM_ZERO; Local_u8LoopIndex--) {
	 //Output the data on DS line according to the Value of MSB
	 if (!(Copy_u8DataOneByte & (HC595_u8NUM_ONE << Local_u8LoopIndex))) {
	 HC595DataLow(Copy_u8DeviceIdx);	//MSB is 0 so output low
	 } else {
	 HC595DataHigh(Copy_u8DeviceIdx); //MSB is 1 so output high
	 }
	 HC595Pulse(Copy_u8DeviceIdx);  //Pulse the Clock line
	 }
	 Local_u8RetrunStatus = u8OK;
	 #endif
	 break;
	 default:
	 Local_u8RetrunStatus = u8ERROR;
	 break;
	 }
	 return Local_u8RetrunStatus;
	 */
}
/*Comment!: Initialize HC595 System*/
extern void HC595_voidInit(void) {
//DIO_u8WritePinDir(HC595_DS, DIO_u8OUTPUT);
//DIO_u8WritePinDir(HC595_SH_CP, DIO_u8OUTPUT);
//DIO_u8WritePinDir(HC595_ST_CP, DIO_u8OUTPUT);
}

