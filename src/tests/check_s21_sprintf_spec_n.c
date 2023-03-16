#include "check.h"

START_TEST(sprintf_n_check_0) {
  int test_int = 50;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%d%n=%d%n=test", test_int, &s1, test_int, &s2);
  int res2 =
      s21_sprintf(str2, "test=%d%n=%d%n=test", test_int, &s3, test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_1) {
  int test_int = 5;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%d%n=%d%n=test", test_int, &s1, test_int, &s2);
  int res2 =
      s21_sprintf(str2, "test=%d%n=%d%n=test", test_int, &s3, test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_2) {
  int test_int = -5;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%d%n=%d%n=test", test_int, &s1, test_int, &s2);
  int res2 =
      s21_sprintf(str2, "test=%d%n=%d%n=test", test_int, &s3, test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_3) {
  int test_int = 5;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_4) {
  int test_int = -5;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_5) {
  int test_int = 5;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_6) {
  int test_int = -4;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-5.15d%n=%-5.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-5.15d%n=%-5.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_7) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+5.5d%n=%+5.5d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+5.5d%n=%+5.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_8) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+5.5d%n=%+5.5d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+5.5d%n=%+5.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_9) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+.5d%n=%+.5d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+.5d%n=%+.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_10) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+5.d%n=%+5.d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+5.d%n=%+5.d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_11) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+.5d%n=%+.5d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+.5d%n=%+.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_12) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%15.15d%n=%15.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%15.15d%n=%15.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_13) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%16.15d%n=%16.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%16.15d%n=%16.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_14) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%15.15d%n=%15.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%15.15d%n=%15.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_15) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%11.1d%n=%11.1d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%11.1d%n=%11.1d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_16) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%11.1d%n=%11.1d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%11.1d%n=%11.1d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_17) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%1.11d%n=%1.11d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%1.11d%n=%1.11d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_18) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%1.11d%n=%1.11d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%1.11d%n=%1.11d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_19) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%3.3d%n=%3.3d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%3.3d%n=%3.3d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_20) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%3.3d%n=%3.3d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%3.3d%n=%3.3d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_21) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+3.3d%n=%+3.3d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+3.3d%n=%+3.3d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_22) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+3.3d%n=%+3.3d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+3.3d%n=%+3.3d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_23) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n%%=%n%%=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n%%=%n%%=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_24) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%.2d%n=%.2d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%.2d%n=%.2d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_25) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-2.2d%n=%+-2.2d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-2.2d%n=%+-2.2d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_26) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-2.2d%n=%+-2.2d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-2.2d%n=%+-2.2d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_27) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-15.15d%n=%-15.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-15.15d%n=%-15.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_28) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-15.15d%n=%-15.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-15.15d%n=%-15.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_29) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_30) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-15.5d%n=%-15.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_31) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-5.15d%n=%-5.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-5.15d%n=%-5.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_32) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-5.15d%n=%-5.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-5.15d%n=%-5.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_33) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-+5.5d%n=%-+5.5d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-+5.5d%n=%-+5.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_34) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n%%\n=%n%%\n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n%%\n=%n%%\n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_35) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%-.5d%n=%-.5d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-.5d%n=%-.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_36) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%-5d%n=%-5d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-5d%n=%-5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_37) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%-10d%n=%-10d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-10d%n=%-10d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_38) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+-5d%n=%+-5d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-5d%n=%+-5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_39) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%16.15d%n=%16.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%16.15d%n=%16.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_40) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=% 5.5d%n=% 5.5d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=% 5.5d%n=% 5.5d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_41) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%.15d%n=%.15d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%.15d%n=%.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_42) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%.15d%n=%.15d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%.15d%n=%.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_43) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+.15d%n=%+.15d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+.15d%n=%+.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_44) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+.15d%n=%+.15d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+.15d%n=%+.15d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_45) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%15.2d%n=%15.2d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%15.2d%n=%15.2d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_46) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+15.2d%n=%+15.2d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+15.2d%n=%+15.2d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_47) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+15.2d%n=%+15.2d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+15.2d%n=%+15.2d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_48) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%15.12d%n=%15.12d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%15.12d%n=%15.12d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_49) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%-.11d%n=%-.11d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-.11d%n=%-.11d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_50) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+.10d%n=%+.10d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+.10d%n=%+.10d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_51) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-.10d%n=%+-.10d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-.10d%n=%+-.10d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_52) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-.10d%n=%+-.10d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-.10d%n=%+-.10d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_53) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 =
      sprintf(str, "test=%+050d%n=%+050d%n=test", test_int, &s1, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+050d%n=%+050d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_54) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-13.8d%n=%+-13.8d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-13.8d%n=%+-13.8d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_55) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%-+13.8d%n=%-+13.8d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%-+13.8d%n=%-+13.8d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_56) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-13.8d%n=%+-13.8d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-13.8d%n=%+-13.8d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_57) {
  int test_int = INT_MIN;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+15.13d%n=%+15.13d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+15.13d%n=%+15.13d%n=test", test_int, &s3,
                         test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_58) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-15.15d%n=%+-15.15d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-15.15d%n=%+-15.15d%n=test", test_int,
                         &s3, test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_59) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-13.10d%n=%+-13.10d%n=test", test_int, &s1,
                     test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-13.10d%n=%+-13.10d%n=test", test_int,
                         &s3, test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_60) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-*.10d%n=%+-*.10d%n=test", MAX_WIDTH_D,
                     test_int, &s1, MAX_WIDTH_D, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-*.10d%n=%+-*.10d%n=test", MAX_WIDTH_D,
                         test_int, &s3, MAX_WIDTH_D, test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_61) {
  int test_int = INT_MAX;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%+-13.*d%n=%+-13.*d%n=test", MAX_WIDTH_D,
                     test_int, &s1, MAX_WIDTH_D, test_int, &s2);
  int res2 = s21_sprintf(str2, "test=%+-13.*d%n=%+-13.*d%n=test", MAX_WIDTH_D,
                         test_int, &s3, MAX_WIDTH_D, test_int, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_62) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_63) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_64) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_65) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_66) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_67) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_68) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_69) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_70) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_n_check_71) {
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, "test=%n=%n=test", &s1, &s2);
  int res2 = s21_sprintf(str2, "test=%n=%n=test", &s3, &s4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(s1, s3);
  ck_assert_int_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
Suite *suite_s21_sprintf_spec_n(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator %n");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_n_check_0);
  tcase_add_test(tc_core, sprintf_n_check_1);
  tcase_add_test(tc_core, sprintf_n_check_2);
  tcase_add_test(tc_core, sprintf_n_check_3);
  tcase_add_test(tc_core, sprintf_n_check_4);
  tcase_add_test(tc_core, sprintf_n_check_5);
  tcase_add_test(tc_core, sprintf_n_check_6);
  tcase_add_test(tc_core, sprintf_n_check_7);
  tcase_add_test(tc_core, sprintf_n_check_8);
  tcase_add_test(tc_core, sprintf_n_check_9);
  tcase_add_test(tc_core, sprintf_n_check_10);
  tcase_add_test(tc_core, sprintf_n_check_11);
  tcase_add_test(tc_core, sprintf_n_check_12);
  tcase_add_test(tc_core, sprintf_n_check_13);
  tcase_add_test(tc_core, sprintf_n_check_14);
  tcase_add_test(tc_core, sprintf_n_check_15);
  tcase_add_test(tc_core, sprintf_n_check_16);
  tcase_add_test(tc_core, sprintf_n_check_17);
  tcase_add_test(tc_core, sprintf_n_check_18);
  tcase_add_test(tc_core, sprintf_n_check_19);
  tcase_add_test(tc_core, sprintf_n_check_20);
  tcase_add_test(tc_core, sprintf_n_check_21);
  tcase_add_test(tc_core, sprintf_n_check_22);
  tcase_add_test(tc_core, sprintf_n_check_23);
  tcase_add_test(tc_core, sprintf_n_check_24);
  tcase_add_test(tc_core, sprintf_n_check_25);
  tcase_add_test(tc_core, sprintf_n_check_26);
  tcase_add_test(tc_core, sprintf_n_check_27);
  tcase_add_test(tc_core, sprintf_n_check_28);
  tcase_add_test(tc_core, sprintf_n_check_29);
  tcase_add_test(tc_core, sprintf_n_check_30);
  tcase_add_test(tc_core, sprintf_n_check_31);
  tcase_add_test(tc_core, sprintf_n_check_32);
  tcase_add_test(tc_core, sprintf_n_check_33);
  tcase_add_test(tc_core, sprintf_n_check_34);
  tcase_add_test(tc_core, sprintf_n_check_35);
  tcase_add_test(tc_core, sprintf_n_check_36);
  tcase_add_test(tc_core, sprintf_n_check_37);
  tcase_add_test(tc_core, sprintf_n_check_38);
  tcase_add_test(tc_core, sprintf_n_check_39);
  tcase_add_test(tc_core, sprintf_n_check_40);
  tcase_add_test(tc_core, sprintf_n_check_41);
  tcase_add_test(tc_core, sprintf_n_check_42);
  tcase_add_test(tc_core, sprintf_n_check_43);
  tcase_add_test(tc_core, sprintf_n_check_44);
  tcase_add_test(tc_core, sprintf_n_check_45);
  tcase_add_test(tc_core, sprintf_n_check_46);
  tcase_add_test(tc_core, sprintf_n_check_47);
  tcase_add_test(tc_core, sprintf_n_check_48);
  tcase_add_test(tc_core, sprintf_n_check_49);
  tcase_add_test(tc_core, sprintf_n_check_50);
  tcase_add_test(tc_core, sprintf_n_check_51);
  tcase_add_test(tc_core, sprintf_n_check_52);
  tcase_add_test(tc_core, sprintf_n_check_53);
  tcase_add_test(tc_core, sprintf_n_check_54);
  tcase_add_test(tc_core, sprintf_n_check_55);
  tcase_add_test(tc_core, sprintf_n_check_56);
  tcase_add_test(tc_core, sprintf_n_check_57);
  tcase_add_test(tc_core, sprintf_n_check_58);
  tcase_add_test(tc_core, sprintf_n_check_59);
  tcase_add_test(tc_core, sprintf_n_check_60);
  tcase_add_test(tc_core, sprintf_n_check_61);
  tcase_add_test(tc_core, sprintf_n_check_62);
  tcase_add_test(tc_core, sprintf_n_check_63);
  tcase_add_test(tc_core, sprintf_n_check_64);
  tcase_add_test(tc_core, sprintf_n_check_65);
  tcase_add_test(tc_core, sprintf_n_check_66);
  tcase_add_test(tc_core, sprintf_n_check_67);
  tcase_add_test(tc_core, sprintf_n_check_68);
  tcase_add_test(tc_core, sprintf_n_check_69);
  tcase_add_test(tc_core, sprintf_n_check_70);
  tcase_add_test(tc_core, sprintf_n_check_71);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_n() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_n();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
