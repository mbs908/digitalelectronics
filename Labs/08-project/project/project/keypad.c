/*
 * keypad.c
 *
 * Created: 23/11/2020 18:25:33
 *  Author: enola
 */ 
#include <avr/sfr_defs.h>
#include "gpio.h"
#include <avr/delay.h>
uint8_t code_analyzer(char code[4],char correct_code1[4],char correct_code2[4],char correct_code3[4])
{
	
		uint8_t cnt1=0;
		uint8_t cnt2=0;
		uint8_t cnt3=0;
		uint8_t equal=0;
		for (uint8_t i=0;i<4;i++)
		{
			if((code[i]==correct_code1[i])){
				cnt1++;
			}
			
			if((code[i]==correct_code2[i])){
				cnt2++;
			}
			
			if((code[i]==correct_code3[i])){
				cnt3++;
			}
			
		}
		
		if((cnt1==4)|(cnt2==4)|(cnt3==4))
		{
			equal=1;//correct CODE
		}	
		
		return equal;
		
	
}
//void wait_clear(volatile uint8_t *reg_name){
	for(uint8_t i=0;i<7;i++){
		loop_until_bit_is_clear(reg_name,i);
	}
}
//void detect_digit(volatile uint8_t *reg_name){
	uint8_t zeros=1;
	while(zeros==1){//loop until there is a change in the keypad
		for(uint8_t i=0;i<7;i++){
			if(GPIO_read(reg_name,i)==1){
				zeros=0;
			}
		}
	}
}

char read_digits(volatile uint8_t *reg_name){
	
	GPIO_write_low(&PORTC,0);
	GPIO_write_high(&PORTC,1);
	GPIO_write_high(&PORTC,2);
	
	if(GPIO_read(&PINC,3)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,3)==0);
		return '1';
	}
	if(GPIO_read(&PINC,4)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,4)==0);
		return '4';
	}
	if(GPIO_read(&PINC,5)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,5)==0);
		return '7';
	}
	if(GPIO_read(&PINC,6)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,6)==0);
		return '*';
	}
	
	
	GPIO_write_high(&PORTC,0);
	GPIO_write_low(&PORTC,1);
	GPIO_write_high(&PORTC,2);
	
	if(GPIO_read(&PINC,3)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,3)==0);
		return '2';
	}
	if(GPIO_read(&PINC,4)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,4)==0);
		return '5';
	}
	if(GPIO_read(&PINC,5)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,5)==0);
		return '8';
	}
	if(GPIO_read(&PINC,6)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,6)==0);
		return '0';
	}
	
	
	GPIO_write_high(&PORTC,0);
	GPIO_write_high(&PORTC,1);
	GPIO_write_low(&PORTC,2);
	
	if(GPIO_read(&PINC,3)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,3)==0);
		return '3';
	}
	if(GPIO_read(&PINC,4)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,4)==0);
		return '6';
	}
	if(GPIO_read(&PINC,5)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,5)==0);
		return '9';
	}
	if(GPIO_read(&PINC,6)==0){
		_delay_ms(10);
		while(GPIO_read(&PINC,6)==0);
		return '#';
	}
	
	return 'X';
	
}