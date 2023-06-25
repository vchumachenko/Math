#include "../s21_math.h"

long double s21_sqrt(double x) {
  if (s21_isnan(x)) return S21_NAN;
  if (x < 0) return S21_NAN;
  if (x == S21_INF_POS) return S21_INF_POS;
  if (x == 0) return 0;

  long double left = 1 > x ? x : 1;
  long double right = 1 > x ? 1 : x;

  while (100 * left * left < x) left *= 10;
  while (0.01 * right * right > x) right *= 0.1;

  long double mid = (left + right) / 2;

  for (int i = 0; i < 100 && x * x != mid; i++) {
    mid = (left + right) / 2;
    if (mid * mid > x) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return mid;
}
