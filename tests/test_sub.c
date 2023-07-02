#include <check.h>
#include <stdio.h>

#include "../binary.h"

START_TEST(sub_nill) {
  // Arrange
  int diff = 0;

  // Act

  // Assert
  for (int i = -12; i < 12; i++) {
    e_sub(i, i, &diff);
    ck_assert_int_eq(diff, i - i);
  }
}
END_TEST

START_TEST(sub_pos) {
  // Arrange
  int n1 = 11;
  int n2 = 21;
  int diff = 0;

  // Act
  e_sub(n1, n2, &diff);

  // Assert
  ck_assert_int_eq(diff, n1 - n2);
}
END_TEST

START_TEST(sub_neg) {
  // Arrange
  int n1 = -11;
  int n2 = -21;
  int diff = 0;

  // Act
  e_sub(n1, n2, &diff);

  // Assert
  ck_assert_int_eq(diff, n1 - n2);
}
END_TEST

START_TEST(sub_pos_neg) {
  // Arrange
  int n1 = 11;
  int n2 = -21;
  int diff = 0;

  // Act
  e_sub(n1, n2, &diff);

  // Assert
  ck_assert_int_eq(diff, n1 - n2);
}
END_TEST

START_TEST(sub_neg_pos) {
  // Arrange
  int n1 = 11;
  int n2 = -21;
  int diff = 0;

  // Act
  e_sub(n1, n2, &diff);

  // Assert
  ck_assert_int_eq(diff, n1 - n2);
}
END_TEST

Suite* sub_func(void) {
  Suite* s;
  TCase* tc_sub;

  s = suite_create("sub function");

  tc_sub = tcase_create("two numbers diffmation");
  tcase_add_test(tc_sub, sub_nill);
  tcase_add_test(tc_sub, sub_pos);
  tcase_add_test(tc_sub, sub_neg);
  tcase_add_test(tc_sub, sub_pos_neg);
  tcase_add_test(tc_sub, sub_neg_pos);
  suite_add_tcase(s, tc_sub);

  return s;
}

int main(void) {
  int failed = 0;
  Suite* sub_suite;
  SRunner* runner;

  sub_suite = sub_func();
  runner = srunner_create(sub_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\033[0\n", failed);

  return failed ? 1 : 0;
}
