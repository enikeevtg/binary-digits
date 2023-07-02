#ifndef _INTERNAL_INTERNAL_H_
#define _INTERNAL_INTERNAL_H_

#include "../binary.h"

int e_get_bit(int value, int bit_pos);
void e_set_bit(int* value, int bit_pos, int bit_value);

int e_get_sign(int value);
void e_set_sign(int* value, int sign);

int e_mul_10(int value, int* result);
int e_div_10(int value, int* result);
int e_shift_to_right(int value, int offset);
int e_shift_to_left(int value, int offset);

int* e_int_to_bin(int number);

#endif  // _INTERNAL_INTERNAL_H_
