/*
 * Seguidor_Linea.c
 *
 * Created: 15/03/2022 9:51:33 a. m.
 * Author : Carlos F. Quintero
 */ 

#include <avr/io.h>
#define F_CPU 16000000L
#include <util/delay.h>
#include "SpeedModule.h"
#include "Motores.h"
#include "Modulo_DeteccionLinea.h"
#include "do_mods.h"

#define LineaDerecha 0x04
#define LineaIzquierda 0x08
#define Ofrente 0x01 
#define Olateral 0x02

int main(void)
{
	DDRC &= ~(1<<0) & ~(1<<1) & ~(1<<2) & ~(1<<3);
	DDRD |= (1<<3) | (1<<4) | (1<<2) | (1<<7); 
	ConfigPWM();
	int SeguirLinea;
	while (1) 
    {
		if(ObjetoAlFrente(Ofrente)) SeguirLinea = 0;
		else SeguirLinea = 1;
		
		VelocidadGiro(240,240);
		while (SeguirLinea == 1 ){
			if(ObjetoAlFrente(Ofrente)){
				SeguirLinea = 0;
				TLeft();
				_delay_ms(450);
				stop();
				break;
			}
			else{
				if (!DeteccionLineaDER(LineaDerecha) && !DeteccionLineaIZQ(LineaIzquierda)){
					TForwards();
				}
				if (!DeteccionLineaDER(LineaDerecha) && DeteccionLineaIZQ(LineaIzquierda)){
					TLeft();
				}
				if (DeteccionLineaDER(LineaDerecha) && !DeteccionLineaIZQ(LineaIzquierda)){
					TRight();
				}
				else{
					stop();
				}	
			}
		}
		
		//-----------------------------SEGUIR CONTORNO------------------------------
		while (SeguirLinea == 0){
			if( DeteccionLineaDER(LineaDerecha) || DeteccionLineaIZQ(LineaIzquierda) ){
				TForwards();
				_delay_ms(10);
				stop();
				_delay_ms(500);
				VelocidadGiro(210,210);
				while  (!DeteccionLineaIZQ(LineaIzquierda)) TLeft();
				stop();
				TRight();
				_delay_ms(50);
				stop();
				SeguirLinea = 1;
				break;
			}
			else{
				if( !ObjetoAlFrente(Ofrente) && !ObjetoAlLado(Olateral) ){
					TRight();
					_delay_ms(50);
				}
				else if ( !ObjetoAlFrente(Ofrente) && ObjetoAlLado(Olateral) ){
					TForwards();
					_delay_ms(50);
				}
				else if ( ObjetoAlFrente(Ofrente) && !ObjetoAlLado(Olateral) ){
					TRight();
					_delay_ms(50);
				}
				else{
					TLeft();
					_delay_ms(50);
				}
			}
		}
    }
}

