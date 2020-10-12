/*
 * gpio.c
 *
 * Created: 07/10/2020 9:45:03
 *  Author: Marina
 */ 
/* Includes ----------------------------------------------------------*/
#include "gpio.h"

/* Function definitions ----------------------------------------------*/
void GPIO_config_output(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name | (1<<pin_num);//set the bit
}

/*--------------------------------------------------------------------*/
void GPIO_config_input_nopull(volatile uint8_t *reg_name, uint8_t pin_num)
{
	
	*reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register
	*reg_name++;                    // Change pointer to Data Register  CHANGE WHERE LOCATION IS POINTED
	*reg_name = *reg_name & ~(1<<pin_num);   // I HAVE TO CLEAN THE VALUE Data Register
	
}

/*--------------------------------------------------------------------*/
void GPIO_config_input_pullup(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register
	*reg_name++;                    // Change pointer to Data Register  CHANGE WHERE LOCATION IS POINTED
	*reg_name = *reg_name | (1<<pin_num);   // Data Register
}

/*--------------------------------------------------------------------*/
void GPIO_write_low(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name & ~(1<<pin_num);
}

/*--------------------------------------------------------------------*/
void GPIO_write_high(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name | (1<<pin_num);
}

/*--------------------------------------------------------------------*/
void GPIO_toggle(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name ^ (1<<pin_num);
}

/*--------------------------------------------------------------------*/
/* GPIO_read HOMEWORK */
uint8_t GPIO_read(volatile uint8_t *reg_name, uint8_t pin_num)
{
	  uint8_t input;
	  
	  if(bit_is_set(*reg_name , pin_num)) //This will return a 0 if the bit is clear, and non-zero if the bit is set.
	  {
		  input=1;
	  }
	 
	else 
	  {
		  input=0;
	  }
	  
	  return(input);
}