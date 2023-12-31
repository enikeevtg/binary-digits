#include <check.h>
#include <stdio.h>

#include "../binary.h"

START_TEST(add_pos) {
  // Arrange
  int n1 = 11;
  int n2 = 21;
  int sum = 0;

  // Act
  e_add(n1, n2, &sum);

  // Assert
  ck_assert_int_eq(sum, n1 + n2);
}
END_TEST

START_TEST(add_neg) {
  // Arrange
  int n1 = -11;
  int n2 = -21;
  int sum = 0;

  // Act
  e_add(n1, n2, &sum);

  // Assert
  ck_assert_int_eq(sum, n1 + n2);
}
END_TEST

START_TEST(add_pos_neg) {
  // Arrange
  int n1 = 11;
  int n2 = -21;
  int sum = 0;

  // Act
  e_add(n1, n2, &sum);

  // Assert
  ck_assert_int_eq(sum, n1 + n2);
}
END_TEST

START_TEST(add_neg_pos) {
  // Arrange
  int n1 = -11;
  int n2 = -21;
  int sum = 0;

  // Act
  e_add(n1, n2, &sum);

  // Assert
  ck_assert_int_eq(sum, n1 + n2);
}
END_TEST

Suite* add_func(void) {
  Suite* s = suite_create("add function");

  TCase* tc_add = tcase_create("two numbers summation");
  tcase_add_test(tc_add, add_pos);
  tcase_add_test(tc_add, add_neg);
  tcase_add_test(tc_add, add_pos_neg);
  tcase_add_test(tc_add, add_neg_pos);
  suite_add_tcase(s, tc_add);

  return s;
}

int main(void) {
  Suite* add_suite = add_func();
  SRunner* runner = srunner_create(add_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
