﻿/*
 * Motores.c
 *
 * Created: 29/01/2022 8:38:42 p. m.
 *  Author: JOHAN
 */ 
#include "Motores.h"
void TRight(){
	I &= ~(1<<I1) & ~(1<<I2) & ~(1<<I3);
	I|=(1<<I4);
}
//////////////////
void TLeft(){
	I &= ~(1<<I1) & ~(1<<I3) & ~(1<<I4);
	I|=(1<<I2);
}
////////////////
void TForwards(){
	I &= ~(1<<I1) & ~(1<<I3);
	I|=(1<<I2)|(1<<I4);
}
///////////////////
void TBackwards(){
	I &= ~(1<<I2) & ~(1<<I4);
	I|=(1<<I1)|(1<<I3);
}
///////////////////
void stop(){
	I &=0xf0;
}

