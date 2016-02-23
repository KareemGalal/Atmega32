#ifndef _74HC595_CONFIG_H_
#define _74HC595_CONFIG_H_
/*******************************************************/  
/************** Pin Configuration  HC595 ***************/  
/*******************************************************/ 

/*Comment!: Data pin (DS) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_DS			DIO_u8PIN26
/*Comment!: Shift Clock (SH_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_SH_CP			DIO_u8PIN24
/*Comment!: Store Clock (ST_CP) pin location */
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define HC595_ST_CP			DIO_u8PIN25


#endif 
