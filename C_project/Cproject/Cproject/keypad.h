/*
 * keypad.h
 *
 * Created: 23/11/2020 18:25:15
 *  Author: Marina
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

void wait_clear(volatile uint8_t *reg_name);
uint8_t read_digits(volatile uint8_t *reg_name);
void detect_digits(volatile uint8_t *reg_name);



#endif /* KEYPAD_H_ */