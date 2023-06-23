/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief get/set sign bit of the signed int 'value'
 *
 * @param 'value' is the number that function should define sign.
 *
 * @return value of 31st bit of 'value'
 * '0' is positive int value
 * '1' is negative int value
 */

#include "internal.h"

int e_get_sign(int value) {
  return e_get_bit(value, 31);
}

void e_set_sign(int* value, int sign) {
  return e_set_bit(value, sign, 31);
}
