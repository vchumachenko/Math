#include "s21_math_test.h"

START_TEST(s21exp_positive_1) {
  double x = 0.5;

  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(s21exp_positive_2) {
  double x = 10;

  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(s21exp_positive_3) {
  double x = 25048.369;
  ck_assert_double_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(s21exp_negative_1) {
  double x = -2.5813;
  ck_assert_double_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(s21exp_negative_2) {
  double x = -5.1813111;
  ck_assert_double_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(s21exp_inf_1) {
  double x = S21_INF_POS;
  ck_assert_double_infinite(s21_exp(x));
  ck_assert_double_infinite(exp(x));
}
END_TEST

START_TEST(s21exp_inf_2) {
  double x = S21_INF_NEG;
  ck_assert_double_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(s21exp_nan) {
  double x = S21_NAN;
  ck_assert_double_nan(s21_exp(x));
  ck_assert_double_nan(exp(x));
}
END_TEST

Suite *s21_exp_suite(void) {
  Suite *s;

  TCase *s21_exp_test;

  s = suite_create("s21_exp_test");

  s21_exp_test = tcase_create("s21_exp_testcase");

  tcase_add_test(s21_exp_test, s21exp_positive_1);
  tcase_add_test(s21_exp_test, s21exp_positive_2);
  tcase_add_test(s21_exp_test, s21exp_positive_3);

  tcase_add_test(s21_exp_test, s21exp_negative_1);
  tcase_add_test(s21_exp_test, s21exp_negative_2);

  tcase_add_test(s21_exp_test, s21exp_inf_1);
  tcase_add_test(s21_exp_test, s21exp_inf_2);

  tcase_add_test(s21_exp_test, s21exp_nan);

  suite_add_tcase(s, s21_exp_test);

  return s;
}