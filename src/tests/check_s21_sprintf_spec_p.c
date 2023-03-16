#include "check.h"

START_TEST(sprintf_p_check_0) {
  char test_str[] = "test=%p=%p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  // printf("%s, %s\n", str, str2);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_1) {
  char test_str[] = "test=%30p=%30p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_2) {
  char test_str[] = "test=%-30p=%-30p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_3) {
  char test_str[] = "test=%5p=%5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_4) {
  char test_str[] = "test=%-5p=%-5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, 50, &test_str, 50, &test_str);
  s21_sprintf(str2, test_str, 50, &test_str, 50, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_5) {
  char test_str[] = "test=%-15.5p=%-15.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_6) {
  char test_str[] = "test=%-5.15p=%-5.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_7) {
  char test_str[] = "test=%+5.5p=%+5.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_8) {
  char test_str[] = "test=%+5.5p=%+5.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_9) {
  char test_str[] = "test=%+.5p=%+.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_10) {
  char test_str[] = "test=%+5.p=%+5.p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_11) {
  char test_str[] = "test=%+.5p=%+.6p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_12) {
  char test_str[] = "test=%15.15p=%15.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_13) {
  char test_str[] = "test=%16.15p=%16.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_14) {
  char test_str[] = "test=%15.15p=%15.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_15) {
  char test_str[] = "test=%11.1p=%11.1p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_16) {
  char test_str[] = "test=%11.1p=%11.1p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_17) {
  char test_str[] = "test=%1.11p=%1.11p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_18) {
  char test_str[] = "test=%1.11p=%1.11p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_19) {
  char test_str[] = "test=%3.3p=%3.3p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_20) {
  char test_str[] = "test=%3.3p=%3.3p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_21) {
  char test_str[] = "test=%+3.3p=%+3.3p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_22) {
  char test_str[] = "test=%+3.3p=%+3.3p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_23) {
  char test_str[] = "test=%p%%=%p%%=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_24) {
  char test_str[] = "test=%.2p=%.2p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_25) {
  char test_str[] = "test=%+-2.2p=%-+2.2p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_26) {
  char test_str[] = "test=%+-2.2p=%-+2.2p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_27) {
  char test_str[] = "test=%-15.15p=%-15.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_28) {
  char test_str[] = "test=%-15.15p=%-15.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_29) {
  char test_str[] = "test=%-15.5p=%-15.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_30) {
  char test_str[] = "test=%-15.5p=%-15.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_31) {
  char test_str[] = "test=%-5.15p=%-5.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_32) {
  char test_str[] = "test=%-5.15p=%-5.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_33) {
  char test_str[] = "test=%-+5.5p=%+-5.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_34) {
  char test_str[] = "test=%-p%%\n=%-p%%\n=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_35) {
  char test_str[] = "test=%-.5p=%-.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_36) {
  char test_str[] = "test=%-5p=%-5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_37) {
  char test_str[] = "test=%-10p=%-10p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_38) {
  char test_str[] = "test=%+-5p=%-+5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_39) {
  char test_str[] = "test=%16.15p=%16.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_40) {
  char test_str[] = "test=% 5.5p=% 5.5p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_41) {
  char test_str[] = "test=%.15p=%.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_42) {
  char test_str[] = "test=%.15p=%.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_43) {
  char test_str[] = "test=%+.15p=%+.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_44) {
  char test_str[] = "test=%+.15p=%+.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_45) {
  char test_str[] = "test=%15.2p=%15.2p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_46) {
  char test_str[] = "test=%+15.2p=%+15.2p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_47) {
  char test_str[] = "test=%+15.2p=%+15.2p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_48) {
  char test_str[] = "test=%15.12p=%15.12p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_49) {
  char test_str[] = "test=%-.11p=%.11p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_50) {
  char test_str[] = "test=%+.10p=%+.10p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_51) {
  char test_str[] = "test=%+-.10p=%-+.10p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_52) {
  char test_str[] = "test=%+-.13p=%-+.13p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_53) {
  char test_str[] = "test=%+050p=%+050p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_54) {
  char test_str[] = "test=%+-13.8p=%-+13.8p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_55) {
  char test_str[] = "test=%+-13.8p=%-+13.8p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_56) {
  char test_str[] = "test=%+-13.8p=%-+13.8p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_57) {
  char test_str[] = "test=%+15.13p=%+15.13p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_58) {
  char test_str[] = "test=%+-15.15p=%-+15.15p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_59) {
  char test_str[] = "test=%+-13.10p=%-+13.10p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, &test_str, &test_str);
  s21_sprintf(str2, test_str, &test_str, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_60) {
  char test_str[] = "test=%+-*.10p=%-+*.10p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, &test_str, MAX_WIDTH_D, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, &test_str, MAX_WIDTH_D, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_61) {
  char test_str[] = "test=%+-13.*p=%-+13.*p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, &test_str, MAX_WIDTH_D, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, &test_str, MAX_WIDTH_D, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_62) {
  char test_str[] = "test=%+-*.*p=%-+*.*p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_63) {
  char test_str[] = "test=%+-*.*p=%-+*.*p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str,
          MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str,
              MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_64) {
  char test_str[] = "test=%0+-*.*p=%0-+*.*p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str,
          MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str,
              MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_65) {
  char test_str[] = "test=% -*.*p=% -*.*p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str,
          MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str,
              MAX_WIDTH_D + 10, MAX_WIDTH_D, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_66) {
  char test_str[] = "test=% +-*.*p=% -+*.*p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_67) {
  char test_str[] = "test=%+-0*.*p=%-+0*.*p=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_68) {
  char test_str[] = "test=%+-0*.*hp=%-+0*.*lp=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_WIDTH_D, MAX_WIDTH_D + 10, &test_str, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, &test_str);
  s21_sprintf(str2, test_str, MIN_WIDTH_D, MAX_WIDTH_D + 10, &test_str,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_69) {
  char test_str[] = "test=%+-0*.*Lp=%-+0*.*lp=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str, MIN_WIDTH_D,
          MAX_WIDTH_D + 10, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str,
              MIN_WIDTH_D, MAX_WIDTH_D + 10, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_70) {
  char test_str[] = "test=%+-0*.*Lp=%-+0*.*lp=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str, MAX_WIDTH_D,
          MAX_WIDTH_D + 10, &test_str);
  s21_sprintf(str2, test_str, MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str,
              MAX_WIDTH_D, MAX_WIDTH_D + 10, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_71) {
  char test_str[] = "test=%+0*.*Lp=%+0*.*lp=test";
  char *str = (char *)calloc(SIZE_STR, sizeof(char));
  char *str2 = (char *)calloc(SIZE_STR, sizeof(char));
  sprintf(str, test_str, MIN_WIDTH_D, MIN_WIDTH_D, &test_str, MIN_WIDTH_D,
          MIN_WIDTH_D, &test_str);
  s21_sprintf(str2, test_str, MIN_WIDTH_D, MIN_WIDTH_D, &test_str, MIN_WIDTH_D,
              MIN_WIDTH_D, &test_str);
  ck_assert_str_eq(str, str2);
  output3(str, str2, test_str, test_str);
  free(str);
  free(str2);
}
END_TEST
START_TEST(sprintf_p_check_72) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*p", 5, (void *)888888);
  sprintf(std, "%*p", 5, (void *)888888);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_p_check_73) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%p", (void *)888888);
  sprintf(std, "%p", (void *)888888);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_p_check_74) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%*p", 5, (void *)888888);
  sprintf(std, "%*p", 5, (void *)888888);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_p_check_75) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%p", (void *)888888);
  sprintf(std, "%p", (void *)888888);
  ck_assert_str_eq(std, s21);
}
END_TEST
Suite *suite_s21_sprintf_spec_p(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator %p");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_p_check_0);
  tcase_add_test(tc_core, sprintf_p_check_1);
  tcase_add_test(tc_core, sprintf_p_check_2);
  tcase_add_test(tc_core, sprintf_p_check_3);
  tcase_add_test(tc_core, sprintf_p_check_4);
  tcase_add_test(tc_core, sprintf_p_check_5);
  tcase_add_test(tc_core, sprintf_p_check_6);
  tcase_add_test(tc_core, sprintf_p_check_7);
  tcase_add_test(tc_core, sprintf_p_check_8);
  tcase_add_test(tc_core, sprintf_p_check_9);
  tcase_add_test(tc_core, sprintf_p_check_10);
  tcase_add_test(tc_core, sprintf_p_check_11);
  tcase_add_test(tc_core, sprintf_p_check_12);
  tcase_add_test(tc_core, sprintf_p_check_13);
  tcase_add_test(tc_core, sprintf_p_check_14);
  tcase_add_test(tc_core, sprintf_p_check_15);
  tcase_add_test(tc_core, sprintf_p_check_16);
  tcase_add_test(tc_core, sprintf_p_check_17);
  tcase_add_test(tc_core, sprintf_p_check_18);
  tcase_add_test(tc_core, sprintf_p_check_19);
  tcase_add_test(tc_core, sprintf_p_check_20);
  tcase_add_test(tc_core, sprintf_p_check_21);
  tcase_add_test(tc_core, sprintf_p_check_22);
  tcase_add_test(tc_core, sprintf_p_check_23);
  tcase_add_test(tc_core, sprintf_p_check_24);
  tcase_add_test(tc_core, sprintf_p_check_25);
  tcase_add_test(tc_core, sprintf_p_check_26);
  tcase_add_test(tc_core, sprintf_p_check_27);
  tcase_add_test(tc_core, sprintf_p_check_28);
  tcase_add_test(tc_core, sprintf_p_check_29);
  tcase_add_test(tc_core, sprintf_p_check_30);
  tcase_add_test(tc_core, sprintf_p_check_31);
  tcase_add_test(tc_core, sprintf_p_check_32);
  tcase_add_test(tc_core, sprintf_p_check_33);
  tcase_add_test(tc_core, sprintf_p_check_34);
  tcase_add_test(tc_core, sprintf_p_check_35);
  tcase_add_test(tc_core, sprintf_p_check_36);
  tcase_add_test(tc_core, sprintf_p_check_37);
  tcase_add_test(tc_core, sprintf_p_check_38);
  tcase_add_test(tc_core, sprintf_p_check_39);
  tcase_add_test(tc_core, sprintf_p_check_40);
  tcase_add_test(tc_core, sprintf_p_check_41);
  tcase_add_test(tc_core, sprintf_p_check_42);
  tcase_add_test(tc_core, sprintf_p_check_43);
  tcase_add_test(tc_core, sprintf_p_check_44);
  tcase_add_test(tc_core, sprintf_p_check_45);
  tcase_add_test(tc_core, sprintf_p_check_46);
  tcase_add_test(tc_core, sprintf_p_check_47);
  tcase_add_test(tc_core, sprintf_p_check_48);
  tcase_add_test(tc_core, sprintf_p_check_49);
  tcase_add_test(tc_core, sprintf_p_check_50);
  tcase_add_test(tc_core, sprintf_p_check_51);
  tcase_add_test(tc_core, sprintf_p_check_52);
  tcase_add_test(tc_core, sprintf_p_check_53);
  tcase_add_test(tc_core, sprintf_p_check_54);
  tcase_add_test(tc_core, sprintf_p_check_55);
  tcase_add_test(tc_core, sprintf_p_check_56);
  tcase_add_test(tc_core, sprintf_p_check_57);
  tcase_add_test(tc_core, sprintf_p_check_58);
  tcase_add_test(tc_core, sprintf_p_check_59);
  tcase_add_test(tc_core, sprintf_p_check_60);
  tcase_add_test(tc_core, sprintf_p_check_61);
  tcase_add_test(tc_core, sprintf_p_check_62);
  tcase_add_test(tc_core, sprintf_p_check_63);
  tcase_add_test(tc_core, sprintf_p_check_64);
  tcase_add_test(tc_core, sprintf_p_check_65);
  tcase_add_test(tc_core, sprintf_p_check_66);
  tcase_add_test(tc_core, sprintf_p_check_67);
  tcase_add_test(tc_core, sprintf_p_check_68);
  tcase_add_test(tc_core, sprintf_p_check_69);
  tcase_add_test(tc_core, sprintf_p_check_70);
  tcase_add_test(tc_core, sprintf_p_check_71);
  tcase_add_test(tc_core, sprintf_p_check_72);
  tcase_add_test(tc_core, sprintf_p_check_73);
  tcase_add_test(tc_core, sprintf_p_check_74);
  tcase_add_test(tc_core, sprintf_p_check_75);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_p() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_p();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
