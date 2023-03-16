#include "check.h"

START_TEST(sprintf_e2_check_1_1) {
  char test_str[] = "test=%E=%E=test";
  float test_ = 123;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, test_, test_);
  int res2 = s21_sprintf(str2, test_str, test_, test_);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_1_2) {
  char test_str[] = "test=%E=%E=test";
  float test_1 = 10000.0, test_2 = 314.15;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, test_1, test_2);
  int res2 = s21_sprintf(str2, test_str, test_1, test_2);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_1_3) {
  char test_str[] = "test=%.1E=%#.1E=%.1E=test";
  float test_1 = 123, test_3 = 10000.0, test_4 = 314.15;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, test_3, test_4, test_1);
  int res2 = s21_sprintf(str2, test_str, test_3, test_4, test_1);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_1_4) {
  char test_str[] = "test=%.6E=%.8E=%.*E=test";
  float test_1 = 123, test_3 = 10000.0, test_4 = 314.15;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, test_3, test_4, 1, test_1);
  int res2 = s21_sprintf(str2, test_str, test_3, test_4, 1, test_1);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_1_5) {
  char test_str[] = "test=%1.6E=%10.8E=%*.*E=test";
  float test_1 = 123, test_3 = 10000.0, test_4 = 314.15;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, test_3, test_4, 12, 1, test_1);
  int res2 = s21_sprintf(str2, test_str, test_3, test_4, 12, 1, test_1);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
// START_TEST(sprintf_e2_check_1_6) {
//   char test_str[] = "test=%1.6LE=%10.6LE=%*.*LE=test";
//   long double test_1 = -0.000001, test_3 = 10000.0, test_4 = 314.15;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   int res1 = sprintf(str, test_str, test_3, test_4, 12, 1, test_1);
//   int res2 = s21_sprintf(str2, test_str, test_3, test_4, 12, 1, test_1);
//   ck_assert_str_eq(str, str2);
//   ck_assert_int_eq(res1, res2);
//   free(str);
//   free(str2);
// }
// END_TEST
START_TEST(sprintf_e2_check_1) {
  char test_str[] = "test=%2.2E=%2.2E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_2) {
  char test_str[] = "test=%E=%E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_3) {
  char test_str[] = "test=%.2E=%.2E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_4) {
  char test_str[] = "test=%E=%E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_5) {
  char test_str[] = "test=%E=%E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_6) {
  char test_str[] = "test=%2E=%2E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_7) {
  char test_str[] = "test=%2E=%2E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_8) {
  char test_str[] = "test=% 2E=% 2E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_9) {
  char test_str[] = "test=%- 2E=%- 2E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_10) {
  char test_str[] = "test=%.0E=%.0E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_11) {
  char test_str[] = "test=%.0E=%.0E=test";
  double test_double = 0.99;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_12) {
  char test_str[] = "test=%0E=%0E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_13) {
  char test_str[] = "test=%0E=%0E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_14) {
  char test_str[] = "test=%+E=%+E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_15) {
  char test_str[] = "test=%-15E=%-15E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_16) {
  char test_str[] = "test=%+15E=%+15E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_17) {
  char test_str[] = "test=%-15E=%-15E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_18) {
  char test_str[] = "test=%+15E=%+15E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_19) {
  char test_str[] = "test=%+-15E=%+-15E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_20) {
  char test_str[] = "test=%+-15E=%+-15E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_21) {
  char test_str[] = "test=%8.2E=%8.2E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_22) {
  char test_str[] = "test=%8.2E=%8.2E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_23) {
  char test_str[] = "test=%2.8E=%2.8E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_24) {
  char test_str[] = "test=%2.8E=%2.8E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_25) {
  char test_str[] = "test=%2.8E=%2.8E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_26) {
  char test_str[] = "test=%8.8E=%8.8E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_27) {
  char test_str[] = "test=%8.8E=%8.8E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_28) {
  char test_str[] = "test=%-8.2E=%-8.2E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_29) {
  char test_str[] = "test=%-8.2E=%-8.2E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_30) {
  char test_str[] = "test=%-2.8E=%-2.8E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_31) {
  char test_str[] = "test=%-2.8E=%-2.8E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_32) {
  char test_str[] = "test=%-2.8E=%-2.8E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_33) {
  char test_str[] = "test=%-8.8E=%-8.8E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_34) {
  char test_str[] = "test=%-8.8E=%-8.8E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_35) {
  char test_str[] = "test=%9.0E=%9.0E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_36) {
  char test_str[] = "test=%9.0LE=%9.0LE=test";
  long double test_double = MAX_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, MAX_F_L);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_37) {
  char test_str[] = "test=%9.0LE=%9.0LE=test";
  long double test_double = MIN_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_38) {
  char test_str[] = "test=%.1E=%.1E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_39) {
  char test_str[] = "test=%.6E=%.6E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_40) {
  char test_str[] = "test=%#E=%#E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_41) {
  char test_str[] = "test=%#E=%#E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_42) {
  char test_str[] = "test=%#E=%#E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_43) {
  char test_str[] = "test=%#E=%#E=test";
  double test_double = FLOAT2;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_44) {
  char test_str[] = "test=%#E=%#E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_45) {
  char test_str[] = "test=%.5LE=%.5LE=test";
  long double test_double = MAX_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_46) {
  char test_str[] = "test=%.5LE=%.5LE=test";
  long double test_double = MIN_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_47) {
  char test_str[] = "test=%.0LE=%.0LE=test";
  long double test_double = MAX_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_48) {
  char test_str[] = "test=%.0LE=%.0LE=test";
  long double test_double = MIN_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_49) {
  char test_str[] = "test=%#LE=%#LE=test";
  long double test_double = MAX_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_50) {
  char test_str[] = "test=%#LE=%#LE=test";
  long double test_double = MIN_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_51) {
  char test_str[] = "test=%30.17LE=%30.17LE=test";
  long double test_double = MAX_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_52) {
  char test_str[] = "test=%30.17LE=%30.17LE=test";
  long double test_double = MIN_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_53) {
  char test_str[] = "test=%.15LE=%.15LE=test";
  long double test_double = MAX_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_54) {
  char test_str[] = "test=%.15LE=%.15LE=test";
  long double test_double = MIN_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_55) {
  char test_str[] = "test=%LE=%LE=test";
  long double test_double = MAX_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_56) {
  char test_str[] = "test=%LE=%LE=test";
  long double test_double = MIN_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_57) {
  char test_str[] = "test=%.LE=%.LE=test";
  long double test_double = MAX_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_58) {
  char test_str[] = "test=%.LE=%.LE=test";
  long double test_double = MIN_F_L;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_59) {
  char test_str[] = "test=% E=% E=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_60) {
  char test_str[] = "test=% E=% E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_61) {
  char test_str[] = "test=% E=% E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_62) {
  char test_str[] = "test=% E=% E=test";
  double test_double = FLOAT2;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_63) {
  char test_str[] = "test=% E=% E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, test_double, test_double);
  s21_sprintf(str2, test_str, test_double, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST  /////////////////
// START_TEST(sprintf_e2_check_64) {
//   char test_str[] = "test=%.*E=%.*E=test";
//   double test_double = MIN_F;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MAX_ACC_F, test_double, 70, test_double);
//   s21_sprintf(str2, test_str, MAX_ACC_F, test_double, 70, test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
START_TEST(sprintf_e2_check_65) {
  char test_str[] = "test=%.*E=%.*E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, test_double, 7, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, test_double, 7, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_66) {
  char test_str[] = "test=%.*E=%.*E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, test_double, 3, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, test_double, 3, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_67) {
  char test_str[] = "test=%.*E=%.*E=test";
  double test_double = FLOAT2;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, test_double, 1, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, test_double, 1, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_68) {
  char test_str[] = "test=%.*E=%.*E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, test_double, 10, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, test_double, 10, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
// START_TEST(sprintf_e2_check_69) {
//   char test_str[] = "test=%#*.*E=%#*.*E=test";
//   double test_double = MIN_F;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 70,
//           test_double);
//   s21_sprintf(str2, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 70,
//               test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
START_TEST(sprintf_e2_check_70) {
  char test_str[] = "test=%#*.*E=%#*.*E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 7, 7, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 7, 7,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_71) {
  char test_str[] = "test=%#*.*E=%#*.*E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 3, 3, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 3, 3,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_72) {
  char test_str[] = "test=%#*.*E=%#*.*E=test";
  double test_double = FLOAT2;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 1, 1, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 1, 1,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_73) {
  char test_str[] = "test=%#*.*E=%#*.*E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 10, 10,
          test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 10, 10,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
// START_TEST(sprintf_e2_check_74) {
//   char test_str[] = "test=% +#*.*E=% +#*.*E=test";
//   double test_double = MIN_F;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 70,
//           test_double);
//   s21_sprintf(str2, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 70,
//               test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
START_TEST(sprintf_e2_check_75) {
  char test_str[] = "test=% +#*.*E=% +#*.*E=test";
  double test_double = MAX_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 7, 7, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 7, 7,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_76) {
  char test_str[] = "test=% +#*.*E=% +#*.*E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 3, 3, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 3, 3,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_77) {
  char test_str[] = "test=% +#*.*E=% +#*.*E=test";
  double test_double = FLOAT2;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 1, 1, test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 1, 1,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_78) {
  char test_str[] = "test=% +#*.*E%%=% +#*.*E%%=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 10, 10,
          test_double);
  s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 10, 10,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_e2_check_79) {
  char test_str[] = "test=% +#*.*E=% +#*.*E=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, 300, 18, test_double, 10, 10, test_double);
  s21_sprintf(str2, test_str, 300, 18, test_double, 10, 10, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
// START_TEST(sprintf_e2_check_80) {
//   char std[4096];
//   char s21[4096];
//   s21_sprintf(s21, "%E %E", 10000.10001, 0.0000001);
//   sprintf(std, "%E %E", 10000.10001, 0.0000001);
//   ck_assert_str_eq(std, s21);
// }
// END_TEST
// START_TEST(sprintf_e2_check_81) {
//   char std[4096];
//   char s21[4096];
//   s21_sprintf(s21, "%LE %LE", (long double)10000.10001, (long
//   double)0.0000001); sprintf(std, "%LE %LE", (long double)10000.10001, (long
//   double)0.0000001); ck_assert_str_eq(std, s21);
// }
// END_TEST
// START_TEST(sprintf_e2_check_82) {
//   char std[4096];
//   char s21[4096];
//   s21_sprintf(s21, "%E %E", 10000.10001, 0.0000001);
//   sprintf(std, "%E %E", 10000.10001, 0.0000001);
//   ck_assert_str_eq(std, s21);
// }
// END_TEST
// START_TEST(sprintf_e2_check_83) {
//   char std[4096];
//   char s21[4096];
//   s21_sprintf(s21, "%LE %LE", (long double)10000.10001, (long
//   double)0.0000001); sprintf(std, "%LE %LE", (long double)10000.10001, (long
//   double)0.0000001); ck_assert_str_eq(std, s21);
// }
// END_TEST
Suite *suite_s21_sprintf_spec_e2(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator %E");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_e2_check_1_1);
  tcase_add_test(tc_core, sprintf_e2_check_1_2);
  tcase_add_test(tc_core, sprintf_e2_check_1_3);
  tcase_add_test(tc_core, sprintf_e2_check_1_4);
  tcase_add_test(tc_core, sprintf_e2_check_1_5);
  // tcase_add_test(tc_core, sprintf_e2_check_1_6);
  tcase_add_test(tc_core, sprintf_e2_check_1);
  tcase_add_test(tc_core, sprintf_e2_check_2);
  tcase_add_test(tc_core, sprintf_e2_check_3);
  tcase_add_test(tc_core, sprintf_e2_check_4);
  tcase_add_test(tc_core, sprintf_e2_check_5);
  tcase_add_test(tc_core, sprintf_e2_check_6);
  tcase_add_test(tc_core, sprintf_e2_check_7);
  tcase_add_test(tc_core, sprintf_e2_check_8);
  tcase_add_test(tc_core, sprintf_e2_check_9);
  tcase_add_test(tc_core, sprintf_e2_check_10);
  tcase_add_test(tc_core, sprintf_e2_check_11);
  tcase_add_test(tc_core, sprintf_e2_check_12);
  tcase_add_test(tc_core, sprintf_e2_check_13);
  tcase_add_test(tc_core, sprintf_e2_check_14);
  tcase_add_test(tc_core, sprintf_e2_check_15);
  tcase_add_test(tc_core, sprintf_e2_check_16);
  tcase_add_test(tc_core, sprintf_e2_check_17);
  tcase_add_test(tc_core, sprintf_e2_check_18);
  tcase_add_test(tc_core, sprintf_e2_check_19);
  tcase_add_test(tc_core, sprintf_e2_check_20);
  tcase_add_test(tc_core, sprintf_e2_check_21);
  tcase_add_test(tc_core, sprintf_e2_check_22);
  tcase_add_test(tc_core, sprintf_e2_check_23);
  tcase_add_test(tc_core, sprintf_e2_check_24);
  tcase_add_test(tc_core, sprintf_e2_check_25);
  tcase_add_test(tc_core, sprintf_e2_check_26);
  tcase_add_test(tc_core, sprintf_e2_check_27);
  tcase_add_test(tc_core, sprintf_e2_check_28);
  tcase_add_test(tc_core, sprintf_e2_check_29);
  tcase_add_test(tc_core, sprintf_e2_check_30);
  tcase_add_test(tc_core, sprintf_e2_check_31);
  tcase_add_test(tc_core, sprintf_e2_check_32);
  tcase_add_test(tc_core, sprintf_e2_check_33);
  tcase_add_test(tc_core, sprintf_e2_check_34);
  tcase_add_test(tc_core, sprintf_e2_check_35);
  tcase_add_test(tc_core, sprintf_e2_check_36);
  tcase_add_test(tc_core, sprintf_e2_check_37);
  tcase_add_test(tc_core, sprintf_e2_check_38);
  tcase_add_test(tc_core, sprintf_e2_check_39);
  tcase_add_test(tc_core, sprintf_e2_check_40);
  tcase_add_test(tc_core, sprintf_e2_check_41);
  tcase_add_test(tc_core, sprintf_e2_check_42);
  tcase_add_test(tc_core, sprintf_e2_check_43);
  tcase_add_test(tc_core, sprintf_e2_check_44);
  tcase_add_test(tc_core, sprintf_e2_check_45);
  tcase_add_test(tc_core, sprintf_e2_check_46);
  tcase_add_test(tc_core, sprintf_e2_check_47);
  tcase_add_test(tc_core, sprintf_e2_check_48);
  tcase_add_test(tc_core, sprintf_e2_check_49);
  tcase_add_test(tc_core, sprintf_e2_check_50);
  tcase_add_test(tc_core, sprintf_e2_check_51);
  tcase_add_test(tc_core, sprintf_e2_check_52);
  tcase_add_test(tc_core, sprintf_e2_check_53);
  tcase_add_test(tc_core, sprintf_e2_check_54);
  tcase_add_test(tc_core, sprintf_e2_check_55);
  tcase_add_test(tc_core, sprintf_e2_check_56);
  tcase_add_test(tc_core, sprintf_e2_check_57);
  tcase_add_test(tc_core, sprintf_e2_check_58);
  tcase_add_test(tc_core, sprintf_e2_check_59);
  tcase_add_test(tc_core, sprintf_e2_check_60);
  tcase_add_test(tc_core, sprintf_e2_check_61);
  tcase_add_test(tc_core, sprintf_e2_check_62);
  tcase_add_test(tc_core, sprintf_e2_check_63);
  // tcase_add_test(tc_core, sprintf_e2_check_64);
  tcase_add_test(tc_core, sprintf_e2_check_65);
  tcase_add_test(tc_core, sprintf_e2_check_66);
  tcase_add_test(tc_core, sprintf_e2_check_67);
  tcase_add_test(tc_core, sprintf_e2_check_68);
  // tcase_add_test(tc_core, sprintf_e2_check_69);
  tcase_add_test(tc_core, sprintf_e2_check_70);
  tcase_add_test(tc_core, sprintf_e2_check_71);
  tcase_add_test(tc_core, sprintf_e2_check_72);
  tcase_add_test(tc_core, sprintf_e2_check_73);
  // tcase_add_test(tc_core, sprintf_e2_check_74);
  tcase_add_test(tc_core, sprintf_e2_check_75);
  tcase_add_test(tc_core, sprintf_e2_check_76);
  tcase_add_test(tc_core, sprintf_e2_check_77);
  tcase_add_test(tc_core, sprintf_e2_check_78);
  tcase_add_test(tc_core, sprintf_e2_check_79);
  // tcase_add_test(tc_core, sprintf_e2_check_80);
  // tcase_add_test(tc_core, sprintf_e2_check_81);
  // tcase_add_test(tc_core, sprintf_e2_check_82);
  // tcase_add_test(tc_core, sprintf_e2_check_83);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_e2() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_e2();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
