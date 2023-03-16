#include "check.h"

START_TEST(sprintf_u_check_0_0) {
  char test_str[] = "test=%u=%u=%5u=%5u=%.5u=test";
  unsigned int t_1 = 50, t_2 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_1, t_2, t_1);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_1, t_2, t_1);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_u_check_0) {
  char test_str[] = "test=%u=%u=test";
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
START_TEST(sprintf_u_check_1) {
  char test_str[] = "test=%u=%u=test";
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
START_TEST(sprintf_u_check_2) {
  char test_str[] = "test=%u=%u=test";
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
START_TEST(sprintf_u_check_3) {
  char test_str[] = "test=%-15.5u=%-15.5u=test";
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
START_TEST(sprintf_u_check_4) {
  char test_str[] = "test=%-15.5u=%-15.5u=test";
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
START_TEST(sprintf_u_check_5) {
  char test_str[] = "test=%-15.5u=%-15.5u=test";
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
START_TEST(sprintf_u_check_6) {
  char test_str[] = "test=%-5.15u=%-5.15u=test";
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
START_TEST(sprintf_u_check_7) {
  char test_str[] = "test=%+5.5u=%+5.5u=test";
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
START_TEST(sprintf_u_check_8) {
  char test_str[] = "test=%+5.5u=%+5.5u=test";
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
START_TEST(sprintf_u_check_9) {
  char test_str[] = "test=%+.5u=%+.5u=test";
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
START_TEST(sprintf_u_check_10) {
  char test_str[] = "test=%+5.u=%+5.u=test";
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
START_TEST(sprintf_u_check_11) {
  char test_str[] = "test=%+.5u=%+.6u=test";
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
START_TEST(sprintf_u_check_12) {
  char test_str[] = "test=%15.15u=%15.15u=test";
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
START_TEST(sprintf_u_check_13) {
  char test_str[] = "test=%16.15u=%16.15u=test";
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
START_TEST(sprintf_u_check_14) {
  char test_str[] = "test=%15.15u=%15.15u=test";
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
START_TEST(sprintf_u_check_15) {
  char test_str[] = "test=%11.1u=%11.1u=test";
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
START_TEST(sprintf_u_check_16) {
  char test_str[] = "test=%11.1u=%11.1u=test";
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
START_TEST(sprintf_u_check_17) {
  char test_str[] = "test=%1.11u=%1.11u=test";
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
START_TEST(sprintf_u_check_18) {
  char test_str[] = "test=%1.11u=%1.11u=test";
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
START_TEST(sprintf_u_check_19) {
  char test_str[] = "test=%3.3u=%3.3u=test";
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
START_TEST(sprintf_u_check_20) {
  char test_str[] = "test=%3.3u=%3.3u=test";
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
START_TEST(sprintf_u_check_21) {
  char test_str[] = "test=%+3.3u=%+3.3u=test";
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
START_TEST(sprintf_u_check_22) {
  char test_str[] = "test=%+3.3u=%+3.3u=test";
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
START_TEST(sprintf_u_check_23) {
  char test_str[] = "test=%u%%=%u%%=test";
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
START_TEST(sprintf_u_check_24) {
  char test_str[] = "test=%.2u=%.2u=test";
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
START_TEST(sprintf_u_check_25) {
  char test_str[] = "test=%+-2.2u=%-+2.2u=test";
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
START_TEST(sprintf_u_check_26) {
  char test_str[] = "test=%+-2.2u=%-+2.2u=test";
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
START_TEST(sprintf_u_check_27) {
  char test_str[] = "test=%-15.15u=%-15.15u=test";
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
START_TEST(sprintf_u_check_28) {
  char test_str[] = "test=%-15.15u=%-15.15u=test";
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
START_TEST(sprintf_u_check_29) {
  char test_str[] = "test=%-15.5u=%-15.5u=test";
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
START_TEST(sprintf_u_check_30) {
  char test_str[] = "test=%-15.5u=%-15.5u=test";
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
START_TEST(sprintf_u_check_31) {
  char test_str[] = "test=%-5.15u=%-5.15u=test";
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
START_TEST(sprintf_u_check_32) {
  char test_str[] = "test=%-5.15u=%-5.15u=test";
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
START_TEST(sprintf_u_check_33) {
  char test_str[] = "test=%-+5.5u=%+-5.5u=test";
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
START_TEST(sprintf_u_check_34) {
  char test_str[] = "test=%%%-u%%\n=%%%-u%%\n=test";
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
START_TEST(sprintf_u_check_35) {
  char test_str[] = "test=%-.5u=%-.5u=test";
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
START_TEST(sprintf_u_check_36) {
  char test_str[] = "test=%-5u=%-5u=test";
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
START_TEST(sprintf_u_check_37) {
  char test_str[] = "test=%-10u=%-10u=test";
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
START_TEST(sprintf_u_check_38) {
  char test_str[] = "test=%+-5u=%-+5u=test";
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
START_TEST(sprintf_u_check_39) {
  char test_str[] = "test=%16.15u=%16.15u=test";
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
START_TEST(sprintf_u_check_40) {
  char test_str[] = "test=% 5.5u=% 5.5u=test";
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
START_TEST(sprintf_u_check_41) {
  char test_str[] = "test=%.15u=%.15u=test";
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
START_TEST(sprintf_u_check_42) {
  char test_str[] = "test=%.15u=%.15u=test";
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
START_TEST(sprintf_u_check_43) {
  char test_str[] = "test=%+.15u=%+.15u=test";
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
START_TEST(sprintf_u_check_44) {
  char test_str[] = "test=%+.15u=%+.15u=test";
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
START_TEST(sprintf_u_check_45) {
  char test_str[] = "test=%15.2u=%15.2u=test";
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
START_TEST(sprintf_u_check_46) {
  char test_str[] = "test=%+15.2u=%+15.2u=test";
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
START_TEST(sprintf_u_check_47) {
  char test_str[] = "test=%+15.2u=%+15.2u=test";
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
START_TEST(sprintf_u_check_48) {
  char test_str[] = "test=%15.12u=%15.12u=test";
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
START_TEST(sprintf_u_check_49) {
  char test_str[] = "test=%-.11u=%.11u=test";
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
START_TEST(sprintf_u_check_50) {
  char test_str[] = "test=%+.10u=%+.10u=test";
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
START_TEST(sprintf_u_check_51) {
  char test_str[] = "test=%+-.10u=%-+.10u=test";
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
START_TEST(sprintf_u_check_52) {
  char test_str[] = "test=%+-.13u=%-+.13u=test";
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
START_TEST(sprintf_u_check_53) {
  char test_str[] = "test=%+050u=%+050u=test";
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
START_TEST(sprintf_u_check_54) {
  char test_str[] = "test=%+-13.8u=%-+13.8u=test";
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
START_TEST(sprintf_u_check_55) {
  char test_str[] = "test=%+-13.8u=%-+13.8u=test";
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
START_TEST(sprintf_u_check_56) {
  char test_str[] = "test=%+-13.8u=%-+13.8u=test";
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
START_TEST(sprintf_u_check_57) {
  char test_str[] = "test=%+15.13u=%+15.13u=test";
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
START_TEST(sprintf_u_check_58) {
  char test_str[] = "test=%+-15.15u=%-+15.15u=test";
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
START_TEST(sprintf_u_check_59) {
  char test_str[] = "test=%+-13.10u=%-+13.10u=test";
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
START_TEST(sprintf_u_check_60) {
  char test_str[] = "test=%+-*.10u=%-+*.10u=test";
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
START_TEST(sprintf_u_check_61) {
  char test_str[] = "test=%+-13.*u=%-+13.*u=test";
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
START_TEST(sprintf_u_check_62) {
  char test_str[] = "test=%+-*.*u=%-+*.*u=test";
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
START_TEST(sprintf_u_check_63) {
  char test_str[] = "test=%+-*.*u=%-+*.*u=test";
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
START_TEST(sprintf_u_check_64) {
  char test_str[] = "test=%0+-*.*u=%0-+*.*u=test";
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
START_TEST(sprintf_u_check_65) {
  char test_str[] = "test=% -*.*u=% -*.*u=test";
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
START_TEST(sprintf_u_check_66) {
  char test_str[] = "test=% +-*.*u=% -+*.*u=test";
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
START_TEST(sprintf_u_check_67) {
  char test_str[] = "test=%+-0*.*u=%-+0*.*u=test";
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
START_TEST(sprintf_u_check_68) {
  char test_str[] = "test=%+-0*.*hu=%-+0*.*lu=test";
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
START_TEST(sprintf_u_check_69) {
  char test_str[] = "test=%+-0*.*Lu=%-+0*.*lu=test";
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
START_TEST(sprintf_u_check_70) {
  char test_str[] = "test=%+-0*.*Lu=%-+0*.*lu=test";
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
START_TEST(sprintf_u_check_71) {
  char test_str[] = "test=%+0*.*Lu=%+0*.*lu=test";
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
START_TEST(sprintf_u_check_72) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hu", 65535);
  sprintf(std, "%hu", 65535);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_u_check_73) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hhu", 255);
  sprintf(std, "%hhu", 255);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_u_check_74) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hu", 65535);
  sprintf(std, "%hu", 65535);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_u_check_75) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%hhu", 255);
  sprintf(std, "%hhu", 255);
  ck_assert_str_eq(std, s21);
}
END_TEST
Suite *suite_s21_sprintf_spec_u(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator %u");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_u_check_0_0);
  tcase_add_test(tc_core, sprintf_u_check_0);
  tcase_add_test(tc_core, sprintf_u_check_1);
  tcase_add_test(tc_core, sprintf_u_check_2);
  tcase_add_test(tc_core, sprintf_u_check_3);
  tcase_add_test(tc_core, sprintf_u_check_4);
  tcase_add_test(tc_core, sprintf_u_check_5);
  tcase_add_test(tc_core, sprintf_u_check_6);
  tcase_add_test(tc_core, sprintf_u_check_7);
  tcase_add_test(tc_core, sprintf_u_check_8);
  tcase_add_test(tc_core, sprintf_u_check_9);
  tcase_add_test(tc_core, sprintf_u_check_10);
  tcase_add_test(tc_core, sprintf_u_check_11);
  tcase_add_test(tc_core, sprintf_u_check_12);
  tcase_add_test(tc_core, sprintf_u_check_13);
  tcase_add_test(tc_core, sprintf_u_check_14);
  tcase_add_test(tc_core, sprintf_u_check_15);
  tcase_add_test(tc_core, sprintf_u_check_16);
  tcase_add_test(tc_core, sprintf_u_check_17);
  tcase_add_test(tc_core, sprintf_u_check_18);
  tcase_add_test(tc_core, sprintf_u_check_19);
  tcase_add_test(tc_core, sprintf_u_check_20);
  tcase_add_test(tc_core, sprintf_u_check_21);
  tcase_add_test(tc_core, sprintf_u_check_22);
  tcase_add_test(tc_core, sprintf_u_check_23);
  tcase_add_test(tc_core, sprintf_u_check_24);
  tcase_add_test(tc_core, sprintf_u_check_25);
  tcase_add_test(tc_core, sprintf_u_check_26);
  tcase_add_test(tc_core, sprintf_u_check_27);
  tcase_add_test(tc_core, sprintf_u_check_28);
  tcase_add_test(tc_core, sprintf_u_check_29);
  tcase_add_test(tc_core, sprintf_u_check_30);
  tcase_add_test(tc_core, sprintf_u_check_31);
  tcase_add_test(tc_core, sprintf_u_check_32);
  tcase_add_test(tc_core, sprintf_u_check_33);
  tcase_add_test(tc_core, sprintf_u_check_34);
  tcase_add_test(tc_core, sprintf_u_check_35);
  tcase_add_test(tc_core, sprintf_u_check_36);
  tcase_add_test(tc_core, sprintf_u_check_37);
  tcase_add_test(tc_core, sprintf_u_check_38);
  tcase_add_test(tc_core, sprintf_u_check_39);
  tcase_add_test(tc_core, sprintf_u_check_40);
  tcase_add_test(tc_core, sprintf_u_check_41);
  tcase_add_test(tc_core, sprintf_u_check_42);
  tcase_add_test(tc_core, sprintf_u_check_43);
  tcase_add_test(tc_core, sprintf_u_check_44);
  tcase_add_test(tc_core, sprintf_u_check_45);
  tcase_add_test(tc_core, sprintf_u_check_46);
  tcase_add_test(tc_core, sprintf_u_check_47);
  tcase_add_test(tc_core, sprintf_u_check_48);
  tcase_add_test(tc_core, sprintf_u_check_49);
  tcase_add_test(tc_core, sprintf_u_check_50);
  tcase_add_test(tc_core, sprintf_u_check_51);
  tcase_add_test(tc_core, sprintf_u_check_52);
  tcase_add_test(tc_core, sprintf_u_check_53);
  tcase_add_test(tc_core, sprintf_u_check_54);
  tcase_add_test(tc_core, sprintf_u_check_55);
  tcase_add_test(tc_core, sprintf_u_check_56);
  tcase_add_test(tc_core, sprintf_u_check_57);
  tcase_add_test(tc_core, sprintf_u_check_58);
  tcase_add_test(tc_core, sprintf_u_check_59);
  tcase_add_test(tc_core, sprintf_u_check_60);
  tcase_add_test(tc_core, sprintf_u_check_61);
  tcase_add_test(tc_core, sprintf_u_check_62);
  tcase_add_test(tc_core, sprintf_u_check_63);
  tcase_add_test(tc_core, sprintf_u_check_64);
  tcase_add_test(tc_core, sprintf_u_check_65);
  tcase_add_test(tc_core, sprintf_u_check_66);
  tcase_add_test(tc_core, sprintf_u_check_67);
  tcase_add_test(tc_core, sprintf_u_check_68);
  tcase_add_test(tc_core, sprintf_u_check_69);
  tcase_add_test(tc_core, sprintf_u_check_70);
  tcase_add_test(tc_core, sprintf_u_check_71);
  tcase_add_test(tc_core, sprintf_u_check_72);
  tcase_add_test(tc_core, sprintf_u_check_73);
  tcase_add_test(tc_core, sprintf_u_check_74);
  tcase_add_test(tc_core, sprintf_u_check_75);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_u() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_u();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
