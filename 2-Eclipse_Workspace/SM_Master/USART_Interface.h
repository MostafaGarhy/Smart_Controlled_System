#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void UART_VidInit				 			  (void);
void UART_VidTransmitData		    (u8 Copy_U8Data);
u8 	 UART_VidReceiveData		 		 	  (void);
void UART_VidTransmitString		 (u8 *Copy_U8String);
void UART_VidTransmitSNumber	(s32 Copy_S32Number);
void UART_VidTerminalPrintChar (u8 Copy_U8Character);
void UART_VoidSendNumber(s32 Copy_s32Number);
#endif
