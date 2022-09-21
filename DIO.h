/*
 * DIO.h
 *
 *  Created on: seb 21, 2022
 *      Author: Nessma
 */

#ifndef DIO_H_
#define DIO_H_
#include"type.h"

#define DIO_CHANNEL00  0
#define DIO_CHANNEL01  1
#define DIO_CHANNEL02  2
#define DIO_CHANNEL03  3
#define DIO_CHANNEL04  4
#define DIO_CHANNEL05  5
#define DIO_CHANNEL06  6
#define DIO_CHANNEL07  7
//b
#define DIO_CHANNEL08  8
#define DIO_CHANNEL09  9
#define DIO_CHANNEL10 10
#define DIO_CHANNEL11 11
#define DIO_CHANNEL12 12
#define DIO_CHANNEL13 13
#define DIO_CHANNEL14 14
#define DIO_CHANNEL15 15
//c
#define DIO_CHANNEL16 16
#define DIO_CHANNEL17 17
#define DIO_CHANNEL18 18
#define DIO_CHANNEL19 19
#define DIO_CHANNEL20 20
#define DIO_CHANNEL21 21
#define DIO_CHANNEL22 22
#define DIO_CHANNEL23 23
//d
#define DIO_CHANNEL24 24
#define DIO_CHANNEL25 25
#define DIO_CHANNEL26 26
#define DIO_CHANNEL27 27
#define DIO_CHANNEL28 28
#define DIO_CHANNEL29 29
#define DIO_CHANNEL30 30
#define DIO_CHANNEL31 31


typedef enum{
    Dio_enuOk = 0 ,
    Dio_enuChannelError ,
    Dio_enuLevelError ,
    Dio_enuDirectionError ,
    Dio_enuNullPointer ,
    Dio_enuPortError
}Dio_tenuErrorStatus ;


#define DIO_u8HIGH 1
#define DIO_u8LOW  0
#define DIO_u8REG_SIZE 8






/* PORTS */
#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

/* DIRECTION */
#define DIO_u8INPUT 0
#define DIO_u8OUTPUT 1
#define DIO_u8INPUT_PORT 0x00
#define DIO_u8OUTPUT_PORT 0xFF

/* MAX & MIN NUM OF CHANNELS */
#define DIO_u8MIN_CHANNELS 0
#define DIO_u8MAX_CHANNELS 31
#define DIO_u8MIN_PORTS 0
#define DIO_u8MAX_PORTS 4





#define NULL (void*)0

Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level);
Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId ,pu8 Add_pu8ChannelId);
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value);
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId ,pu8 Add_up8PortId);
Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId );




#endif /* DIO_H_ */
