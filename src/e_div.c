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

#include <stdio.h>
#include "../binary.h"

void e_div_alg(int value_1, int value_2, int* result);

int e_div(int value_1, int value_2, int* result) {
  *result = 0;
  if (value_2 != 0) {
    // preset result:
    int sign_1 = e_get_sign(value_1);
    int sign_2 = e_get_sign(value_2);
    int sign_res = (sign_1 + sign_2) % 2;

    // preset values
    value_1 = sign_1 ? -value_1 : value_1;
    value_2 = sign_2 ? -value_2 : value_2;

    // main algorithm
    if (value_1 >= value_2) {
      e_div_alg(value_1, value_2, result);
      if (sign_res) *result = -(*result);
    }
  }
  return 0;
}

/// @brief main diviseion algorithm
/// @param value_1 
/// @param value_2 
/// @param result 
void e_div_alg(int value_1, int value_2, int* result) {
  // preset current devider:
  int left_nills_1 = 30;
  int left_nills_2 = 30;
  while (!e_get_bit(value_1, left_nills_1)) left_nills_1--;
  while (!e_get_bit(value_2, left_nills_2)) left_nills_2--;
  int current_devider = e_shift_to_left(value_2, left_nills_1 - left_nills_2);

  int current_result_bit_pos = left_nills_1 - left_nills_2;
  while (current_devider >= value_2) {
    if (value_1 >= current_devider) {
      e_set_bit(result, current_result_bit_pos, 1);
      value_1 -= current_devider;
    } else {
      e_set_bit(result, current_result_bit_pos, 0);
    }
    current_result_bit_pos--;
    current_devider = current_devider >> 1;
  }
}
