#include <math.h>
#include <stdio.h>

#include "../s21_math.h"

long double s21_tan(double x) {
  if (x == S21_INF_POS || x == S21_INF_NEG) return S21_NAN;
  if (s21_isnan(x)) return S21_NAN;

  if (x == 0) return 0;
  if (x == S21_M_PI / 2 || x == -S21_M_PI / 2) return S21_NAN;

  x = s21_fmod(x, S21_M_PI);
  long double new_cos = s21_cos(x);

  return new_cos ? s21_sin(x) / new_cos : S21_NAN;
}