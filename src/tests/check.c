#include "check.h"

int main() {
  int no_failed = 0;

  no_failed |= check_s21_sprintf_spec_d();
  no_failed |= check_s21_sprintf_spec_i();
  no_failed |= check_s21_sprintf_spec_f();
  no_failed |= check_s21_sprintf_spec_f2();
  no_failed |= check_s21_sprintf_spec_u();
  no_failed |= check_s21_sprintf_spec_c();
  no_failed |= check_s21_sprintf_spec_s();
  no_failed |= check_s21_sprintf_spec_p();
  no_failed |= check_s21_sprintf_spec_o();
  no_failed |= check_s21_sprintf_spec_x();
  no_failed |= check_s21_sprintf_spec_x2();
  no_failed |= check_s21_sprintf_spec_e();
  no_failed |= check_s21_sprintf_spec_e2();
  no_failed |= check_s21_sprintf_spec_g();
  no_failed |= check_s21_sprintf_spec_g2();
  no_failed |= check_s21_sprintf_spec_n();
  no_failed |= check_s21_sprintf_spec_inf_nan();
  no_failed |= check_s21_sprintf_spec_other();
  no_failed |= check_s21_upper();
  no_failed |= check_s21_lower();
  no_failed |= check_s21_trim();
  no_failed |= check_s21_insert();
  no_failed |= check_gigacheck_string();

  no_failed |= check_s21_sscanf();
  no_failed |= test_sscanf2();
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void output(char *str, char *str2, char *test_str, int test_int) {
  (void)str;
  (void)str2;
  (void)test_int;
  (void)test_str;
#ifdef DEBUG
  (void)str;
  (void)str2;
  (void)test_int;
  (void)test_str;
  if (!strcmp(str, str2)) {
    printf(
        "\033[0;32mSuccess:\t\t%-30s\t%-13d\tif width - * then width %d"
        "\033[0m\n",
        test_str, test_int, MAX_WIDTH_D);
    // printf("%s\n%s\n", str, str2);
  } else
    printf(
        "\033[0;31mFail: %20s,\t%20d\nOUTPUT sprintf:%s\nOUTPUT     "
        "s21:%s\033[0m\n",
        test_str, test_int, str, str2);
#endif
}
void output2(char *str, char *str2, char *test_str, char *test_int) {
  (void)str;
  (void)str2;
  (void)test_int;
  (void)test_str;

#ifdef DEBUG
  (void)str;
  (void)str2;
  (void)test_int;
  (void)test_str;
  if (!strcmp(str, str2)) {
    printf(
        "\033[0;32mSuccess:\t\t%-30s\t%-13s\tif width - * then width %d"
        "\033[0m\n",
        test_str, test_int, MAX_WIDTH_D);
    // printf("%s\n%s\n", str, str2);
  } else
    printf(
        "\033[0;31mFail: %20s,\t%20s\nOUTPUT sprintf:%s\nOUTPUT     "
        "s21:%s\033[0m\n",
        test_str, test_int, str, str2);
#endif
}
void output3(char *str, char *str2, char *test_str, char *test_int) {
  (void)str;
  (void)str2;
  (void)test_int;
  (void)test_str;
#ifdef DEBUG
  (void)str;
  (void)str2;
  (void)test_int;
  (void)test_str;
  if (!strcmp(str, str2)) {
    printf(
        "\033[0;32mSuccess:\t\t%-30s\t%-13p\tif width - * then width %d"
        "\033[0m\n",
        test_str, test_int, MAX_WIDTH_D);
    // printf("%s\n%s\n", str, str2);
  } else
    printf(
        "\033[0;31mFail: %20s,\t%20p\nOUTPUT sprintf:%s\nOUTPUT     "
        "s21:%s\033[0m\n",
        test_str, test_int, str, str2);
#endif
}
