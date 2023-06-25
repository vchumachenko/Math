#include "../s21_math.h"

long double s21_acos(double x) {
  long double result;
  if (x > 0 && x < 1) {
    result = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (x > -1 && x < 0) {
    result = S21_M_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (x == 1) {
    result = 0;
  } else if (x == -1) {
    result = S21_M_PI;
  } else if (x == 0) {
    result = S21_M_PI_2;
  } else {
    result = S21_NAN;
  }
  return result;
}
