/***********************************************************************
 * 
 * Control LEDs using functions from GPIO and Timer libraries. Do not 
 * use delay library any more.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_D1  PC5
#define LED_D2  PC4
#define LED_D3  PC3
#define LED_D4  PC2
#define LED_D5  PC1
#define BTN     PD4
/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "gpio.h"         // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC

/* Function definitions ----------------------------------------------*/

uint8_t mkr;//marker
int main(void)
{
    /* Configuration of LEDs */
     GPIO_config_output(&DDRC, LED_D1);
     GPIO_write_high(&PORTC, LED_D1);
    
	 GPIO_config_output(&DDRC, LED_D2);
	 GPIO_write_low(&PORTC, LED_D2);
	 
	 GPIO_config_output(&DDRC, LED_D3);
	 GPIO_write_low(&PORTC, LED_D3);
	  
	 GPIO_config_output(&DDRC, LED_D4);
	 GPIO_write_low(&PORTC, LED_D4);
	   
	 GPIO_config_output(&DDRC, LED_D5);
	 GPIO_write_low(&PORTC, LED_D5);
		
     GPIO_config_input_pullup( &DDRD, BTN);

    /* Configuration of 16-bit Timer/Counter1
     * Set prescaler and enable overflow interrupt */
    TIM1_overflow_1s();
    TIM1_overflow_interrupt_enable();

 
    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**
 * ISR starts when Timer/Counter1 overflows. */
ISR(TIMER1_OVF_vect)
{
   
	mkr++;
	PORTC=(PORTC>>1);
	if(mkr==5)
	{
		mkr=0;
		PORTC=32;
	}
	
	GPIO_read(&PIND,BTN);
	if(GPIO_read(&PIND,BTN)==0)
	{
		TIM1_overflow_262ms();
	}
	else
	{
		TIM1_overflow_1s();
	}
		
	
}

