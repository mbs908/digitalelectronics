/*
 * snake.c
 *
 * Created: 26/10/2020 18:30:56
 * Author : Marina
 */ 

#include <avr/io.h>         
#include <avr/interrupt.h>
#include "timer.h"          
#include "segment.h"  
    
uint8_t cnt0=0;
int main(void)
{
    
    SEG_init();

    SEG_update_shift_regs(cnt0, 0); 
     
	TIM1_overflow_262ms();
	TIM1_overflow_interrupt_enable();
		 
    sei();
    
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    return 0;
}

ISR(TIMER1_OVF_vect)
{
	cnt0++;
	SEG_update_shift_regs(cnt0,0);
	if(cnt0>=6)
	{
		cnt0=0;
		SEG_update_shift_regs(cnt0,0);
	}
}



		 

