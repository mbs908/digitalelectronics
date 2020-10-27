/***********************************************************************
 * 
 * Decimal counter with 7-segment output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>
#include "timer.h"          
#include "segment.h"  
   

//Variables
uint8_t unit=0;
uint8_t dec=0;
 
int main(void)
{
    // Configure SSD signals
    SEG_init();

    SEG_update_shift_regs(unit, 0);

	/* Configure 8-bit Timer/Counter0
     * Set prescaler and enable overflow interrupt */
	TIM0_overflow_4ms();
	TIM0_overflow_interrupt_enable();
	
    /* Configure 16-bit Timer/Counter1
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

ISR(TIMER1_OVF_vect)
{
	unit++;

	 if(unit>=10)
	 {
		unit=0;
	    dec++;
				
				if(dec>=6)
				{
					unit=0;
					dec=0;
				}
				
	 }
}
		 
ISR(TIMER0_OVF_vect)
{		 
	 static uint8_t pos=0;
	 if(pos==0)
	 {
		 SEG_update_shift_regs(unit,pos);
		 pos=1;
	 }
	 else
	 {
		 SEG_update_shift_regs(dec,pos);
		 pos=0;
	 }
}
