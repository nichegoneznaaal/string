#include "check.h"

START_TEST(sprintf_r_check_0_0) {
  char s21[4096];
  char std[4096];
  int res1 = s21_sprintf(std, "%% ' '");
  int res2 = s21_sprintf(s21, "%% ' '");
  ck_assert_str_eq(std, s21);
  ck_assert_int_eq(res1, res2);
}
END_TEST
START_TEST(sprintf_r_check_0) {
  char s21[4096];
  s21_sprintf(s21, "%r", 1);
  ck_assert_str_eq(s21, "r");
}
END_TEST
START_TEST(sprintf_r_check_1) {
  char s21[4096];
  s21_sprintf(s21, "%r", "r");
  ck_assert_str_eq(s21, "r");
}
END_TEST
START_TEST(sprintf_r_check_2) {
  char s21[4096];
  s21_sprintf(s21, "%r", 1);
  ck_assert_str_eq(s21, "r");
}
END_TEST
START_TEST(sprintf_r_check_3) {
  char s21[4096];
  s21_sprintf(s21, "%r", "r");
  ck_assert_str_eq(s21, "r");
}
END_TEST
Suite *suite_s21_sprintf_spec_other(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator other");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_r_check_0_0);
  tcase_add_test(tc_core, sprintf_r_check_0);
  tcase_add_test(tc_core, sprintf_r_check_1);
  tcase_add_test(tc_core, sprintf_r_check_2);
  tcase_add_test(tc_core, sprintf_r_check_3);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_other() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_other();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
