#include "../s21_math.h"

long double s21_pow(double base, double expa) {
  if (expa == 0) return 1;
  if (base == S21_INF_NEG && expa == S21_INF_NEG) return 0;
  if (base == S21_INF_POS && expa == S21_INF_NEG) return 0;
  if (base == S21_INF_POS || expa == S21_INF_POS) return S21_INF_POS;
  if (base < 0 && expa != (long long int)expa) return S21_NAN;
  long double res = 0.0;
  int sign = base > 0 ? 1 : -1;
  res = s21_exp(expa * s21_log(base * sign));
  if (s21_fmod(expa, 2)) res *= sign;
  return res;
}