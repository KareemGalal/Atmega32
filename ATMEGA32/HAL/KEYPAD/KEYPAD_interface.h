#ifndef _KEYPAD_INTERFACE_H_ 
#define _KEYPAD_INTERFACE_H_   
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  

  
/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
  
/*Comment!: Intialization Function*/
void Keypad_voidInit(void);
/*Comment!: Intialization Function*/
extern u8 KEYPAD_u8Read(u8* Copy_u8PtrVal);
  
#endif  
