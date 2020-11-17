/***********************************************************************
 * 
 * Analog-to-digital conversion with displaying result on LCD and 
 * transmitting via UART.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function
#include "uart.h"           // Peter Fleury's UART library
#define F_CPU 16000000

/* Function definitions ----------------------------------------------*/
/**
 * Main function where the program execution begins. Use Timer/Counter1
 * and start ADC conversion four times per second. Send value to LCD
 * and UART.
 */
uint8_t parity_calculator(uint16_t value)
{
	uint8_t j=0;
	uint8_t parity=0; //ODD PARITY
	uint8_t i=0;
	
	for(i=0;i<15;i++)
	{
		if((value % 2)==1)
		{
			j++;
		}
		value=value>>1;
	}
	
	if((j % 2)==1)
	{
		parity=0;
	}
	else
	{
		parity=1;
	}
	return parity;
}

int main(void)
{
    // Initialize LCD display
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(1, 0); lcd_puts("value:");
    lcd_gotoxy(3, 1); lcd_puts("parity:");
    lcd_gotoxy(8, 0); lcd_puts("a");    // Put ADC value in decimal
    lcd_gotoxy(13,0); lcd_puts("b");    // Put ADC value in hexadecimal
    lcd_gotoxy(8, 1); lcd_puts("c");    // Put button name here

    // Configure ADC to convert PC0[A0] analog value
    // Set ADC reference to AVcc
	ADMUX=ADMUX|(1<<REFS0);
    // Set input channel to ADC0
    ADMUX&=~((1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0));
    // Enable ADC module
    ADCSRA|=(1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA|=(1<<ADIE);
    // Set clock prescaler to 128

    ADCSRA|=((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Enable interrupt and set the overflow prescaler to 262 ms
	TIM1_overflow_interrupt_enable()
	TIM1_overflow_262ms()


    // Initialize UART to asynchronous, 8N1, 9600
	uart_init(UART_BAUD_SELECT(9600,F_CPU));


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
 * ISR starts when Timer/Counter1 overflows. Use single conversion mode
 * and start conversion four times per second.
 */
ISR(TIMER1_OVF_vect)
{
	static uint8_t i=0;
	if(i==3)
	{
		i=0;
		ADCSRA=ADCSRA|(1<<ADSC);
	}
	
	else
	{
		i++;
	}

}

/* -------------------------------------------------------------------*/
/**
 * ISR starts when ADC completes the conversion. Display value on LCD
 * and send it to UART.
 */
ISR(ADC_vect)
{
    uint16_t value = 0;
    char lcd_string[4] = "0000";

    value = ADC;    // Copy ADC result to 16-bit variable
    itoa(value, lcd_string, 10);    // Convert decimal value to string
	lcd_gotoxy(8,0);
	lcd_puts("    ");
	lcd_gotoxy(8,0);
	lcd_puts(lcd_string);
	
	if(value<=80)
	{
		uart_puts("right button");
	}
	
	if((value>80) && (value<190 ))
	{
		uart_puts("up button");
	}
	
	if((value>190) && (value<370 ))
	{
		uart_puts("down button");
	}
	
	if((value>370) && (value<570 ))
	{
		uart_puts("left button");
	}
	if((value>570) && (value<700 ))
	{
		uart_puts("left button");
	}
	if((value>700) && (value<1090 ))
	{
		uart_puts("none button");
	}
	
	
	
    uart_puts(lcd_string);
	uart_puts("\r\n");
	
	itoa(value, lcd_string, 16);    // Convert decimal value to string
	lcd_gotoxy(13,0);
	lcd_puts("    ");
	lcd_gotoxy(13,0);
	lcd_puts(lcd_string);


    //PARITY
	itoa(parity_calculator(value), lcd_string, 10);
	lcd_gotoxy(12,1);
	lcd_puts("    ");
	lcd_gotoxy(12,1);
	lcd_puts(lcd_string);
	


}
