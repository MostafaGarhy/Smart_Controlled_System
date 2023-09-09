/****************************************************/
/* SWC 	  	   : KPAD Driver                        */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 14 AUG 2023                        */
/* Description : interface with KEY PAD	            */
/****************************************************/

#ifndef KPAD_INTERFACE_H_
#define KPAD_INTERFACE_H_


u8 KPAD_U8GetPressedKey(u8 *Copy_U8Returned);
void KPAD_Void_INIT(void);


#endif
