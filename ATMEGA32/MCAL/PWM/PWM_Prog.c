/*
 * PWM_Prog.c
 *
 *  Created on: Feb 2, 2016
 *      Author: KiMo
 */

#include "Types.h"
#include "PWM_Config.h"
#include "PWM_Interface.h"
#include "PWM_Private.h"

/*******************************************************/
/***************** Public Functions ********************/
/*******************************************************/

/*Comment!: Initialization Function */
extern void PWM_voidInit(void) {
	PWM_u8TCCR1A = PWM_u8TCCR1A_VAL;
	PWM_u8TCCR1B = PWM_u8TCCR1B_VAL;
	PWM_u16ICR1 = 4999;//PWM_TOPVALUE;
	PWM_u16OCR1A = PWM_u16OCR1B = PWM_INTIAL_DUTY;
	PWM_u8DDRD |= (DIO_u8OUTPUT << PWM_u8CH2_PD5) | (DIO_u8OUTPUT << PWM_u8CH3_PD4);
	return;
}
/*Comment!: Set Duty Cycle for a specific channel Function */
extern u8 PWM_Set_Duty(u8 Copy_u8PinIDx, u16 Copy_u16Duty) {
	u8 Local_u8Status;
	switch (Copy_u8PinIDx) {
	case PWM_u8CH2:
		PWM_u16OCR1A = Copy_u16Duty;	//0 degree
		Local_u8Status = u8OK;
		break;
	case PWM_u8CH3:
		PWM_u16OCR1B = Copy_u16Duty;	//0 degree
		Local_u8Status = u8OK;
		break;
	default:
		Local_u8Status = u8ERROR;
		break;
	}
	return Local_u8Status;
}
