/*
 TSW_Prog.c

 Created on: Feb 22, 2016
 Author: Kareem Galal
 */

#include "..\..\Utilities\Types.h"
#include "..\..\MCAL\DIO\DIO_interface.h"
#include "TSW_Interface.h"
#include "TSW_Config.h"
#include "TSW_Private.h"

#if (TSW_CONNECTED_NUM == TSW_u8NUM1)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM2)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM3)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM4)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM5)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM6)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PI};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM7)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM8)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM9)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN, TSW_u8SWITCH9PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM10)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN, TSW_u8SWITCH9PIN, TSW_u8SWITCH10PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM11)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN, TSW_u8SWITCH9PIN, TSW_u8SWITCH10PIN, TSW_u8SWITCH11PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM12)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN, TSW_u8SWITCH9PIN, TSW_u8SWITCH10PIN, TSW_u8SWITCH11PIN, TSW_u8SWITCH12PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM13)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN, TSW_u8SWITCH9PIN, TSW_u8SWITCH10PIN, TSW_u8SWITCH11PIN, TSW_u8SWITCH12PIN, TSW_u8SWITCH13PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM14)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN, TSW_u8SWITCH9PIN, TSW_u8SWITCH10PIN, TSW_u8SWITCH11PIN, TSW_u8SWITCH12PIN, TSW_u8SWITCH13PIN, TSW_u8SWITCH14PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM15)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN, TSW_u8SWITCH9PIN, TSW_u8SWITCH10PIN, TSW_u8SWITCH11PIN, TSW_u8SWITCH12PIN, TSW_u8SWITCH13PIN, TSW_u8SWITCH14PIN, TSW_u8SWITCH15PIN};
#elif (TSW_CONNECTED_NUM == TSW_u8NUM16)
static const u8 TSW_u8SwitchNumArr[TSW_ARRAY_SIZE] = {TSW_u8SWITCH1PIN, TSW_u8SWITCH2PIN, TSW_u8SWITCH3PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH5PIN, TSW_u8SWITCH6PIN, TSW_u8SWITCH7PIN, TSW_u8SWITCH8PIN, TSW_u8SWITCH9PIN, TSW_u8SWITCH10PIN, TSW_u8SWITCH11PIN, TSW_u8SWITCH12PIN, TSW_u8SWITCH13PIN, TSW_u8SWITCH4PIN, TSW_u8SWITCH15PIN, TSW_u8SWITCH16PIN};
#endif

extern u8 TSW_u8CheckSwitch(u8 Copy_u8SwIdx, u8* Copy_u8PtrVal) {
	u8 Local_u8RetrunStatus;
	if ((Copy_u8SwIdx > TSW_CONNECTED_NUM)) {
		Local_u8RetrunStatus = u8ERROR;
	} else {
	    u8 Local_u8SwitchValue;
		static u8 Local_u8PressedCounter[TSW_ARRAY_SIZE] = {0};
		static u8 Local_u8RealesedCounter[TSW_ARRAY_SIZE] = {0};
		static u8 Local_u8SwState[TSW_ARRAY_SIZE] = {TSW_u8RELEASED_STATE};
		static u8 Local_u8SwFlag[TSW_ARRAY_SIZE] = {TSW_u8RELEASED}; //to remember the previous state
		switch (Local_u8SwState[Copy_u8SwIdx]) {
		case TSW_u8RELEASED_STATE:
			DIO_u8ReadPinVal(TSW_u8SwitchNumArr[Copy_u8SwIdx], &Local_u8SwitchValue);
			if (Local_u8SwitchValue == TSW_u8PRESSED) {
				Local_u8SwState[Copy_u8SwIdx] = TSW_u8BOUNCING_STATE;
				*Copy_u8PtrVal = Local_u8SwFlag[Copy_u8SwIdx] = TSW_u8RELEASED;
			} else { //Local_u8Value==TSW_u8RELEASED
				Local_u8SwState[Copy_u8SwIdx] = TSW_u8RELEASED_STATE;
				*Copy_u8PtrVal = Local_u8SwFlag[Copy_u8SwIdx] = TSW_u8RELEASED;
			}
			Local_u8RetrunStatus = u8OK;
			break;
		case TSW_u8BOUNCING_STATE:
			DIO_u8ReadPinVal(TSW_u8SwitchNumArr[Copy_u8SwIdx], &Local_u8SwitchValue);
			if (Local_u8SwitchValue == TSW_u8PRESSED) {
				Local_u8PressedCounter[Copy_u8SwIdx]++;
				Local_u8RealesedCounter[Copy_u8SwIdx] = 0;
				if (Local_u8PressedCounter[Copy_u8SwIdx] == TSW_u8PRESSED_RELEASED_LEVEL) {
					Local_u8SwState[Copy_u8SwIdx] = TSW_u8PRESSED_STATE;
				} else {
				}
			} else {  //Local_u8Value==TSW_u8RELEASED
				Local_u8RealesedCounter[Copy_u8SwIdx]++;
				Local_u8PressedCounter[Copy_u8SwIdx] = 0;
				if (Local_u8RealesedCounter[Copy_u8SwIdx] == TSW_u8PRESSED_RELEASED_LEVEL) {
					Local_u8SwState[Copy_u8SwIdx] = TSW_u8RELEASED_STATE;
				} else {
				}
			}
			*Copy_u8PtrVal = Local_u8SwFlag[Copy_u8SwIdx];
			Local_u8RetrunStatus = u8OK;
			break;
		case TSW_u8PRESSED_STATE:
			DIO_u8ReadPinVal(TSW_u8SwitchNumArr[Copy_u8SwIdx], &Local_u8SwitchValue);
			if (Local_u8SwitchValue == TSW_u8PRESSED) {
				Local_u8SwState[Copy_u8SwIdx] = TSW_u8PRESSED_STATE;
				*Copy_u8PtrVal = Local_u8SwFlag[Copy_u8SwIdx] = TSW_u8PRESSED;
			} else {
				Local_u8SwState[Copy_u8SwIdx] = TSW_u8BOUNCING_STATE;
				*Copy_u8PtrVal = Local_u8SwFlag[Copy_u8SwIdx] = TSW_u8PRESSED;
			}
			Local_u8RetrunStatus = u8OK;
			break;
		default:
			Local_u8SwState[Copy_u8SwIdx] = TSW_u8RELEASED_STATE;
			*Copy_u8PtrVal = TSW_u8RELEASED;
			Local_u8RetrunStatus = u8OK;
			break;
		}
	}
	return Local_u8RetrunStatus;
}

extern void TSW_voidInit(void) {
//	u8 Copy_u8SwIdx;
//	for (Copy_u8SwIdx = 0; Copy_u8SwIdx < TSW_ARRAY_SIZE; Copy_u8SwIdx++) {
//		DIO_u8WritePinDir(TSW_u8SwitchNumArr[Copy_u8SwIdx], DIO_u8INPUT);
//	}
}

