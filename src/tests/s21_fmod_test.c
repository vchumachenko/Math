#include "s21_math_test.h"

START_TEST(s21fmod_negative_1) {
  double x = -0.5;
  double y = 0.1;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(s21fmod_negative_2) {
  double x = -1923.5;
  double y = -11.3;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(s21fmod_positive_1) {
  double x = 1.6;
  double y = 0.3;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(s21fmod_positive_2) {
  double x = 10593.3;
  double y = 11.2;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(s21fmod_inf_1) {
  double x = S21_INF_POS;
  double y = S21_INF_NEG;

  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21fmod_inf_2) {
  double x = S21_INF_POS;
  double y = S21_INF_POS;

  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21fmod_nan_1) {
  double x = 1.6;
  double y = 0.0;

  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21fmod_nan_2) {
  double x = 0.0;
  double y = 0.0;

  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

Suite *s21_fmod_suite(void) {
  Suite *s;

  TCase *s21fmod_tcase;

  s = suite_create("s21_fmod_test");

  s21fmod_tcase = tcase_create("s21_fmod_negative");

  tcase_add_test(s21fmod_tcase, s21fmod_negative_1);
  tcase_add_test(s21fmod_tcase, s21fmod_negative_2);

  tcase_add_test(s21fmod_tcase, s21fmod_positive_1);
  tcase_add_test(s21fmod_tcase, s21fmod_positive_2);

  tcase_add_test(s21fmod_tcase, s21fmod_inf_1);
  tcase_add_test(s21fmod_tcase, s21fmod_inf_2);

  tcase_add_test(s21fmod_tcase, s21fmod_nan_1);
  tcase_add_test(s21fmod_tcase, s21fmod_nan_2);

  suite_add_tcase(s, s21fmod_tcase);

  return s;
}