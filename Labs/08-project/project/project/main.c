#include <avr/io.h>
#include "timer.h"
#include "gpio.h"
#include "keypad.h"
#include "lcd.h"
#include "lcd_definitions.h"
#include "uart.h"
#include "avr/sfr_defs.h"
#include <util/delay.h> 
#include <avr/interrupt.h> 
#define F_CPU	16000000
#define LED_GREEN PD1
#define LED_RED PD0



#include <stdlib.h>
int main(void)
{   
	GPIO_config_output(&DDRD, LED_GREEN);
	GPIO_write_low(&PORTD, LED_GREEN);//lED OFF because active-high*/

    GPIO_config_output(&DDRD, LED_RED);
    GPIO_write_low(&PORTD, LED_RED);//lED OFF because active-high*/

    
	
	lcd_init(LCD_DISP_ON);
	GPIO_config_output(&DDRC,0);
	GPIO_config_output(&DDRC,1);
	GPIO_config_output(&DDRC,2);
	GPIO_config_input_pullup(&DDRC,3);
	GPIO_config_input_pullup(&DDRC,4);
	GPIO_config_input_pullup(&DDRC,5);
	GPIO_config_input_pullup(&DDRC,6);
	
	GPIO_config_output(&DDRB,3);
	TIM1_overflow_33ms();
	TIM1_overflow_interrupt_enable();
	char code[4];
	
	char lcd_string[4] = "0000";
	char control='X';
	sei();
    /* Replace with your application code */
    while (1) 
    {
		/*for(uint8_t i=0;i<4;i++){
			control='X';
			while(control=='X'){
				control=read_digits(&PINC);
			}
			code[i]=control;
			
			
			lcd_gotoxy(i+1,0);
			itoa(code[i], lcd_string, 10);
			lcd_putc(code[i]);
			
			
		
			
			
		}
		if (code_analyzer(code,correct_code1,correct_code2,correct_code3)==1)
		{
			GPIO_write_high(&PORTB,3);
			_delay_ms(1000);
			//GPIO_write_low(&PORTB,3);
		}*/
		
		/*if(code_analyzer(code,correct_code1,correct_code2,correct_code3)==1)
		{
			 GPIO_write_high(&PORTD, LED_GREEN);
			
			LO QUE HE HECHO YO HOY JUNTO CON CAMBIAR LA FUNCION CODE ANALYZER
		}
		
    }*/
}
ISR(TIMER1_OVF_vect){
	
	char correct_code1[4]={1,2,3,4};
	char correct_code2[4]={5,6,7,8};
	char correct_code3[4]={6,3,9,7};
	static uint8_t cnt=0;
	static uint8_t time_limit_on=0;
	static uint16_t time_limit=0;
	char code[4];
	char readed=read_digits(&PINC);
	if(readed!='X'){
		code[cnt]=readed;
		lcd_gotoxy(cnt+1,0);
		lcd_putc(readed);
		cnt++;
		
		if(cnt==1){
			time_limit=0;
			time_limit_on=1;
		}
		if(cnt==4){
			time_limit_on=0;
			code_analyzer(code,correct_code1,correct_code2,correct_code3);
			if(code_analyzer(code,correct_code1,correct_code2,correct_code3)==1)
			{
				GPIO_write_high(&PORTD, LED_GREEN);
				
				//LO QUE HE HECHO YO HOY JUNTO CON CAMBIAR LA FUNCION CODE ANALYZER
			}
			else
			{
				GPIO_write_high(&PORTD,LED_RED);
			}
			
		}
	}
	
	if(cnt==4){ 
		cnt=0;
	}
	time_limit++;
	if((time_limit==250)&&(time_limit_on==1)){
		time_limit=0;
		cnt=0;
		lcd_gotoxy(1,0);
		lcd_puts("    ");
	}
}


