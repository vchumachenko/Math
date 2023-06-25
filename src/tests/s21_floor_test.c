#include "s21_math_test.h"

START_TEST(s21floor_positive_1) {
  double x = 0.5;

  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST

START_TEST(s21floor_positive_2) {
  double x = 103.0003E-2;

  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST

START_TEST(s21floor_positive_3) {
  double x = 1.042E-10;

  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST

START_TEST(s21floor_negative_1) {
  double x = -1.0;

  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST

START_TEST(s21floor_inf_1) {
  double x = S21_INF_POS;

  ck_assert_ldouble_infinite(floor(x));
  ck_assert_ldouble_infinite(s21_floor(x));
}
END_TEST

START_TEST(s21floor_inf_2) {
  double x = S21_INF_NEG;

  ck_assert_ldouble_infinite(floor(x));
  ck_assert_ldouble_infinite(s21_floor(x));
}
END_TEST

START_TEST(s21floor_nan) {
  double x = S21_NAN;

  ck_assert_ldouble_nan(floor(x));
  ck_assert_ldouble_nan(s21_floor(x));
}
END_TEST

Suite *s21_floor_suite(void) {
  Suite *s;

  TCase *s21_floor_tcase;

  s = suite_create("s21_floor_test");

  s21_floor_tcase = tcase_create("s21_floor_tcase");

  tcase_add_test(s21_floor_tcase, s21floor_negative_1);

  tcase_add_test(s21_floor_tcase, s21floor_positive_1);
  tcase_add_test(s21_floor_tcase, s21floor_positive_2);
  tcase_add_test(s21_floor_tcase, s21floor_positive_3);

  tcase_add_test(s21_floor_tcase, s21floor_inf_1);
  tcase_add_test(s21_floor_tcase, s21floor_inf_2);

  tcase_add_test(s21_floor_tcase, s21floor_nan);

  suite_add_tcase(s, s21_floor_tcase);

  return s;
}
