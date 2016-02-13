/*
 * PWM_Config.h
 *
 *  Created on: Feb 2, 2016
 *      Author: KiMo
 */

#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

/*
The frequency of the control signal for the SERVO is 50hz (i.e. the period is 20ms) and the width of positive pulse controls the angle.


 0.388ms = 0 degree.
 1.264ms = 90 degrees. (neutral position)
 2.14ms = 180 degrees.

We chose the Prescaler as 64. So the timer will get 16MHz/64 = 250khz (4 uS period). We setup Timer Mode as Mode 14.

Timer Mode 14 features

    FAST PWM Mode
    TOP Value = ICR1
The timer will count from 0 to ICR1(TOP Value)

FPWM= fclk_I/O  /  N(1+TOP)
50Hz= 16MHz  /  64(1+TOP)
So TOP = ICR1=4999

 Servo Angle 0 degrees require pulse width of 0.388ms(388uS) so value of OCR1A = 388us/4us = 97
 Servo Angle 90 degrees require pulse width of 1.264ms(1264uS) so value of OCR1A = 1264us/4us = 316
 Servo Angle 180 degrees require pulse width of 2.140ms(2140uS) so value of OCR1A = 2140us/4us = 535

Timer 1 Pins:-
			OC1A >> PD5
			OC1B >> PD4

Timer/Counter1 Control Register A – TCCR1A
Bit 7 	6	   5	 4		 3	    2	 1	   0
COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10
R/W	   R/W 	  R/W    R/W	W	  W		R/W	  R/W
Initial Value 0 0 0 0 0 0 0 0

TCCR1A = 0b10100010 = 0xA2

Timer/Counter1 Control Register B – TCCR1B
Bit 7		6 	5 4 	3 		2	 1 	0
	ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10
	R/W   R/W 	R R/W   R/W   R/W  R/W  R/W
Initial Value 0 0 0 0 0 0 0 0
TCCR1B=0b00011011 = 0x1B

TCCR1A = (PWM_SIGNAL_CH2<<6)|(PWM_SIGNAL_CH3<<4)|(00<<2)|(WAVE_MODE_CH23&0x03)
TCCR1B = ((WAVE_MODE_CH23&0xC)<<1)|PWM_PRESCALER_CH23



CS12 CS11 CS10
0	 1		1  =clk/64 (From Prescaler)

To Set the MCU to Mode 14
WGM13	WGM12	WGM11	WGM10
1 		1 		1 		0


 */

//Wave Mode
#define PWM_WAVE_MODE_CH23		PWM23_FAST_MODE14	//PWM_FAST_MODE or PWM1_PHASE_CORRECT_MODE

//Prescaler
//PWM01_PRESCALER_0 , PWM23_PRESCALER_1 , PWM23_PRESCALER_8 , PWM23_PRESCALER_64 , PWM23_PRESCALER_256 , PWM23_PRESCALER_1024
//#define PWM_PRESCALER_CH01	PWM01_PRESCALER_1
#define PWM_PRESCALER_CH23		PWM23_PRESCALER_64
//#define PWM_PRESCALER_CH45	PWM45_PRESCALER_1

//PWM Signal Shape Inverted or Non-Inverted

//PWM_INVERTED or PWM_NON_INVERTED
//#define PWM_SIGNAL_CH0		PWM_NON_INVERTED 	//0A
//#define PWM_SIGNAL_CH1		PWM_NON_INVERTED	//0B
#define PWM_SIGNAL_CH2			PWM_NON_INVERTED	//OC1A >> PD5
#define PWM_SIGNAL_CH3			PWM_NON_INVERTED	//OC1B >> PD4
//#define PWM_SIGNAL_CH4		PWM_NON_INVERTED	//2A
//#define PWM_SIGNAL_CH5		PWM_NON_INVERTED	//2B

//Initial Duty Value
#define PWM_INTIAL_DUTY			0	//Range of 0 : 255

#define PWM_TOPVALUE			(16000000/(64*50) - 1)

#endif /* PWM_CONFIG_H_ */
