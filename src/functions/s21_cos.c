#include "../s21_math.h"

long double s21_cos(double x) {
  if (s21_isnan(x)) return S21_NAN;
  if (x == S21_INF_POS || x == S21_INF_NEG) return S21_NAN;

  return s21_sin(S21_M_PI_2 - x);
}