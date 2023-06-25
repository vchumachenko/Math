#include "../s21_math.h"

long double s21_ceil(double x) {
  if (x == S21_INF_NEG || x == S21_INF_POS) return x;
  if (x >= S21_MAX_DOUBLE) return S21_MAX_DOUBLE;
  if (x <= (-S21_MAX_DOUBLE + 1)) return -S21_MAX_DOUBLE + 1;
  if (s21_isnan(x)) return S21_NAN;
  long double result = (int)x;
  if (result < x) {
    result++;
  }
  return result;
}