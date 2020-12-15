
#ifndef KEYPAD_H_
#define KEYPAD_H_

/* Function definitions ----------------------------------------------*/

uint8_t read_digits(volatile uint8_t *reg_name);
//void detect_digit(volatile uint8_t *reg_name);	
uint8_t code_analyzer(uint8_t code[4],uint8_t correct_code1[4],uint8_t correct_code2[4],uint8_t correct_code3[4])




#endif /* KEYPAD_H_ */