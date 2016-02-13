/*
 * DIO_Delay.h
 *
 *  Created on: Feb 1, 2016
 *      Author: KiMo
 */

#ifndef _PWM_DELAY_H_
#define _PWM_DELAY_H_

#include "PWM_DelayConfig.h"

/*******************************************************/
/***************** Public Functions ********************/
/*******************************************************/
/*Comment!: Delay Function with MS */
#define PWM_voidDELAY_MS(n) do{for(u32 Local_u32DelayCounter=(Delay_u8SYSCLCK*125UL*n);Local_u32DelayCounter>0;Local_u32DelayCounter--){__asm("NOP");}}while(0)
//#define Wait(t) {u16 wait; for (wait = 0; wait < (t); wait++) {}};
#endif /* _PWM_DELAY_H_ */
