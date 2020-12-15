/*
 * keypad.c
 *
 * Created: 23/11/2020 18:24:51
 *  Author: Marina
 */ 
#include "gpio.h"
#include "<avr/sfr_defs.h>"

void wait_clear(volatile uint8_t *reg_name)
{
	for(uint8_t i=0;i<7;i++)
	{
		loop_until_bit_is_clear(*reg_name,i);
		
	}
	
};
void detect_digits(volatile uint8_t *reg_name)
{
	uint8_t zeros=1;
	while(zeros==1)
	{
		for(uint8_t i=0;i<7;i++)
		{
			(if GPIO_read( *reg_name,i)==1)
			{
				zeros=0;
			}
		}
		
	}
	
}
uint8_t read_digits(volatile uint8_t *reg_name)
{
	uint8_t xy_vector[7];
	uint8_t decnum;
	for(uint8_t i=0;i<7;i++)
	{
		uint8_t GPIO_read(volatile uint8_t *reg_name, uint8_t i);
	}
	
	if(xy_vector[0]==1)
	{
		if(xy_vector[4]==1)
		{
			decnum=1;
		}
		
		if(xy_vector[5]==1)
		{
			decnum=2;
		}
		
		if(xy_vector[6]==1)
		{
			decnum=3;
		}
	}
	
	if(xy_vector[1]==1)
	{
		if(xy_vector[4]==1)
		{
			decnum=4;
		}
		
		if(xy_vector[5]==1)
		{
			decnum=5;
		}
		
		if(xy_vector[6]==1)
		{
			decnum=6;
		}
	}
	
	if(xy_vector[2]==1)
	{
		if(xy_vector[4]==1)
		{
			decnum=7;
		}
		
		if(xy_vector[5]==1)
		{
			decnum=8;
		}
		
		if(xy_vector[6]==1)
		{
			decnum=9;
		}
	}
	
	if(xy_vector[3]==1)
	{
		if(xy_vector[4]==1)
		{
			decnum=10;//asterisk
		}
		
		if(xy_vector[5]==1)
		{
			decnum=0;
		}
		
		if(xy_vector[6]==1)
		{
			decnum=11;//sharp
		}
	}
	
	return decnum;
}