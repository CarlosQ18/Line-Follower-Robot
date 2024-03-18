/*
 * do_mods.c
 *
 * Created: 31/01/2022 5:08:44 p. m.
 *  Author: Jhonier Vargas
 */ 
#include <avr/io.h>
#include "do_mods.h"

int ObjetoAlFrente(unsigned char ofrente)
{
	if (PINC & ofrente)
		return 0;
	else
		return 1;
}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int ObjetoAlLado(unsigned char olado)
{
	if (PINC & olado)
		return 0;
	else
		return 1;
}



