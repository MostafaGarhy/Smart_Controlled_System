/****************************************************/
/* SWC 	  	   : KPAD Driver                        */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 14 AUG 2023                        */
/* Description : interface with KEY PAD	            */
/****************************************************/

#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_


#define KPAD_ARR {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}}

#define KPD_KEYS               {{7,8,9,'/'},   \
				  	           {4,5,6,'*'},   \
				  	           {1,2,3,'-'},   \
				  	           {'c',0,'=','+'}}

#define KPAD_COLUMN_PORT

#define COLUMN_NUMBERS          4
#define ROW_NUMBERS  	        4

#define KPAD_PORT             DIO_PORTA

#define KPAD_COLUMN_PIN0      DIO_PIN4
#define KPAD_COLUMN_PIN1      DIO_PIN5
#define KPAD_COLUMN_PIN2      DIO_PIN6
#define KPAD_COLUMN_PIN3      DIO_PIN7
#define KPAD_COLUMN_PIN3      DIO_PIN7
#define KPAD_COLUMN_PIN3      DIO_PIN7
#define KPAD_COLUMN_PIN3      DIO_PIN7

#define KPAD_ROW_PIN0         DIO_PIN0
#define KPAD_ROW_PIN1         DIO_PIN1
#define KPAD_ROW_PIN2         DIO_PIN2
#define KPAD_ROW_PIN3         DIO_PIN3



#endif
