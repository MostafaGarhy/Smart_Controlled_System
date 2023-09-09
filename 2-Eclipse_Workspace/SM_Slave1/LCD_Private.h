/****************************************************/
/* SWC 	  	   : DIO Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 9 AUG 2023                         */
/* Description : Digital Input Outpot driver        */
/****************************************************/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_FUN_SET 		0b00111000
#define LCD_DISPLAY_ON_OFF  0b00001100
#define LCD_CLEAR           0b00000001

#define LCD_8BIT_MODE 0
#define LCD_4BIT_MODE 1

/* Commands of initialization of the LCD_8BIT_MODE */
#define FUN_SET           0b00111000
#define DISPLAY_ON_OFF    0b00001111
#define DISPLAY_CLEAR     0b00000001
#define ENTRY_MODE_SET    0b00000110

/* Commands of initialization of the LCD_4BIT_MODE */
#define FUN_SET1          0b00110011
#define FUN_SET2          0b00110010
#define FUN_SET3          0b00101000

#endif
