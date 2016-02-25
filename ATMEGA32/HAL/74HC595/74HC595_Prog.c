#include "..\..\Utilities\Types.h"
#include "..\..\Utilities\Delay.h"
#include "..\..\MCAL\DIO\DIO_interface.h"
#include "74HC595_Config.h"
#include "74HC595_Interface.h"
#include "74HC595_Private.h"

/*Comment!: change data to high (DS)lines*/
extern u8 HC595_u8DataHigh(u8 Copy_u8DeviceIdx) {
	u8 Local_u8RetrunStatus;
	switch (Copy_u8DeviceIdx) {
#if (HC595_ID1_INITSTATE == HC595_u8ONSTATE)
	case HC595_u8NUM1:
		DIO_u8WritePinVal(HC595_ID1_SER_DATA_PIN, DIO_u8HIGH);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID2_INITSTATE == HC595_u8ONSTATE)
	case HC595_u8NUM2:
		DIO_u8WritePinVal(HC595_ID2_SER_DATA_PIN, DIO_u8HIGH);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID3_INITSTATE == HC595_u8ONSTATE)
		case HC595_u8NUM3:
		DIO_u8WritePinVal(HC595_ID3_SER_DATA_PIN, DIO_u8HIGH);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID4_INITSTATE == HC595_u8ONSTATE)
		case HC595_u8NUM4:
		DIO_u8WritePinVal(HC595_ID4_SER_DATA_PIN, DIO_u8HIGH);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
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
#if (HC595_ID1_INITSTATE == HC595_u8ONSTATE)
	case HC595_u8NUM1:
		DIO_u8WritePinVal(HC595_ID1_SER_DATA_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID2_INITSTATE == HC595_u8ONSTATE)
	case HC595_u8NUM2:
		DIO_u8WritePinVal(HC595_ID2_SER_DATA_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID3_INITSTATE == HC595_u8ONSTATE)
		case HC595_u8NUM3:
		DIO_u8WritePinVal(HC595_ID3_SER_DATA_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID4_INITSTATE == HC595_u8ONSTATE)
		case HC595_u8NUM4:
		DIO_u8WritePinVal(HC595_ID4_SER_DATA_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
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
#if (HC595_ID1_INITSTATE == HC595_u8ONSTATE)
	case HC595_u8NUM1:
		DIO_u8WritePinVal(HC595_ID1_SCK_PIN, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ID1_SCK_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID2_INITSTATE == HC595_u8ONSTATE)
	case HC595_u8NUM2:
		DIO_u8WritePinVal(HC595_ID2_SCK_PIN, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ID2_SCK_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID3_INITSTATE == HC595_u8ONSTATE)
		case HC595_u8NUM3:
		DIO_u8WritePinVal(HC595_ID3_SCK_PIN, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ID3_SCK_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID4_INITSTATE == HC595_u8ONSTATE)
		case HC595_u8NUM4:
		DIO_u8WritePinVal(HC595_ID4_SCK_PIN, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ID4_SCK_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
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
#if (HC595_ID1_INITSTATE == HC595_u8ONSTATE)
	case HC595_u8NUM1:
		DIO_u8WritePinVal(HC595_ID1_RCK_PIN, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ID1_RCK_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID2_INITSTATE == HC595_u8ONSTATE)
	case HC595_u8NUM2:
		DIO_u8WritePinVal(HC595_ID2_RCK_PIN, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ID2_RCK_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID3_INITSTATE == HC595_u8ONSTATE)
		case HC595_u8NUM3:
		DIO_u8WritePinVal(HC595_ID3_RCK_PIN, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ID3_RCK_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#if (HC595_ID4_INITSTATE == HC595_u8ONSTATE)
		case HC595_u8NUM4:
		DIO_u8WritePinVal(HC595_ID4_RCK_PIN, DIO_u8HIGH);
		DIO_u8WritePinVal(HC595_ID4_RCK_PIN, DIO_u8LOW);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
	default:
		Local_u8RetrunStatus = u8ERROR;
		break;
	}
	return Local_u8RetrunStatus;
}
/*Comment!: write a single byte to Output shift register 74HC595.*/
extern u8 HC595_u8WriteByte(u8 Copy_u8DeviceIdx, u8 Copy_u8DataOneByte) { //Send each 8 bits serially
	u8 Local_u8RetrunStatus;
	if (Copy_u8DeviceIdx > HC595_u8NUMOFCONNECTED) {
		Local_u8RetrunStatus = u8ERROR;
	} else {
		s8 Local_u8LoopIndex; //Take care of that because we loop till zero and we need it
		for (Local_u8LoopIndex = HC595_u8NUM_BITS_EACH_BYTE;
				Local_u8LoopIndex >= HC595_u8NUM_ZERO; Local_u8LoopIndex--) {
			if (!(Copy_u8DataOneByte & (HC595_u8NUM_ONE << Local_u8LoopIndex))) { //Output the data on DS line according to the Value of MSB
				HC595_u8DataLow(Copy_u8DeviceIdx);	//MSB is 0 so output high
			} else {
				HC595_u8DataHigh(Copy_u8DeviceIdx); //MSB is 1 so output high
			}
			HC595_u8ShiftPulse(Copy_u8DeviceIdx);  //Pulse the Clock line
		}  //Now all 8 bits have been transferred to shift register
		   //HC595_u8LatchPulse(Copy_u8DeviceIdx); //Move them to output latch at one
		Local_u8RetrunStatus = u8OK;
	}
	return Local_u8RetrunStatus;
}
/*Comment!: Initialize HC595 System*/
extern void HC595_voidInit(void) {
//DIO_u8WritePinDir(HC595_ID1_SER_DATA_PIN, DIO_u8OUTPUT);
//DIO_u8WritePinDir(HC595_ID1_SCK_PIN, DIO_u8OUTPUT);
//DIO_u8WritePinDir(HC595_ID1_RCK_PIN, DIO_u8OUTPUT);
}

