/*
 * GccApplication1.c
 *
 * Created: 06/10/2020 17:12:37
 * Author : Marina
 */ 

#include <avr/io.h>


/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_1   PC5     // AVR pin where green LED is connected
#define LED_2   PC4  
#define LED_3   PC3
#define LED_4   PC2
#define LED_5   PC1
#define BTN         PD4
#define BLINK_DELAY 250
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/sfr_defs.h> 


/* Functions ---------------------------------------------------------*/
/**
 * Main function where the program execution begins. Toggle two LEDs 
 * when a push button is pressed.
 */
int main(void)
{   //ACTIVE HIGH ALL
    /* 1 */
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_1);
    // ...and turn LED OFF in Data Register
    PORTC = PORTC & ~(1<<LED_1);

    /* second LED */
	// Set pin as output in Data Direction Register...
	DDRC = DDRC | (1<<LED_2);
	// ...and turn LED OFF in Data Register
	PORTC = PORTC & ~(1<<LED_2);
	
	/* 3 LED */
	// Set pin as output in Data Direction Register...
	DDRC = DDRC | (1<<LED_3);
	// ...and turn LED OFF in Data Register
	PORTC = PORTC & ~(1<<LED_3);
	
	/* 4 LED */
	// Set pin as output in Data Direction Register...
	DDRC = DDRC | (1<<LED_4);
	// ...and turn LED ON in Data Register
	PORTC = PORTC & ~(1<<LED_4);
	
	/* 5 LED */
	// Set pin as output in Data Direction Register...
	DDRC = DDRC | (1<<LED_5);
	// ...and turn LED ON in Data Register
	PORTC = PORTC & ~(1<<LED_5);
	
	
	
	
	// PUSH BOTTON To set internal pull-up resistor 
	DDRD = DDRD & (0<<BTN);
	PORTD = PORTD | (1<<BTN);
	
	
	

    // Infinite loop
    while (1)
    {
		
		loop_until_bit_is_clear(PIND, 4);
		{
		 // Pause several milliseconds
		    PORTC=32;
			_delay_ms(BLINK_DELAY);
			PORTC=(PORTC>>1);
			_delay_ms(BLINK_DELAY);
			PORTC=(PORTC>>1);
			_delay_ms(BLINK_DELAY);
			PORTC=(PORTC>>1);
			_delay_ms(BLINK_DELAY);
			PORTC=(PORTC>>1);
			_delay_ms(BLINK_DELAY);
			PORTC=(PORTC>>1);
			
		}
		
		
       
    }

    // Will never reach this
    return 0;
}




