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

#include "../binary.h"

int e_mul(int value_1, int value_2, int* result) {
  int offset_buf = 0;
  for (int i = 0; i < INT_BIN_LEN; i++) {
    if (e_get_bit(value_2, i)) {
      value_1 = e_shift_to_left(value_1, i - offset_buf);
      e_add(value_1, *result, result);
      offset_buf = i;
    }
  }
  return 0;
}
