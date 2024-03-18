/*
 * Detectar_Linea.c
 *
 * Created: 3/02/2022 12:14:49 p. m.
 * Author : Carlos F. Quintero
 */ 
#define F_CPU 8000000U
#include <avr/io.h>
#include <util/delay.h>
#include "Modulo_DeteccionLinea.h"

int main(void)
{
    unsigned char LineaDerecha = 0x04;  //mascara para la detección de la linea por el sensor Derecho robot.
    unsigned char LineaIzquierda = 0x08; //mascara para la detección de la linea por el sensor Izquierdo robot.
    
    DDRC &= ~(1<<2) & ~(1<<3); // Configura el puerto C2 y C3 como entradas
    DDRB |= (1<<2) | (1<<3); // Configura el puerto B2 Y B3 como salidas
    
    while (1)
    {
	    if( DeteccionLineaDER(LineaDerecha) && DeteccionLineaIZQ(LineaIzquierda) ){
		    PORTB = (1 << 2) | ( 1 << 3);
	    }
	    else if (  DeteccionLineaDER(LineaDerecha) && !DeteccionLineaIZQ(LineaIzquierda) ){
		    PORTB |= ( 1 << 2 );
		    PORTB &= ~( 1 << 3 );
	    }
	    else if (  !DeteccionLineaDER(LineaDerecha) && DeteccionLineaIZQ(LineaIzquierda) ){
		    PORTB &= ~( 1 << 2 );
		    PORTB |=  ( 1 << 3 );
	    }
	    else{
		    PORTB &= ~( 1 << 2 ) & ~( 1 << 3 );
	    }
    }
    return 1;
}

