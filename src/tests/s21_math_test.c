#include "s21_math_test.h"

int main(void) {
  int number_failed = 0;
  Suite* s[] = {
      s21_abs_suite(),  s21_fmod_suite(),  s21_log_suite(),  s21_pow_suite(),
      s21_exp_suite(),  s21_sqrt_suite(),  s21_cos_suite(),  s21_sin_suite(),
      s21_fabs_suite(), s21_floor_suite(), s21_tan_suite(),  s21_ceil_suite(),
      s21_atan_suite(), s21_asin_suite(),  s21_acos_suite(), NULL};
  for (Suite** current_suit = s; *current_suit != NULL; current_suit++) {
    s21_test_one_suite(*current_suit, &number_failed);
  }
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void s21_test_one_suite(Suite* current_suit, int* sum_of_errors) {
  SRunner* sr;
  sr = srunner_create(current_suit);

  srunner_run_all(sr, CK_NORMAL);
  *sum_of_errors += srunner_ntests_failed(sr);
  srunner_free(sr);
}