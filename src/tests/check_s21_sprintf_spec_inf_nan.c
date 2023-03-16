#include "check.h"

START_TEST(sprintf_inf_check_0) {
  char std[4096];
  char s21[4096];
  uint64_t infPlus = 0x7ff0000000000000ull;
  sprintf(std, "%g %f %e", *(double *)&infPlus, *(double *)&infPlus,
          *(double *)&infPlus);
  s21_sprintf(s21, "%g %f %e", *(double *)&infPlus, *(double *)&infPlus,
              *(double *)&infPlus);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_inf_check_1) {
  char std[4096];
  char s21[4096];
  uint64_t infPlus = 0x7ff0000000000000ull;
  sprintf(std, "%g %f %e", *(double *)&infPlus, *(double *)&infPlus,
          *(double *)&infPlus);
  s21_sprintf(s21, "%g %f %e", *(double *)&infPlus, *(double *)&infPlus,
              *(double *)&infPlus);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_inf_check_2) {
  char std[4096];
  char s21[4096];
  uint64_t infMinus = 0xfff0000000000000ull;
  sprintf(std, "%g %f %e", *(double *)&infMinus, *(double *)&infMinus,
          *(double *)&infMinus);
  s21_sprintf(s21, "%g %f %e", *(double *)&infMinus, *(double *)&infMinus,
              *(double *)&infMinus);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_nan_check_3) {
  char std[4096];
  char s21[4096];
  uint64_t nanPlus = 0x7ff8000000000000ull;
  sprintf(std, "%g %f %e", *(double *)&nanPlus, *(double *)&nanPlus,
          *(double *)&nanPlus);
  s21_sprintf(s21, "%g %f %e", *(double *)&nanPlus, *(double *)&nanPlus,
              *(double *)&nanPlus);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_nan_check_4) {
  char std[4096];
  char s21[4096];
  uint64_t nanMinus = 0xfff8000000000000ull;
  sprintf(std, "%g %f %e", *(double *)&nanMinus, *(double *)&nanMinus,
          *(double *)&nanMinus);
  s21_sprintf(s21, "%g %f %e", *(double *)&nanMinus, *(double *)&nanMinus,
              *(double *)&nanMinus);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_inf_check_5) {
  char std[4096];
  char s21[4096];
  uint64_t infPlus = 0x7ff0000000000000ull;
  sprintf(std, "%g %f %e", *(double *)&infPlus, *(double *)&infPlus,
          *(double *)&infPlus);
  s21_sprintf(s21, "%g %f %e", *(double *)&infPlus, *(double *)&infPlus,
              *(double *)&infPlus);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_inf_check_6) {
  char std[4096];
  char s21[4096];
  uint64_t infMinus = 0xfff0000000000000ull;
  sprintf(std, "%g %f %e", *(double *)&infMinus, *(double *)&infMinus,
          *(double *)&infMinus);
  s21_sprintf(s21, "%g %f %e", *(double *)&infMinus, *(double *)&infMinus,
              *(double *)&infMinus);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_nan_check_7) {
  char std[4096];
  char s21[4096];
  uint64_t nanPlus = 0x7ff8000000000000ull;
  sprintf(std, "%g %f %e", *(double *)&nanPlus, *(double *)&nanPlus,
          *(double *)&nanPlus);
  s21_sprintf(s21, "%g %f %e", *(double *)&nanPlus, *(double *)&nanPlus,
              *(double *)&nanPlus);
  ck_assert_str_eq(std, s21);
}
END_TEST
START_TEST(sprintf_nan_check_8) {
  uint64_t nanMinus = 0xfff8000000000000ull;
  char std[4096];
  char s21[4096];
  sprintf(std, "%g %f %e", *(double *)&nanMinus, *(double *)&nanMinus,
          *(double *)&nanMinus);
  s21_sprintf(s21, "%g %f %e", *(double *)&nanMinus, *(double *)&nanMinus,
              *(double *)&nanMinus);
  ck_assert_str_eq(std, s21);
}
END_TEST
Suite *suite_s21_sprintf_spec_inf_nan(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;
  s = suite_create("S21 sprintf specificator inf nan");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_inf_check_0);
  tcase_add_test(tc_core, sprintf_inf_check_1);
  tcase_add_test(tc_core, sprintf_inf_check_2);
  tcase_add_test(tc_core, sprintf_nan_check_3);
  tcase_add_test(tc_core, sprintf_nan_check_4);
  tcase_add_test(tc_core, sprintf_inf_check_5);
  tcase_add_test(tc_core, sprintf_inf_check_6);
  tcase_add_test(tc_core, sprintf_nan_check_7);
  tcase_add_test(tc_core, sprintf_nan_check_8);
  suite_add_tcase(s, tc_core);
  return s;
}
int check_s21_sprintf_spec_inf_nan() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = suite_s21_sprintf_spec_inf_nan();
  runner = srunner_create(s);

#ifdef TEST_LEAK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif  // TEST_LEAK
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
