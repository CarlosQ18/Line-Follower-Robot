/*
 * VelocidadGiro.c
 *
 * Created: 14/03/2022 10:46:39 a. m.
 * Author : Carlos F. Quintero
 */ 

#include <avr/io.h>
#define F_CPU 8000000L
#include <util/delay.h>
#include "SpeedModule.h"

int main(void)
{
	ConfigPWM();
    while (1) 
    {
		VelocidadGiro(0,230);
		VelocidadGiro(100,230);
		VelocidadGiro(0,230);
		VelocidadGiro(255,230);
    }
}

