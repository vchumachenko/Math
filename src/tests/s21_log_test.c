#include "s21_math_test.h"

START_TEST(s21log_negative) {
  double x = -0.5;

  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(s21log_positive_1) {
  double x = 0.5;

  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
}
END_TEST

START_TEST(s21log_positive_2) {
  double x = 10;

  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
}
END_TEST

START_TEST(s21log_positive_3) {
  double x = 25;

  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
}
END_TEST

START_TEST(s21log_positive_4) {
  double x = 100;

  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
}
END_TEST

START_TEST(s21log_nan_1) {
  double x = 0;

  ck_assert_ldouble_infinite(s21_log(x));
  ck_assert_ldouble_infinite(log(x));
}
END_TEST

START_TEST(s21log_nan_2) {
  double x = S21_NAN;

  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_ldouble_nan(log(x));
}
END_TEST

START_TEST(s21log_inf) {
  double x = S21_INF_POS;

  ck_assert_ldouble_infinite(s21_log(x));
  ck_assert_ldouble_infinite(log(x));
}
END_TEST

Suite *s21_log_suite(void) {
  Suite *s;

  TCase *s21_log_test;

  s = suite_create("s21_log_test");

  s21_log_test = tcase_create("s21_log_testcase");

  tcase_add_test(s21_log_test, s21log_negative);
  tcase_add_test(s21_log_test, s21log_positive_1);
  tcase_add_test(s21_log_test, s21log_positive_2);
  tcase_add_test(s21_log_test, s21log_positive_3);
  tcase_add_test(s21_log_test, s21log_positive_4);
  tcase_add_test(s21_log_test, s21log_nan_1);
  tcase_add_test(s21_log_test, s21log_nan_2);
  tcase_add_test(s21_log_test, s21log_inf);

  suite_add_tcase(s, s21_log_test);

  return s;
}