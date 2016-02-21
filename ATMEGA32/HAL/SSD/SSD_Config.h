#ifndef _SSD_CONFIG_H_ 
#define _SSD_CONFIG_H_ 

/*******************************************************/
/**************** Public Definitions *******************/
/*******************************************************/

/*Comment!: Number of Connected Display*/
/*Range!  : 1:6 */
#define SSD_u8DISPCNT			2	// No magic numbers

/*******************************************************/
/********** Configuration for Display Num1 *************/
/*******************************************************/

/*Comment!: Display Type*/
/*Range!  : SSD_u8COMANOD or SSD_u8COMCATH */
#define	 SSD_u8DISP1_TYPE		SSD_u8COMCATH
/*Comment!: Initial Value*/
/*Range!  : SSD_u8NUM0:9 */
#define	SSD_u8DISP1_INITVAL		SSD_u8NUM0
/*Comment!: Initial State*/
/*Range!  : SSD_U8OFFSTATE or  SSD_U8ONSTATE*/
#define	SSD_u8DISP1_INITSTATE	SSD_u8ONSTATE
/*Comment!: Display Pins*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define	SSD_u8DISP1_COM			DIO_u8PIN8
#define	SSD_u8DISP1_SEGA		DIO_u8PIN1
#define	SSD_u8DISP1_SEGB		DIO_u8PIN2
#define	SSD_u8DISP1_SEGC		DIO_u8PIN3
#define	SSD_u8DISP1_SEGD		DIO_u8PIN4
#define	SSD_u8DISP1_SEGE		DIO_u8PIN5
#define	SSD_u8DISP1_SEGF		DIO_u8PIN6
#define	SSD_u8DISP1_SEGG		DIO_u8PIN7

/*******************************************************/
/********** Configuration for Display Num2 *************/
/*******************************************************/

/*Comment!: Display Type*/
/*Range!  : SSD_u8COMANOD or SSD_u8COMCATH */
#define	SSD_u8DISP2_TYPE		SSD_u8COMCATH
/*Comment!: Initial Value*/
/*Range!  : SSD_u8NUM0:9 */
#define	SSD_u8DISP2_INITVAL		SSD_u8NUM0
/*Comment!: Initial State*/
/*Range!  : SSD_U8OFFSTATE or  SSD_U8ONSTATE*/
#define	SSD_u8DISP2_INITSTATE	SSD_u8ONSTATE
/*Comment!: Display Pins*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define	SSD_u8DISP2_COM			DIO_u8PIN9
#define	SSD_u8DISP2_SEGA		DIO_u8PIN1
#define	SSD_u8DISP2_SEGB		DIO_u8PIN2
#define	SSD_u8DISP2_SEGC		DIO_u8PIN3
#define	SSD_u8DISP2_SEGD		DIO_u8PIN4
#define	SSD_u8DISP2_SEGE		DIO_u8PIN5
#define	SSD_u8DISP2_SEGF		DIO_u8PIN6
#define	SSD_u8DISP2_SEGG		DIO_u8PIN7

/*******************************************************/
/********** Configuration for Display Num3 *************/
/*******************************************************/

/*Comment!: Display Type*/
/*Range!  : SSD_u8COMANOD or SSD_u8COMCATH */
#define	SSD_u8DISP3_TYPE		SSD_u8COMCATH
/*Comment!: Initial Value*/
/*Range!  : SSD_u8NUM0:9 */
#define	SSD_u8DISP3_INITVAL		SSD_u8NUM0
/*Comment!: Initial State*/
/*Range!  : SSD_U8OFFSTATE or  SSD_U8ONSTATE*/
#define	SSD_u8DISP3_INITSTATE	SSD_u8ONSTATE
/*Comment!: Display Pins*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define	SSD_u8DISP3_COM			DIO_u8PIN10
#define	SSD_u8DISP3_SEGA		DIO_u8PIN1
#define	SSD_u8DISP3_SEGB		DIO_u8PIN2
#define	SSD_u8DISP3_SEGC		DIO_u8PIN3
#define	SSD_u8DISP3_SEGD		DIO_u8PIN4
#define	SSD_u8DISP3_SEGE		DIO_u8PIN5
#define	SSD_u8DISP3_SEGF		DIO_u8PIN6
#define	SSD_u8DISP3_SEGG		DIO_u8PIN7

/*******************************************************/
/********** Configuration for Display Num4 *************/
/*******************************************************/

/*Comment!: Display Type*/
/*Range!  : SSD_u8COMANOD or SSD_u8COMCATH */
#define	SSD_u8DISP4_TYPE		SSD_u8COMCATH
/*Comment!: Initial Value*/
/*Range!  : SSD_u8NUM0:9 */
#define	SSD_u8DISP4_INITVAL		SSD_u8NUM0
/*Comment!: Initial State*/
/*Range!  : SSD_U8OFFSTATE or  SSD_U8ONSTATE*/
#define	SSD_u8DISP4_INITSTATE	SSD_u8ONSTATE
/*Comment!: Display Pins*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define	SSD_u8DISP4_COM			DIO_u8PIN11
#define	SSD_u8DISP4_SEGA		DIO_u8PIN1
#define	SSD_u8DISP4_SEGB		DIO_u8PIN2
#define	SSD_u8DISP4_SEGC		DIO_u8PIN3
#define	SSD_u8DISP4_SEGD		DIO_u8PIN4
#define	SSD_u8DISP4_SEGE		DIO_u8PIN5
#define	SSD_u8DISP4_SEGF		DIO_u8PIN6
#define	SSD_u8DISP4_SEGG		DIO_u8PIN7

/*******************************************************/
/********** Configuration for Display Num5 *************/
/*******************************************************/

/*Comment!: Display Type*/
/*Range!  : SSD_u8COMANOD or SSD_u8COMCATH */
#define	SSD_u8DISP5_TYPE		SSD_u8COMCATH
/*Comment!: Initial Value*/
/*Range!  : SSD_u8NUM0:9 */
#define	SSD_u8DISP5_INITVAL		SSD_u8NUM0
/*Comment!: Initial State*/
/*Range!  : SSD_U8OFFSTATE or  SSD_U8ONSTATE*/
#define	SSD_u8DISP5_INITSTATE	SSD_u8OFFSTATE
/*Comment!: Display Pins*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define	SSD_u8DISP5_COM			DIO_u8PIN0
#define	SSD_u8DISP5_SEGA		DIO_u8PIN1
#define	SSD_u8DISP5_SEGB		DIO_u8PIN2
#define	SSD_u8DISP5_SEGC		DIO_u8PIN3
#define	SSD_u8DISP5_SEGD		DIO_u8PIN4
#define	SSD_u8DISP5_SEGE		DIO_u8PIN5
#define	SSD_u8DISP5_SEGF		DIO_u8PIN6
#define	SSD_u8DISP5_SEGG		DIO_u8PIN7

/*******************************************************/
/********** Configuration for Display Num6 *************/
/*******************************************************/

/*Comment!: Display Type*/
/*Range!  : SSD_u8COMANOD or SSD_u8COMCATH */
#define	SSD_u8DISP6_TYPE		SSD_u8COMCATH
/*Comment!: Initial Value*/
/*Range!  : SSD_u8NUM0:9 */
#define	SSD_u8DISP6_INITVAL		SSD_u8NUM0
/*Comment!: Initial State*/
/*Range!  : SSD_U8OFFSTATE or  SSD_U8ONSTATE*/
#define	SSD_u8DISP6_INITSTATE	SSD_u8OFFSTATE
/*Comment!: Display Pins*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define	SSD_u8DISP6_COM			DIO_u8PIN0
#define	SSD_u8DISP6_SEGA		DIO_u8PIN1
#define	SSD_u8DISP6_SEGB		DIO_u8PIN2
#define	SSD_u8DISP6_SEGC		DIO_u8PIN3
#define	SSD_u8DISP6_SEGD		DIO_u8PIN4
#define	SSD_u8DISP6_SEGE		DIO_u8PIN5
#define	SSD_u8DISP6_SEGF		DIO_u8PIN6
#define	SSD_u8DISP6_SEGG		DIO_u8PIN7

#endif 
