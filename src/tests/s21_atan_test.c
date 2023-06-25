#include "s21_math_test.h"

START_TEST(s21atan_positive_1) {
  double x = 0.5;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(s21atan_positive_2) {
  double x = 10.0;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(s21atan_positive_3) {
  double x = 12.12345;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(s21atan_negative_1) {
  double x = -1.0;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(s21atan_negative_2) {
  double x = -0.736;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(s21atan_negative_3) {
  double x = -12.12345;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(s21atan_zero) {
  double x = 0;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(s21atan_nan) {
  double x = S21_NAN;

  ck_assert_ldouble_nan(s21_atan(x));
  ck_assert_ldouble_nan(atan(x));
}
END_TEST

START_TEST(s21atan_inf_1) {
  double x = S21_INF_POS;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(s21atan_inf_2) {
  double x = S21_INF_NEG;

  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

Suite *s21_atan_suite() {
  Suite *s = suite_create("s21_atan_test");

  TCase *s21_atan_test = tcase_create("s21_atan_testcase");

  tcase_add_test(s21_atan_test, s21atan_positive_1);
  tcase_add_test(s21_atan_test, s21atan_positive_2);
  tcase_add_test(s21_atan_test, s21atan_positive_3);

  tcase_add_test(s21_atan_test, s21atan_negative_1);
  tcase_add_test(s21_atan_test, s21atan_negative_2);
  tcase_add_test(s21_atan_test, s21atan_negative_3);

  tcase_add_test(s21_atan_test, s21atan_inf_1);
  tcase_add_test(s21_atan_test, s21atan_inf_2);

  tcase_add_test(s21_atan_test, s21atan_zero);
  tcase_add_test(s21_atan_test, s21atan_nan);

  suite_add_tcase(s, s21_atan_test);
  return s;
}
