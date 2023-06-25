#include "s21_math_test.h"

START_TEST(s21pow_positive_1) {
  double x = 0.5;
  double y = 0.7;

  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(s21pow_positive_2) {
  double x = 25.5;
  double y = 3.4;

  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(s21pow_positive_3) {
  double x = 101.15;
  double y = 4.3;

  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(s21pow_negative_1) {
  double x = -0.5;
  double y = -0.7;

  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(s21pow_negative_2) {
  double x = -2;
  double y = -3;

  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(s21pow_negative_3) {
  double x = -10.2815;
  double y = 5;

  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(s21pow_negative_4) {
  double x = 100;
  double y = -5;

  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(s21pow_inf_1) {
  double x = S21_INF_POS;
  double y = S21_INF_NEG;

  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(s21pow_inf_2) {
  double x = S21_INF_POS;
  double y = S21_INF_POS;

  ck_assert_ldouble_infinite(s21_pow(x, y));
  ck_assert_ldouble_infinite(pow(x, y));
}
END_TEST

START_TEST(s21pow_inf_3) {
  double x = S21_INF_NEG;
  double y = S21_INF_POS;

  ck_assert_ldouble_infinite(s21_pow(x, y));
  ck_assert_ldouble_infinite(pow(x, y));
}
END_TEST

START_TEST(s21pow_inf_4) {
  double x = S21_INF_NEG;
  double y = S21_INF_NEG;

  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

Suite *s21_pow_suite(void) {
  Suite *s;

  TCase *s21_pow_test;

  s = suite_create("s21_pow_test");

  s21_pow_test = tcase_create("s21_pow_testcase");

  tcase_add_test(s21_pow_test, s21pow_positive_1);
  tcase_add_test(s21_pow_test, s21pow_positive_2);
  tcase_add_test(s21_pow_test, s21pow_positive_3);

  tcase_add_test(s21_pow_test, s21pow_negative_1);
  tcase_add_test(s21_pow_test, s21pow_negative_2);
  tcase_add_test(s21_pow_test, s21pow_negative_3);
  tcase_add_test(s21_pow_test, s21pow_negative_4);

  tcase_add_test(s21_pow_test, s21pow_inf_1);
  tcase_add_test(s21_pow_test, s21pow_inf_2);
  tcase_add_test(s21_pow_test, s21pow_inf_3);
  tcase_add_test(s21_pow_test, s21pow_inf_4);

  suite_add_tcase(s, s21_pow_test);

  return s;
}