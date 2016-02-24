#ifndef _74HC595_INTERFACE_H_
#define _74HC595_INTERFACE_H_
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  

/*Comment!: Number of connected 74HC595*/
#define	HC595_u8NUMOFCONNECTED	HC595_u8NUM2


/*Comment!: Displays Numbers*/
#define	HC595_u8NUM1	0
#define HC595_u8NUM2	1
#define HC595_u8NUM3	2
#define HC595_u8NUM4	3

/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
  
/*Comment!: Sends a clock pulse on SH_CP line*/
extern u8 HC595_u8ShiftPulse(u8 Copy_u8DeviceIdx);
/*Comment!: Sends a clock pulse on ST_CP line*/
extern u8 HC595_u8LatchPulse(u8 Copy_u8DeviceIdx);
/*Comment!: write a single byte to Output shift register 74HC595.*/
extern u8 HC595_u8WriteByte(u8 Copy_u8DeviceIdx, u8 Copy_u8data);
/*Comment!: change data to high (DS)lines*/
extern u8 HC595_u8DataHigh(u8 Copy_u8DeviceIdx);
/*Comment!: change data to low (DS)lines*/
extern u8 HC595_u8DataLow(u8 Copy_u8DeviceIdx);
/*Comment!: Initialize HC595 System*/
extern void HC595_voidInit(void);
  
#endif  
