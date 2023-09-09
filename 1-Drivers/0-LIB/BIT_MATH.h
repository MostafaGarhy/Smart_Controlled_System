//Header File
#ifndef bit_math_h
#define bit_math_h

#define SET_BIT(reg,bit) reg = reg|(1<<bit)
#define CLR_BIT(reg,bit) reg = reg &(~(1<<bit))
#define TOG_BIT(reg,bit) reg = reg^(1<<bit)
#define GET_BIT(reg,bit)       (reg>>bit)&1
#define SRR_BIT(reg,bit) 	   (reg%2)*128+(reg>>1)
#define SLR_BIT(reg,bit)       (reg|128)+(reg<<1)
#define KNOW_NUMBER(bit)        bit&(bit-1)


#define LOW 0
#define HIGH 1
#define NULL ((void *)0)
#define	NULL_STR  '\0'
#define ERROR_STATE_OK  1
#define ERROR_STATE_NOK 0
#endif
