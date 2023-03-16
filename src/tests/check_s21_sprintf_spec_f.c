#include "check.h"

START_TEST(sprintf_f_check_1_0) {
  char test_str[] = "test=%Lf=test";
  long double t_1 =
      3.40987654567899876543456789876543467898765432478987654345678987654356787654098765432345689098765434567898765434567890987654345678956789765456789654567876543567876543456787654345678765432345678765434567895434789876567887654876548765434568765456789876545678909879876543888;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1);
  int res2 = s21_sprintf(str2, test_str, t_1);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_1) {
  char test_str[] = "test=%.0f=%.0f=%f=%f=test";
  float t_1 = 0.9999999, t_2 = -0.9999999, t_3 = 0, t_4 = 0.123456;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_2) {
  char test_str[] = "test=%5f=%5f=%5f=%5f=test";
  float t_1 = 0.9999999, t_2 = -0.9999999, t_3 = 0, t_4 = 0.123456;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_3) {
  char test_str[] = "test=%+f=%+f=%+f=%+f=test";
  float t_1 = 0.9999999, t_2 = -0.9999999, t_3 = 0, t_4 = 0.123456;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_4) {
  char test_str[] = "test=%-f=%-f=%-f=%-f=test";
  float t_1 = 0.9999999, t_2 = -0.9999999, t_3 = 0, t_4 = 0.123456;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_5) {
  char test_str[] = "test=% f=% f=% f=test";
  float t_1 = 0.9999999, t_2 = -0.9999999, t_3 = 0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_6) {
  char test_str[] = "test=%.0f=%.5f=%.5f=%.5f=%.0f=test";
  float t_1 = 0.9999999, t_2 = -0.9999999, t_3 = 0, t_4 = 0.123456;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4, t_1);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4, t_1);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_7) {
  char test_str[] = "test=%lf=%lf=%lf=test";
  double t_1 = 123456.123456, t_2 = 123456.123456, t_3 = 0.0;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_8) {
  char test_str[] = "test=%f=%f=%f=%f=test";
  float t_1 = 100000.0, t_2 = 9.999999, t_3 = -3.14, t_4 = 0.000001;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_9) {
  char test_str[] = "test=%.9f=%.0f=%.11f=%.22f=%.*f=test";
  float t_1 = 100000.0, t_2 = 9.999999, t_3 = -3.14;
  float t_4 = 0.000001, t_5 = -0.000001;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4, 15, t_5);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4, 15, t_5);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_10) {
  char test_str[] = "test=%#-17.9f=%#-08.1f=%010.11f=%.1f=%#*.*f=test";
  float t_1 = 100000.0, t_2 = 9.999999, t_3 = -3.14;
  float t_4 = 0.000001, t_5 = -0.000001;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4, 8, 1, t_5);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4, 8, 1, t_5);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_11) {
  char test_str[] = "=%+17.9f=%#08.0f=%+-010.11f=%+.1f=% +#*.*f=";
  float t_1 = 100000.0, t_2 = 9.999999, t_3 = -3.14;
  float t_4 = 0.000001, t_5 = -0.000001;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3, t_4, 8, 0, t_5);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3, t_4, 8, 0, t_5);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1_12) {
  char test_str[] = "test=%30.25Lf=%30.30Lf=%30.20Lf=test";
  long double t_1 = 999999999.99999999999999999999;
  long double t_2 = 0.00000000000000000001;
  long double t_3 = -0.00000000000000001;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  int res1 = sprintf(str, test_str, t_1, t_2, t_3);
  int res2 = s21_sprintf(str2, test_str, t_1, t_2, t_3);
  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_1) {
  char test_str[] = "test=%2.2f=%2.2f=test";
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
START_TEST(sprintf_f_check_2) {
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  // sprintf(str, "test=%f__%f__%f__%f=test", DBL_MAX, DBL_MAX, DBL_MAX,
  // DBL_MAX); s21_sprintf(str2, "test=%f__%f__%f__%f=test", DBL_MAX, DBL_MAX,
  // DBL_MAX,
  //             DBL_MAX);
  sprintf(str, "test=%f=%f=test", FLOAT2, FLOAT2);
  s21_sprintf(str2, "test=%f=%f=test", FLOAT2, FLOAT2);
  ck_assert_str_eq(str, str2);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_3) {
  char test_str[] = "test=%.2f=%.2f=test";
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
START_TEST(sprintf_f_check_4) {
  char test_str[] = "test=%f=%f=test";
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
START_TEST(sprintf_f_check_5) {
  char test_str[] = "test=%f=%f=test";
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
START_TEST(sprintf_f_check_6) {
  char test_str[] = "test=%2f=%2f=test";
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
START_TEST(sprintf_f_check_7) {
  char test_str[] = "test=%2f=%2f=test";
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
START_TEST(sprintf_f_check_8) {
  char test_str[] = "test=% 2f=% 2f=test";
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
START_TEST(sprintf_f_check_9) {
  char test_str[] = "test=%- 2f=%- 2f=test";
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
START_TEST(sprintf_f_check_10) {
  char test_str[] = "test=%.0f=%.0f=test";
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
START_TEST(sprintf_f_check_11) {
  char test_str[] = "test=%.0f=%.0f=test";
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
START_TEST(sprintf_f_check_12) {
  char test_str[] = "test=%0f=%0f=test";
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
START_TEST(sprintf_f_check_13) {
  char test_str[] = "test=%0f=%0f=test";
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
START_TEST(sprintf_f_check_14) {
  char test_str[] = "test=%+f=%+f=test";
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
START_TEST(sprintf_f_check_15) {
  char test_str[] = "test=%-15f=%-15f=test";
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
START_TEST(sprintf_f_check_16) {
  char test_str[] = "test=%+15f=%+15f=test";
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
START_TEST(sprintf_f_check_17) {
  char test_str[] = "test=%-15f=%-15f=test";
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
START_TEST(sprintf_f_check_18) {
  char test_str[] = "test=%+15f=%+15f=test";
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
START_TEST(sprintf_f_check_19) {
  char test_str[] = "test=%+-15f=%+-15f=test";
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
START_TEST(sprintf_f_check_20) {
  char test_str[] = "test=%+-15f=%+-15f=test";
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
START_TEST(sprintf_f_check_21) {
  char test_str[] = "test=%8.2f=%8.2f=test";
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
START_TEST(sprintf_f_check_22) {
  char test_str[] = "test=%8.2f=%8.2f=test";
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
START_TEST(sprintf_f_check_23) {
  char test_str[] = "test=%2.8f=%2.8f=test";
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
START_TEST(sprintf_f_check_24) {
  char test_str[] = "test=%2.8f=%2.8f=test";
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
START_TEST(sprintf_f_check_25) {
  char test_str[] = "test=%2.8f=%2.8f=test";
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
START_TEST(sprintf_f_check_26) {
  char test_str[] = "test=%8.8f=%8.8f=test";
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
START_TEST(sprintf_f_check_27) {
  char test_str[] = "test=%8.8f=%8.8f=test";
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
START_TEST(sprintf_f_check_28) {
  char test_str[] = "test=%-8.2f=%-8.2f=test";
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
START_TEST(sprintf_f_check_29) {
  char test_str[] = "test=%-8.2f=%-8.2f=test";
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
START_TEST(sprintf_f_check_30) {
  char test_str[] = "test=%-2.8f=%-2.8f=test";
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
START_TEST(sprintf_f_check_31) {
  char test_str[] = "test=%-2.8f=%-2.8f=test";
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
START_TEST(sprintf_f_check_32) {
  char test_str[] = "test=%-2.8f=%-2.8f=test";
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
START_TEST(sprintf_f_check_33) {
  char test_str[] = "test=%-8.8f=%-8.8f=test";
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
START_TEST(sprintf_f_check_34) {
  char test_str[] = "test=%-8.8f=%-8.8f=test";
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
START_TEST(sprintf_f_check_35) {
  char test_str[] = "test=%9.0f=%9.0f=test";
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
START_TEST(sprintf_f_check_36) {
  char test_str[] = "test=%9.0Lf=%9.0Lf=test";
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
START_TEST(sprintf_f_check_37) {
  char test_str[] = "test=%9.0Lf=%9.0Lf=test";
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
START_TEST(sprintf_f_check_38) {
  char test_str[] = "test=%.1f=%.1f=test";
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
START_TEST(sprintf_f_check_39) {
  char test_str[] = "test=%.6f=%.6f=test";
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
START_TEST(sprintf_f_check_40) {
  char test_str[] = "test=%#f=%#f=test";
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
START_TEST(sprintf_f_check_41) {
  char test_str[] = "test=%#f=%#f=test";
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
START_TEST(sprintf_f_check_42) {
  char test_str[] = "test=%#f=%#f=test";
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
START_TEST(sprintf_f_check_43) {
  char test_str[] = "test=%#f=%#f=test";
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
START_TEST(sprintf_f_check_44) {
  char test_str[] = "test=%#f=%#f=test";
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
START_TEST(sprintf_f_check_45) {
  char test_str[] = "test=%.5Lf=%.5Lf=test";
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
START_TEST(sprintf_f_check_46) {
  char test_str[] = "test=%.5Lf=%.5Lf=test";
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
START_TEST(sprintf_f_check_47) {
  char test_str[] = "test=%.0Lf=%.0Lf=test";
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
START_TEST(sprintf_f_check_48) {
  char test_str[] = "test=%.0Lf=%.0Lf=test";
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
START_TEST(sprintf_f_check_49) {
  char test_str[] = "test=%#Lf=%#Lf=test";
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
START_TEST(sprintf_f_check_50) {
  char test_str[] = "test=%#Lf=%#Lf=test";
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
START_TEST(sprintf_f_check_51) {
  char test_str[] = "test=%30.17Lf=%30.17Lf=test";
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
START_TEST(sprintf_f_check_52) {
  char test_str[] = "test=%30.17Lf=%30.17Lf=test";
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
START_TEST(sprintf_f_check_53) {
  char test_str[] = "test=%.15Lf=%.15Lf=test";
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
START_TEST(sprintf_f_check_54) {
  char test_str[] = "test=%.15Lf=%.15Lf=test";
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
START_TEST(sprintf_f_check_55) {
  char test_str[] = "test=%Lf=%Lf=test";
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
START_TEST(sprintf_f_check_56) {
  char test_str[] = "test=%Lf=%Lf=test";
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
START_TEST(sprintf_f_check_57) {
  char test_str[] = "test=%.Lf=%.Lf=test";
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
START_TEST(sprintf_f_check_58) {
  char test_str[] = "test=%.Lf=%.Lf=test";
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
START_TEST(sprintf_f_check_59) {
  char test_str[] = "test=% f=% f=test";
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
START_TEST(sprintf_f_check_60) {
  char test_str[] = "test=% f=% f=test";
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
START_TEST(sprintf_f_check_61) {
  char test_str[] = "test=% f=% f=test";
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
START_TEST(sprintf_f_check_62) {
  char test_str[] = "test=% f=% f=test";
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
START_TEST(sprintf_f_check_63) {
  char test_str[] = "test=% f=% f=test";
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
START_TEST(sprintf_f_check_64) {
  char test_str[] = "test=%.*f=%.*f=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_ACC_F, test_double, 70, test_double);
  s21_sprintf(str2, test_str, MAX_ACC_F, test_double, 70, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_65) {
  char test_str[] = "test=%.*f=%.*f=test";
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
START_TEST(sprintf_f_check_66) {
  char test_str[] = "test=%.*f=%.*f=test";
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
START_TEST(sprintf_f_check_67) {
  char test_str[] = "test=%.*f=%.*f=test";
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
START_TEST(sprintf_f_check_68) {
  char test_str[] = "test=%.*f=%.*f=test";
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
START_TEST(sprintf_f_check_69) {
  char test_str[] = "test=%#*.*f=%#*.*f=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 70,
          test_double);
  s21_sprintf(str2, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 70,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_70) {
  char test_str[] = "test=%#*.*f=%#*.*f=test";
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
START_TEST(sprintf_f_check_71) {
  char test_str[] = "test=%#*.*f=%#*.*f=test";
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
START_TEST(sprintf_f_check_72) {
  char test_str[] = "test=%#*.*f=%#*.*f=test";
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
START_TEST(sprintf_f_check_73) {
  char test_str[] = "test=%#*.*f=%#*.*f=test";
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
START_TEST(sprintf_f_check_74) {
  char test_str[] = "test=% +#*.*f=% +#*.*f=test";
  double test_double = MIN_F;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 70,
          test_double);
  s21_sprintf(str2, test_str, MAX_ACC_F, MAX_ACC_F, test_double, 70, 70,
              test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_75) {
  char test_str[] = "test=% +#*.*f=% +#*.*f=test";
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
START_TEST(sprintf_f_check_76) {
  char test_str[] = "test=% +#*.*f=% +#*.*f=test";
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
START_TEST(sprintf_f_check_77) {
  char test_str[] = "test=% +#*.*f=% +#*.*f=test";
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
START_TEST(sprintf_f_check_78) {
  char test_str[] = "test=% +#*.*f%%=% +#*.*f%%=test";
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
START_TEST(sprintf_f_check_79) {
  char test_str[] = "test=% +#*.*f=% +#*.*f=test";
  double test_double = FLOAT;
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, 300, 17, test_double, 10, 10, test_double);
  s21_sprintf(str2, test_str, 300, 17, test_double, 10, 10, test_double);
  ck_assert_str_eq(str, str2);
  output(str, str2, test_str, test_double);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_f_check_80) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%f %f", 0.0, 1.0);
  sprintf(std, "%f %f", 0.0, 1.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_81) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*f %f", 10, 0.0, 1.0);
  sprintf(std, "%*f %f", 10, 0.0, 1.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_82) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.15f", 0.0000000000000001234567890);
  sprintf(std, "%.15f", 0.0000000000000001234567890);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_83) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.5f", 12345678901011121314151617181920.0);
  sprintf(std, "%.5f", 12345678901011121314151617181920.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_84) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.2f", 123456789.123456789);
  sprintf(std, "%.2f", 123456789.123456789);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_85) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.0f", 9.9999999);
  sprintf(std, "%.0f", 9.9999999);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_86) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%#f", 9.9999999);
  sprintf(std, "%#f", 9.9999999);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_87) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%Lf %Lf", (long double)0.0, (long double)1.0);
  sprintf(std, "%Lf %Lf", (long double)0.0, (long double)1.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_88) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*Lf %Lf", 10, (long double)0.0, (long double)1.0);
  sprintf(std, "%*Lf %Lf", 10, (long double)0.0, (long double)1.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_89) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.15Lf", (long double)0.0000000000000001234567890);
  sprintf(std, "%.15Lf", (long double)0.0000000000000001234567890);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_90) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.5Lf", (long double)12345678901011121314151617181920.0);
  sprintf(std, "%.5Lf", (long double)12345678901011121314151617181920.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_91) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.2Lf", (long double)123456789.123456789);
  sprintf(std, "%.2Lf", (long double)123456789.123456789);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_92) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.0Lf", (long double)9.9999999);
  sprintf(std, "%.0Lf", (long double)9.9999999);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_93) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%#Lf", (long double)9.9999999);
  sprintf(std, "%#Lf", (long double)9.9999999);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_94) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%f %f", 0.0, 1.0);
  sprintf(std, "%f %f", 0.0, 1.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_95) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*f %f", 10, 0.0, 1.0);
  sprintf(std, "%*f %f", 10, 0.0, 1.0);
  ck_assert_str_eq(std, s21);
}
END_TEST

START_TEST(sprintf_f_check_96) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.15f", 0.0000000000000001234567890);
  sprintf(std, "%.15f", 0.0000000000000001234567890);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_97) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.5f", 12345678901011121314151617181920.0);
  sprintf(std, "%.5f", 12345678901011121314151617181920.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_98) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.2f", 123456789.123456789);
  sprintf(std, "%.2f", 123456789.123456789);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_99) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.0f", 9.9999999);
  sprintf(std, "%.0f", 9.9999999);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_100) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%#f", 9.9999999);
  sprintf(std, "%#f", 9.9999999);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_101) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%Lf %Lf", (long double)0.0, (long double)1.0);
  sprintf(std, "%Lf %Lf", (long double)0.0, (long double)1.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_102) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*Lf %Lf", 10, (long double)0.0, (long double)1.0);
  sprintf(std, "%*Lf %Lf", 10, (long double)0.0, (long double)1.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_103) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.15Lf", (long double)0.0000000000000001234567890);
  sprintf(std, "%.15Lf", (long double)0.0000000000000001234567890);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_104) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.5Lf", (long double)12345678901011121314151617181920.0);
  sprintf(std, "%.5Lf", (long double)12345678901011121314151617181920.0);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_105) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.2Lf", (long double)123456789.123456789);
  sprintf(std, "%.2Lf", (long double)123456789.123456789);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_106) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%.0Lf", (long double)9.9999999);
  sprintf(std, "%.0Lf", (long double)9.9999999);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f_check_107) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%#Lf", (long double)9.9999999);
  sprintf(std, "%#Lf", (long double)9.9999999);
  ck_assert_str_eq(std, s21);
}
END_TEST
Suite *suite_s21_sprintf_spec_f(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator %f");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_f_check_1_0);
  tcase_add_test(tc_core, sprintf_f_check_1_1);
  tcase_add_test(tc_core, sprintf_f_check_1_2);
  tcase_add_test(tc_core, sprintf_f_check_1_3);
  tcase_add_test(tc_core, sprintf_f_check_1_4);
  tcase_add_test(tc_core, sprintf_f_check_1_5);
  tcase_add_test(tc_core, sprintf_f_check_1_6);
  tcase_add_test(tc_core, sprintf_f_check_1_7);
  tcase_add_test(tc_core, sprintf_f_check_1_8);
  tcase_add_test(tc_core, sprintf_f_check_1_9);
  tcase_add_test(tc_core, sprintf_f_check_1_10);
  tcase_add_test(tc_core, sprintf_f_check_1_11);
  tcase_add_test(tc_core, sprintf_f_check_1_12);
  tcase_add_test(tc_core, sprintf_f_check_1);
  tcase_add_test(tc_core, sprintf_f_check_2);
  tcase_add_test(tc_core, sprintf_f_check_3);
  tcase_add_test(tc_core, sprintf_f_check_4);
  tcase_add_test(tc_core, sprintf_f_check_5);
  tcase_add_test(tc_core, sprintf_f_check_6);
  tcase_add_test(tc_core, sprintf_f_check_7);
  tcase_add_test(tc_core, sprintf_f_check_8);
  tcase_add_test(tc_core, sprintf_f_check_9);
  tcase_add_test(tc_core, sprintf_f_check_10);
  tcase_add_test(tc_core, sprintf_f_check_11);
  tcase_add_test(tc_core, sprintf_f_check_12);
  tcase_add_test(tc_core, sprintf_f_check_13);
  tcase_add_test(tc_core, sprintf_f_check_14);
  tcase_add_test(tc_core, sprintf_f_check_15);
  tcase_add_test(tc_core, sprintf_f_check_16);
  tcase_add_test(tc_core, sprintf_f_check_17);
  tcase_add_test(tc_core, sprintf_f_check_18);
  tcase_add_test(tc_core, sprintf_f_check_19);
  tcase_add_test(tc_core, sprintf_f_check_20);
  tcase_add_test(tc_core, sprintf_f_check_21);
  tcase_add_test(tc_core, sprintf_f_check_22);
  tcase_add_test(tc_core, sprintf_f_check_23);
  tcase_add_test(tc_core, sprintf_f_check_24);
  tcase_add_test(tc_core, sprintf_f_check_25);
  tcase_add_test(tc_core, sprintf_f_check_26);
  tcase_add_test(tc_core, sprintf_f_check_27);
  tcase_add_test(tc_core, sprintf_f_check_28);
  tcase_add_test(tc_core, sprintf_f_check_29);
  tcase_add_test(tc_core, sprintf_f_check_30);
  tcase_add_test(tc_core, sprintf_f_check_31);
  tcase_add_test(tc_core, sprintf_f_check_32);
  tcase_add_test(tc_core, sprintf_f_check_33);
  tcase_add_test(tc_core, sprintf_f_check_34);
  tcase_add_test(tc_core, sprintf_f_check_35);
  tcase_add_test(tc_core, sprintf_f_check_36);
  tcase_add_test(tc_core, sprintf_f_check_37);
  tcase_add_test(tc_core, sprintf_f_check_38);
  tcase_add_test(tc_core, sprintf_f_check_39);
  tcase_add_test(tc_core, sprintf_f_check_40);
  tcase_add_test(tc_core, sprintf_f_check_41);
  tcase_add_test(tc_core, sprintf_f_check_42);
  tcase_add_test(tc_core, sprintf_f_check_43);
  tcase_add_test(tc_core, sprintf_f_check_44);
  tcase_add_test(tc_core, sprintf_f_check_45);
  tcase_add_test(tc_core, sprintf_f_check_46);
  tcase_add_test(tc_core, sprintf_f_check_47);
  tcase_add_test(tc_core, sprintf_f_check_48);
  tcase_add_test(tc_core, sprintf_f_check_49);
  tcase_add_test(tc_core, sprintf_f_check_50);
  tcase_add_test(tc_core, sprintf_f_check_51);
  tcase_add_test(tc_core, sprintf_f_check_52);
  tcase_add_test(tc_core, sprintf_f_check_53);
  tcase_add_test(tc_core, sprintf_f_check_54);
  tcase_add_test(tc_core, sprintf_f_check_55);
  tcase_add_test(tc_core, sprintf_f_check_56);
  tcase_add_test(tc_core, sprintf_f_check_57);
  tcase_add_test(tc_core, sprintf_f_check_58);
  tcase_add_test(tc_core, sprintf_f_check_59);
  tcase_add_test(tc_core, sprintf_f_check_60);
  tcase_add_test(tc_core, sprintf_f_check_61);
  tcase_add_test(tc_core, sprintf_f_check_62);
  tcase_add_test(tc_core, sprintf_f_check_63);
  tcase_add_test(tc_core, sprintf_f_check_64);
  tcase_add_test(tc_core, sprintf_f_check_65);
  tcase_add_test(tc_core, sprintf_f_check_66);
  tcase_add_test(tc_core, sprintf_f_check_67);
  tcase_add_test(tc_core, sprintf_f_check_68);
  tcase_add_test(tc_core, sprintf_f_check_69);
  tcase_add_test(tc_core, sprintf_f_check_70);
  tcase_add_test(tc_core, sprintf_f_check_71);
  tcase_add_test(tc_core, sprintf_f_check_72);
  tcase_add_test(tc_core, sprintf_f_check_73);
  tcase_add_test(tc_core, sprintf_f_check_74);
  tcase_add_test(tc_core, sprintf_f_check_75);
  tcase_add_test(tc_core, sprintf_f_check_76);
  tcase_add_test(tc_core, sprintf_f_check_77);
  tcase_add_test(tc_core, sprintf_f_check_78);
  tcase_add_test(tc_core, sprintf_f_check_79);
  tcase_add_test(tc_core, sprintf_f_check_80);
  tcase_add_test(tc_core, sprintf_f_check_81);
  tcase_add_test(tc_core, sprintf_f_check_82);
  tcase_add_test(tc_core, sprintf_f_check_83);
  tcase_add_test(tc_core, sprintf_f_check_84);
  tcase_add_test(tc_core, sprintf_f_check_85);
  tcase_add_test(tc_core, sprintf_f_check_86);
  tcase_add_test(tc_core, sprintf_f_check_87);
  tcase_add_test(tc_core, sprintf_f_check_88);
  tcase_add_test(tc_core, sprintf_f_check_89);
  tcase_add_test(tc_core, sprintf_f_check_90);
  tcase_add_test(tc_core, sprintf_f_check_91);
  tcase_add_test(tc_core, sprintf_f_check_92);
  tcase_add_test(tc_core, sprintf_f_check_93);
  tcase_add_test(tc_core, sprintf_f_check_94);
  tcase_add_test(tc_core, sprintf_f_check_95);
  tcase_add_test(tc_core, sprintf_f_check_96);
  tcase_add_test(tc_core, sprintf_f_check_97);
  tcase_add_test(tc_core, sprintf_f_check_98);
  tcase_add_test(tc_core, sprintf_f_check_99);
  tcase_add_test(tc_core, sprintf_f_check_100);
  tcase_add_test(tc_core, sprintf_f_check_101);
  tcase_add_test(tc_core, sprintf_f_check_102);
  tcase_add_test(tc_core, sprintf_f_check_103);
  tcase_add_test(tc_core, sprintf_f_check_104);
  tcase_add_test(tc_core, sprintf_f_check_105);
  tcase_add_test(tc_core, sprintf_f_check_106);
  tcase_add_test(tc_core, sprintf_f_check_107);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_f() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_f();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
