#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  if (x == S21_INF_POS || x == S21_INF_NEG) return S21_NAN;
  if (y == S21_INF_POS || y == S21_INF_NEG) return x;
  if (s21_isnan(x) || s21_isnan(y)) return S21_NAN;
  if (y == 1) return 0;

  long double res, tmpy = 0;

  if (y == 0) {
    res = S21_NAN;
  } else if (s21_fabs(x) == s21_fabs(y)) {
    res = 0;
  } else {
    res = s21_fabs(x);
  }

  tmpy = s21_fabs(y);

  while (res >= tmpy) {
    res -= tmpy;
  }

  if (x < 0) {
    return -res;
  } else {
    return res;
  }
}