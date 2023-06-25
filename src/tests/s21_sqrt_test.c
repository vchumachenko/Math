#include "s21_math_test.h"

START_TEST(s21sqrt_negative) {
  double x = -0.5;

  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(s21sqrt_positive_1) {
  double x = 0.5;

  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(s21sqrt_positive_2) {
  double x = 10;

  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(s21sqrt_positive_3) {
  double x = 25;

  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(s21sqrt_positive_4) {
  double x = 100;

  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(s21sqrt_positive_5) {
  double x = 151.23156;

  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(s21sqrt_inf_1) {
  double x = S21_INF_POS;

  ck_assert_ldouble_infinite(s21_sqrt(x));
  ck_assert_ldouble_infinite(sqrt(x));
}
END_TEST

START_TEST(s21sqrt_inf_2) {
  double x = S21_INF_NEG;

  ck_assert_ldouble_nan(s21_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(s21sqrt_nan) {
  double x = S21_NAN;

  ck_assert_ldouble_nan(s21_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

Suite *s21_sqrt_suite(void) {
  Suite *s;

  TCase *s21_sqrt_test;

  s = suite_create("s21_sqrt_test");

  s21_sqrt_test = tcase_create("s21_sqrt_testcase");

  tcase_add_test(s21_sqrt_test, s21sqrt_negative);
  tcase_add_test(s21_sqrt_test, s21sqrt_positive_1);
  tcase_add_test(s21_sqrt_test, s21sqrt_positive_2);
  tcase_add_test(s21_sqrt_test, s21sqrt_positive_3);
  tcase_add_test(s21_sqrt_test, s21sqrt_positive_4);
  tcase_add_test(s21_sqrt_test, s21sqrt_positive_5);
  tcase_add_test(s21_sqrt_test, s21sqrt_inf_1);
  tcase_add_test(s21_sqrt_test, s21sqrt_inf_2);
  tcase_add_test(s21_sqrt_test, s21sqrt_nan);

  suite_add_tcase(s, s21_sqrt_test);

  return s;
}