/****************************************************/
/* SWC 	  	   : DIO Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 9 AUG 2023                         */
/* Description : Digital Input Outpot driver        */
/****************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_DATA_PORT    	 DIO_PORTA
#define LCD_CONTROL_PORT 	 DIO_PORTD

#define CONTROL_RS  	     DIO_PIN2
#define CONTROL_RW  	     DIO_PIN3
#define CONTROL_E   	     DIO_PIN4

/* Select LCD Mode: LCD_8BIT_MODE - LCD_4BIT_MODE */
#define LCD_MODE 		 	LCD_4BIT_MODE




#endif
