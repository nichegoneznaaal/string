#include "check.h"

START_TEST(to_trim_) {
  char *str1 = S21_NULL;
  char *str2 = "daR";
  char *str3 = s21_trim(str1, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST
START_TEST(to_trim_1) {
  char *str1 = "dangeon Master";
  char *str2 = "daR";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ngeon Master");
  free(str3);
}
END_TEST

START_TEST(to_trim_2) {
  char *str1 = "Remdiggar999";
  char *str2 = "daR920";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "emdiggar");
  free(str3);
}
END_TEST

START_TEST(to_trim_3) {
  char *str1 = "           Remdiggar999";
  char *str2 = "daR920 ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "emdiggar");
  free(str3);
}
END_TEST

START_TEST(to_trim_4) {
  char *str1 = "1111222\0f333";
  char *str2 = "1";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "222");
  free(str3);
}
END_TEST

START_TEST(to_trim_5) {
  char *str1 = "\0w1111222f333";
  char *str2 = "132f";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(to_trim_6) {
  char *str1 = "fartLOUV";
  char *str2 = "";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "fartLOUV");
  free(str3);
}
END_TEST

START_TEST(to_trim_7) {
  char *str1 = " fartLOUV";
  char *str2 = "";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "fartLOUV");
  free(str3);
}
END_TEST

START_TEST(to_trim_8) {
  char *str1 = "fartLOUV ";
  char *str2 = "";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "fartLOUV");
  free(str3);
}
END_TEST

START_TEST(to_trim_9) {
  char *str1 = " fartLOUV ";
  char *str2 = "";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "fartLOUV");
  free(str3);
}
END_TEST

START_TEST(to_trim_10) {
  char *str1 = " fartLOUV ";
  char *str2 = "";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "fartLOUV");
  free(str3);
}
END_TEST

START_TEST(to_trim_11) {
  char *str1 = " \t fartLOUV     ";
  char *str2 = "";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "fartLOUV");
  free(str3);
}
END_TEST

START_TEST(to_trim_12) {
  char *str1 = "     fa\0rtLOUV ";
  char *str2 = "";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "fa");
  free(str3);
}
END_TEST

START_TEST(to_trim_13) {
  char *str1 = " fartLOUV ";
  char *str2 = S21_NULL;
  char *str3 = s21_trim(str1, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(to_trim_14) {
  char *str1 = S21_NULL;
  char *str2 = "7gnr";
  char *str3 = s21_trim(str1, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(to_trim_15) {
  char *str1 = " abc123abc_";
  char *str2 = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, " abc123abc_");
  free(str3);
}
END_TEST

START_TEST(to_trim_16) {
  char *str1 = "";
  char *str2 = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(to_trim_17) {
  char *str1 = " spases ";
  char *str2 = "";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "spases");
  free(str3);
}
END_TEST

START_TEST(to_trim_18) {
  char *str1 = " spases ";
  char *str2 = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "spases");
  free(str3);
}
END_TEST

START_TEST(to_trim_19) {
  char *str1 = "                  Too many SpaSes        ";
  char *str2 = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "Too many SpaSes");
  free(str3);
}
END_TEST

START_TEST(to_trim_20) {
  char *str1 = "MEIBY_BEIBY";
  char *str2 = "MEIBY_BEIBY";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(to_trim_21) {
  char *str1 = "123123123";
  char *str2 = "321";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(to_trim_22) {
  char *str1 = "12312.3123";
  char *str2 = "321";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, ".");
  free(str3);
}
END_TEST

START_TEST(to_trim_23) {
  char *str1 = "Hello\0 World!";
  char *str2 = "oH";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ell");
  free(str3);
}
END_TEST

START_TEST(to_trim_24) {
  char *str1 = "Hello World!";
  char *str2 = "12b";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "Hello World!");
  free(str3);
}
END_TEST

START_TEST(to_trim_25) {
  char *str1 = "Hello World!";
  char *str2 = "Ho";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ello World!");
  free(str3);
}
END_TEST

Suite *suite_to_trim(void) {
  Suite *s21 = S21_NULL;
  TCase *tc21 = S21_NULL;
  s21 = suite_create("s21_TO_trim");
  tc21 = tcase_create("case_to_trim");
  tcase_add_test(tc21, to_trim_);
  tcase_add_test(tc21, to_trim_1);
  tcase_add_test(tc21, to_trim_2);
  tcase_add_test(tc21, to_trim_3);
  tcase_add_test(tc21, to_trim_4);
  tcase_add_test(tc21, to_trim_5);
  tcase_add_test(tc21, to_trim_6);
  tcase_add_test(tc21, to_trim_7);
  tcase_add_test(tc21, to_trim_8);
  tcase_add_test(tc21, to_trim_9);
  tcase_add_test(tc21, to_trim_10);
  tcase_add_test(tc21, to_trim_11);
  tcase_add_test(tc21, to_trim_12);
  tcase_add_test(tc21, to_trim_13);
  tcase_add_test(tc21, to_trim_14);
  tcase_add_test(tc21, to_trim_15);
  tcase_add_test(tc21, to_trim_16);
  tcase_add_test(tc21, to_trim_17);
  tcase_add_test(tc21, to_trim_18);
  tcase_add_test(tc21, to_trim_19);
  tcase_add_test(tc21, to_trim_20);
  tcase_add_test(tc21, to_trim_21);
  tcase_add_test(tc21, to_trim_22);
  tcase_add_test(tc21, to_trim_23);
  tcase_add_test(tc21, to_trim_24);
  tcase_add_test(tc21, to_trim_25);
  suite_add_tcase(s21, tc21);
  return s21;
};

int check_s21_trim() {
  int no_failed = 0;
  Suite *s = S21_NULL;
  SRunner *runner = S21_NULL;

  s = suite_to_trim();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
