#ifndef SRC_CHECK_H_
#define SRC_CHECK_H_
#include <check.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#define MAX_WIDTH_D 20
#define MIN_WIDTH_D -10
#define MAX_ACC_F 15
#define MIN_ACC_F -10
#define MIN_F_L (long double)-100.100
#define MAX_F_L (long double)100.100
#define MIN_F -100.100
#define MAX_F 100.100
#define FLOAT 50.1234567890
#define FLOAT2 0.999
#define SIZE_STR 1000000

int check_s21_sprintf_spec_d();
int check_s21_sprintf_spec_i();
int check_s21_sprintf_spec_f();
int check_s21_sprintf_spec_f2();
int check_s21_sprintf_spec_u();
int check_s21_sprintf_spec_c();
int check_s21_sprintf_spec_s();
int check_s21_sprintf_spec_p();
int check_s21_sprintf_spec_o();
int check_s21_sprintf_spec_x();
int check_s21_sprintf_spec_x2();
int check_s21_sprintf_spec_e();
int check_s21_sprintf_spec_e2();
int check_s21_sprintf_spec_g();
int check_s21_sprintf_spec_g2();
int check_s21_sprintf_spec_n();
int check_s21_sprintf_spec_inf_nan();
int check_s21_sprintf_spec_other();
int check_s21_upper();
int check_s21_lower();
int check_s21_trim();
int check_s21_insert();
int check_s21_sscanf();
int check_gigacheck_string();
int test_sscanf2();

void output(char *str, char *str2, char *test_str, int test_int);
void output2(char *str, char *str2, char *test_str, char *test_int);
void output3(char *str, char *str2, char *test_str, char *test_int);

#endif  // SRC_CHECK_H_
