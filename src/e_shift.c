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

#include "internal.h"

/* shift to right function */
int e_shift_to_right(int value, int offset) {
  offset = offset % 32;
  if (offset) {
    int i = 0;
    for (; i + offset <= 31; i++) {
      int bit = e_get_bit(value, i + offset);
      e_set_bit(&value, i, bit);
    }
    for (; i <= 31; i++) e_set_bit(&value, i, 0);
  }
  return value;
}

/* shift to left function */
int e_shift_to_left(int value, int offset) {
  offset = offset % 32;
  if (offset) {
    int i = 31;
    for (; i - offset >= 0; i--) {
      int bit = e_get_bit(value, i - offset);
      e_set_bit(&value, i, bit);
    }
    for (; i >= 0; i--) e_set_bit(&value, i, 0);
  }
  return value;
}
