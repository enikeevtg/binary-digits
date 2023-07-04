#include <check.h>
#include <stdio.h>

#include "../binary.h"

START_TEST(get_bit_11) {
  // Arrange
  int number = 11;
  char ref_str[33] = "00000000000000000000000000001011";

  // Act
  char res_str[33];
  res_str[32] = '\0';
  int i = 32;
  while (i--) res_str[31 - i] = e_get_bit(number, i) + 48;

  // Assert
  ck_assert_str_eq(res_str, ref_str);
}
END_TEST

START_TEST(get_sign_minus) {
  // Arrange
  int number = -11;

  // Assert
  ck_assert_int_eq(e_get_sign(number), MINUS);
}
END_TEST

START_TEST(get_sign_plus) {
  // Arrange
  int number = 11;

  // Assert
  ck_assert_int_eq(e_get_sign(number), PLUS);
}
END_TEST

Suite* get_bit_func(void) {
  Suite* s = suite_create("get functions");

  TCase* tc_1 = tcase_create("get functions");;
  tcase_add_test(tc_1, get_bit_11);
  tcase_add_test(tc_1, get_sign_minus);
  tcase_add_test(tc_1, get_sign_plus);
  suite_add_tcase(s, tc_1);

  return s;
}

int main(void) {
  Suite* get_bit_suite = get_bit_func();
  SRunner* runner = srunner_create(get_bit_suite);  

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
