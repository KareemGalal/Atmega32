/*
   DIO_private.h

    Created on: Jan 27, 2016
        Author: Kareem Galal
*/

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/*******************************************************/
/***************** Private Definitions  ****************/
/*******************************************************/
/*Comment!: Number of Pins per Port */
#define NUMBER_OF_PINS_PER_PORT		8

/*Comment!: Number of PORTS*/
#define NUMBER_OF_PORTS 			4

/*Comment!: ATMEGA32 I/O Registers */
#define DIO_u8PORTA   ((volatile u8*)(0x3B))
#define DIO_u8DDRA    ((volatile u8*)(0x3A))
#define DIO_u8PINA    ((volatile u8*)(0x39))
#define DIO_u8PORTB   ((volatile u8*)(0x38))
#define DIO_u8DDRB    ((volatile u8*)(0x37))
#define DIO_u8PINB    ((volatile u8*)(0x36))
#define DIO_u8PORTC   ((volatile u8*)(0x35))
#define DIO_u8DDRC    ((volatile u8*)(0x34))
#define DIO_u8PINC    ((volatile u8*)(0x33))
#define DIO_u8PORTD   ((volatile u8*)(0x32))
#define DIO_u8DDRD    ((volatile u8*)(0x31))
#define DIO_u8PIND    ((volatile u8*)(0x30))

/*******************************************************/
/***************** Private Functions *******************/
/*******************************************************/

/*Comment!: Concatenate Function */
#define CONC_HELPER(x7,x6,x5,x4,x3,x2,x1,x0) 0b##x7##x6##x5##x4##x3##x2##x1##x0
#define CONC(x7,x6,x5,x4,x3,x2,x1,x0)    CONC_HELPER(x7,x6,x5,x4,x3,x2,x1,x0)

/*Comment!: Port Initial Direction */
#define DIO_u8PORTA_DIR CONC(DIO_u8PIN7_INITDIR, DIO_u8PIN6_INITDIR, DIO_u8PIN5_INITDIR, DIO_u8PIN4_INITDIR, DIO_u8PIN3_INITDIR, DIO_u8PIN2_INITDIR, DIO_u8PIN1_INITDIR, DIO_u8PIN0_INITDIR)
#define DIO_u8PORTB_DIR CONC(DIO_u8PIN15_INITDIR, DIO_u8PIN14_INITDIR, DIO_u8PIN13_INITDIR, DIO_u8PIN12_INITDIR, DIO_u8PIN11_INITDIR, DIO_u8PIN10_INITDIR, DIO_u8PIN9_INITDIR, DIO_u8PIN8_INITDIR)
#define DIO_u8PORTC_DIR CONC(DIO_u8PIN23_INITDIR, DIO_u8PIN22_INITDIR, DIO_u8PIN21_INITDIR, DIO_u8PIN20_INITDIR, DIO_u8PIN19_INITDIR, DIO_u8PIN18_INITDIR, DIO_u8PIN17_INITDIR, DIO_u8PIN16_INITDIR)
#define DIO_u8PORTD_DIR CONC(DIO_u8PIN31_INITDIR, DIO_u8PIN30_INITDIR, DIO_u8PIN29_INITDIR, DIO_u8PIN28_INITDIR, DIO_u8PIN27_INITDIR, DIO_u8PIN26_INITDIR, DIO_u8PIN25_INITDIR, DIO_u8PIN24_INITDIR)

/*Comment!: Port Initial Value */
#define DIO_u8PORTA_VAL CONC(DIO_u8PIN7_INITVAL, DIO_u8PIN6_INITVAL, DIO_u8PIN5_INITVAL, DIO_u8PIN4_INITVAL, DIO_u8PIN3_INITVAL, DIO_u8PIN2_INITVAL, DIO_u8PIN1_INITVAL, DIO_u8PIN0_INITVAL)
#define DIO_u8PORTB_VAL CONC(DIO_u8PIN15_INITVAL, DIO_u8PIN14_INITVAL, DIO_u8PIN13_INITVAL, DIO_u8PIN12_INITVAL, DIO_u8PIN11_INITVAL, DIO_u8PIN10_INITVAL, DIO_u8PIN9_INITVAL, DIO_u8PIN8_INITVAL)
#define DIO_u8PORTC_VAL CONC(DIO_u8PIN23_INITVAL, DIO_u8PIN22_INITVAL, DIO_u8PIN21_INITVAL, DIO_u8PIN20_INITVAL, DIO_u8PIN19_INITVAL, DIO_u8PIN18_INITVAL, DIO_u8PIN17_INITVAL, DIO_u8PIN16_INITVAL)
#define DIO_u8PORTD_VAL CONC(DIO_u8PIN30_INITVAL, DIO_u8PIN30_INITVAL, DIO_u8PIN29_INITVAL, DIO_u8PIN28_INITVAL, DIO_u8PIN27_INITVAL, DIO_u8PIN26_INITVAL, DIO_u8PIN25_INITVAL, DIO_u8PIN24_INITVAL)

#endif /* _DIO_PRIVATE_H_ */
