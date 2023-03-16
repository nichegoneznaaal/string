#include "check.h"

START_TEST(sprintf_d_check_0_0_0) {
  char test_str[] = "test=%hd=%ld=test";
  short int t_1 = 134;
  long int t_2 = 123123123;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_0_0) {
  char test_str[] = "test=%d=%d=%d=test";
  int int_1 = 50, int_2 = -50, int_3 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, int_1, int_2, int_3);
  int res2 = s21_sprintf(str2, test_str, int_1, int_2, int_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_0_1) {
  char test_str[] = "test=%5d=%5d=%5d=test";
  int int_1 = 50, int_2 = -50, int_3 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, int_1, int_2, int_3);
  int res2 = s21_sprintf(str2, test_str, int_1, int_2, int_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_0_2) {
  char test_str[] = "test=%+d=%+d=%+d=test";
  int int_1 = 50, int_2 = -50, int_3 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, int_1, int_2, int_3);
  int res2 = s21_sprintf(str2, test_str, int_1, int_2, int_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_0_3) {
  char test_str[] = "test=%-d=%-d=%-d=test";
  int int_1 = 50, int_2 = -50, int_3 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, int_1, int_2, int_3);
  int res2 = s21_sprintf(str2, test_str, int_1, int_2, int_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_0_4) {
  char test_str[] = "test=% d=% d=% d=test";
  int int_1 = 50, int_2 = -50, int_3 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, int_1, int_2, int_3);
  int res2 = s21_sprintf(str2, test_str, int_1, int_2, int_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_0_5) {
  char test_str[] = "test=%.5d=%.5d=test";
  int int_1 = 50, int_2 = -50;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, int_1, int_2);
  int res2 = s21_sprintf(str2, test_str, int_1, int_2);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_0_6) {
  char test_str[] = "test=%ld=%ld=%ld=test";
  long int int_1 = 9999999, int_2 = -9999999, int_3 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, int_1, int_2, int_3);
  int res2 = s21_sprintf(str2, test_str, int_1, int_2, int_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_0) {
  char test_str[] = "test=%d=%d=test";
  int test_int = 50;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_1) {
  char test_str[] = "test=%d=%d=test";
  int test_int = 5;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_2) {
  char test_str[] = "test=%d=%d=test";
  int test_int = -5;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_3) {
  char test_str[] = "test=%-15.5d=%-15.5d=test";
  int test_int = 5;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_4) {
  char test_str[] = "test=%-15.5d=%-15.5d=test";
  int test_int = -5;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_5) {
  char test_str[] = "test=%-15.5d=%-15.5d=test";
  int test_int = 5;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_6) {
  char test_str[] = "test=%-5.15d=%-5.15d=test";
  int test_int = -4;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_7) {
  char test_str[] = "test=%+5.5d=%+5.5d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_8) {
  char test_str[] = "test=%+5.5d=%+5.5d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_9) {
  char test_str[] = "test=%+.5d=%+.5d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_10) {
  char test_str[] = "test=%+5.d=%+5.d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_11) {
  char test_str[] = "test=%+.5d=%+.6d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_12) {
  char test_str[] = "test=%15.15d=%15.15d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_13) {
  char test_str[] = "test=%16.15d=%16.15d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_14) {
  char test_str[] = "test=%15.15d=%15.15d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_15) {
  char test_str[] = "test=%11.1d=%11.1d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_16) {
  char test_str[] = "test=%11.1d=%11.1d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_17) {
  char test_str[] = "test=%1.11d=%1.11d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_18) {
  char test_str[] = "test=%1.11d=%1.11d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_19) {
  char test_str[] = "test=%3.3d=%3.3d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_20) {
  char test_str[] = "test=%3.3d=%3.3d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_21) {
  char test_str[] = "test=%+3.3d=%+3.3d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_22) {
  char test_str[] = "test=%+3.3d=%+3.3d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_23) {
  char test_str[] = "test=%d%%=%d%%=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_24) {
  char test_str[] = "test=%.2d=%.2d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_25) {
  char test_str[] = "test=%+-2.2d=%-+2.2d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_26) {
  char test_str[] = "test=%+-2.2d=%-+2.2d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_27) {
  char test_str[] = "test=%-15.15d=%-15.15d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_28) {
  char test_str[] = "test=%-15.15d=%-15.15d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_29) {
  char test_str[] = "test=%-15.5d=%-15.5d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_30) {
  char test_str[] = "test=%-15.5d=%-15.5d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_31) {
  char test_str[] = "test=%-5.15d=%-5.15d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_32) {
  char test_str[] = "test=%-5.15d=%-5.15d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_33) {
  char test_str[] = "test=%-+5.5d=%+-5.5d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_34) {
  char test_str[] = "test=%-d%%\n=%-d%%\n=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_35) {
  char test_str[] = "test=%-.5d=%-.5d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_36) {
  char test_str[] = "test=%-5d=%-5d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_37) {
  char test_str[] = "test=%-10d=%-10d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_38) {
  char test_str[] = "test=%+-5d=%-+5d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_39) {
  char test_str[] = "test=%16.15d=%16.15d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_40) {
  char test_str[] = "test=% 5.5d=% 5.5d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_41) {
  char test_str[] = "test=%.15d=%.15d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_42) {
  char test_str[] = "test=%.15d=%.15d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_43) {
  char test_str[] = "test=%+.15d=%+.15d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_44) {
  char test_str[] = "test=%+.15d=%+.15d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_45) {
  char test_str[] = "test=%15.2d=%15.2d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_46) {
  char test_str[] = "test=%+15.2d=%+15.2d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_47) {
  char test_str[] = "test=%+15.2d=%+15.2d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_48) {
  char test_str[] = "test=%15.12d=%15.12d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_49) {
  char test_str[] = "test=%-.11d=%.11d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_50) {
  char test_str[] = "test=%+.10d=%+.10d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_51) {
  char test_str[] = "test=%+-.10d=%-+.10d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_52) {
  char test_str[] = "test=%+-.13d=%-+.13d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_53) {
  char test_str[] = "test=%+050d=%+050d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_54) {
  char test_str[] = "test=%+-13.8d=%-+13.8d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_55) {
  char test_str[] = "test=%+-13.8d=%-+13.8d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_56) {
  char test_str[] = "test=%+-13.8d=%-+13.8d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_57) {
  char test_str[] = "test=%+15.13d=%+15.13d=test";
  int test_int = INT_MIN;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_58) {
  char test_str[] = "test=%+-15.15d=%-+15.15d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_59) {
  char test_str[] = "test=%+-13.10d=%-+13.10d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_int, test_int);
  s21_sprintf(str2, test_str, test_int, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_60) {
  char test_str[] = "test=%+-*.10d=%-+*.10d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, test_int, MAX_WIDTH_D, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, test_int, MAX_WIDTH_D, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_61) {
  char test_str[] = "test=%+-13.*d=%-+13.*d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, test_int, MAX_WIDTH_D, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, test_int, MAX_WIDTH_D, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_62) {
  char test_str[] = "test=%+-*.*d=%-+*.*d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_63) {
  char test_str[] = "test=%+-*.*d=%-+*.*d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int,
          MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int,
              MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_64) {
  char test_str[] = "test=%0+-*.*d=%0-+*.*d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int,
          MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int,
              MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_65) {
  char test_str[] = "test=% -*.*d=% -*.*d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int,
          MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int,
              MAX_WIDTH_D + 10, MAX_WIDTH_D, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_66) {
  char test_str[] = "test=% +-*.*d=% -+*.*d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_67) {
  char test_str[] = "test=%+-0*.*d=%-+0*.*d=test";
  int test_int = INT_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_68) {
  char test_str[] = "test=%+-0*.*hd=%-+0*.*ld=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_WIDTH_D, MAX_WIDTH_D + 10, SHRT_MAX, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, (long)LONG_MAX);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, SHRT_MAX,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, (long)LONG_MAX);
  ck_assert_str_eq(str, str2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_69) {
  char test_str[] = "test=%+-0*.*Ld=%-+0*.*ld=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, (long)LONG_MAX,
          MIN_WIDTH_D, MAX_WIDTH_D + 10, (long)LONG_MAX);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, (long)LONG_MAX,
              MIN_WIDTH_D, MAX_WIDTH_D + 10, (long)LONG_MAX);
  ck_assert_str_eq(str, str2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_70) {
  char test_str[] = "test=%+-0*.*Ld=%-+0*.*ld=test";
  long long int test_int = (long)LONG_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, test_int);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_71) {
  char test_str[] = "test=%+0*.*Ld=%+0*.*ld=test";
  long long int test_int = (long)LONG_MAX;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_WIDTH_D, MIN_WIDTH_D, test_int, MIN_WIDTH_D,
          MIN_WIDTH_D, test_int);
  s21_sprintf(str2, test_str, MIN_WIDTH_D, MIN_WIDTH_D, test_int, MIN_WIDTH_D,
              MIN_WIDTH_D, test_int);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_int);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_d_check_72) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*d %d", -10, 123456789, 123456789);
  sprintf(std, "%*d %d", -10, 123456789, 123456789);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_73) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*d %*d", -10, 123456789, 5, -123456789);
  sprintf(std, "%*d %*d", -10, 123456789, 5, -123456789);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_74) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%d", 0);
  sprintf(std, "%d", 0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_75) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hd", 1);
  sprintf(std, "%hd", 1);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_76) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%d", -1);
  sprintf(std, "%d", -1);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_77) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hhd", -1);
  sprintf(std, "%hhd", -1);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_78) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hhd", 127);
  sprintf(std, "%hhd", 127);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_79) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*d", 5, 888888);
  sprintf(std, "%*d", 5, 888888);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_80) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%lld", 999999999999ull);
  sprintf(std, "%lld", 999999999999ull);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_81) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "% d %d", -1, 10);
  sprintf(std, "% d %d", -1, 10);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_82) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%-10d %d", -1, 10);
  sprintf(std, "%-10d %d", -1, 10);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_83) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%+d %+d", -1, 10);
  sprintf(std, "%+d %+d", -1, 10);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_84) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "% d %+d", 5461, 10);
  sprintf(std, "% d %+d", 5461, 10);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_85) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%lld", -999999999999ull);
  sprintf(std, "%lld", -999999999999ull);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_86) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%+8d", -123456);
  sprintf(std, "%+8d", -123456);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_87) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%d", 0);
  sprintf(std, "%d", 0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_88) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hd", 1);
  sprintf(std, "%hd", 1);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_89) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%d", -1);
  sprintf(std, "%d", -1);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_90) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hhd", -1);
  sprintf(std, "%hhd", -1);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_91) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hhd", 127);
  sprintf(std, "%hhd", 127);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_92) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*d", 5, 888888);
  sprintf(std, "%*d", 5, 888888);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_93) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%lld", 999999999999ull);
  sprintf(std, "%lld", 999999999999ull);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_94) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "% d %d", -1, 10);
  sprintf(std, "% d %d", -1, 10);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_95) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%-10d %d", -1, 10);
  sprintf(std, "%-10d %d", -1, 10);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_96) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%+d %+d", -1, 10);
  sprintf(std, "%+d %+d", -1, 10);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_97) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "% d %+d", 5461, 10);
  sprintf(std, "% d %+d", 5461, 10);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_98) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%lld", -999999999999ull);
  sprintf(std, "%lld", -999999999999ull);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_99) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%+8d", -123456);
  sprintf(std, "%+8d", -123456);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_100) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*d %d", -10, 123456789, 123456789);
  sprintf(std, "%*d %d", -10, 123456789, 123456789);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_d_check_101) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*d %*d", -10, 123456789, 5, -123456789);
  sprintf(std, "%*d %*d", -10, 123456789, 5, -123456789);
  ck_assert_str_eq(std, s21);
}
END_TEST
Suite *suite_s21_sprintf_spec_d(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator %d");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_d_check_0_0_0);
  tcase_add_test(tc_core, sprintf_d_check_0_0);
  tcase_add_test(tc_core, sprintf_d_check_0_1);
  tcase_add_test(tc_core, sprintf_d_check_0_2);
  tcase_add_test(tc_core, sprintf_d_check_0_3);
  tcase_add_test(tc_core, sprintf_d_check_0_4);
  tcase_add_test(tc_core, sprintf_d_check_0_5);
  tcase_add_test(tc_core, sprintf_d_check_0_6);
  tcase_add_test(tc_core, sprintf_d_check_0);
  tcase_add_test(tc_core, sprintf_d_check_1);
  tcase_add_test(tc_core, sprintf_d_check_2);
  tcase_add_test(tc_core, sprintf_d_check_3);
  tcase_add_test(tc_core, sprintf_d_check_4);
  tcase_add_test(tc_core, sprintf_d_check_5);
  tcase_add_test(tc_core, sprintf_d_check_6);
  tcase_add_test(tc_core, sprintf_d_check_7);
  tcase_add_test(tc_core, sprintf_d_check_8);
  tcase_add_test(tc_core, sprintf_d_check_9);
  tcase_add_test(tc_core, sprintf_d_check_10);
  tcase_add_test(tc_core, sprintf_d_check_11);
  tcase_add_test(tc_core, sprintf_d_check_12);
  tcase_add_test(tc_core, sprintf_d_check_13);
  tcase_add_test(tc_core, sprintf_d_check_14);
  tcase_add_test(tc_core, sprintf_d_check_15);
  tcase_add_test(tc_core, sprintf_d_check_16);
  tcase_add_test(tc_core, sprintf_d_check_17);
  tcase_add_test(tc_core, sprintf_d_check_18);
  tcase_add_test(tc_core, sprintf_d_check_19);
  tcase_add_test(tc_core, sprintf_d_check_20);
  tcase_add_test(tc_core, sprintf_d_check_21);
  tcase_add_test(tc_core, sprintf_d_check_22);
  tcase_add_test(tc_core, sprintf_d_check_23);
  tcase_add_test(tc_core, sprintf_d_check_24);
  tcase_add_test(tc_core, sprintf_d_check_25);
  tcase_add_test(tc_core, sprintf_d_check_26);
  tcase_add_test(tc_core, sprintf_d_check_27);
  tcase_add_test(tc_core, sprintf_d_check_28);
  tcase_add_test(tc_core, sprintf_d_check_29);
  tcase_add_test(tc_core, sprintf_d_check_30);
  tcase_add_test(tc_core, sprintf_d_check_31);
  tcase_add_test(tc_core, sprintf_d_check_32);
  tcase_add_test(tc_core, sprintf_d_check_33);
  tcase_add_test(tc_core, sprintf_d_check_34);
  tcase_add_test(tc_core, sprintf_d_check_35);
  tcase_add_test(tc_core, sprintf_d_check_36);
  tcase_add_test(tc_core, sprintf_d_check_37);
  tcase_add_test(tc_core, sprintf_d_check_38);
  tcase_add_test(tc_core, sprintf_d_check_39);
  tcase_add_test(tc_core, sprintf_d_check_40);
  tcase_add_test(tc_core, sprintf_d_check_41);
  tcase_add_test(tc_core, sprintf_d_check_42);
  tcase_add_test(tc_core, sprintf_d_check_43);
  tcase_add_test(tc_core, sprintf_d_check_44);
  tcase_add_test(tc_core, sprintf_d_check_45);
  tcase_add_test(tc_core, sprintf_d_check_46);
  tcase_add_test(tc_core, sprintf_d_check_47);
  tcase_add_test(tc_core, sprintf_d_check_48);
  tcase_add_test(tc_core, sprintf_d_check_49);
  tcase_add_test(tc_core, sprintf_d_check_50);
  tcase_add_test(tc_core, sprintf_d_check_51);
  tcase_add_test(tc_core, sprintf_d_check_52);
  tcase_add_test(tc_core, sprintf_d_check_53);
  tcase_add_test(tc_core, sprintf_d_check_54);
  tcase_add_test(tc_core, sprintf_d_check_55);
  tcase_add_test(tc_core, sprintf_d_check_56);
  tcase_add_test(tc_core, sprintf_d_check_57);
  tcase_add_test(tc_core, sprintf_d_check_58);
  tcase_add_test(tc_core, sprintf_d_check_59);
  tcase_add_test(tc_core, sprintf_d_check_60);
  tcase_add_test(tc_core, sprintf_d_check_61);
  tcase_add_test(tc_core, sprintf_d_check_62);
  tcase_add_test(tc_core, sprintf_d_check_63);
  tcase_add_test(tc_core, sprintf_d_check_64);
  tcase_add_test(tc_core, sprintf_d_check_65);
  tcase_add_test(tc_core, sprintf_d_check_66);
  tcase_add_test(tc_core, sprintf_d_check_67);
  tcase_add_test(tc_core, sprintf_d_check_68);
  tcase_add_test(tc_core, sprintf_d_check_69);
  tcase_add_test(tc_core, sprintf_d_check_70);
  tcase_add_test(tc_core, sprintf_d_check_71);
  tcase_add_test(tc_core, sprintf_d_check_72);
  tcase_add_test(tc_core, sprintf_d_check_73);
  tcase_add_test(tc_core, sprintf_d_check_74);
  tcase_add_test(tc_core, sprintf_d_check_75);
  tcase_add_test(tc_core, sprintf_d_check_76);
  tcase_add_test(tc_core, sprintf_d_check_77);
  tcase_add_test(tc_core, sprintf_d_check_78);
  tcase_add_test(tc_core, sprintf_d_check_79);
  tcase_add_test(tc_core, sprintf_d_check_80);
  tcase_add_test(tc_core, sprintf_d_check_81);
  tcase_add_test(tc_core, sprintf_d_check_82);
  tcase_add_test(tc_core, sprintf_d_check_83);
  tcase_add_test(tc_core, sprintf_d_check_84);
  tcase_add_test(tc_core, sprintf_d_check_85);
  tcase_add_test(tc_core, sprintf_d_check_86);
  tcase_add_test(tc_core, sprintf_d_check_87);
  tcase_add_test(tc_core, sprintf_d_check_88);
  tcase_add_test(tc_core, sprintf_d_check_87);
  tcase_add_test(tc_core, sprintf_d_check_88);
  tcase_add_test(tc_core, sprintf_d_check_89);
  tcase_add_test(tc_core, sprintf_d_check_90);
  tcase_add_test(tc_core, sprintf_d_check_91);
  tcase_add_test(tc_core, sprintf_d_check_92);
  tcase_add_test(tc_core, sprintf_d_check_93);
  tcase_add_test(tc_core, sprintf_d_check_94);
  tcase_add_test(tc_core, sprintf_d_check_95);
  tcase_add_test(tc_core, sprintf_d_check_96);
  tcase_add_test(tc_core, sprintf_d_check_97);
  tcase_add_test(tc_core, sprintf_d_check_98);
  tcase_add_test(tc_core, sprintf_d_check_99);
  tcase_add_test(tc_core, sprintf_d_check_100);
  tcase_add_test(tc_core, sprintf_d_check_101);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_d() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_d();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
