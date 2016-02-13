/*
 * DIO_prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: KiMo
 */

#include "..\..\Utilities\Types.h"
#include "..\..\Utilities\Util.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

static u8* const DIO_u8DDRS[NUMBER_OF_PORTS] = { DIO_u8DDRA, DIO_u8DDRB, DIO_u8DDRC, DIO_u8DDRD };
static u8* const DIO_u8PORTS[NUMBER_OF_PORTS] = { DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD };
static u8* const DIO_u8PINS[NUMBER_OF_PORTS] = { DIO_u8PINA, DIO_u8PINB, DIO_u8PINC, DIO_u8PIND };


/*Comment!: Initialization Function */
extern void DIO_voidInit(void) {
	/*Comment!: Initialization Direction & Value for PORTA */
	//*DIO_u8DDRS[DIO_u8PORT0] = DIO_u8PORTA_DIR;
	*DIO_u8DDRA = DIO_u8PORTA_DIR;
	*DIO_u8PORTA = ((*DIO_u8PORTA) & (~DIO_u8PORTA_DIR)) | (DIO_u8PORTA_DIR & DIO_u8PORTA_VAL);
	/*Comment!: Initialization Direction & Value for PORTB */
	*DIO_u8DDRB = DIO_u8PORTB_DIR;
	*DIO_u8PORTB = ((*DIO_u8PORTB) & (~DIO_u8PORTB_DIR)) | (DIO_u8PORTB_DIR & DIO_u8PORTB_VAL);
	/*Comment!: Initialization Direction & Value for PORTC */
	*DIO_u8DDRC = DIO_u8PORTC_DIR;
	*DIO_u8PORTC = ((*DIO_u8PORTC) & (~DIO_u8PORTC_DIR)) | (DIO_u8PORTC_DIR & DIO_u8PORTC_VAL);
	/*Comment!: Initialization Direction & Value for PORTD */
	*DIO_u8DDRD = DIO_u8PORTD_DIR;
	*DIO_u8PORTD = ((*DIO_u8PORTD) & (~DIO_u8PORTD_DIR)) | (DIO_u8PORTD_DIR & DIO_u8PORTD_VAL);

	return;
}

/*Comment!: Read Pin Value */
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx, u8* Copy_u8PtrToPinVal) {
	u8 Local_u8Status;
	if ((Copy_u8PinIdx <= DIO_u8PIN31)) {
		u8 Local_u8PinNum = Copy_u8PinIdx % NUMBER_OF_PINS_PER_PORT;
		u8 Local_u8PortNum = Copy_u8PinIdx / NUMBER_OF_PINS_PER_PORT;
		*Copy_u8PtrToPinVal = GET_BIT((*DIO_u8PINS[Local_u8PortNum]), Local_u8PinNum);
		Local_u8Status = u8OK;
	} else {
		Local_u8Status = u8ERROR;
	}
	return Local_u8Status;
}

/*Comment!: Write Pin Value */
extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx, u8 Copy_u8PinVal) {
	u8 Local_u8Status;
	if ((Copy_u8PinIdx <= DIO_u8PIN31) && ((Copy_u8PinVal == DIO_u8LOW) || (Copy_u8PinVal == DIO_u8HIGH))) {
		u8 Local_u8PinNum = Copy_u8PinIdx % NUMBER_OF_PINS_PER_PORT;
		u8 Local_u8PortNum = Copy_u8PinIdx / NUMBER_OF_PINS_PER_PORT;
		if (Copy_u8PinVal == DIO_u8LOW) { // ASSIGN BIT
			CLR_BIT((*DIO_u8PORTS[Local_u8PortNum]), Local_u8PinNum);
		} else { // Copy_u8PinVal == DIO_u8HIGH
			SET_BIT((*DIO_u8PORTS[Local_u8PortNum]), Local_u8PinNum);
		}
		Local_u8Status = u8OK;
	} else {
		Local_u8Status = u8ERROR;
	}
	return Local_u8Status;
}

/*Comment!: Read Port Value */
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx, u8* Copy_u8PtrToPortVal) {
	u8 Local_u8Status;
	if ((Copy_u8PortIdx <= DIO_u8PORT3)) {
		*Copy_u8PtrToPortVal = (*DIO_u8PINS[Copy_u8PortIdx]);
		Local_u8Status = u8OK;
	} else {
		Local_u8Status = u8ERROR;
	}
	return Local_u8Status;
}

/*Comment!: Write Port Value */
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal) {
	//case if Copy_u8PortVal < 0 OR >255
	u8 Local_u8Status;
	if ((Copy_u8PortIdx <= DIO_u8PORT3)) {
		(*DIO_u8DDRS[Copy_u8PortIdx]) = Copy_u8PortVal;
		Local_u8Status = u8OK;
	} else {
		Local_u8Status = u8ERROR;
	}
	return Local_u8Status;
}

/*Comment!: Read Pin Direction */
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx, u8* Copy_u8PtrToPinDir) {
	u8 Local_u8Status;
	if ((Copy_u8PinIdx <= DIO_u8PIN31)) {
		u8 Local_u8PinNum = Copy_u8PinIdx % NUMBER_OF_PINS_PER_PORT;
		u8 Local_u8PortNum = Copy_u8PinIdx / NUMBER_OF_PINS_PER_PORT;
		*Copy_u8PtrToPinDir = GET_BIT((*DIO_u8DDRS[Local_u8PortNum]), Local_u8PinNum);
		Local_u8Status = u8OK;
	} else {
		Local_u8Status = u8ERROR;
	}
	return Local_u8Status;
}

/*Comment!: Write Pin Direction */
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx, u8 Copy_u8PinDir) {
	u8 Local_u8Status;
	if ((Copy_u8PinIdx <= DIO_u8PIN31) && ((Copy_u8PinDir == DIO_u8INPUT) || (Copy_u8PinDir == DIO_u8OUTPUT))) {
		u8 Local_u8PinNum = Copy_u8PinIdx % NUMBER_OF_PINS_PER_PORT;
		u8 Local_u8PortNum = Copy_u8PinIdx / NUMBER_OF_PINS_PER_PORT;
		if (Copy_u8PinDir == DIO_u8INPUT) {
			CLR_BIT((*DIO_u8DDRS[Local_u8PortNum]), Local_u8PinNum);
		} else { // Copy_u8PinVal == DIO_u8INPUT
			SET_BIT((*DIO_u8DDRS[Local_u8PortNum]), Local_u8PinNum);
		}
		Local_u8Status = u8OK;
	} else {
		Local_u8Status = u8ERROR;
	}
	return Local_u8Status;
}

/*Comment!: Read Port Direction */
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx, u8* Copy_u8PtrToPortDir) {
	u8 Local_u8Status;
	if ((Copy_u8PortIdx <= DIO_u8PORT3)) {
		*Copy_u8PtrToPortDir = (*DIO_u8DDRS[Copy_u8PortIdx]);
		Local_u8Status = u8OK;
	} else {
		Local_u8Status = u8ERROR;
	}
	return Local_u8Status;
}

/*Comment!: Write Port Direction */
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx, u8 Copy_u8PortDir) {
	//case if Copy_u8PortDir < 0 OR >255
	u8 Local_u8Status;
	if ((Copy_u8PortIdx <= DIO_u8PORT3)) {
		(*DIO_u8DDRS[Copy_u8PortIdx]) = Copy_u8PortDir;
		Local_u8Status = u8OK;
	} else {
		Local_u8Status = u8ERROR;
	}
	return Local_u8Status;
}
