/*
 * PWM.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Nessma
 */
#include"type.h"
#include"bit_utils.h"
#include"register.h"
#include"port.h"
#include"PWM.h"

void PWM_vidInit()
{
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,COMO1);
	SET_BIT(TCCR0,CS01);
 Port_enuSetPinDirection(PORT_u8PIN11,	PORT_u8OUTPUT);
}
 void PWM_VidSetOCR0Value(u8 value)
 {

		 OCR0=value;

 }



