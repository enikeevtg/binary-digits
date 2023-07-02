/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief value mutiplication bu ten function 
 *
 * @param 'value' is the number have to be multiplicated.
 * @param 'result' is the pointer to result variable.
 *
 * @return error codes:
 * 0 - OK
 * 1 - the number is too large or equal to infinity
 * 2 - the number is too small or equal to negative infinity
 */

#include "internal.h"

int e_mul_10(int value, int* result) {
  int value_1 = e_shift_to_left(value, 1);
  int value_2 = e_shift_to_left(value, 3);
  e_add(value_1, value_2, result);
  return 0;
}
