/*
 * PWM.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Nessma
 */

#ifndef PWM_H_
#define PWM_H_
#include"type.h"

#define TCCR0 *(unsigned char*)(0x53)
#define OCR0 *(unsigned char*)(0x5C)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COMOO 4
#define COMO1 5
#define WGM00 6



//function
void PWM_vidInit();
void PWM_VidSetOCR0Value(u8 value);
#endif /* PWM_H_ */
