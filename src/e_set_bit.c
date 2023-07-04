/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief Set the bit_value (0 or 1) to the bit_pos bit of the value.
 *
 * @param 'value' is pointer to number that should be changed.
 * @param 'bit_pos' is the bit position of the 'value' that should be set.
 * @param 'bit_value' is value of the 'value' bit in position 'bit_pos'
 * that should be in the result.
 *
 * @warning If the bit_pos > 95 (31 for int), function doesn't make changes.
 */

#include "../binary.h"

void e_set_bit(int* value, int bit_pos, int bit_value) {
  if (bit_pos < 32) {
    int bit_mask = 1U << bit_pos;
    if (bit_value)
      *value |= bit_mask;
    else
      *value &= ~bit_mask;
  }
}

/// @brief set sign bit of the signed int 'value'
/// @version v.2
/// @param value is the number that function should define sign
/// @param sign is value of sign bit of integer value:
///        '0' is positive int value
///        '1' is negative int value
void e_set_sign(int* value, int sign) {
  *value = sign ? (*value | INT_BIN_LEN) : (*value & ~(INT_BIN_LEN));
}

/// @brief set sign bit of the signed int 'value'
/// @version v.1
/// @param value is the number that function should define sign
/// @param sign is value of sign bit of integer value:
///        '0' is positive int value
///        '1' is negative int value
void e_set_sign_v1(int* value, int sign) {
  return e_set_bit(value, sign, 31);
}

