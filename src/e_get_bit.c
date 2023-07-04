/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief get the value of the number bit in position bit_pos
 * (in count from right side)
 *
 * @param value is the number that function should get 'bit_value'.
 * @param bit_pos is the bit position of the number bit function should get.
 *
 * @return value of the number bit in position bit_pos
 */

#include "../binary.h"

int e_get_bit(int value, int bit_pos) {
  int bit_mask = 1U << bit_pos;
  int bit_value = bit_mask & value;
  return bit_value ? 1 : 0;
}

/// @brief get sign bit of the signed int 'value'
/// @version v.2
/// @param value is the number that function should define sign
/// @return value of 31st bit of 'value':
///         '0' is positive int value
///         '1' is negative int value
int e_get_sign(int value) {
  return (value & INT_BIN_LEN) ? 1 : 0;
}

/// @brief get sign bit of the signed int 'value'
/// @version v.1
/// @param value is the number that function should define sign
/// @return value of 31st bit of 'value':
///         '0' is positive int value
///         '1' is negative int value
int e_get_sign_v1(int value) {
  return e_get_bit(value, 31);
}
