#include "s21_math_test.h"

START_TEST(s21abs_negative_1) {
  int x = -10;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21abs_negative_2) {
  int x = -231;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21abs_positive_1) {
  int x = 10;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21abs_positive_2) {
  int x = 235;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21abs_max_int) {
  int x = INT_MAX;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21abs_min_int) {
  int x = INT_MIN;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21abs_zero) {
  int x = 0;

  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

Suite *s21_abs_suite(void) {
  Suite *s;

  TCase *s21_abs_tcase;

  s = suite_create("s21_abs_test");

  s21_abs_tcase = tcase_create("s21_abs_tcase");

  tcase_add_test(s21_abs_tcase, s21abs_negative_1);
  tcase_add_test(s21_abs_tcase, s21abs_negative_2);

  tcase_add_test(s21_abs_tcase, s21abs_positive_1);
  tcase_add_test(s21_abs_tcase, s21abs_positive_2);

  tcase_add_test(s21_abs_tcase, s21abs_max_int);
  tcase_add_test(s21_abs_tcase, s21abs_min_int);

  tcase_add_test(s21_abs_tcase, s21abs_zero);

  suite_add_tcase(s, s21_abs_tcase);

  return s;
}