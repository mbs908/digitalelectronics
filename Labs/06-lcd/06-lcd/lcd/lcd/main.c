

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function

/* Function definitions ----------------------------------------------*/
/**
 * Main function where the program execution begins. Update stopwatch
 * value on LCD display when 8-bit Timer/Counter2 overflows.
 */
int main(void)
{
		// Custom character definition using https://omerk.github.io/lcdchargen/
		uint8_t customChar[48] = {
			// addr 0: .....
			0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000,
			// addr 1: |....
			0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000,
			0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000,
			0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100,
			0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110,
			0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111
			};
	// Initialize LCD display
	lcd_init(LCD_DISP_ON);
	// Set pointer to beginning of CGRAM memory
	lcd_command(1 << LCD_CGRAM);
	for (uint8_t i = 0; i < 48; i++)
	{
		// Store all new chars to memory line by line
		lcd_data(customChar[i]);
	}
	// Set DDRAM address
	lcd_command(1 << LCD_DDRAM);
		
    
    
	TIM2_overflow_interrupt_enable();
	TIM2_overflow_16ms();
	
	TIM0_overflow_16ms();
	TIM0_overflow_interrupt_enable();

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
 * ISR starts when Timer/Counter2 overflows. Update the stopwatch on
 * LCD display every sixth overflow, ie approximately every 100 ms
 * (6 x 16 ms = 100 ms).
 */
/* Interrupt service routines ----------------------------------------*/
/**
 * ISR starts when Timer/Counter2 overflows. Update the stopwatch on
 * LCD display every sixth overflow, ie approximately every 100 ms
 * (6 x 16 ms = 100 ms).
 */
ISR(TIMER2_OVF_vect)
{
    static uint8_t number_of_overflows = 0;
    static uint8_t tens = 0;        // Tenths 
    static uint8_t secs = 0;        // Seconds
	static uint8_t mins = 0;		//Minutes
    char lcd_string[2] = "  ";      // String for converting numbers by itoa()
	uint16_t a=0;				//Square of seconds

    number_of_overflows++;
    if (number_of_overflows >= 6)
    {
        // Do this every 6 x 16 ms = 100 ms
        number_of_overflows = 0;
        tens++;
		if(tens>9){
			tens=0;
			secs++;
		}
		if(secs>59){
			mins++;
			secs=0;
		}
		if(mins>59){
			mins=0;
		}
		
		
		
		itoa(mins, lcd_string, 10);
		if(mins<10){
			lcd_gotoxy(1, 0);
			lcd_putc('0');
			lcd_gotoxy(2, 0);
			lcd_puts(lcd_string);
		}
		else{
			lcd_gotoxy(1, 0);
			lcd_puts(lcd_string);
		}
		
		lcd_gotoxy(3, 0);
		lcd_putc(':');
		
		
		itoa(secs, lcd_string, 10);     
		if(secs<10){
			lcd_gotoxy(4, 0);
			lcd_putc('0');
			lcd_gotoxy(5, 0);
			lcd_puts(lcd_string);
		}
		else{
			lcd_gotoxy(4, 0);
			lcd_puts(lcd_string);
		}
		
		lcd_gotoxy(6, 0);
		lcd_putc('.');
		
		itoa(tens, lcd_string, 10);
		lcd_gotoxy(7, 0);
		lcd_puts(lcd_string);
		
		a=secs*secs;
		itoa(a, lcd_string, 10);
		lcd_gotoxy(11, 0);
		lcd_puts("0000");//Clear screen
		if(a<10){
			lcd_gotoxy(14, 0);
		}
		else if(a<100){
			lcd_gotoxy(13, 0);
		}
		else if(a<1000){
			lcd_gotoxy(12, 0);
		}
		else{
			lcd_gotoxy(11, 0);
		}
	
		
		lcd_puts(lcd_string);
    }
}

/**
 * ISR starts when Timer/Counter0 overflows. Update the progress bar on
 * LCD display every 16 ms.
 */

ISR(TIMER0_OVF_vect)
{
    static uint8_t symbol = 0;
    static uint8_t position = 0;
	static uint8_t overflows = 0;

    
	if(symbol>5){
		position++;
		symbol=0;
	}
	lcd_gotoxy(1 + position, 1);
    lcd_putc(symbol);
	symbol++;

	if(overflows>=59){
		position=0;
		overflows=0;
		for(uint8_t i=0;i<11;i++){
			lcd_gotoxy(1+i,1);
			lcd_putc(0);
		}
	}
	overflows++;
	
}