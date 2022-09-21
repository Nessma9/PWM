/*
 * register.h
 *
 *  Created on: seb 21, 2022
 *      Author: Nessma
 */


#ifndef REGISTER_H_
#define REGISTER_H_


#define PORTA *(unsigned char*)(0x3B)
#define DDRA *(unsigned char*)(0x3A)
#define PINA *(unsigned char*)(0x39)

#define PORTB *(unsigned char*)(0x38)
#define DDRB *(unsigned char*)(0x37)
#define PINB *(unsigned char*)(0x36)

#define PORTC *(unsigned char*)(0x35)
#define DDRC *(unsigned char*)(0x34)
#define PINC *(unsigned char*)(0x33)

#define PORTD *(unsigned char*)(0x32)
#define DDRD *(unsigned char*)(0x31)
#define PIND *(unsigned char*)(0x30)



//interrupt
#define SREG *(unsigned char*)(0x3F)
#define MCUCR *(unsigned char*)(0x55)
#define MCUCSR *(unsigned char*)(0x54)
#define GICR *(unsigned char*)(0x5B)
#define GIFR *(unsigned char*)(0x5A)



//SPI
#define SPCR *(unsigned char*)(0x2D)
#define SPSR *(unsigned char*)(0x2E)
#define SPDR *(unsigned char*)(0x2F)


#endif /* REGISTER_H_ */




