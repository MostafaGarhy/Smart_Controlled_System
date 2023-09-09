#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define UART_UDR_REG                *((volatile u8*)0x2C)
#define UART_UCSRA_REG              *((volatile u8*)0x2B)
#define UART_UCSRB_REG              *((volatile u8*)0x2A)
#define UART_UCSRC_REG              *((volatile u8*)0x40)
#define UART_UBRRL_REG              *((volatile u8*)0x29)
#define UART_UBRRH_REG              *((volatile u8*)0x40)

#define UCSRC_URSEL_BIT					7
#define UCSRC_UCSZ0_BIT					1
#define UCSRC_UCSZ1_BIT					2
#define UCSRB_RXEN_BIT					4
#define UCSRB_TXEN_BIT					3
#define UCSRA_UDRE_BIT					5
#define UCSRA_RXC_BIT					7

#endif
