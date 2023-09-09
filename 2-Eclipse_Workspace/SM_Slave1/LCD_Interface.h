/****************************************************/
/* SWC 	  	   : DIO Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 9 AUG 2023                         */
/* Description : Digital Input Outpot driver        */
/****************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_VoidLCDInit(void);
void LCD_VoidSendData(u8 Copy_u8Char);
void LCD_VoidSendCommand(u8 Copy_U8Command);

void LCD_VoidGoToRowCol(u8 Copy_U8Row ,u8 Copy_U8Col);

void LCD_VoidSendNumber(s32 Copy_s32Number);
u8 LCD_u8WriteString(u8 *Copy_U8String);



#endif
