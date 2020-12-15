/*
 * Cproject.c
 *
 * Created: 23/11/2020 18:05:49
 * Author : Marina
 */ 

#include <avr/io.h>
#include "keypad.h"
#include <avr/sfr_defs.h>
#include "lcd.h"
#include "lcd_definitions.h"
#include "uart.h"


int main(void)
{
   lcd_init(LCD_DISP_ON);
   GPIO_config_input_pullup(&DDRC, PC0);
   GPIO_config_input_pullup(&DDRC, PC1);
   GPIO_config_input_pullup(&DDRC, PC2);
   GPIO_config_input_pullup(&DDRC, PC3);
   GPIO_config_input_pullup(&DDRC, PC4);
   GPIO_config_input_pullup(&DDRC, PC5);
   GPIO_config_input_pullup(&DDRC, PC6);
   
   uint8_t code[4];
   
   char lcd_string[4]= "0000";
    while (1) 
    {
	    for(uint8_t i=0;i<4;i++)
		{
			wait_clear(PINC);
			detect_digits(PINC);
			code[i]=read_digits(PINC);
			lcd_gotoxy(i+1,0);
			itoa(code[i],lcd_string,10);
			lcd_puts(lcd_string);
			
		}
		
    }
}

