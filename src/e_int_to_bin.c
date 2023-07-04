/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief converting from integer to binary form
 * @return array of values of the number bits
 */

#include "../binary.h"

int* e_int_to_bin(int number) {
  static int bin_number[INT_BIN_LEN];
  int index = INT_BIN_LEN - 1;
  int bit_pos = 0;
  while (index) {
    bin_number[index] = e_get_bit(number, bit_pos);
    index--;
    bit_pos++;
  }
  return bin_number;
}
