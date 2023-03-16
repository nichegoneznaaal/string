#include "check.h"

START_TEST(to_lower_77) {
  char *str1 = S21_NULL;
  char *str2 = s21_to_lower(str1);
  ck_assert_ptr_eq(str2, S21_NULL);
  free(str2);
}
END_TEST
START_TEST(to_lower_1) {
  char str1[15] = "DANGEON MASTER";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "dangeon master");
  free(str2);
}
END_TEST

START_TEST(to_lower_2) {
  char str1[20] = "BOY next door";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "boy next door");
  free(str2);
}
END_TEST

START_TEST(to_lower_3) {
  char str1[15] = "MEIBY BEIBY";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "meiby beiby");
  free(str2);
}
END_TEST

START_TEST(to_lower_4) {
  char str1[20] = "HELLO\0oooo";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "hello");
  free(str2);
}
END_TEST

START_TEST(to_lower_5) {
  char str1[15] = "";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_lower_6) {
  char str1[20] = "    ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "    ");
  free(str2);
}
END_TEST

START_TEST(to_lower_7) {
  char str1[80] = "74^&$#@%12$!#%@#^8780";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "74^&$#@%12$!#%@#^8780");
  if (str2) free(str2);
}

START_TEST(to_lower_8) {
  char str1[80] = "74^&$#@%12$!#%@#^8780";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "74^&$#@%12$!#%@#^8780");
  if (str2) free(str2);
}

START_TEST(to_lower_9) {
  char str1[80] = "HELLO\nWORLD";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "hello\nworld");
  if (str2) free(str2);
}

Suite *suite_to_lower(void) {
  Suite *s21 = S21_NULL;
  TCase *tc21 = S21_NULL;
  s21 = suite_create("s21_TO_lower");
  tc21 = tcase_create("case_to_lower");
  tcase_add_test(tc21, to_lower_77);
  tcase_add_test(tc21, to_lower_1);
  tcase_add_test(tc21, to_lower_2);
  tcase_add_test(tc21, to_lower_3);
  tcase_add_test(tc21, to_lower_4);
  tcase_add_test(tc21, to_lower_5);
  tcase_add_test(tc21, to_lower_6);
  tcase_add_test(tc21, to_lower_7);
  tcase_add_test(tc21, to_lower_8);
  tcase_add_test(tc21, to_lower_9);
  suite_add_tcase(s21, tc21);
  return s21;
};

int check_s21_lower() {
  int no_failed = 0;
  Suite *s = S21_NULL;
  SRunner *runner = S21_NULL;

  s = suite_to_lower();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}