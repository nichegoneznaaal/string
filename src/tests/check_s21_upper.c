#include "check.h"

START_TEST(to_upper_1) {
  char str1[15] = "dangeon Master";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "DANGEON MASTER");
  free(str2);
}
END_TEST

START_TEST(to_upper_2) {
  char str1[20] = "BOY next door";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "BOY NEXT DOOR");
  free(str2);
}
END_TEST

START_TEST(to_upper_3) {
  char str1[15] = "MEIBY BEIBY";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "MEIBY BEIBY");
  free(str2);
}
END_TEST

START_TEST(to_upper_4) {
  char str1[20] = "hello\0oooo";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "HELLO");
  free(str2);
}
END_TEST

START_TEST(to_upper_5) {
  char str1[15] = "";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_upper_6) {
  char str1[20] = "\0HELLO";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_upper_7) {
  char *str1 = S21_NULL;
  char *str2 = s21_to_upper(str1);
  ck_assert_ptr_eq(str2, S21_NULL);
  free(str2);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s21 = S21_NULL;
  TCase *tc21 = S21_NULL;
  s21 = suite_create("s21_TO_UPPER");
  tc21 = tcase_create("case_to_upper");
  tcase_add_test(tc21, to_upper_1);
  tcase_add_test(tc21, to_upper_2);
  tcase_add_test(tc21, to_upper_3);
  tcase_add_test(tc21, to_upper_4);
  tcase_add_test(tc21, to_upper_5);
  tcase_add_test(tc21, to_upper_6);
  tcase_add_test(tc21, to_upper_7);
  suite_add_tcase(s21, tc21);
  return s21;
};

int check_s21_upper() {
  int no_failed = 0;
  Suite *s = S21_NULL;
  SRunner *runner = S21_NULL;

  s = suite_to_upper();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
