/*
   TSW_Interface.h

    Created on: Feb 22, 2016
        Author: Kareem Galal
*/

#ifndef _TSW_INTERFACE_H_
#define _TSW_INTERFACE_H_

/*******************************************************/
/***************** Public Definitions ******************/
/*******************************************************/

/*******************************************************/
/*****************  Public Functions  ******************/
/*******************************************************/

/*Comment!: check the switch state Pressed or Released*/
extern u8 TSW_u8CheckSwitch(u8 Copy_u8SwIdx, u8* Copy_u8PtrVal);

/*Comment!: Initialize the Tactile_Switch*/
extern void TSW_voidInit(void);

#endif	/* _TSW_INTERFACE_H_ */
