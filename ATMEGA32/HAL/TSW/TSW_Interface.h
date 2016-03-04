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

/*Comment!: Displays Numbers*/
#define	TSW_u8NUM1	0
#define TSW_u8NUM2	1
#define TSW_u8NUM3	2
#define TSW_u8NUM4	3
#define TSW_u8NUM5	4
#define TSW_u8NUM6	5
#define TSW_u8NUM7	6
#define TSW_u8NUM8	7
#define TSW_u8NUM9	8
#define TSW_u8NUM10	9
#define TSW_u8NUM11	10
#define TSW_u8NUM12	11
#define TSW_u8NUM13	12
#define TSW_u8NUM14	13
#define TSW_u8NUM15	14
#define TSW_u8NUM16	15

/*Comment!: Switch State*/
/*Range!: DIO_u8LOW or DIO_u8HIGH*/
#define	TSW_u8PRESSED	DIO_u8LOW//Low if active pull up resistor & High for pull down resistor
#define	TSW_u8RELEASED	DIO_u8HIGH

/*******************************************************/
/*****************  Public Functions  ******************/
/*******************************************************/

/*Comment!: check the switch state Pressed or Released*/
extern u8 TSW_u8CheckSwitch(u8 Copy_u8SwIdx, u8* Copy_u8PtrVal);

/*Comment!: Initialize the Tactile_Switch*/
extern void TSW_voidInit(void);

#endif	/* _TSW_INTERFACE_H_ */
