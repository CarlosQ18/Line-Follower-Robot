/*
 * Motores.c
 *
 * Created: 28/01/2022 12:36:45 a. m.
 * Author : JOHAN
 */ 

#include <avr/io.h>
#include "Motores.h"
#define F_CPU	16000000
#include <util/delay.h>

int main(void)
{
	DDRD = 0x0f;
	PORTD = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(6000);
		TForwards();
    }
}

