#include <check.h>
#include <stdio.h>

#include "../binary.h"

START_TEST(div_pos_pos) {
  // Arrange
  int val_1 = 121;
  int val_2 = 11;
  int res = 0;

  // Act
  e_div(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 / val_2);
}
END_TEST

START_TEST(div_neg_pos) {
  // Arrange
  int val_1 = -121;
  int val_2 = 11;
  int res = 0;

  // Act
  e_div(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 / val_2);
}
END_TEST

START_TEST(div_pos_neg) {
  // Arrange
  int val_1 = 121;
  int val_2 = -11;
  int res = 0;

  // Act
  e_div(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 / val_2);
}
END_TEST

START_TEST(div_neg_neg) {
  // Arrange
  int val_1 = -121;
  int val_2 = -11;
  int res = 0;

  // Act
  e_div(val_1, val_2, &res);

  // Assert
  ck_assert_int_eq(res, val_1 / val_2);
}
END_TEST

Suite* div_func(void) {
  Suite* s = suite_create("division function");

  TCase* tc_div = tcase_create("two numbers division");
  tcase_add_test(tc_div, div_pos_pos);
  tcase_add_test(tc_div, div_neg_pos);
  tcase_add_test(tc_div, div_pos_neg);
  tcase_add_test(tc_div, div_neg_neg);
  suite_add_tcase(s, tc_div);

  return s;
}

int main(void) {
  Suite* div_suite = div_func();
  SRunner* runner = srunner_create(div_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32mSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31mFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
