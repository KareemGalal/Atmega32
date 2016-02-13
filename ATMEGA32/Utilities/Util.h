/*
 * Util.h
 *
 *  Created on: Feb 4, 2016
 *      Author: KiMo
 */

#ifndef _UTIL_H_
#define _UTIL_H_


#define	GET_BIT(REG,BIT_NUM)				(((REG)>>(BIT_NUM))&0b1)
#define SET_BIT(REG,BIT_NUM)				((REG)|=(1<<(BIT_NUM)))
#define CLR_BIT(REG,BIT_NUM)				((REG)&=~(1<<(BIT_NUM)))//??
#define TOGGLE_BIT(REG,BIT_NUM)				((REG)^=(1<<(BIT_NUM)))
#define ASSIGN_BIT(REG,BIT_NUM,VALUE)		((REG)= ((REG) & ~(1<<(BIT_NUM))) | (VALUE<<(BIT_NUM)))

#define	GET_REG(REG)						(REG)
#define SET_REG(REG)						((REG)=0xFF)
#define CLR_REG(REG)						((REG)=0x00)
#define TOGGLE_REG(REG)						((REG)~=(REG))	//((REG)^=0xFF)
#define ASSIGN_REG(REG,VALUE)				((REG)=(VALUE))

#define	GET_LOW_NIB(REG)					((REG)&0x0F)
#define SET_LOW_NIB(REG)					((REG)|=0x0F)
#define CLR_LOW_NIB(REG)					((REG)&=0xF0)
#define TOGGLE_LOW_NIB(REG)					((REG)^=0x0F)
#define ASSIGN_LOW_NIB(REG,VALUE)			((REG)=(((REG)&0xF0)|((VALUE)&0x0F))) //??

#define	GET_HIGH_NIB(REG)					(((REG)&0XF0)>>4)//((REG)>>4)
#define SET_HIGH_NIB(REG)					((REG)|=0XF0)
#define CLR_HIGH_BIT(REG)					((REG)&=0X0F)
#define TOGGLE_HIGH_NIB(REG)				((REG)^=0XF0)
#define ASSIGN_HIGH_NIB(REG,VALUE)			((REG)=((VALUE<<4)|(REG&0x0F)))

#endif /* _UTIL_H_ */
