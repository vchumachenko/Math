#include "../s21_math.h"

long double s21_ipow(double base, int exp) {
  if (exp == 0) return 1;
  long double res = base;
  int sign = exp % 2 == 0 ? 1 : 0;
  for (int i = 1; i < s21_abs(exp); i++) {
    res = res * base;
  }
  if (sign) {
    res = s21_fabs(res);
  }
  return exp > 0 ? res : 1 / res;
}
