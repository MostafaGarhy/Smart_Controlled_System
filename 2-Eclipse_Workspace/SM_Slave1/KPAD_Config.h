/****************************************************/
/* SWC 	  	   : KPAD Driver                        */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 14 AUG 2023                        */
/* Description : interface with KEY PAD	            */
/****************************************************/

#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_


#define KPAD_ARR {{'c','7','8','9','*','/'},{'I','4','5','6','-','M'},{'%','1','2','3','+','N'},{'S','0','.','=','+','P'}}

#define KPD_KEYS               {{'c','7','8','9','*','/'},   \
				  	           {'I','4','5','6','-','M'},   \
				  	           {'%','1','2','3','+','N'},   \
				  	           {'S','0','.','=','+','P'}}



#define COLUMN_NUMBERS          6
#define ROW_NUMBERS  	        4

#define KPAD_COLUMN_PORT           DIO_PORTB
#define KPAD_ROW_PORT              DIO_PORTD

#define KPAD_COLUMN_PIN0      DIO_PIN0
#define KPAD_COLUMN_PIN1      DIO_PIN1
#define KPAD_COLUMN_PIN2      DIO_PIN2
#define KPAD_COLUMN_PIN3      DIO_PIN3
#define KPAD_COLUMN_PIN4      DIO_PIN4
#define KPAD_COLUMN_PIN5      DIO_PIN5


#define KPAD_ROW_PIN0         DIO_PIN0
#define KPAD_ROW_PIN1         DIO_PIN1
#define KPAD_ROW_PIN2         DIO_PIN2
#define KPAD_ROW_PIN3         DIO_PIN3


#endif
