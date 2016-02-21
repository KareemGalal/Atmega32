#ifndef _TSW_CONFIG_H_
#define _TSW_CONFIG_H_

/*******************************************************/
/**************** Public Definitions *******************/
/*******************************************************/

/*Comment!: Number of Connected Switches */
/*Range!  : 1:12 */
#define TSW_CONNECTED_NUM	 1

/*Switch State*/
#define	TSW_u8PRESSED	DIO_u8LOW
#define	TSW_u8RELEASED	DIO_u8HIGH

/*Comment!: Switches Initial State*/
#define TSW_u8PRESSED_RELEASED_LEVEL	100

/*Comment!: Switches Initial State*/
/*Range!  : TSW_u8OFFSTATE or  TSW_u8ONSTATE*/
#define TSW_u8SWITCH1_INITSTATE		TSW_u8ONSTATE
#define TSW_u8SWITCH2_INITSTATE		TSW_u8OFFSTATE
#define TSW_u8SWITCH3_INITSTATE		TSW_u8OFFSTATE
#define TSW_u8SWITCH4_INITSTATE		TSW_u8OFFSTATE
#define TSW_u8SWITCH5_INITSTATE		TSW_u8OFFSTATE
#define TSW_u8SWITCH6_INITSTATE		TSW_u8OFFSTATE
#define TSW_u8SWITCH7_INITSTATE		TSW_u8OFFSTATE
#define TSW_u8SWITCH8_INITSTATE		TSW_u8OFFSTATE
#define TSW_u8SWITCH9_INITSTATE		TSW_u8OFFSTATE
#define TSW_u8SWITCH10_INITSTATE	TSW_u8OFFSTATE
#define TSW_u8SWITCH11_INITSTATE	TSW_u8OFFSTATE
#define TSW_u8SWITCH12_INITSTATE	TSW_u8OFFSTATE

/*Comment!: Switch Pin Configuration*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define TSW_u8SWITCH1PIN	DIO_u8PIN0
#define TSW_u8SWITCH2PIN	DIO_u8PIN0
#define TSW_u8SWITCH3PIN	DIO_u8PIN0
#define TSW_u8SWITCH4PIN	DIO_u8PIN0
#define TSW_u8SWITCH5PIN	DIO_u8PIN0
#define TSW_u8SWITCH6PIN	DIO_u8PIN0
#define TSW_u8SWITCH7PIN	DIO_u8PIN0
#define TSW_u8SWITCH8PIN	DIO_u8PIN0
#define TSW_u8SWITCH9PIN	DIO_u8PIN0
#define TSW_u8SWITCH10PIN	DIO_u8PIN0
#define TSW_u8SWITCH11PIN	DIO_u8PIN0
#define TSW_u8SWITCH12PIN	DIO_u8PIN0

#endif 
