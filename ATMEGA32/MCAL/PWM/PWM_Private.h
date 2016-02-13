/*
 * PWM_Private.h
 *
 *  Created on: Feb 2, 2016
 *      Author: KiMo
 */

#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

/*******************************************************/
/***************** Private Definitions  ****************/
/*******************************************************/

/*
 MODE WGM13	WGM12	WGM11	WGM10	 DESCRIPTION	 				 		TOP
 0	 0		0 		0 		0 	 		Normal 						 		0xFFFF
 1	 0		0 		0 		1 			PWM, Phase Corrected, 8bit		 	0x00FF
 2	 0		0 		1 		0 	 		PWM, Phase Corrected, 9bit	 		0x01FF
 3	 0		0		1 		1 			PWM, Phase Corrected, 10bit 	 	0x03FF
 5	 0 		1 		0 		1 			Fast PWM, 8bit 					 	0x00FF
 6	 0 		1 		1 		0 	 		Fast PWM, 9bit 				 		0x01FF
 7	 0 		1 		1		1 	 		Fast PWM, 10bit 			 		0x03FF
 8	 1 		0 		0 		0 			PWM, Phase and Frequency Corrected 	ICR1
 9	 1 		0 		0 		1 			PWM, Phase and Frequency Corrected 	OCR1A
 10	 1 		0 		1 		0 			PWM, Phase Correct 					ICR1
 11	 1 		0 		1 		1 			PWM, Phase Correct 				    OCR1A
 14	 1 		1 		1 		0 			Fast PWM 							ICR1
 15	 1 		1 		1 		1			Fast PWM							OCR1A
 */
/*Comment!: PWM modes for Timer 1 >> CH2,3*/
#define PWM23_FAST_MODE14				1110

/*Comment!: Prescaler Options*/
#define	PWM23_PRESCALER_0			000			//No clock source (Timer/Counter0 Disabled)
#define	PWM23_PRESCALER_1			001 		//Sets prescaler value to 1
#define	PWM23_PRESCALER_8			010 		//Sets prescaler value to 8
#define	PWM23_PRESCALER_64			011 		//Sets prescaler value to 64
#define	PWM23_PRESCALER_256			100 		//Sets prescaler value to 256
#define	PWM23_PRESCALER_1024		101	 		//Sets prescaler value to 1024
/*
 COM1A1	COM1A0
 COM1B1	COM1B0	DESCRIPTION
 0		0 	 	Normal port operation, OC1A/OC1B disconnected.
 0		1 	 	Mode 9,11,14,15 only: Enable OCR1A only (OC1B disconnected)
 1		0 	 	None-inverted mode (HIGH at bottom, LOW on Match)
 1		1 	 	Inverted mode (LOW at bottom, HIGH on Match)
 */
#define	PWM_NON_INVERTED	10 	//PWM noninverted mode
#define	PWM_INVERTED 		11	//PWM inverted mode

/*Comment!: Digital I/O Direction*/
#define DIO_u8OUTPUT		1

/*Comment!: ATMEGA32 I/O Registers */
#define PWM_u8DDRA 			*((volatile u8*)(0x3A))
#define PWM_u8DDRB 			*((volatile u8*)(0x37))
#define PWM_u8DDRC 			*((volatile u8*)(0x34))
#define PWM_u8DDRD 			*((volatile u8*)(0x31))

#define PWM_u8CH2_PD5		5
#define PWM_u8CH3_PD4		4

/*Comment!: ATMEGA32 TIMERS Registers */
/* Timer 0 */
#define PWM_u8TCCR0			*((volatile u8*)(0x53))
#define PWM_u8TCNT0  		*((volatile u8*)(0x52))
/* Timer 1 */
#define PWM_u16ICR1    		*((volatile u16*)(0x46))
#define PWM_u8ICR1L   		*((volatile u8*)(0x46))
#define PWM_u8ICR1H   		*((volatile u8*)(0x47))
#define PWM_u16OCR1B   		*((volatile u16*)(0x48))
#define PWM_u8OCR1BL  		*((volatile u8*)(0x48))
#define PWM_u8OCR1BH  		*((volatile u8*)(0x49))
#define PWM_u16OCR1A   		*((volatile u16*)(0x4A))
#define PWM_u8OCR1AL  		*((volatile u8*)(0x4A))
#define PWM_u8OCR1AH  		*((volatile u8*)(0x4B))
#define PWM_u16TCNT1   		*((volatile u16*)(0x4C))
#define PWM_u8TCNT1L  		*((volatile u8*)(0x2C))
#define PWM_u8TCNT1H  		*((volatile u8*)(0x4D))
#define PWM_u8TCCR1B  		*((volatile u8*)(0x4E))
#define PWM_u8TCCR1A  		*((volatile u8*)(0x4F))
/* Timer 2 */
#define PWM_u8OCR2    		*((volatile u8*)(0x43))
#define PWM_u8TCNT2   		*((volatile u8*)(0x44))
#define PWM_u8TCCR2  			*((volatile u8*)(0x45))


#if (PWM_WAVE_MODE_CH23==PWM23_FAST_MODE14)
#define PWM_WGM13_WGM12	11
#define PWM_WGM11_WGM10	10
#endif

/*******************************************************/
/***************** Private Functions *******************/
/*******************************************************/

/*Comment!: Concatenate Function for TCCR1A Initial Value */
#define CONC_HELPER_TCCR1A(x2,x1,x0) 	 0b##x2##x1##00##x0
#define	CONC_TCCR1A(x2,x1,x0)			 CONC_HELPER_TCCR1A(x2,x1,x0)
#define	PWM_u8TCCR1A_VAL				 CONC_TCCR1A(PWM_SIGNAL_CH2, PWM_SIGNAL_CH3, PWM_WGM11_WGM10)
// TCCR1A = (PWM_SIGNAL_CH2<<6)|(PWM_SIGNAL_CH3<<4)|(00<<2)|(PWM23_FAST_MODE14&0x03)
/*Comment!: Concatenate Function for TCCR1A Initial Value */

#define CONC_HELPER_TCCR1B(x1,x0) 		 0b##000##x1##x0
#define	CONC_TCCR1B(x1,x0)				 CONC_HELPER_TCCR1B(x1,x0)
#define	PWM_u8TCCR1B_VAL				 CONC_TCCR1B(PWM_WGM13_WGM12,PWM_PRESCALER_CH23)
// TCCR1B = ((WAVE_MODE_CH23&0xC)<<1)|PWM_PRESCALER_CH23

#endif /* PWM_PRIVATE_H_ */
