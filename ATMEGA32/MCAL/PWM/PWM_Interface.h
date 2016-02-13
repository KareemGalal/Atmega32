/*
 * PWM_Interface.h
 *
 *  Created on: Feb 2, 2016
 *      Author: KiMo
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

/*******************************************************/
/***************** Public Definitions  *****************/
/*******************************************************/

/*Comment!: Channel Index Numbers*/
//#define PWM_u8CH0		0
//#define PWM_u8CH1		1
#define PWM_u8CH2		2
#define PWM_u8CH3		3
//#define PWM_u8CH4		4
//#define PWM_u8CH5		5

/*******************************************************/
/***************** Public Functions ********************/
/*******************************************************/

/*Comment!: Initialization Function */
extern void PWM_voidInit(void);
/*Comment!: Set Duty Cycle for a specific channel Function */
extern u8 PWM_Set_Duty(u8 Copy_u8PinIDx,u16 Copy_u16Duty);
/*Comment!: Start PWM Function */
//extern u8 PWM_Start();
/*Comment!: Stop PWM Function */
//extern u8 PWM_Stop();



#endif /* PWM_INTERFACE_H_ */
