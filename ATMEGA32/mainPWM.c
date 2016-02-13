/*
 * main.c
 *
 *  Created on: Feb 2, 2016
 *      Author: KiMo
 */

#include "Types.h"
#include "PWM_Interface.h"
#include "PWM_Delay.h"

void main(void) {

	PWM_voidInit();
	/*
	 #define PWM_u16OCR1A   		*((volatile u16*)(0x4A))
	 #define PWM_u16OCR1B   		*((volatile u16*)(0x48))
	 #define PWM_u16ICR1    		*((volatile u16*)(0x46))
	 #define PWM_u8TCCR1B  		*((volatile u8*)(0x4E))
	 #define PWM_u8TCCR1A  		*((volatile u8*)(0x4F))
	 #define PWM_u8DDRD 			*((volatile u8*)(0x31))

	 PWM_u8TCCR1A|=(1<<7)|(1<<5)|(1<<1);		 	//NON Inverted PWM
	 PWM_u8TCCR1B|=(1<<4)|(1<<3)|(1<<1)|(1<<0);	//PRESCALER=64 MODE 14(FAST PWM)
	 PWM_u16ICR1=4999;	//fPWM=50Hz (Period = 20ms Standard).
	 PWM_u8DDRD|=(1<<4)|(1<<5);	//PWM Pins as Out
	 */
	while (1) {

		PWM_Set_Duty(PWM_u8CH2, 97);	//0 degree
		PWM_voidDELAY_MS(500);
		PWM_Set_Duty(PWM_u8CH2, 316);	//90 degree
		PWM_voidDELAY_MS(500);
		PWM_Set_Duty(PWM_u8CH2, 425);	//135 degree
		PWM_voidDELAY_MS(500);
		PWM_Set_Duty(PWM_u8CH2, 535);	//180 degree
		PWM_voidDELAY_MS(500);
		/*
		 PWM_u16OCR1A = 97;	//0 degree
		 Wait(1000);
		 PWM_u16OCR1A = 316;	//90 degree
		 Wait(1000);
		 PWM_u16OCR1A = 425;	//135 degree
		 Wait(1000);
		 PWM_u16OCR1A = 535;	//180 degree
		 Wait(1000);
		 */
	}
	return;
}
