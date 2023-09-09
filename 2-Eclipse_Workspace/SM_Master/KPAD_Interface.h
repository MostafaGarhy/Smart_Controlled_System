/****************************************************/
/* SWC 	  	   : KPAD Driver                        */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 14 AUG 2023                        */
/* Description : interface with KEY PAD	            */
/****************************************************/

#ifndef KPAD_INTERFACE_H_
#define KPAD_INTERFACE_H_

void KPAD_VidInit(void);
u8 KPAD_U8GetPressedKey(u8 *Copy_U8Returned);



#endif
