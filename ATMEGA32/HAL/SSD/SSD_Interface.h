#ifndef _SSD_INTERFACE_H_ 
#define _SSD_INTERFACE_H_   
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: Numbers*/ 
#define SSD_u8NUM0	0
#define SSD_u8NUM1	1
#define SSD_u8NUM2	2
#define SSD_u8NUM3	3
#define SSD_u8NUM4	4
#define SSD_u8NUM5	5
#define SSD_u8NUM6	6
#define SSD_u8NUM7	7
#define SSD_u8NUM8	8
#define SSD_u8NUM9	9

/*Comment!: Displays Numbers*/ 
#define	SSD_u8DISP1	0
#define SSD_u8DISP2	1
#define SSD_u8DISP3	2
#define SSD_u8DISP4	3
#define SSD_u8DISP5	4
#define SSD_u8DISP6	5
  
/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
  
/*Comment!: */  
extern u8 SSD_u8Display(u8 Copy_u8DispIdx, u8 Copy_u8DispVal); 
  
/*Comment!: */  
extern u8 SSD_u8GetVal(u8 Copy_u8DispIdx, u8* Copy_u8DispVal); 
  
/*Comment!: */  
extern u8 SSD_u8TurnOn(u8 Copy_u8DispIdx); 
 
/*Comment!: */  
extern u8 SSD_u8TurnOff(u8 Copy_u8DispIdx); 
 
/*Comment!: */  
extern void SSD_voidInit(void); 
  
#endif  
