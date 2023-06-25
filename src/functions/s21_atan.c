#include "../s21_math.h"

long double s21_atan(double x) {
  if (x == S21_INF_POS) return S21_M_PI / 2;
  if (x == S21_INF_NEG) return S21_M_PI / -2;
  if (s21_isnan(x)) return S21_NAN;
  long double result = 0;
  if (s21_fabs(x) < 1) {
    for (register int i = 0; i < 5000; i++) {
      result += (s21_ipow(-1, i) * s21_ipow(x, 1 + (2 * i))) / (1 + (2 * i));
    }
  } else if (x == 1) {
    result = S21_M_PI_4;
  } else if (x == -1) {
    result = S21_M_PI_4 * -1;
  } else {
    for (register int i = 0; i < 7000; i++) {
      result += s21_ipow(-1, i) * s21_ipow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    result = S21_M_PI * s21_fabs(x) / (2 * x) - result;
  }
  return result;
}
