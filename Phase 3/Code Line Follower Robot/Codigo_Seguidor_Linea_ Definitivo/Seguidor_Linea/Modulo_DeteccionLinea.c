/*
 * Modulo_DeteccionLinea.c
 *
 * Created: 30/01/2022 12:17:25 p. m.
 *  Author: Carlos F. Quintero
 */ 

#include <avr/io.h>
#include "Modulo_DeteccionLinea.h"

int DeteccionLineaDER(unsigned char LineaDER)
{
	if (PINC & LineaDER) return 1;
	else return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int DeteccionLineaIZQ(unsigned char LineaIZQ)
{
	if (PINC & LineaIZQ) return 1;
	else return 0;
}
