#include <stdio.h>
#include "binary.h"

int main() {
  // Checking int representation
  // printf("              0b00000000000000000000000000001011: %d\n", 0b00001011);
  // printf("         (int)0b11111111111111111111111111110101: %d\n", (int)0b11111111111111111111111111110101);
  // printf("(unsigned int)0b11111111111111111111111111110101: %u", (unsigned int)0b11111111111111111111111111110101);

  // Checking int representation by inverse and +1U
  // int num = 11;
  // int inv_num = ~num + 1U;
  // printf("num = %d\ninv_num = %d\n", num, inv_num);
  // printf("So int type has \"Two's complement\" representation\n");
  // printf("-11 -> uint: %u\n", -11);
  // printf("%X", 0b10000000000000000000000000000000);

  // convert int to binary representation
  // int value = 0;
  // scanf("%d", &value);
  // char str[33] = {0};
  // int char_id = 0;
  // for (int i = 31; i >= 0; i--, char_id++)
  //   str[char_id] = e_get_bit(value, i) + 48;
  // printf("0b%s", str);

  return 0;
}
