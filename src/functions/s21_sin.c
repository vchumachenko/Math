#include "../s21_math.h"

long double s21_sin(double x) {
  if (x == S21_INF_POS || x == S21_INF_NEG) return S21_NAN;
  if (s21_isnan(x)) return S21_NAN;
  while (s21_fabs(x) > S21_M_PI)
    if (x > S21_M_PI) {
      x += 2 * -S21_M_PI;
    } else {
      x += 2 * S21_M_PI;
    }

  long double res = x, tmp = x;
  for (int i = 1.0; s21_fabs(tmp) > S21_EPS; i++) {
    res += tmp = (-tmp) * x * x / ((2 * i + 1) * (2 * i));
  }
  return res;
}