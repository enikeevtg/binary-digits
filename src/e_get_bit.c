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

#include "internal.h"

int e_get_bit(int value, int bit_pos) {
  int bit_mask = 1U << bit_pos;
  int bit_value = bit_mask & value;
  return bit_value ? 1 : 0;
}
