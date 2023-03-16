#include "check.h"

START_TEST(to_insert_) {
  char *str1 = S21_NULL;
  char *str2 = "Billy and ";
  char *str3 = s21_insert(str1, str2, 0);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST
START_TEST(to_insert_1) {
  char *str1 = "dangeon Master";
  char *str2 = "Billy and ";
  char *str3 = s21_insert(str1, str2, 0);
  ck_assert_str_eq(str3, "Billy and dangeon Master");
  free(str3);
}
END_TEST

START_TEST(to_insert_2) {
  char *str1 = "aaabbb";
  char *str2 = " ";
  char *str3 = s21_insert(str1, str2, 3);
  ck_assert_str_eq(str3, "aaa bbb");
  free(str3);
}
END_TEST

START_TEST(to_insert_3) {
  char *str1 = "abc";
  char *str2 = "def";
  char *str3 = s21_insert(str1, str2, 1);
  ck_assert_str_eq(str3, "adefbc");
  free(str3);
}
END_TEST

START_TEST(to_insert_4) {
  char *str1 = "abc\0hello";
  char *str2 = "1";
  char *str3 = s21_insert(str1, str2, 2);
  ck_assert_str_eq(str3, "ab1c");
  free(str3);
}
END_TEST

START_TEST(to_insert_5) {
  char *str1 = "\0w1111222f333";
  char *str2 = "132f";
  char *str3 = s21_insert(str1, str2, 2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(to_insert_6) {
  char *str1 = "fartLOUV";
  char *str2 = "NO";
  char *str3 = s21_insert(str1, str2, 8);
  ck_assert_str_eq(str3, "fartLOUVNO");
  free(str3);
}
END_TEST

START_TEST(to_insert_7) {
  char *str1 = "NO";
  char *str2 = "YES";
  char *str3 = s21_insert(str1, str2, 3);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(to_insert_8) {
  char *str1 = "/0/0/0\0a111";
  char *str2 = "";
  char *str3 = s21_insert(str1, str2, 2);
  ck_assert_str_eq(str3, "/0/0/0");
  free(str3);
}
END_TEST

START_TEST(to_insert_9) {
  char *str1 = "/0/0/0\0a111";
  char *str2 = "ppp";
  char *str3 = s21_insert(str1, str2, 4);
  ck_assert_str_eq(str3, "/0/0ppp/0");
  free(str3);
}
END_TEST

START_TEST(to_insert_10) {
  char *str1 = "WHO IS \0JOHN GOLT";
  char *str2 = "JOHN GOLT\0";
  char *str3 = s21_insert(str1, str2, 6);
  ck_assert_str_eq(str3, "WHO ISJOHN GOLT ");
  free(str3);
}
END_TEST

START_TEST(to_insert_11) {
  char str1[80] = "Abcde";
  char str2[80] = "123";
  s21_size_t index = 3;
  char *res = s21_insert(str1, str2, index);
  ck_assert_str_eq(res, "Abc123de");
  if (res) free(res);
}
END_TEST

START_TEST(to_insert_12) {
  char str1[80] = "Abcde";
  char str2[80] = "123";
  s21_size_t index = 4;
  char *res = s21_insert(str1, str2, index);
  ck_assert_str_eq(res, "Abcd123e");
  if (res) free(res);
}
END_TEST

START_TEST(to_insert_13) {
  char str1[80] = "Abcde";
  char str2[80] = "123";
  s21_size_t index = 5;
  char *res = s21_insert(str1, str2, index);
  ck_assert_str_eq(res, "Abcde123");
  if (res) free(res);
}
END_TEST

START_TEST(to_insert_14) {
  char str1[80] = "Abcde";
  char str2[80] = "123";
  s21_size_t index = 6;
  char *res = s21_insert(str1, str2, index);
  ck_assert_ptr_eq(res, S21_NULL);
  if (res) free(res);
}
END_TEST

START_TEST(to_insert_15) {
  char str1[80] = "Abcde";
  char str2[80] = "123";
  s21_size_t index = -1;
  char *res = s21_insert(str1, str2, index);
  ck_assert_ptr_eq(res, S21_NULL);
  if (res) free(res);
}
END_TEST

START_TEST(to_insert_16) {
  char str1[80] = "";
  char str2[80] = " 1 ";
  s21_size_t index = 0;
  char *res = s21_insert(str1, str2, index);
  ck_assert_str_eq(res, " 1 ");
  if (res) free(res);
}
END_TEST

START_TEST(to_insert_17) {
  char str1[80] = " S   p a s   e s ";
  char str2[80] = "  i n ser  t ";
  s21_size_t index = 10;
  char *res = s21_insert(str1, str2, index);
  ck_assert_str_eq(res, " S   p a s  i n ser  t    e s ");
  if (res) free(res);
}
END_TEST

START_TEST(to_insert_18) {
  char str1[80] = "asd\0fgh";
  char str2[80] = "123";
  s21_size_t index = 3;
  char *res = s21_insert(str1, str2, index);
  ck_assert_str_eq(res, "asd123");
  if (res) free(res);
}
END_TEST

START_TEST(to_insert_19) {
  char str1[80] = "asd\0fgh";
  char str2[80] = "123";
  s21_size_t index = 4;
  char *res = s21_insert(str1, str2, index);
  ck_assert_ptr_eq(res, S21_NULL);
  if (res) free(res);
}
END_TEST

Suite *suite_to_insert(void) {
  Suite *s21 = S21_NULL;
  TCase *tc21 = S21_NULL;
  s21 = suite_create("s21_TO_insert");
  tc21 = tcase_create("case_to_insert");
  tcase_add_test(tc21, to_insert_);
  tcase_add_test(tc21, to_insert_1);
  tcase_add_test(tc21, to_insert_2);
  tcase_add_test(tc21, to_insert_3);
  tcase_add_test(tc21, to_insert_4);
  tcase_add_test(tc21, to_insert_5);
  tcase_add_test(tc21, to_insert_6);
  tcase_add_test(tc21, to_insert_7);
  tcase_add_test(tc21, to_insert_8);
  tcase_add_test(tc21, to_insert_9);
  tcase_add_test(tc21, to_insert_10);
  tcase_add_test(tc21, to_insert_11);
  tcase_add_test(tc21, to_insert_12);
  tcase_add_test(tc21, to_insert_13);
  tcase_add_test(tc21, to_insert_14);
  tcase_add_test(tc21, to_insert_15);
  tcase_add_test(tc21, to_insert_16);
  tcase_add_test(tc21, to_insert_17);
  tcase_add_test(tc21, to_insert_18);
  tcase_add_test(tc21, to_insert_19);
  suite_add_tcase(s21, tc21);
  return s21;
};

int check_s21_insert() {
  int no_failed = 0;
  Suite *s = S21_NULL;
  SRunner *runner = S21_NULL;

  s = suite_to_insert();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
