#include "../s21_math.h"

long double s21_asin(double x) {
  long double result;
  if (s21_fabs(x) <= 1 && x != 0) {
    result = S21_M_PI_2 - s21_acos(x);
  } else if (x == 0) {
    result = 0;
  } else {
    result = S21_NAN;
  }
  return result;
}
