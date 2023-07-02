#include <check.h>
#include <stdio.h>

#include "../binary.h"

START_TEST(mul_pos) {
  // Arrange
  int n = 11;
  int mul = 0;

  // Act
  e_mul_10(n, &mul);

  // Assert
  ck_assert_int_eq(mul, n * 10);
}
END_TEST

START_TEST(mul_neg) {
  // Arrange
  int n = -11;
  int mul = 0;

  // Act
  e_mul_10(n, &mul);

  // Assert
  ck_assert_int_eq(mul, n * 10);
}
END_TEST

START_TEST(div_pos) {
  // Arrange
  int n = 11;
  int div = 0;

  // Act
  e_div_10(n, &div);

  // Assert
  ck_assert_int_eq(div, n / 10);
}
END_TEST

START_TEST(div_neg) {
  // Arrange
  int n = -11;
  int div = 0;

  // Act
  e_div_10(n, &div);

  // Assert
  ck_assert_int_eq(div, n / 10);
}
END_TEST

Suite* mul_func(void) {
  Suite* s;
  TCase* tc_mul;
  TCase* tc_div;

  s = suite_create("mul_10 and div_10 functions");

  tc_mul = tcase_create("number mutiplication by 10");
  tcase_add_test(tc_mul, mul_pos);
  tcase_add_test(tc_mul, mul_neg);

  tc_div = tcase_create("number division by 10");
  tcase_add_test(tc_div, div_pos);
  tcase_add_test(tc_div, div_neg);
  suite_add_tcase(s, tc_div);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* mul_suite;
  SRunner* runner;

  mul_suite = mul_func();
  runner = srunner_create(mul_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
