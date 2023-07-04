#include <check.h>
#include <stdio.h>
#include <stdint.h>

#include "../binary.h"

START_TEST(mul_pos_pos) {
  // Arrange
  int val_1 = 11;
  int val_2 = 254;
  int res = 0;

  // Act
  e_mul(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 * val_2);
}
END_TEST

START_TEST(mul_neg_pos) {
  // Arrange
  int val_1 = -11;
  int val_2 = 254;
  int res = 0;

  // Act
  e_mul(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 * val_2);
}
END_TEST

START_TEST(mul_pos_neg) {
  // Arrange
  int val_1 = 11;
  int val_2 = -254;
  int res = 0;

  // Act
  e_mul(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 * val_2);
}
END_TEST

START_TEST(mul_neg_neg) {
  // Arrange
  int val_1 = -11;
  int val_2 = -254;
  int res = 0;

  // Act
  e_mul(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 * val_2);
}
END_TEST

START_TEST(mul_max_int_pos) {
  // Arrange
  int val_1 = INT32_MAX;
  int val_2 = 254;
  int res = 0;

  // Act
  e_mul(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 * val_2);
}
END_TEST

START_TEST(mul_min_int_pos) {
  // Arrange
  int val_1 = INT32_MIN;
  int val_2 = 254;
  int res = 0;

  // Act
  e_mul(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 * val_2);
}
END_TEST

// START_TEST(div_pos) {
//   // Arrange
//   int n = 11;
//   int div = 0;

//   // Act
//   e_div_10(n, &div);

//   // Assert
//   ck_assert_int_eq(div, n / 10);
// }
// END_TEST

// START_TEST(div_neg) {
//   // Arrange
//   int n = -11;
//   int div = 0;

//   // Act
//   e_div_10(n, &div);

//   // Assert
//   ck_assert_int_eq(div, n / 10);
// }
// END_TEST

Suite* mul_func(void) {
  Suite* s = suite_create("multiplication function");

  TCase* tc_mul = tcase_create("two numbers mutiplication");
  tcase_add_test(tc_mul, mul_pos_pos);
  tcase_add_test(tc_mul, mul_neg_pos);
  tcase_add_test(tc_mul, mul_pos_neg);
  tcase_add_test(tc_mul, mul_neg_neg);
  tcase_add_test(tc_mul, mul_max_int_pos);
  tcase_add_test(tc_mul, mul_min_int_pos);
  suite_add_tcase(s, tc_mul);

  // TCase* tc_div = tcase_create("number division by 10");
  // tcase_add_test(tc_div, div_pos);
  // tcase_add_test(tc_div, div_neg);
  // suite_add_tcase(s, tc_div);

  return s;
}

int main(void) {
  Suite* mul_suite = mul_func();
  SRunner* runner = srunner_create(mul_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
