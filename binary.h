#ifndef _SRC_TAGIR_E_INTEGER_H_
#define _SRC_TAGIR_E_INTEGER_H_

#define INT_BIN_LEN 32
#define SIGN_MASK 0x80000000  // 0b10000000000000000000000000000000
#define MINUS 1
#define PLUS 0


#define TRUE 1
#define FALSE 0

// MAIN FUNCTIONS
int e_add(int value_1, int value_2, int* result);
int e_sub(int value_1, int value_2, int* result);
int e_mul(int value_1, int value_2, int* result);

// INTERNAL FUNCTIONS
int e_get_bit(int value, int bit_pos);
int e_get_sign(int value);

void e_set_bit(int* value, int bit_pos, int bit_value);
void e_set_sign(int* value, int sign);


int e_div_10(int value, int* result);
int e_shift_to_right(int value, unsigned int offset);
int e_shift_to_left(int value, unsigned int offset);

int* e_int_to_bin(int number);

#endif  // _SRC_TAGIR_E_INTEGER_H_
