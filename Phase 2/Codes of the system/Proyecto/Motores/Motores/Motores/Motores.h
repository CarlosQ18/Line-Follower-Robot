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
#define I1	0
#define I2	1
#define I3	2
#define I4	3
#define L	4
#define B	5
#define T	6
#define R	7
void TRight();
void TLeft();
void TForwards();
void TBackwards();
void stop();