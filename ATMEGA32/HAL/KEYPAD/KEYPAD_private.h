#ifndef _KEYPAD_PRIVATE_H_ 
#define _KEYPAD_PRIVATE_H_   
  
  
/*******************************************************/  
/**************** Private Definitions ******************/  
/*******************************************************/  
  
/*Comment!: States for the T_Switch*/
#define KEYPAD_u8RELEASED_STATE			1
#define KEYPAD_u8BOUNCING_STATE			2
#define KEYPAD_u8PRESSED_STATE			3
  
  
/*******************************************************/  
/*****************  Private Functions  *****************/  
/*******************************************************/  

/*Comment!: Function to Check Keypad Key with DEBOUNCING*/
static u8 KEYPAD_u8CheckSwitch(u8 Copy_u8RowIdx, u8 Copy_u8ColumnIdx, u8* Copy_u8PtrVal);
  
#endif  
