#include "s21_math_test.h"

START_TEST(s21tan_positive_1) {
  double x = 0.5;

  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(s21tan_positive_2) {
  double x = 100.0;

  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(s21tan_positive_3) {
  double x = 12345.12345;

  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(s21tan_negative_1) {
  double x = -1.0;

  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(s21tan_negative_2) {
  double x = -0.736;

  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(s21tan_negative_3) {
  double x = -12345.12345;

  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(s21tan_zero) {
  double x = 0;

  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(s21tan_nan) {
  double x = S21_NAN;

  ck_assert_ldouble_nan(s21_tan(x));
  ck_assert_ldouble_nan(tan(x));
}
END_TEST

START_TEST(s21tan_inf_1) {
  double x = S21_INF_POS;

  ck_assert_ldouble_nan(s21_tan(x));
  ck_assert_ldouble_nan(tan(x));
}
END_TEST

START_TEST(s21tan_inf_2) {
  double x = S21_INF_NEG;

  ck_assert_ldouble_nan(s21_tan(x));
  ck_assert_ldouble_nan(tan(x));
}
END_TEST

Suite *s21_tan_suite() {
  Suite *s = suite_create("s21_tan_test");

  TCase *s21_tan_test = tcase_create("s21_tan_testcase");

  tcase_add_test(s21_tan_test, s21tan_positive_1);
  tcase_add_test(s21_tan_test, s21tan_positive_2);
  tcase_add_test(s21_tan_test, s21tan_positive_3);

  tcase_add_test(s21_tan_test, s21tan_negative_1);
  tcase_add_test(s21_tan_test, s21tan_negative_2);
  tcase_add_test(s21_tan_test, s21tan_negative_3);

  tcase_add_test(s21_tan_test, s21tan_inf_1);
  tcase_add_test(s21_tan_test, s21tan_inf_2);

  tcase_add_test(s21_tan_test, s21tan_zero);
  tcase_add_test(s21_tan_test, s21tan_nan);

  suite_add_tcase(s, s21_tan_test);
  return s;
}
