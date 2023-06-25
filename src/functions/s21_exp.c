#include "../s21_math.h"

long double s21_exp(double x) {
  if (x == S21_INF_NEG) return 0;
  if (x == S21_INF_POS) return S21_INF_POS;
  if (s21_isnan(x)) return S21_NAN;
  if (x == 0) return 1;
  if (x < -'A') return 0;

  long double tmp = 1;
  long double series = 1;
  long double i = 1;

  while (s21_fabs(tmp) > S21_EPS) {
    tmp *= x / i;
    i++;
    series += tmp;
    if (series > S21_MAX_DOUBLE) {
      series = S21_INF_POS;
      break;
    }
  }
  return series;
}
