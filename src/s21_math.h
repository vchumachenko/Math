#include <limits.h>
#include <stdio.h>

#define S21_M_E 2.7182818284590452354
#define S21_M_LOG2E 1.4426950408889634074
#define S21_M_LOG10E 0.43429448190325182765
#define S21_M_LN2 0.69314718055994530942
#define S21_M_LN10 2.30258509299404568402
#define S21_M_PI 3.14159265358979323846
#define S21_M_PI_2 1.57079632679489661923
#define S21_M_PI_4 0.78539816339744830962
#define S21_M_1_PI 0.31830988618379067154
#define S21_M_2_PI 0.63661977236758134308
#define S21_M_2_SQRTPI 1.12837916709551257390
#define S21_M_SQRT2 1.41421356237309504880
#define S21_M_SQRT1_2 0.70710678118654752440
#define S21_MAX_DOUBLE 1.7976931348623157E+308
#define S21_EPS 1e-17
#define S21_INF_POS 1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define s21_SQRT2 1.41421356237309504880
#define s21_NAN 0.0 / 0.0
#define s21_PI 3.14159265358979323846
#define s21_INF 1.0 / 0.0

int s21_abs(int x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_floor(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_ceil(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);

long double s21_ipow(double base, int exp);
int s21_isnan(double x);