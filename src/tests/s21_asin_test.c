#include "s21_math_test.h"

START_TEST(s21asin_positive_1) {
  double x = 0.5;

  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(s21asin_negative_1) {
  double x = -1.0;

  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(s21asin_negative_2) {
  double x = -0.736;

  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(s21asin_zero) {
  double x = 0;

  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(s21asin_nan_1) {
  double x = S21_NAN;

  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(s21asin_nan_2) {
  double x = 100.0;

  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(s21asin_nan_3) {
  double x = 12345.12345;

  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(s21asin_nan_4) {
  double x = -12345.12345;

  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(s21asin_inf_1) {
  double x = S21_INF_POS;

  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(s21asin_inf_2) {
  double x = S21_INF_NEG;

  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

Suite *s21_asin_suite() {
  Suite *s = suite_create("s21_asin_test");

  TCase *s21_asin_test = tcase_create("s21_asin_testcase");

  tcase_add_test(s21_asin_test, s21asin_positive_1);
  // tcase_add_test(s21_asin_test, s21asin_positive_2);
  // tcase_add_test(s21_asin_test, s21asin_positive_3);

  tcase_add_test(s21_asin_test, s21asin_negative_1);
  tcase_add_test(s21_asin_test, s21asin_negative_2);
  // tcase_add_test(s21_asin_test, s21asin_negative_3);

  tcase_add_test(s21_asin_test, s21asin_inf_1);
  tcase_add_test(s21_asin_test, s21asin_inf_2);

  tcase_add_test(s21_asin_test, s21asin_zero);

  tcase_add_test(s21_asin_test, s21asin_nan_1);
  tcase_add_test(s21_asin_test, s21asin_nan_2);
  tcase_add_test(s21_asin_test, s21asin_nan_3);
  tcase_add_test(s21_asin_test, s21asin_nan_4);

  suite_add_tcase(s, s21_asin_test);
  return s;
}
