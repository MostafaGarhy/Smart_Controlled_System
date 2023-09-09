/****************************************************/
/* SWC 	  	   : DIO Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 9 AUG 2023                         */
/* Description : Digital Input Outpot driver        */
/****************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_DATA_PORT    	DIO_PORTA
#define LCD_CONTROL_PORT 	DIO_PORTD

#define CONTROL_E   	  DIO_PIN6
#define CONTROL_RS        DIO_PIN4
#define CONTROL_RW  	  DIO_PIN5

/* options
 * LCD_8BIT_MODE --> 0
   LCD_4BIT_MODE --> 1
 *
 *
 * */
#define LCD_PINS_MODE LCD_4BIT_MODE




#endif
