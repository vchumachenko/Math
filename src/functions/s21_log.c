#include "../s21_math.h"

long double s21_log(double x) {
  if (s21_isnan(x)) return S21_NAN;
  if (x < 0) return S21_NAN;
  if (x == 0) return S21_INF_NEG;
  if (x == S21_INF_POS) return x;

  int ex_pow = 0;
  long double result = 0.0;
  long double compare = 0.0;

  for (; x >= S21_M_E; ex_pow++) x /= S21_M_E;

  for (int i = 0; i < 100; i++) {
    compare = result;
    result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
  }
  return (result + ex_pow);
}
