#include "check.h"

START_TEST(sprintf_f2_check_0) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%F %F", 10000.10001, 0.0000001);
  sprintf(std, "%F %F", 10000.10001, 0.0000001);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f2_check_1) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%LF %LF", (long double)10000.10001, (long double)0.0000001);
  sprintf(std, "%LF %LF", (long double)10000.10001, (long double)0.0000001);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f2_check_2) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%F %F", 10000.10001, 0.0000001);
  sprintf(std, "%F %F", 10000.10001, 0.0000001);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_f2_check_3) {
  char std[4096];
  char s21[4096];
  s21_sprintf(s21, "%LF %LF", (long double)10000.10001, (long double)0.0000001);
  sprintf(std, "%LF %LF", (long double)10000.10001, (long double)0.0000001);
  ck_assert_str_eq(std, s21);
}
END_TEST
Suite *suite_s21_sprintf_spec_f2(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator %F");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_f2_check_0);
  tcase_add_test(tc_core, sprintf_f2_check_1);
  tcase_add_test(tc_core, sprintf_f2_check_2);
  tcase_add_test(tc_core, sprintf_f2_check_3);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_f2() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_f2();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
