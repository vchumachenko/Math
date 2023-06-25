#include "../s21_math.h"

long double s21_floor(double x) {
  if (x == S21_INF_POS || x == S21_INF_NEG) return x;
  if (x == S21_MAX_DOUBLE) return S21_MAX_DOUBLE;
  if (x == -S21_MAX_DOUBLE) return -S21_MAX_DOUBLE;
  if (s21_isnan(x)) return x;
  int i = 0;
  long double tmp = x < 0 ? -x : x;

  while (i < tmp) i++;
  return x < 0 ? -i : i - (i != x);
}
