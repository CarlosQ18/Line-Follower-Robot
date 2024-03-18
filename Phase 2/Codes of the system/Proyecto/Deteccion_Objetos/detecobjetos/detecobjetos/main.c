/*
 * detecobjetos.c
 *
 * Created: 31/01/2022 4:40:01 p. m.
 * Author : Jhonier Vargas
 */ 

#include <avr/io.h>
#define F_CPU 8000000L
#include <util/delay.h>
#include "do_mods.h"

int main(void)

{
    unsigned char Ofrente = 0x01; //mascara para la detección de un objeto al frente del robot.
	unsigned char Olateral = 0x02; //mascara para la detección de un objeto al lado del robot.
	
	DDRC &= ~(1<<0) & ~(1<<1); // Configura el puerto C0 y C1 como entradas
	DDRB |= (1<<0) | (1<<1); // Configura el puerto B0 Y B1 como salidas
				
    while (1) 
    {
		if( ObjetoAlFrente(Ofrente) && ObjetoAlLado(Olateral) ){
			PORTB = (1 << 0) | ( 1 << 1);
		}
		else if ( ObjetoAlFrente(Ofrente) && !ObjetoAlLado(Olateral) ){
			PORTB |= ( 1 << 0 );
			PORTB &= ~( 1 << 1 );
		}
		else if ( !ObjetoAlFrente(Ofrente) && ObjetoAlLado(Olateral) ){
			PORTB &= ~( 1 << 0 );
			PORTB |=  ( 1 << 1 );
		}
		else{
			PORTB &= ~( 1 << 0 ) & ~( 1 << 1 );
		}
	}
	return 1;
}

