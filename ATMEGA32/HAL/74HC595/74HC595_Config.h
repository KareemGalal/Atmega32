#ifndef _74HC595_CONFIG_H_
#define _74HC595_CONFIG_H_

/*******************************************************/
/********** Configuration for 74HC595 Num1 *************/
/*******************************************************/ 

/*Comment!: Initial State*/
/*Range!  : HC595_U8OFFSTATE or  HC595_U8ONSTATE*/
#define	HC595_IC1_INITSTATE		HC595_u8ONSTATE
/*Comment!: Data pin (DS) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_DS1				DIO_u8PIN24
/*Comment!: Shift Clock (SH_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_SH_CP1			DIO_u8PIN25
/*Comment!: Store Clock (ST_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ST_CP1			DIO_u8PIN26

/*******************************************************/
/********** Configuration for 74HC595 Num2 *************/
/*******************************************************/

/*Comment!: Initial State*/
/*Range!  : HC595_U8OFFSTATE or  HC595_U8ONSTATE*/
#define	HC595_IC2_INITSTATE		HC595_u8ONSTATE
/*Comment!: Data pin (DS) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_DS2				DIO_u8PIN27
/*Comment!: Shift Clock (SH_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_SH_CP2			DIO_u8PIN28
/*Comment!: Store Clock (ST_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ST_CP2			DIO_u8PIN29

/*******************************************************/
/********** Configuration for 74HC595 Num3 *************/
/*******************************************************/

/*Comment!: Initial State*/
/*Range!  : HC595_U8OFFSTATE or  HC595_U8ONSTATE*/
#define	HC595_IC3_INITSTATE		HC595_u8OFFSTATE
/*Comment!: Data pin (DS) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_DS3				DIO_u8PIN27
/*Comment!: Shift Clock (SH_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_SH_CP3			DIO_u8PIN28
/*Comment!: Store Clock (ST_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ST_CP3			DIO_u8PIN29

/*******************************************************/
/********** Configuration for 74HC595 Num4 *************/
/*******************************************************/

/*Comment!: Initial State*/
/*Range!  : HC595_U8OFFSTATE or  HC595_U8ONSTATE*/
#define	HC595_IC4_INITSTATE		HC595_u8OFFSTATE
/*Comment!: Data pin (DS) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_DS4				DIO_u8PIN27
/*Comment!: Shift Clock (SH_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_SH_CP4			DIO_u8PIN28
/*Comment!: Store Clock (ST_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ST_CP4			DIO_u8PIN29
#endif 
