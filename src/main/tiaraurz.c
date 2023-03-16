#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_sprintf.h"
#include "../s21_string.h"
#include "../dependences.h"
#include "../s21_sscanf.h"
#include <check.h>

// в начале проверять есть ли пробелы и пропускать их до первого вхождения
// проверка на пустую строку

START_TEST(test_1) {
    char s[80] = {};
    char s2[80] = {};
    int res = s21_sscanf("Hello", "%s", s);
    int res2 = sscanf("Hello", "%s", s2);

    ck_assert_str_eq(s, s2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_2) {
    int dec = 21;
    int dec2 = 21;

    int res = s21_sscanf("0X78ED3", "%i", &dec);
    int res2 = sscanf("0X78ED3", "%i", &dec2);

    ck_assert_int_eq(dec, dec2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_3) {
    char c = 0;
    char c2 = 0;

    int res = s21_sscanf("0X78ED3", "%c", &c);
    int res2 = sscanf("0X78ED3", "%c", &c2);

    ck_assert_int_eq(c, c2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_4) {
    float f1 = 0;
    float f2 = 0;

    int res = s21_sscanf("4.5", "%f", &f1);
    int res2 = sscanf("4.5", "%f", &f2);

    ck_assert_float_eq(f1, f2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_5) {
    float f1 = 0;
    float f2 = 0;

    int res = s21_sscanf(".4.5", "%f", &f1);
    int res2 = sscanf(".4.5", "%f", &f2);

    ck_assert_float_eq(f1, f2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_6) {
    float f1 = 0;
    float f2 = 0;

    int res = s21_sscanf("4..5", "%f", &f1);
    int res2 = sscanf("4..5", "%f", &f2);

    ck_assert_float_eq(f1, f2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_7) {
    float f1 = 0;
    float f2 = 0;

    int res = s21_sscanf("//4..5", "%f", &f1);
    int res2 = sscanf("//4..5", "%f", &f2);

    ck_assert_float_eq(f1, f2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_8) {
    float f1 = 0;
    float f2 = 0;

    int res = s21_sscanf("5.rw", "%f", &f1);
    int res2 = sscanf("5.rw", "%f", &f2);

    ck_assert_float_eq(f1, f2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_9) {
    double f1 = 0;
    double f2 = 0;

    int res =
        s21_sscanf("5.000000000000000000000000000000000000004", "%lf", &f1);
    int res2 = sscanf("5.000000000000000000000000000000000000004", "%lf", &f2);

    ck_assert_double_eq(f1, f2);
    ck_assert_int_eq(res, res2);

    char orig_c = 0;
    char s21_c = 0;
    res = s21_sscanf("5.e345r", "%lf%c", &f1, &s21_c);
    res2 = sscanf("5.e345r", "%lf%c", &f2, &orig_c);

    ck_assert_double_eq(f1, f2);
    ck_assert_int_eq(orig_c, s21_c);
    ck_assert_int_eq(res, res2);

    res = s21_sscanf("1.0e256", "%lf", &f1);
    res2 = sscanf("1.0e256", "%lf", &f2);
    ck_assert_double_eq(f1, f2);
    ck_assert_int_eq(res, res2);

    res = s21_sscanf("e256", "%lf", &f1);
    res2 = sscanf("e256", "%lf", &f2);
    ck_assert_double_eq(f1, f2);
    ck_assert_int_eq(res, res2);

    res = s21_sscanf(".e256", "%lf", &f1);
    res2 = sscanf(".e256", "%lf", &f2);

    ck_assert_double_eq(f1, f2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_10) {
    int dec1 = 0;
    int dec2 = 0;

    int res = s21_sscanf("45434", "%d", &dec1);
    int res2 = sscanf("45434", "%d", &dec2);

    ck_assert_float_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_11) {
    int dec1 = 0;
    int dec2 = 0;

    int res = s21_sscanf("1000000000000000000", "%d", &dec1);
    int res2 = sscanf("1000000000000000000", "%d", &dec2);

    ck_assert_float_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_12) {
    int dec1 = 0;
    int dec2 = 0;

    int res = s21_sscanf("3.3", "%d", &dec1);
    int res2 = sscanf("3.3", "%d", &dec2);

    ck_assert_float_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_13) {
    long int dec1 = 0;
    long int dec2 = 0;

    int res = s21_sscanf("-100000000000000000L00", "%ld", &dec1);
    int res2 = sscanf("-100000000000000000L00", "%ld", &dec2);
    
    ck_assert_ldouble_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_14) {
    long int dec1 = 0;
    long int dec2 = 0;

    int res = s21_sscanf("-100000000000000000000000000L00", "%ld", &dec1);
    int res2 = sscanf("-100000000000000000000000000L00", "%ld", &dec2);

    ck_assert_ldouble_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);
    // printf("-----------------------------------\n");
    res = s21_sscanf("453223523", "%ld", &dec1);
    res2 = sscanf("453223523", "%ld", &dec2);

    ck_assert_ldouble_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_15) {
    unsigned int dec1 = 0;
    unsigned int dec2 = 0;

    int res = s21_sscanf("-0x7B15", "%x", &dec1);
    int res2 = sscanf("-0x7B15", "%x", &dec2);

    ck_assert_ldouble_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);

    res = s21_sscanf("------------0x7B15", "%x", &dec1);
    res2 = sscanf("------------0x7B15", "%x", &dec2);

    ck_assert_ldouble_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);

    res = s21_sscanf("0x7B15", "%x", &dec1);
    res2 = sscanf("0x7B15", "%x", &dec2);

    ck_assert_ldouble_eq(dec1, dec2);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_16) {
    char *empty_str = "";
    char orig_str[100] = {};
    int orig_res = 0;
    char orig_char = 0;
    int orig_d = 0;
    int orig_i = 0;
    unsigned int orig_u = 0;
    unsigned int orig_o = 0;
    unsigned int orig_x = 0;
    unsigned int orig_X = 0;
    long double orig_lf = 0;
    long double s21_lf = 0;
    float orig_float = 0;
    float s21_float = 0;
    double orig_e = 0;
    double orig_E = 0;
    double orig_f = 0;
    double orig_g = 0;
    float orig_G = 0;
    char s21_str[100] = {};
    int s21_res = 0;
    char s21_char = 0;
    int s21_d = 0;
    int s21_i = 0;
    unsigned int s21_u = 0;
    unsigned int s21_o = 0;
    unsigned int s21_x = 0;
    unsigned int s21_X = 0;
    double s21_e = 0;
    double s21_E = 0;
    double s21_f = 0;
    double s21_g = 0;
    float s21_G = 0;

    orig_res = sscanf("", "%s", orig_str);
    s21_res = s21_sscanf("", "%s", s21_str);
    ck_assert_str_eq(orig_str, s21_str);
    ck_assert_int_eq(orig_res, s21_res);
    orig_res = sscanf("\taboba", "%s", orig_str);
    s21_res = s21_sscanf("\taboba", "%s", s21_str);
    ck_assert_str_eq(orig_str, s21_str);
    ck_assert_int_eq(orig_res, s21_res);
    orig_res = sscanf("ignore aboba", "%*s%s", orig_str);
    s21_res = s21_sscanf("ignore aboba", "%*s%s", s21_str);
    ck_assert_str_eq(orig_str, s21_str);
    ck_assert_int_eq(orig_res, s21_res);

    sscanf(" f", "%c", &orig_char);
    s21_sscanf(" f", "%c", &s21_char);
    ck_assert_int_eq(orig_char, s21_char);
    sscanf("d f", "%*c%c", &orig_char);
    s21_sscanf("d f", "%*c%c", &s21_char);
    ck_assert_int_eq(orig_char, s21_char);
    orig_res = sscanf("", "%c", &orig_char);
    s21_res = s21_sscanf("", "%c", &s21_char);
    ck_assert_int_eq(orig_res, s21_res);
    ck_assert_int_eq(orig_char, s21_char);

    sscanf("23 12", "%*d%d", &orig_d);
    s21_sscanf("23 12", "%*d%d", &s21_d);
    ck_assert_int_eq(orig_d, s21_d);
    sscanf("-12", "%d", &orig_d);
    s21_sscanf("-12", "%d", &s21_d);
    ck_assert_int_eq(orig_d, s21_d);
    sscanf("+12", "%d", &orig_d);
    s21_sscanf("+12", "%d", &s21_d);
    ck_assert_int_eq(orig_d, s21_d);
    sscanf("+12", "aboba%d", &orig_d);
    s21_sscanf("+12", "aboba%d", &s21_d);
    ck_assert_int_eq(orig_d, s21_d);

    sscanf("+12", "%2d", &orig_d);
    s21_sscanf("+12", "%2d", &s21_d);
    ck_assert_int_eq(orig_d, s21_d);
    sscanf("-12", "%%");
    s21_sscanf("-12", "%%");
    ck_assert_int_eq(orig_d, s21_d);
    sscanf("kl", "%2d", &orig_d);
    s21_sscanf("kl", "%2d", &s21_d);
    ck_assert_int_eq(orig_d, s21_d);

    sscanf("23 12", "%i", &orig_i);
    s21_sscanf("23 12", "%i", &s21_i);
    ck_assert_int_eq(orig_i, s21_i);

    sscanf("23 12", "%u", &orig_u);
    s21_sscanf("23 12", "%u", &s21_u);
    ck_assert_int_eq(orig_u, s21_u);

    sscanf("012", "%o", &orig_o);
    s21_sscanf("012", "%o", &s21_o);
    ck_assert_int_eq(orig_o, s21_o);

    sscanf("0x12", "%x", &orig_x);
    s21_sscanf("0x12", "%x", &s21_x);
    ck_assert_int_eq(orig_x, s21_x);
    sscanf("0X12", "%X", &orig_X);
    s21_sscanf("0X12", "%X", &s21_X);
    ck_assert_int_eq(orig_X, s21_X);
    sscanf("0xAC", "%x", &orig_x);
    s21_sscanf("0xAC", "%x", &s21_x);
    ck_assert_int_eq(orig_x, s21_x);
    sscanf("0X78ED3", "%X", &orig_X);
    s21_sscanf("078ED3", "%X", &s21_X);
    ck_assert_int_eq(orig_X, s21_X);
    sscanf("0xac", "%x", &orig_x);
    s21_sscanf("0xac", "%x", &s21_x);
    ck_assert_int_eq(orig_x, s21_x);

    sscanf("5e-1", "%le", &orig_e);
    s21_sscanf("5e-1", "%le", &s21_e);
    ck_assert_double_eq(orig_e, s21_e);
    sscanf("-99e-99", "%le", &orig_e);
    s21_sscanf("-99e-99", "%le", &s21_e);
    ck_assert_double_eq(orig_e, s21_e);
    sscanf("5e-1", "%Le", &orig_lf);
    s21_sscanf("5e-1", "%Le", &s21_lf);
    ck_assert_double_eq(orig_lf, s21_lf);
    sscanf("aboba 5E1", "%lE", &orig_E);
    s21_sscanf("aboba 5E1", "%lE", &s21_E);
    ck_assert_double_eq(orig_E, s21_E);
    sscanf("aboba 5E0", "%E", &orig_float);
    s21_sscanf("aboba 5E0", "%E", &s21_float);
    ck_assert_double_eq(orig_float, s21_float);

    sscanf("aboba 0.4", "%lf", &orig_f);
    s21_sscanf("aboba 0.4", "%lf", &s21_f);
    ck_assert_uint_eq(orig_f, s21_f);
    sscanf("-0.4", "%Lf", &orig_lf);
    s21_sscanf("-0.4", "%Lf", &s21_lf);
    ck_assert_uint_eq(orig_lf, s21_lf);
    sscanf("aboba 0.4", "%f", &orig_float);
    s21_sscanf("aboba 0.4", "%f", &s21_float);
    ck_assert_uint_eq(orig_float, s21_float);
    sscanf("-0.4", "%Lf", &orig_lf);
    s21_sscanf("-0.4", "%f", &s21_lf);
    ck_assert_uint_eq(orig_lf, s21_lf);
    sscanf("0.4", "%Lf", &orig_lf);
    s21_sscanf("0.4", "%f", &s21_lf);
    ck_assert_uint_eq(orig_float, s21_float);
    sscanf("0.4 0.4", "%*f%Lf", &orig_lf);
    s21_sscanf("0.4 0.4", "%*f%f", &s21_lf);
    ck_assert_uint_eq(orig_float, s21_float);

    sscanf("aboba 0.4", "%lg", &orig_g);
    s21_sscanf("aboba 0.4", "%lg", &s21_g);
    ck_assert_uint_eq(orig_g, s21_g);
    sscanf("aboba 0.4", "%G", &orig_G);
    s21_sscanf("aboba 0.4", "%G", &s21_G);
    ck_assert_uint_eq(orig_G, s21_G);

    orig_res = sscanf(empty_str, "%c", &orig_char);
    s21_res = sscanf(empty_str, "%c", &s21_char);
    ck_assert_int_eq(orig_char, s21_char);
    ck_assert_int_eq(orig_res, s21_res);
}
END_TEST

START_TEST(s21_sscanf_test1) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 3", "%d%*d%d", &x1, &x2),
                   s21_sscanf("298 7 3", "%d%*d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test2) {
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0x12fA bB09", "%x%x", &x1, &x2),
                   s21_sscanf("0x12fA bB09", "%x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test3) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0xff01 -96 05678", "%i%i", &x1, &x2),
                   s21_sscanf("0xff01 -96 05678", "%i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test4) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0567 +101 ", "%i%i", &x1, &x2),
                   s21_sscanf("0567 +101 ", "%i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test5) {
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0567 +101 ", "%o%3o", &x1, &x2),
                   s21_sscanf("0567 +101 ", "%o%3o", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test6) {
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("3452 -99", "%u%u", &x1, &x2),
                   s21_sscanf("3452 -99", "%u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test7) {
  unsigned int x1, x2, y1, y2;
  ck_assert_uint_eq(sscanf("3452 -99", "%u%u", &x1, &x2),
                    s21_sscanf("3452 -99", "%u%u", &y1, &y2));
  ck_assert_uint_eq(x1, y1);
  ck_assert_uint_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test8) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("3452-99", "%i%n", &x1, &x2),
                   s21_sscanf("3452-99", "%i%n", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test9) {
  char x1[10] = "\0", x2[10] = "\0", y1[10] = "\0", y2[10] = "\0";
  ck_assert_int_eq(sscanf("hi fry slow", "%9sfry%9s", x1, x2),
                   s21_sscanf("hi fry slow", "%9sfry%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test10) {
  int x1, y1;
  ck_assert_int_eq(sscanf("12%", "%d%%", &x1), s21_sscanf("12%", "%d%%", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test11) {
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("-11-  %", "%d%%", &x1),
                   s21_sscanf("-11-  %", "%d%%", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test12) {
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  ck_assert_int_eq(sscanf("-11  % 4", "%d%%%d", &x1, &x2),
                   s21_sscanf("-11  % 4", "%d%%%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test13) {
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(
      sscanf("0x12fAaaaaaaaaaaaaaaaaaa bB09", "%x%x", &x1, &x2),
      s21_sscanf("0x12fAaaaaaaaaaaaaaaaaaa bB09", "%x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test14) {
  unsigned short int x1, y1;
  ck_assert_int_eq(sscanf("12", "%hu", &x1), s21_sscanf("12", "%hu", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test16) {
  char x1[20] = {0}, x2[20] = {0}, y1[20] = {0}, y2[20] = {0};
  ck_assert_int_eq(sscanf("  ya", "%9s%9s", x1, x2),
                   s21_sscanf("  ya", "%9s%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test17) {
  long x1, y1;
  short x2, y2;
  ck_assert_int_eq(sscanf("12 45", "%ld%hd", &x1, &x2),
                   s21_sscanf("12 45", "%ld%hd", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test18) {
  char x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0 a", "%c%c", &x1, &x2),
                   s21_sscanf("0 a", "%c%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test19) {
  long unsigned int x1, y1;
  unsigned int x2, y2;
  ck_assert_uint_eq(sscanf("3452 -99", "%lu%u", &x1, &x2),
                    s21_sscanf("3452 -99", "%lu%u", &y1, &y2));
  ck_assert_uint_eq(x1, y1);
  ck_assert_uint_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test20) {
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("  g  ", "%i", &x1), s21_sscanf("  g  ", "%i", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test21) {
  unsigned int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("  g  ", "%u", &x1), s21_sscanf("  g  ", "%u", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test22) {
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("V123", "%d", &x1), s21_sscanf("V123", "%d", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test23) {
  wchar_t x1[10], y1[10];
  ck_assert_int_eq(sscanf("qwerty 12345", "%1ls", x1),
                   s21_sscanf("qwerty 12345", "%1ls", y1));
  ck_assert_int_eq(*x1, *y1);
}
END_TEST

START_TEST(s21_sscanf_test24) {
  wchar_t x1, y1;
  char x2, y2;
  ck_assert_int_eq(sscanf("ass", "%lc%c", &x1, &x2),
                   s21_sscanf("ass", "%lc%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test25) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("123456 654321", "%00004d%6d", &x1, &x2),
                   s21_sscanf("123456 654321", "%00004d%6d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test26) {
  long double x1, y1;
  float x2, y2;
  ck_assert_int_eq(sscanf("0.9045010    0.023", "%Le%4f", &x1, &x2),
                   s21_sscanf("0.9045010    0.023", "%Le%4f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test27) {
  float x1, y1, x2, y2;
  ck_assert_int_eq(sscanf("2.17e2 0.4e-3", "%G%g", &x1, &x2),
                   s21_sscanf("2.17e2 0.4e-3", "%G%g", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test28) {
  float x1, y1, x2, y2;
  ck_assert_int_eq(sscanf("2.17e2 0.4e+3", "%E%f", &x1, &x2),
                   s21_sscanf("2.17e2 0.4e+3", "%E%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test29) {
  char x1[30] = {0}, y1[30] = {0};
  float x2, y2;
  unsigned int x3 = 0, y3 = 0;
  ck_assert_int_eq(sscanf("qwerty -12.0345007", "%6s%f%o", x1, &x2, &x3),
                   s21_sscanf("qwerty -12.0345007", "%6s%f%o", y1, &y2, &y3));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq(x3, y3);
}
END_TEST

START_TEST(s21_sscanf_test30) {
  char x1[30] = {0}, y1[30] = {0};
  float x2, y2;
  unsigned int x3 = 0, y3 = 0;
  ck_assert_int_eq(sscanf("qwerty -12.0345007", "%9s%f%2o", x1, &x2, &x3),
                   s21_sscanf("qwerty -12.0345007", "%9s%f%2o", y1, &y2, &y3));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq(x3, y3);
}
END_TEST

START_TEST(s21_sscanf_test31) {
  unsigned int x1, y1;
  char s1[30], s2[30];
  ck_assert_int_eq(sscanf("0xE00A4DOG", "%6x%*d%3s", &x1, s1),
                   s21_sscanf("0xE00A4DOG", "%6x%*d%3s", &y1, s2));
  ck_assert_int_eq(x1, y1);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_s21_sscanf) {
  int a = 0;
  int b = 0;
  ck_assert_int_eq(s21_sscanf("123", "%d", &a), sscanf("123", "%d", &b));
  ck_assert_int_eq(a, b);

  short sa = 0;
  short sb = 0;
  ck_assert_int_eq(s21_sscanf("123456", "%hd", &sa),
                   sscanf("123456", "%hd", &sb));
  ck_assert_int_eq(sa, sb);

  ck_assert_int_eq(s21_sscanf("98765", "%3d", &a), sscanf("98765", "%3d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("98765", "%3hd%d", &sa, &a),
                   sscanf("98765", "%3hd%d", &sb, &b));
  ck_assert_int_eq(sa, sb);
  ck_assert_int_eq(a, b);

  int c = 0;
  int d = 0;
  ck_assert_int_eq(s21_sscanf("111%111", "%d%%%d", &a, &b),
                   sscanf("111%111", "%d%%%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("222%222", "%d %d", &a, &b),
                   sscanf("222%222", "%d %d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("333abcde333", "%dabcde%d", &a, &b),
                   sscanf("333abcde333", "%dabcde%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("44", "%1d %1d", &a, &b),
                   sscanf("44", "%1d %1d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("4 4", "%d%d", &a, &b),
                   sscanf("4 4", "%d%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf(" ", "%%"), sscanf(" ", "%%"));

  // пустая строка
  ck_assert_int_eq(s21_sscanf("", "%d", &a), sscanf("", "%d", &b));
  ck_assert_int_eq(a, b);

  // строки с пробелами
  ck_assert_int_eq(s21_sscanf(" ", "%d", &a), sscanf(" ", "%d", &b));
  ck_assert_int_eq(a, b);

  // пустая форматная строка с флагом -Werror sscanf не работает
  //    ck_assert_int_eq(s21_sscanf("123", "", &a), sscanf("123", "", &b));
  ck_assert_int_eq(s21_sscanf("123", ""), 0);
  ck_assert_int_eq(s21_sscanf("123", "a"), sscanf("123", "a"));

  // скип числа
  ck_assert_int_eq(s21_sscanf("123123", "%*3d%d", &a),
                   sscanf("123123", "%*3d%d", &b));
  ck_assert_int_eq(a, b);

  // несуществующий формат
  ck_assert_int_eq(s21_sscanf("123", "%a", &a), -1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_int) {
  short sa = 0, sb = 0, sc = 0, sd = 0;
  int a = 0, b = 0;
  long la = 0, lb = 0, lc = 0, ld = 0;

  ck_assert_int_eq(s21_sscanf("123456123", "%6hd%hd", &sa, &sb),
                   sscanf("123456123", "%6hd%hd", &sc, &sd));
  ck_assert_int_eq(sa, sc);
  ck_assert_int_eq(sb, sd);

  ck_assert_int_eq(s21_sscanf("12345678901", "%d", &a),
                   sscanf("12345678901", "%d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-12345678901", "%d", &a),
                   sscanf("-12345678901", "%d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-12345678901", "%ld", &la),
                   sscanf("-12345678901", "%ld", &lb));
  ck_assert_int_eq(la, lb);

  // переполнение longlong
  ck_assert_int_eq(s21_sscanf("12345678901234567890", "%ld", &la),
                   sscanf("12345678901234567890", "%ld", &lb));
  ck_assert_int_eq(la, lb);

  ck_assert_int_eq(s21_sscanf("-12345678901234567890", "%ld", &la),
                   sscanf("-12345678901234567890", "%ld", &lb));
  ck_assert_int_eq(la, lb);

  // переполнение на целый круг
  lb = 0;
  ck_assert_int_eq(s21_sscanf("19223372036854775807", "%ld%ld", &la, &lb),
                   sscanf("19223372036854775807", "%ld%ld", &lc, &ld));
  ck_assert_int_eq(la, lc);
  ck_assert_int_eq(lb, ld);

  // понижение разряда при переполнении
  ck_assert_int_eq(s21_sscanf("12345678901234567890", "%d", &a),
                   sscanf("12345678901234567890", "%d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-12345678901234567890", "%d", &a),
                   sscanf("-12345678901234567890", "%d", &b));
  ck_assert_int_eq(a, b);

  // long long
  long long lla = 0, llb = 0, llc = 0, lld = 0;
  ck_assert_int_eq(s21_sscanf("123456789012345", "%lld", &lla),
                   sscanf("123456789012345", "%lld", &llb));
  ck_assert_int_eq(lla, llb);

  ck_assert_int_eq(
      s21_sscanf("-123456789012345678901", "%21lld%lld", &lla, &llb),
      sscanf("-123456789012345678901", "%21lld%lld", &llc, &lld));
  ck_assert_int_eq(lla, llc);
  ck_assert_int_eq(llb, lld);

  ck_assert_int_eq(s21_sscanf("987654321", "%lld", &lla),
                   sscanf("987654321", "%lld", &llb));  // Ld - long long
  // Ахах это УБ
  ck_assert_int_eq(lla, llb);

  // нет числа совсем
  ck_assert_int_eq(s21_sscanf("abc", "%d", &a), sscanf("abc", "%d", &b));
  ck_assert_int_eq(a, b);

  // отрицательное ничего
  ck_assert_int_eq(s21_sscanf("-abc", "%d", &a), sscanf("-abc", "%d", &b));
  ck_assert_int_eq(a, b);

  // слишком широкий спецификатор
  ck_assert_int_eq(s21_sscanf("123", "%5d", &a), sscanf("123", "%5d", &b));
  ck_assert_int_eq(a, b);

  // with +
  ck_assert_int_eq(s21_sscanf("++321", "%d", &a), sscanf("++321", "%d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+321", "%d", &a), sscanf("+321", "%d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+98765", "%*5d%d", &a),
                   sscanf("+98765", "%*5d%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_uint) {
  unsigned int a = 0, b = 0;
  unsigned long la = 0, lb = 0;
  unsigned long long lla = 0, llb = 0;

  ck_assert_int_eq(s21_sscanf("1234567890", "%u", &a),
                   sscanf("1234567890", "%u", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("12345678901", "%u", &a),
                   sscanf("12345678901", "%u", &b));
  ck_assert_int_eq(a, b);

  // переполнение
  ck_assert_int_eq(s21_sscanf("123456789012345678901", "%llu", &lla),
                   sscanf("123456789012345678901", "%llu", &llb));
  ck_assert_int_eq(la, lb);

  ck_assert_int_eq(s21_sscanf("12345678901234567890123", "%22llu", &lla),
                   sscanf("12345678901234567890123", "%22llu", &llb));
  ck_assert_int_eq(la, lb);

  unsigned short sa = 0, sb = 0;
  ck_assert_int_eq(s21_sscanf("1234567890", "%5hu%lu", &sa, &la),
                   sscanf("1234567890", "%5hu%lu", &sb, &lb));
  ck_assert_int_eq(sa, sb);
  ck_assert_int_eq(la, lb);

  // слишком широкий спецификатор
  ck_assert_int_eq(s21_sscanf("123", "%5u", &a), sscanf("123", "%5u", &b));
  ck_assert_int_eq(a, b);

  // -
  ck_assert_int_eq(s21_sscanf("-123", "%u", &a), sscanf("-123", "%u", &b));
  ck_assert_int_eq(a, b);

  // +
  ck_assert_int_eq(s21_sscanf("+123", "%u", &a), sscanf("+123", "%u", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+123", "%*2u%u", &a),
                   sscanf("+123", "%*2u%u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_hex) {
  unsigned int a = 0, b = 0;
  // 0x
  ck_assert_int_eq(s21_sscanf("0x1234567890", "%x", &a),
                   sscanf("0x1234567890", "%x", &b));
  ck_assert_int_eq(a, b);

  // 0X
  ck_assert_int_eq(s21_sscanf("0X1234567890", "%x", &a),
                   sscanf("0X1234567890", "%x", &b));
  ck_assert_int_eq(a, b);

  // a - f
  ck_assert_int_eq(s21_sscanf("0x1abcdef", "%X", &a),
                   sscanf("0x1abcdef", "%X", &b));
  ck_assert_int_eq(a, b);

  // A - F
  ck_assert_int_eq(s21_sscanf("0X1ACDEF", "%X", &a),
                   sscanf("0X1ACDEF", "%X", &b));
  ck_assert_int_eq(a, b);

  // switch case
  ck_assert_int_eq(s21_sscanf("0x1aBcDeF", "%x", &a),
                   sscanf("0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  // half prefix
  ck_assert_int_eq(s21_sscanf("01aBcDeF", "%x", &a),
                   sscanf("01AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("01aBcDeF", "%X", &a),
                   sscanf("01AbCdEf", "%X", &b));
  ck_assert_int_eq(a, b);

  // bad prefix
  ck_assert_int_eq(s21_sscanf("x1aBcDeF", "%x", &a),
                   sscanf("x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(s21_sscanf("X1aBcDeF", "%X", &a),
                   sscanf("X1AbCdEf", "%X", &b));
  ck_assert_int_eq(a, b);

  // -
  ck_assert_int_eq(s21_sscanf("-0x1aBcDeF", "%x", &a),
                   sscanf("-0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  // +
  ck_assert_int_eq(s21_sscanf("++0x1aBcDeF", "%x", &a),
                   sscanf("++0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+0x1aBcDeF", "%x", &a),
                   sscanf("+0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_oct) {
  unsigned int a = 0, b = 0;
  // prefix
  ck_assert_int_eq(s21_sscanf("01234567", "%o", &a),
                   sscanf("01234567", "%o", &b));
  ck_assert_int_eq(a, b);
  // no prefix
  ck_assert_int_eq(s21_sscanf("21234567", "%o", &a),
                   sscanf("21234567", "%o", &b));
  ck_assert_int_eq(a, b);

  // -
  ck_assert_int_eq(s21_sscanf("-01234567", "%o", &a),
                   sscanf("-01234567", "%o", &b));
  ck_assert_int_eq(a, b);

  // bad prefix
  ck_assert_int_eq(s21_sscanf("0-1234567", "%o", &a),
                   sscanf("0-1234567", "%o", &b));

  // +
  a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf("++01234567", "%o", &a),
                   sscanf("++01234567", "%o", &b));  // уб бан
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+01234567", "%o", &a),
                   sscanf("+01234567", "%o", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_i_uint) {
  unsigned int a = 0, b = 0;
  // no prefix
  ck_assert_int_eq(s21_sscanf("1234567890", "%i", &a),
                   sscanf("1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  // oct prefix
  ck_assert_int_eq(s21_sscanf("01234567", "%i", &a),
                   sscanf("01234567", "%i", &b));
  ck_assert_int_eq(a, b);

  // hex prefix
  ck_assert_int_eq(s21_sscanf("0x1234567890", "%i", &a),
                   sscanf("0x1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  // -
  ck_assert_int_eq(s21_sscanf("-1234567890", "%i", &a),
                   sscanf("-1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  // -0 prefix
  ck_assert_int_eq(s21_sscanf("-01234567", "%i", &a),
                   sscanf("-01234567", "%i", &b));
  ck_assert_int_eq(a, b);

  // -0x prefix
  ck_assert_int_eq(s21_sscanf("-0x1234567890", "%i", &a),
                   sscanf("-0x1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  // wierd -- prefix
  ck_assert_int_eq(s21_sscanf("--1234567890", "%i", &a),
                   sscanf("--1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  // wierd -0- prefix
  ck_assert_int_eq(s21_sscanf("-0-1234567890", "%i", &a),
                   sscanf("-0-1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  // wierd -0x- prefix
  ck_assert_int_eq(s21_sscanf("-0x-ab34567890", "%i", &a),
                   sscanf("-0x-ab34567890", "%i", &b));
  ck_assert_int_eq(a, b);

  // hex without prefix
  ck_assert_int_eq(s21_sscanf("123abcdef", "%i", &a),
                   sscanf("123abcdef", "%i", &b));
  ck_assert_int_eq(a, b);

  // hex without prefix starting with letter
  ck_assert_int_eq(s21_sscanf("a123abcdef", "%i", &a),
                   sscanf("a123abcdef", "%i", &b));
  ck_assert_int_eq(a, b);

  // hex with + prefix
  ck_assert_int_eq(s21_sscanf("+0xfaf", "%i", &a), sscanf("+0xfaf", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_ptr) {
  void *a = NULL, *b = NULL;
  ck_assert_int_eq(s21_sscanf("0x1234567890", "%p", &a),
                   sscanf("0x1234567890", "%p", &b));
  ck_assert_ptr_eq(a, b);

  ck_assert_int_eq(s21_sscanf("0xabc", "%p", &a), sscanf("0xabc", "%p", &b));
  ck_assert_ptr_eq(a, b);

  // no prefix
  ck_assert_int_eq(s21_sscanf("1234567890", "%p", &a),
                   sscanf("1234567890", "%p", &b));
  ck_assert_ptr_eq(a, b);

  // -
  ck_assert_int_eq(s21_sscanf("-1234567890", "%p", &a),
                   sscanf("-1234567890", "%p", &b));
  ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(test_parse_string) {
  char buf1[100] = {0}, buf2[100] = {0};
  // %c
  ck_assert_int_eq(s21_sscanf("123", "%c", buf1), sscanf("123", "%c", buf2));
  ck_assert_int_eq(buf1[0], buf2[0]);

  // %s
  ck_assert_int_eq(s21_sscanf("1234567890", "%s", buf1),
                   sscanf("1234567890", "%s", buf2));
  ck_assert_str_eq(buf1, buf2);

  // %c with len
  // %c shouldnt add null terminator
  ck_assert_int_eq(s21_sscanf("qwertyuiop", "%9c", buf1),
                   sscanf("qwertyuiop", "%9c", buf2));
  ck_assert_str_eq(buf1, buf2);

  // %s with len
  ck_assert_int_eq(s21_sscanf("abcdefghk", "%5s", buf1),
                   sscanf("abcdefghk", "%5s", buf2));
  ck_assert_str_eq(buf1, buf2);

  // %c with len
  ck_assert_int_eq(s21_sscanf("qwe", "%2c", buf1), sscanf("qwe", "%2c", buf2));
  ck_assert_str_eq(buf1, buf2);

  // empty string
  ck_assert_int_eq(s21_sscanf("", "%s", buf1), sscanf("", "%s", buf2));
  ck_assert_str_eq(buf1, buf2);

  // two strings with space
  char buf3[100] = {0}, buf4[100] = {0};
  ck_assert_int_eq(s21_sscanf("123 456", "%s %s", buf1, buf3),
                   sscanf("123 456", "%s %s", buf2, buf4));
  ck_assert_str_eq(buf1, buf2);
  ck_assert_str_eq(buf3, buf4);
}
END_TEST

START_TEST(test_scan_n) {
  char buf1[100] = {0}, buf2[100] = {0};
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf("1234567890", "%5s%n", buf1, &a),
                   sscanf("1234567890", "%5s%n", buf2, &b));
  ck_assert_int_eq(a, b);

  // empty string
  ck_assert_int_eq(s21_sscanf("", "%s%n", buf1, &a),
                   sscanf("", "%s%n", buf2, &b));
  ck_assert_int_eq(a, b);

  int i = 0, j = 0;  // опять уб
  ck_assert_int_eq(s21_sscanf("123456", "%*3d%d%n", &i, &a),
                   sscanf("123456", "%*3d%d%n", &j, &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// Функция создания набора тестов.
Suite *example_suite_create(void) {
    Suite *suite = suite_create("Example");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of example");

    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, test_1);
    tcase_add_test(tcase_core, test_2);
    tcase_add_test(tcase_core, test_3);
    tcase_add_test(tcase_core, test_4);
    tcase_add_test(tcase_core, test_5);
    tcase_add_test(tcase_core, test_6);
    tcase_add_test(tcase_core, test_7);
    tcase_add_test(tcase_core, test_8);
    tcase_add_test(tcase_core, test_9);
    tcase_add_test(tcase_core, test_10);
    tcase_add_test(tcase_core, test_11);
    tcase_add_test(tcase_core, test_12);
    tcase_add_test(tcase_core, test_13);
    tcase_add_test(tcase_core, test_14);
    tcase_add_test(tcase_core, test_15);
    tcase_add_test(tcase_core, test_16);

    tcase_add_test(tcase_core, s21_sscanf_test1);
    tcase_add_test(tcase_core, s21_sscanf_test2);
    tcase_add_test(tcase_core, s21_sscanf_test3);
    tcase_add_test(tcase_core, s21_sscanf_test4);
    tcase_add_test(tcase_core, s21_sscanf_test5);
    tcase_add_test(tcase_core, s21_sscanf_test6);
    tcase_add_test(tcase_core, s21_sscanf_test7);
    tcase_add_test(tcase_core, s21_sscanf_test8);
    tcase_add_test(tcase_core, s21_sscanf_test9);
    tcase_add_test(tcase_core, s21_sscanf_test10);
    tcase_add_test(tcase_core, s21_sscanf_test11);
    tcase_add_test(tcase_core, s21_sscanf_test12);
    tcase_add_test(tcase_core, s21_sscanf_test13);
    tcase_add_test(tcase_core, s21_sscanf_test14);
    tcase_add_test(tcase_core, s21_sscanf_test16);
    tcase_add_test(tcase_core, s21_sscanf_test17);
    tcase_add_test(tcase_core, s21_sscanf_test18);
    tcase_add_test(tcase_core, s21_sscanf_test19);
    tcase_add_test(tcase_core, s21_sscanf_test20);
    tcase_add_test(tcase_core, s21_sscanf_test21);
    tcase_add_test(tcase_core, s21_sscanf_test22);
    tcase_add_test(tcase_core, s21_sscanf_test23);
    tcase_add_test(tcase_core, s21_sscanf_test24);
    tcase_add_test(tcase_core, s21_sscanf_test25);
    tcase_add_test(tcase_core, s21_sscanf_test26);
    tcase_add_test(tcase_core, s21_sscanf_test27);
    tcase_add_test(tcase_core, s21_sscanf_test28);
    tcase_add_test(tcase_core, s21_sscanf_test29);
    tcase_add_test(tcase_core, s21_sscanf_test30);
    tcase_add_test(tcase_core, s21_sscanf_test31);

    tcase_add_test(tcase_core, test_s21_sscanf);
    tcase_add_test(tcase_core, test_parse_int);
    tcase_add_test(tcase_core, test_parse_uint);
    tcase_add_test(tcase_core, test_parse_hex);
    tcase_add_test(tcase_core, test_parse_oct);
    tcase_add_test(tcase_core, test_parse_i_uint);
    tcase_add_test(tcase_core, test_parse_ptr);
    tcase_add_test(tcase_core, test_parse_string);
    tcase_add_test(tcase_core, test_scan_n);


    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);

    return suite;
}

int main() {
    int failed_count = 0;
    Suite *suite = example_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    srunner_set_fork_status(suite_runner, CK_NOFORK);
    srunner_run_all(suite_runner, CK_NORMAL);
    // Получаем количество проваленных тестов.
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    if (failed_count != 0) {
        // Сигнализируем о том, что тестирование прошло неудачно.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
