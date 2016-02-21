#include "..\..\Utilities\Types.h"
#include "..\..\MCAL\DIO\DIO_interface.h"
#include "TSW_Interface.h"
#include "TSW_Config.h"
#include "TSW_Private.h"

extern u8 TSW_u8CheckSwitch(u8 Copy_u8SwIdx, u8* Copy_u8PtrVal) {
	u8 Local_u8RetrunStatus;
	if ((Copy_u8SwIdx > TSW_CONNECTED_NUM) || (Copy_u8SwIdx == 0)) {
		Local_u8RetrunStatus = u8ERROR;
	} else {
		u8 Local_u8Value;
		static u8 Local_u8PressedCounter = 0;
		static u8 Local_u8RealesedCounter = 0;
		static u8 Local_u8SwState = TSW_u8RELEASED_STATE;
		switch (Local_u8SwState) {
		case TSW_u8RELEASED_STATE: {
			DIO_u8ReadPinVal(TSW_u8SWITCH1PIN, &Local_u8Value);
			switch (Local_u8Value) {
			case TSW_u8RELEASED: {
				Local_u8SwState = TSW_u8RELEASED_STATE;
				*Copy_u8PtrVal = TSW_u8RELEASED;
			}
				break;
			default:
				Local_u8SwState = TSW_u8BOUNCING_STATE;
				*Copy_u8PtrVal = TSW_u8RELEASED;
				break;
			}
		}
			Local_u8RetrunStatus = u8OK;
			break;
		case TSW_u8BOUNCING_STATE: {
			DIO_u8ReadPinVal(TSW_u8SWITCH1PIN, &Local_u8Value);
			switch (Local_u8Value) {
			case TSW_u8PRESSED: {
				Local_u8PressedCounter++;
				Local_u8RealesedCounter = 0;
				if (Local_u8PressedCounter == TSW_u8PRESSED_RELEASED_LEVEL) {
					Local_u8SwState = TSW_u8PRESSED_STATE;
				} else {
				}
			}
				break;
			default:  //TSW_u8RELEASED
			{
				Local_u8RealesedCounter++;
				Local_u8PressedCounter = 0;
				if (Local_u8RealesedCounter == TSW_u8PRESSED_RELEASED_LEVEL) {
					Local_u8SwState = TSW_u8RELEASED_STATE;

				} else {
				}
			}
				break;
			}
		}
			Local_u8RetrunStatus = u8OK;
			break;
		case TSW_u8PRESSED_STATE: {
			DIO_u8ReadPinVal(TSW_u8SWITCH1PIN, &Local_u8Value);
			switch (Local_u8Value) {
			case TSW_u8PRESSED: {
				Local_u8SwState = TSW_u8PRESSED_STATE;
				*Copy_u8PtrVal = TSW_u8PRESSED;
			}
				break;
			default: {
				Local_u8SwState = TSW_u8BOUNCING_STATE;
				*Copy_u8PtrVal = TSW_u8PRESSED;
			}
				break;
			}
		}
			Local_u8RetrunStatus = u8OK;
			break;
		default:
			Local_u8SwState = TSW_u8RELEASED_STATE;
			*Copy_u8PtrVal = TSW_u8RELEASED;
			Local_u8RetrunStatus = u8OK;
			break;
		}

	}
	return Local_u8RetrunStatus;
}

extern void TSW_voidInit(void) {
	//DIO_u8WritePinDir(TSW_u8SWITCH1PIN, DIO_u8INPUT);
}

