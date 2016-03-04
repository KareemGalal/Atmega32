#ifndef _KEYPAD_CONFIG_H_ 
#define _KEYPAD_CONFIG_H_ 
  
  
/*******************************************************/  
/**************** Public Definitions *******************/  
/*******************************************************/  
  
/*Comment!: Switch State*/
/*Range!: DIO_u8LOW or DIO_u8HIGH*/
#define	TSW_u8PRESSED	DIO_u8LOW //Low for pull up resistor & High for pull down resistor
#define	TSW_u8RELEASED	DIO_u8HIGH

#define KEYPAD_u8PRESSED_RELEASED_LEVEL 50

/*Comment!: KeyPad Configuration Num of Rows & Num of Cols*/
#define NumberOfRows	4
#define NumberOfColumns	4

/*Comment!: Switch Pin Configuration*/
/*Range!  : DIO_u8PIN0 : DIO_u8PIN31*/
#define KEYPAD_ROW1_PIN 		DIO_U8PIN0
#DEFINE KEYPAD_ROW2_PIN         DIO_U8PIN1
#DEFINE KEYPAD_ROW3_PIN         DIO_U8PIN2
#DEFINE KEYPAD_ROW4_PIN         DIO_U8PIN3
#DEFINE KEYPAD_COLUMN1_PIN      DIO_U8PIN4
#DEFINE KEYPAD_COLUMN2_PIN      DIO_U8PIN5
#DEFINE KEYPAD_COLUMN3_PIN      DIO_U8PIN6
#DEFINE KEYPAD_COLUMN4_PIN      DIO_u8PIN7
/*Comment!: if you want to change the keypad Configuration to be 5*5 just edit the NumberOfRows, NumberOfColumns to be 5 and add another #define with the number of extra row, col like #define KEYPAD_ROW5        DIO_u8PIN3 , #define KEYPAD_COLOUMN5     DIO_u8PIN7*/
 
  
  
#endif 
