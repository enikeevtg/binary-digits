/**
 * @author T. Enikeev
 * enikeev.tg@gmail.com
 * @brief three versions of two integer variables summation
 * by using differents approaches
 *
 * @param 'value_1' and 'value_2' is the numbers have to be summarized.
 * @param 'result' is the pointer to result variable.
 *
 * @return error codes:
 * 0 - OK
 * 1 - the number is too large or equal to infinity
 * 2 - the number is too small or equal to negative infinity
 */

#include "../binary.h"

int e_sub(int value_1, int value_2, int* result) {
  value_2 = ~value_2 + 1U;
  e_add(value_1, value_2, result);
  return 0;
}
