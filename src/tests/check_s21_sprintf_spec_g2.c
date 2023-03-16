#include "check.h"

START_TEST(sprintf_g2_check_1_1) {
  char test_str[] = "test=%G=%G=test";
  float t_1 = 123;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_1);
  int res2 = s21_sprintf(str2, test_str, t_1, t_1);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_g2_check_1_2) {
  char test_str[] = "test=%G=%G=test";
  float t_3 = 10000.0, t_4 = 314.15;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_3, t_4);
  int res2 = s21_sprintf(str2, test_str, t_3, t_4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
// START_TEST(sprintf_g2_check_1_3) {
//   char test_str[] = "test=%#.1G=%#.1G=%#.1G=test";
//   float t_3 = 10000.0, t_4 = 314.15, t_5 = -0.0001;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   int res1 = sprintf(str, test_str, t_3, t_4, t_5);
//   int res2 = s21_sprintf(str2, test_str, t_3, t_4, t_5);
//   ck_assert_str_eq(str, str2);
//   ck_assert_int_eq(res1, res2);
//   free(str);
//   free(str2);
// }
// END_TEST
// START_TEST(sprintf_g2_check_1_4) {
//   char test_str[] = "test=%.6G=%.8G=%.*G=test";
//   float t_1 = 0.221, t_3 = 10000.0, t_4 = 314.15;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   int res1 = sprintf(str, test_str, t_3, t_4, 1, t_1);
//   int res2 = s21_sprintf(str2, test_str, t_3, t_4, 1, t_1);
//   ck_assert_str_eq(str, str2);
//   ck_assert_int_eq(res1, res2);
//   free(str);
//   free(str2);
// }
// END_TEST
// START_TEST(sprintf_g2_check_1_5) {
//   char test_str[] = "test=%1.6G=%10.8G=%*.*G=test";
//   float t_1 = 0.221, t_3 = 10000.0, t_4 = 314.15;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   int res1 = sprintf(str, test_str, t_3, t_4, 12, 1, t_1);
//   int res2 = s21_sprintf(str2, test_str, t_3, t_4, 12, 1, t_1);
//   ck_assert_str_eq(str, str2);
//   ck_assert_int_eq(res1, res2);
//   free(str);
//   free(str2);
// }
// END_TEST
// START_TEST(sprintf_g2_check_1_6) {
//   char test_str[] = "test=%1.6LG=%10.8LG=%*.*LG=test";
//   long double t_1 = -0.3243, t_3 = 0.999, t_4 = 314.15;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   int res1 = sprintf(str, test_str, t_3, t_4, 12, 1, t_1);
//   int res2 = s21_sprintf(str2, test_str, t_3, t_4, 12, 1, t_1);
//   ck_assert_str_eq(str, str2);
//   ck_assert_int_eq(res1, res2);
//   free(str);
//   free(str2);
// }
// END_TEST
START_TEST(sprintf_g2_check_1) {
  char test_str[] = "test=%2.2G=%2.2G=test";
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
START_TEST(sprintf_g2_check_2) {
  char test_str[] = "test=%G=%G=test";
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
START_TEST(sprintf_g2_check_3) {
  char test_str[] = "test=%.2G=%.2G=test";
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
START_TEST(sprintf_g2_check_4) {
  char test_str[] = "test=%G=%G=test";
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
START_TEST(sprintf_g2_check_5) {
  char test_str[] = "test=%G=%G=test";
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
START_TEST(sprintf_g2_check_6) {
  char test_str[] = "test=%2G=%2G=test";
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
START_TEST(sprintf_g2_check_7) {
  char test_str[] = "test=%2G=%2G=test";
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
START_TEST(sprintf_g2_check_8) {
  char test_str[] = "test=% 2G=% 2G=test";
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
START_TEST(sprintf_g2_check_9) {
  char test_str[] = "test=%- 2G=%- 2G=test";
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
START_TEST(sprintf_g2_check_10) {
  char test_str[] = "test=%.0G=%.0G=test";
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
START_TEST(sprintf_g2_check_11) {
  char test_str[] = "test=%.0G=%.0G=test";
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
START_TEST(sprintf_g2_check_12) {
  char test_str[] = "test=%0G=%0G=test";
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
START_TEST(sprintf_g2_check_13) {
  char test_str[] = "test=%0G=%0G=test";
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
START_TEST(sprintf_g2_check_14) {
  char test_str[] = "test=%+G=%+G=test";
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
START_TEST(sprintf_g2_check_15) {
  char test_str[] = "test=%-15G=%-15G=test";
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
START_TEST(sprintf_g2_check_16) {
  char test_str[] = "test=%+15G=%+15G=test";
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
START_TEST(sprintf_g2_check_17) {
  char test_str[] = "test=%-15G=%-15G=test";
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
START_TEST(sprintf_g2_check_18) {
  char test_str[] = "test=%+15G=%+15G=test";
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
START_TEST(sprintf_g2_check_19) {
  char test_str[] = "test=%+-15G=%+-15G=test";
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
START_TEST(sprintf_g2_check_20) {
  char test_str[] = "test=%+-15G=%+-15G=test";
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
START_TEST(sprintf_g2_check_21) {
  char test_str[] = "test=%8.2G=%8.2G=test";
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
START_TEST(sprintf_g2_check_22) {
  char test_str[] = "test=%8.2G=%8.2G=test";
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
START_TEST(sprintf_g2_check_23) {
  char test_str[] = "test=%2.8G=%2.8G=test";
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
START_TEST(sprintf_g2_check_24) {
  char test_str[] = "test=%2.8G=%2.8G=test";
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
START_TEST(sprintf_g2_check_25) {
  char test_str[] = "test=%2.8G=%2.8G=test";
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
START_TEST(sprintf_g2_check_26) {
  char test_str[] = "test=%8.8G=%8.8G=test";
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
START_TEST(sprintf_g2_check_27) {
  char test_str[] = "test=%8.8G=%8.8G=test";
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
START_TEST(sprintf_g2_check_28) {
  char test_str[] = "test=%-8.2G=%-8.2G=test";
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
START_TEST(sprintf_g2_check_29) {
  char test_str[] = "test=%-8.2G=%-8.2G=test";
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
START_TEST(sprintf_g2_check_30) {
  char test_str[] = "test=%-2.8G=%-2.8G=test";
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
START_TEST(sprintf_g2_check_31) {
  char test_str[] = "test=%-2.8G=%-2.8G=test";
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
START_TEST(sprintf_g2_check_32) {
  char test_str[] = "test=%-2.8G=%-2.8G=test";
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
START_TEST(sprintf_g2_check_33) {
  char test_str[] = "test=%-8.8G=%-8.8G=test";
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
START_TEST(sprintf_g2_check_34) {
  char test_str[] = "test=%-8.8G=%-8.8G=test";
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
START_TEST(sprintf_g2_check_35) {
  char test_str[] = "test=%9.0G=%9.0G=test";
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
START_TEST(sprintf_g2_check_36) {
  char test_str[] = "test=%9.0LG=%9.0LG=test";
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
START_TEST(sprintf_g2_check_37) {
  char test_str[] = "test=%9.0LG=%9.0LG=test";
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
START_TEST(sprintf_g2_check_38) {
  char test_str[] = "test=%.1G=%.1G=test";
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
START_TEST(sprintf_g2_check_39) {
  char test_str[] = "test=%.6G=%.6G=test";
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
START_TEST(sprintf_g2_check_40) {
  char test_str[] = "test=%#G=%#G=test";
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
START_TEST(sprintf_g2_check_41) {
  char test_str[] = "test=%#G=%#G=test";
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
START_TEST(sprintf_g2_check_42) {
  char test_str[] = "test=%#G=%#G=test";
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
START_TEST(sprintf_g2_check_43) {
  char test_str[] = "test=%#G=%#G=test";
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
START_TEST(sprintf_g2_check_44) {
  char test_str[] = "test=%#G=%#G=test";
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
START_TEST(sprintf_g2_check_45) {
  char test_str[] = "test=%.5LG=%.5LG=test";
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
START_TEST(sprintf_g2_check_46) {
  char test_str[] = "test=%.5LG=%.5LG=test";
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
START_TEST(sprintf_g2_check_47) {
  char test_str[] = "test=%.0LG=%.0LG=test";
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
START_TEST(sprintf_g2_check_48) {
  char test_str[] = "test=%.0LG=%.0LG=test";
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
START_TEST(sprintf_g2_check_49) {
  char test_str[] = "test=%#LG=%#LG=test";
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
START_TEST(sprintf_g2_check_50) {
  char test_str[] = "test=%#LG=%#LG=test";
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
START_TEST(sprintf_g2_check_51) {
  char test_str[] = "test=%30.20LG=%30.20LG=test";
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
START_TEST(sprintf_g2_check_52) {
  char test_str[] = "test=%30.15LG=%30.15LG=test";
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
START_TEST(sprintf_g2_check_53) {
  char test_str[] = "test=%.15LG=%.15LG=test";
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
START_TEST(sprintf_g2_check_54) {
  char test_str[] = "test=%.15LG=%.15LG=test";
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
START_TEST(sprintf_g2_check_55) {
  char test_str[] = "test=%LG=%LG=test";
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
START_TEST(sprintf_g2_check_56) {
  char test_str[] = "test=%LG=%LG=test";
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
START_TEST(sprintf_g2_check_57) {
  char test_str[] = "test=%.LG=%.LG=test";
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
START_TEST(sprintf_g2_check_58) {
  char test_str[] = "test=%.LG=%.LG=test";
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
START_TEST(sprintf_g2_check_59) {
  char test_str[] = "test=% G=% G=test";
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
START_TEST(sprintf_g2_check_60) {
  char test_str[] = "test=% G=% G=test";
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
START_TEST(sprintf_g2_check_61) {
  char test_str[] = "test=% G=% G=test";
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
START_TEST(sprintf_g2_check_62) {
  char test_str[] = "test=% G=% G=test";
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
START_TEST(sprintf_g2_check_63) {
  char test_str[] = "test=% G=% G=test";
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
// START_TEST(sprintf_g2_check_64) {
//   char test_str[] = "test=%.*G=%.*G=test";
//   double test_double = MIN_F;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MAX_ACC_F, test_double, 15, test_double);
//   s21_sprintf(str2, test_str, MAX_ACC_F, test_double, 15, test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
START_TEST(sprintf_g2_check_65) {
  char test_str[] = "test=%.*G=%.*G=test";
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
START_TEST(sprintf_g2_check_66) {
  char test_str[] = "test=%.*G=%.*G=test";
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
START_TEST(sprintf_g2_check_67) {
  char test_str[] = "test=%.*G=%.*G=test";
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
// START_TEST(sprintf_g2_check_68) {
//   char test_str[] = "test=%.*G=%.*G=test";
//   double test_double = FLOAT;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MIN_ACC_F, test_double, 10, test_double);
//   s21_sprintf(str2, test_str, MIN_ACC_F, test_double, 10, test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
// START_TEST(sprintf_g2_check_69) {
//   char test_str[] = "test=%#*.*G=%#*.*G=test";
//   double test_double = MIN_F;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 15,
//           test_double);
//   s21_sprintf(str2, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 15,
//               test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
START_TEST(sprintf_g2_check_70) {
  char test_str[] = "test=%#*.*G=%#*.*G=test";
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
START_TEST(sprintf_g2_check_71) {
  char test_str[] = "test=%#*.*G=%#*.*G=test";
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
START_TEST(sprintf_g2_check_72) {
  char test_str[] = "test=%#*.*G=%#*.*G=test";
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
// START_TEST(sprintf_g2_check_73) {
//   char test_str[] = "test=%#*.*G=%#*.*G=test";
//   double test_double = FLOAT;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 10, 10,
//           test_double);
//   s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 10, 10,
//               test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
// START_TEST(sprintf_g2_check_74) {
//   char test_str[] = "test=% +#*.*G=% +#*.*G=test";
//   double test_double = MIN_F;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 15,
//           test_double);
//   s21_sprintf(str2, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 15,
//               test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
START_TEST(sprintf_g2_check_75) {
  char test_str[] = "test=% +#*.*G=% +#*.*G=test";
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
START_TEST(sprintf_g2_check_76) {
  char test_str[] = "test=% +#*.*G=% +#*.*G=test";
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
START_TEST(sprintf_g2_check_77) {
  char test_str[] = "test=% +#*.*G=% +#*.*G=test";
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
// START_TEST(sprintf_g2_check_78) {
//   char test_str[] = "test=% +#*.*G%%=% +#*.*G%%=test";
//   double test_double = FLOAT;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 10, 10,
//           test_double);
//   s21_sprintf(str2, test_str, MIN_ACC_F, MIN_ACC_F, test_double, 10, 10,
//               test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
// START_TEST(sprintf_g2_check_79) {
//   char test_str[] = "test=% +#*.*G=% +#*.*G=test";
//   double test_double = FLOAT;
//   char *str = (char *)calloc(SIZE_STR, sizeof(char));
//   char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
//   sprintf(str, test_str, 300, 18, test_double, 10, 10, test_double);
//   s21_sprintf(str2, test_str, 300, 18, test_double, 10, 10, test_double);
//   ck_assert_str_eq(str, str2);
//   output(str, str2, test_str, test_double);
//   free(str);
//   free(str2);
// }
// END_TEST
// START_TEST(sprintf_g2_check_80) {
//   char std[4096];
//   char s21[4096];
//   s21_sprintf(s21, "%G %G", 10000.10001, 0.0000001);
//   sprintf(std, "%G %G", 10000.10001, 0.0000001);
//   ck_assert_str_eq(std, s21);
// }
// END_TEST
// START_TEST(sprintf_g2_check_81) {
//   char std[4096];
//   char s21[4096];
//   s21_sprintf(s21, "%LG %LG", (long double)10000.10001, (long
//   double)0.0000001); sprintf(std, "%LG %LG", (long double)10000.10001, (long
//   double)0.0000001); ck_assert_str_eq(std, s21);
// }
// END_TEST
// START_TEST(sprintf_g2_check_82) {
//   char std[4096];
//   char s21[4096];
//   int v1, v2;
//   s21_sprintf(s21, "%G %E %F %d\n%c %s %n", 1.12345, 1.1234567, 1.1234567,
//   -100,
//               '=', "test", &v1);
//   sprintf(std, "%G %E %F %d\n%c %s %n", 1.12345, 1.1234567, 1.1234567, -100,
//           '=', "test", &v2);
//   ck_assert_str_eq(std, s21);
//   ck_assert_int_eq(v1, v2);
// }
// END_TEST
// START_TEST(sprintf_g2_check_83) {
//   char std[4096];
//   char s21[4096];
//   s21_sprintf(s21, "%G %G", 10000.10001, 0.0000001);
//   sprintf(std, "%G %G", 10000.10001, 0.0000001);
//   ck_assert_str_eq(std, s21);
// }
// END_TEST
// START_TEST(sprintf_g2_check_84) {
//   char std[4096];
//   char s21[4096];
//   s21_sprintf(s21, "%LG %LG", (long double)10000.10001, (long
//   double)0.0000001); sprintf(std, "%LG %LG", (long double)10000.10001, (long
//   double)0.0000001); ck_assert_str_eq(std, s21);
// }
// END_TEST
START_TEST(sprintf_g2_check_85) {
  char std[4096];
  char s21[4096];
  int v1, v2;
  s21_sprintf(s21, "%G %E %F %d\n%c %s %n", 1.12345, 1.1234567, 1.1234567, -100,
              '=', "test", &v1);
  sprintf(std, "%G %E %F %d\n%c %s %n", 1.12345, 1.1234567, 1.1234567, -100,
          '=', "test", &v2);
  ck_assert_str_eq(std, s21);
  ck_assert_int_eq(v1, v2);
}
END_TEST
Suite *suite_s21_sprintf_spec_g2(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator %G");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_g2_check_1_1);
  tcase_add_test(tc_core, sprintf_g2_check_1_2);
  // tcase_add_test(tc_core, sprintf_g2_check_1_3);
  // tcase_add_test(tc_core, sprintf_g2_check_1_4);
  // tcase_add_test(tc_core, sprintf_g2_check_1_5);
  // tcase_add_test(tc_core, sprintf_g2_check_1_6);
  tcase_add_test(tc_core, sprintf_g2_check_1);
  tcase_add_test(tc_core, sprintf_g2_check_2);
  tcase_add_test(tc_core, sprintf_g2_check_3);
  tcase_add_test(tc_core, sprintf_g2_check_4);
  tcase_add_test(tc_core, sprintf_g2_check_5);
  tcase_add_test(tc_core, sprintf_g2_check_6);
  tcase_add_test(tc_core, sprintf_g2_check_7);
  tcase_add_test(tc_core, sprintf_g2_check_8);
  tcase_add_test(tc_core, sprintf_g2_check_9);
  tcase_add_test(tc_core, sprintf_g2_check_10);
  tcase_add_test(tc_core, sprintf_g2_check_11);
  tcase_add_test(tc_core, sprintf_g2_check_12);
  tcase_add_test(tc_core, sprintf_g2_check_13);
  tcase_add_test(tc_core, sprintf_g2_check_14);
  tcase_add_test(tc_core, sprintf_g2_check_15);
  tcase_add_test(tc_core, sprintf_g2_check_16);
  tcase_add_test(tc_core, sprintf_g2_check_17);
  tcase_add_test(tc_core, sprintf_g2_check_18);
  tcase_add_test(tc_core, sprintf_g2_check_19);
  tcase_add_test(tc_core, sprintf_g2_check_20);
  tcase_add_test(tc_core, sprintf_g2_check_21);
  tcase_add_test(tc_core, sprintf_g2_check_22);
  tcase_add_test(tc_core, sprintf_g2_check_23);
  tcase_add_test(tc_core, sprintf_g2_check_24);
  tcase_add_test(tc_core, sprintf_g2_check_25);
  tcase_add_test(tc_core, sprintf_g2_check_26);
  tcase_add_test(tc_core, sprintf_g2_check_27);
  tcase_add_test(tc_core, sprintf_g2_check_28);
  tcase_add_test(tc_core, sprintf_g2_check_29);
  tcase_add_test(tc_core, sprintf_g2_check_30);
  tcase_add_test(tc_core, sprintf_g2_check_31);
  tcase_add_test(tc_core, sprintf_g2_check_32);
  tcase_add_test(tc_core, sprintf_g2_check_33);
  tcase_add_test(tc_core, sprintf_g2_check_34);
  tcase_add_test(tc_core, sprintf_g2_check_35);
  tcase_add_test(tc_core, sprintf_g2_check_36);
  tcase_add_test(tc_core, sprintf_g2_check_37);
  tcase_add_test(tc_core, sprintf_g2_check_38);
  tcase_add_test(tc_core, sprintf_g2_check_39);
  tcase_add_test(tc_core, sprintf_g2_check_40);
  tcase_add_test(tc_core, sprintf_g2_check_41);
  tcase_add_test(tc_core, sprintf_g2_check_42);
  tcase_add_test(tc_core, sprintf_g2_check_43);
  tcase_add_test(tc_core, sprintf_g2_check_44);
  tcase_add_test(tc_core, sprintf_g2_check_45);
  tcase_add_test(tc_core, sprintf_g2_check_46);
  tcase_add_test(tc_core, sprintf_g2_check_47);
  tcase_add_test(tc_core, sprintf_g2_check_48);
  tcase_add_test(tc_core, sprintf_g2_check_49);
  tcase_add_test(tc_core, sprintf_g2_check_50);
  tcase_add_test(tc_core, sprintf_g2_check_51);
  tcase_add_test(tc_core, sprintf_g2_check_52);
  tcase_add_test(tc_core, sprintf_g2_check_53);
  tcase_add_test(tc_core, sprintf_g2_check_54);
  tcase_add_test(tc_core, sprintf_g2_check_55);
  tcase_add_test(tc_core, sprintf_g2_check_56);
  tcase_add_test(tc_core, sprintf_g2_check_57);
  tcase_add_test(tc_core, sprintf_g2_check_58);
  tcase_add_test(tc_core, sprintf_g2_check_59);
  tcase_add_test(tc_core, sprintf_g2_check_60);
  tcase_add_test(tc_core, sprintf_g2_check_61);
  tcase_add_test(tc_core, sprintf_g2_check_62);
  tcase_add_test(tc_core, sprintf_g2_check_63);
  // tcase_add_test(tc_core, sprintf_g2_check_64);
  tcase_add_test(tc_core, sprintf_g2_check_65);
  tcase_add_test(tc_core, sprintf_g2_check_66);
  tcase_add_test(tc_core, sprintf_g2_check_67);
  // tcase_add_test(tc_core, sprintf_g2_check_68);
  // tcase_add_test(tc_core, sprintf_g2_check_69);
  tcase_add_test(tc_core, sprintf_g2_check_70);
  tcase_add_test(tc_core, sprintf_g2_check_71);
  tcase_add_test(tc_core, sprintf_g2_check_72);
  // tcase_add_test(tc_core, sprintf_g2_check_73);
  // tcase_add_test(tc_core, sprintf_g2_check_74);
  tcase_add_test(tc_core, sprintf_g2_check_75);
  tcase_add_test(tc_core, sprintf_g2_check_76);
  tcase_add_test(tc_core, sprintf_g2_check_77);
  // tcase_add_test(tc_core, sprintf_g2_check_78);
  // tcase_add_test(tc_core, sprintf_g2_check_79);
  // tcase_add_test(tc_core, sprintf_g2_check_80);
  // tcase_add_test(tc_core, sprintf_g2_check_81);
  // tcase_add_test(tc_core, sprintf_g2_check_82);
  // tcase_add_test(tc_core, sprintf_g2_check_83);
  // tcase_add_test(tc_core, sprintf_g2_check_84);
  tcase_add_test(tc_core, sprintf_g2_check_85);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_g2() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_g2();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
