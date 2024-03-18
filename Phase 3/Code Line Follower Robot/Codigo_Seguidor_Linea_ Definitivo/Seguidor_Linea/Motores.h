/*
 * Motores.h
 *
 * Created: 29/01/2022 6:42:45 p. m.
 *  Author: JOHAN
 */ 

#include <avr/io.h>
#include <stdio.h>
#define dir	PIND
#define I	PORTD
#define I1	3
#define I2	4
#define I3	2
#define I4	7
void TRight();
void TLeft();
void TForwards();
void TBackwards();
void stop();