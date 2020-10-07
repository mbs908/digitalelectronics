/*
 * gpio_library.c
 *
 * Created: 07/10/2020 9:21:53
 * Author : Marina
 */ 

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5
#define LED_RED  PC0                            // AVR pin where green LED is connected
#define BLINK_DELAY 500
#define BTN         PD2
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include "gpio.h"           // GPIO library for AVR-GCC

/* Function definitions ----------------------------------------------*/
/**
 * Main function where the program execution begins. Toggle two LEDs 
 * when a push button is pressed. Functions from user-defined GPIO
 * library is used instead of low-level logic operations.
 */
int main(void)
{
    /* GREEN LED */
    GPIO_config_output(&DDRB, LED_GREEN);
    GPIO_write_low(&PORTB, LED_GREEN);//lED OFF because active-higj

    /* second LED */
	 GPIO_config_output(&DDRC, LED_RED);
	 GPIO_write_high(&PORTC,LED_RED);//LED on because active low
    // WRITE YOUR CODE HERE

  
	// PUSH BOTTON To set internal pull-up resistor
	 GPIO_config_input_pullup(&DDRD, BTN);
	
    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(BLINK_DELAY);

        // WRITE YOUR CODE HERE
		GPIO_toggle(&PORTB,LED_GREEN);
		GPIO_toggle(&PORTC,LED_RED);
		
		//TIENE QUE PARPADEAR SOLO SI SE PULSA EL BOT�N
    }

    // Will never reach this
    return 0;
}
