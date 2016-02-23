#ifndef _74HC595_INTERFACE_H_
#define _74HC595_INTERFACE_H_
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  


/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
  
/*Comment!: Sends a clock pulse on SH_CP line*/
extern u8 HC595_u8ShiftPulse(void);
/*Comment!: Sends a clock pulse on ST_CP line*/
extern u8 HC595_u8LatchPulse(void);
/*Comment!: write a single byte to Output shift register 74HC595.*/
extern u8 HC595_u8WriteByte(u8 Copy_u8data);
/*Comment!: change data to high (DS)lines*/
extern u8 HC595_u8DataHigh(void);
/*Comment!: change data to low (DS)lines*/
extern u8 HC595_u8DataLow(void);
/*Comment!: Initialize HC595 System*/
extern void HC595_voidInit(void);
  
#endif  
