#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

#ifndef S21_MATH_TEST_H
#define S21_MATH_TEST_H

Suite* s21_abs_suite(void);
Suite* s21_fabs_suite(void);
Suite* s21_fmod_suite(void);
Suite* s21_floor_suite(void);
Suite* s21_sin_suite(void);
Suite* s21_log_suite(void);
Suite* s21_pow_suite(void);
Suite* s21_exp_suite(void);
Suite* s21_sqrt_suite(void);
Suite* s21_cos_suite(void);
Suite* s21_sin_suite(void);
Suite* s21_tan_suite(void);
Suite* s21_ceil_suite(void);
Suite* s21_acos_suite(void);
Suite* s21_asin_suite(void);
Suite* s21_atan_suite(void);

void s21_test_one_suite(Suite* current_suit, int* sum_of_errors);

#endif