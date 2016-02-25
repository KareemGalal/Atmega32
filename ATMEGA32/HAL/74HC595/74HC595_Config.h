#ifndef _74HC595_CONFIG_H_
#define _74HC595_CONFIG_H_

/*******************************************************/
/********** Configuration for 74HC595 Num1 *************/
/*******************************************************/ 

/*Comment!: Initial State*/
/*Range!  : HC595_U8OFFSTATE or  HC595_U8ONSTATE*/
#define	HC595_ID1_INITSTATE				HC595_u8ONSTATE
/*Comment!: Serial Data Input pin location pin 14 on the 75HC595*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID1_SER_DATA_PIN			DIO_u8PIN25
/*Comment!: Shift Register ClockInpuT pin location pin 11 on the 75HC595*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID1_SCK_PIN				DIO_u8PIN24
/*Comment!: Storage Register ClockInput pin location (pin 12 on the 75HC595)*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID1_RCK_PIN				DIO_u8PIN26

/*******************************************************/
/********** Configuration for 74HC595 Num2 *************/
/*******************************************************/

/*Comment!: Initial State*/
/*Range!  : HC595_U8OFFSTATE or  HC595_U8ONSTATE*/
#define	HC595_ID2_INITSTATE				HC595_u8ONSTATE
/*Comment!: Serial Data Input pin location pin 14 on the 75HC595*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID2_SER_DATA_PIN			DIO_u8PIN28
/*Comment!: Shift Register ClockInpuT pin location pin 11 on the 75HC595*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID2_SCK_PIN				DIO_u8PIN27
/*Comment!: Storage Register ClockInput pin location (pin 12 on the 75HC595)*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID2_RCK_PIN				DIO_u8PIN29

/*******************************************************/
/********** Configuration for 74HC595 Num3 *************/
/*******************************************************/

/*Comment!: Initial State*/
/*Range!  : HC595_U8OFFSTATE or  HC595_U8ONSTATE*/
#define	HC595_ID3_INITSTATE				HC595_u8ONSTATE
/*Comment!: Serial Data Input pin location pin 14 on the 75HC595*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID3_SER_DATA_PIN			DIO_u8PIN25
/*Comment!: Shift Register ClockInpuT pin location pin 11 on the 75HC595*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID3_SCK_PIN				DIO_u8PIN24
/*Comment!: Storage Register ClockInput pin location (pin 12 on the 75HC595)*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID3_RCK_PIN				DIO_u8PIN26

/*******************************************************/
/********** Configuration for 74HC595 Num4 *************/
/*******************************************************/

/*Comment!: Initial State*/
/*Range!  : HC595_U8OFFSTATE or  HC595_U8ONSTATE*/
#define	HC595_ID4_INITSTATE				HC595_u8ONSTATE
/*Comment!: Serial Data Input pin location pin 14 on the 75HC595*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID4_SER_DATA_PIN			DIO_u8PIN25
/*Comment!: Shift Register ClockInpuT pin location pin 11 on the 75HC595*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID4_SCK_PIN				DIO_u8PIN24
/*Comment!: Storage Register ClockInput pin location (pin 12 on the 75HC595)*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ID4_RCK_PIN				DIO_u8PIN26

#endif 
