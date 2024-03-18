/*
 * SpeedModule.c
 *
 * Created: 14/03/2022 11:15:41 a. m.
 *  Author: Carlos F. Quintero
 */ 
#include <avr/io.h>

void ConfigPWM(){
	DDRD |= (1<<5) | (1<<6); // Configura el puerto D5 y D6 como salidas de la señal PWM
	
	TCCR0A |= (1 << WGM01) | (1 << WGM00); // Configuració de Fast PWM
	TCCR0A |= (1 << COM0A1); // Non inverting mode del PWM del puerto OC0A (D6)	TCCR0A |= (1 << COM0B1); // Non inverting mode del PWM del puerto OC0B (D5)	TCCR0B |= (1 << CS00); // No prescaling	TCNT0 = 0x00;
	OCR0A = 0x00;	OCR0B = 0x00;
}

void VelocidadGiro(uint8_t VelIzq, uint8_t VelDer){
	OCR0A = VelIzq;
	OCR0B = VelDer;
}