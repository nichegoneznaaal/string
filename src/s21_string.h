#ifndef S21_STRINGS_H
#define S21_STRINGS_H
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#define S21_NULL ((void *)0)
#define s21_NULL (void *)0
typedef unsigned long s21_size_t;
typedef unsigned long s21_size_t;
typedef int s21_wchar_t;
#define STR_LEN s21_strlen
#define STR_CAT s21_strcat
#define STR 100
#define MAX_INT_D 2147483647
#define MIN_INT_D -2147483648
#define LEN_LONG_LONG_INT 21
#define LEN_DOUBLE 4000
#define SUB_BUF 1024
#define S21_LONG_MAX 0xffffffffffffffffL

// SSCANF
long s21_strtol(char *str, int notation);
unsigned long s21_strtoul(char *str, int base);
double s21_atof(const char *str);
// long s21_strtol_old(char* str, int notation);

enum WasFlags { WIDTH, SUPPRESS, LENGHT, ALL };

typedef struct Fmt_delimetr {
  char delim[SUB_BUF];
  char *pdel;
} Fmt_delimetr;

typedef struct tia_Token {
  char swidth[SUB_BUF];
  int width;
  char lenght;
  char spec;
  short base;
} tia_Token;

typedef struct Opt {
  int *d;
  short *hd;
  s21_size_t *ld;
  long long int *Ld;
  signed char *sc;
  float *f;
  double *lf;
  long double *Lf;
  char *c;
  char *s;
  char *p;
  void **address;
  int *n;
  s21_wchar_t *ls;
  s21_wchar_t *lc;
  tia_Token tok;
  Fmt_delimetr fmt;
} Opt;

void initOpt(Opt *opt);
void default_str(Opt *opt, va_list ap, char *substring, const char **fmt);
void default_int();
void default_float();
void pars_fmt(const char **fmt, int flags[], Opt *opt);
int pars_s(const char **pb, char **spb, Opt *opt, int flags[]);
int pars_d(const char **pb, char **spb, Opt *opt);
int pars_f(const char **pb, char **spb, Opt *opt, long double *result);
int s21_sscanf(const char *buf, const char *fmt, ...);
void skip_spaces(const char **pb);
void case_decimal(Opt *opt, const char **fmt, int *success, const char **pb,
                  char **spb, int flags[], va_list ap, char *substring);
void s21_width(const char **fmt, int flags[], Opt *opt);
void p_case(Opt *opt, const char **fmt, int *success, const char **pb,
            char **spb, int flags[], va_list ap, char *substring);
void s_case(Opt *opt, const char **fmt, int *success, const char **pb,
            char **spb, int flags[], va_list ap, char *substring);
void f_case(Opt *opt, const char **fmt, int *success, const char **pb,
            char **spb, int flags[], va_list ap, char *substring);
void clean_sub(Opt *opt, char *substring, char **spb);
void not_spec(Opt *opt, const char **fmt);
void spec(Opt *opt, const char **fmt, va_list ap, int *success, const char **pb,
          char **spb, int flags[], char *substring, const char *buf);
int delimiter_check(Opt *opt, const char **pb);
void pars_f_fill(Opt *opt, const char **pb, char **spb, int *success, char *sub,
                 long double *result, int *was_e);
void pars_d_fill(Opt *opt, const char **pb, char **spb, int *success,
                 int *exit);
// SSCANF

// SPRINTF
#ifdef DEBUG
#define LOG_INFO(M, ...) \
  fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_INFO(M, ...)
#endif
#define S21_INF __builtin_huge_vall()
typedef long long int lli;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef const char cch;

typedef struct sprintf {
  int chars;
  int error;
  struct {
    int minus;
    int plus;
    int space;
    int grid;
    int zero;
    int flags;
  } flags;
  struct {
    s21_size_t size;
  } width;
  struct {
    s21_size_t size;
    s21_size_t size_g;
    lli size_float;
    s21_size_t size_double;
    int flag;
  } accuracy;
  struct {
    int h;
    int hh;
    int l;
    int ll;
    int L;
  } modifiers;
  char conv;
  char conv2;
  struct {
    int sign;
    s21_size_t size;
    s21_size_t width_zero;
    s21_size_t int_size;
    s21_size_t tmp;
    char tmp_str[STR];
    int stop_star;
    s21_size_t end_simb;
    int stop_p;
    s21_size_t tmp_p;
    int num_step_e;
    int long_f;
    int g;
    int g_exp;
    int g_exp_s;
    int c_round;
  } help;
} opt;

enum Token { DOWN, UP, INF_SPR, NAN_SPR };

int s21_sprintf(char *str, cch *format, ...);
void specifier(char *str, opt *opt, cch *format, s21_size_t *i,
               s21_size_t *simbol_n, va_list arg);
void up_modif(opt *opt, cch *format, s21_size_t *i);
void up_accur(opt *opt, cch *format, s21_size_t *i, va_list arg);
void up_width(opt *opt, cch *format, s21_size_t *i, va_list arg);
void up_flags(opt *opt, cch *format, s21_size_t *i);
void write_d2(opt *opt, char *str, s21_size_t *simbol_n, va_list arg);
void write_accur(opt *opt, s21_size_t *simbol_n, char *str);
void write_width(opt *opt, s21_size_t *simbol_n, char *str);
void write_sign(opt *opt, s21_size_t *simbol_n, char *str);
void write_number(opt *opt, s21_size_t *simbol_n, char **tmp, char *str);
void integer_part(opt *opt, char **memory_str, ld *int1, ld *double1,
                  ld *acc_tmp, ld double3);
void e_integer_part(opt *opt, char **memory_str);
void fractional_part(opt *opt, char **memory_str, ld *int1, ld *double1,
                     ld *acc_tmp);
void s21f_itoa(opt *opt, char **memory_str, va_list arg);
void spec_d(opt *opt, va_list arg, lli *arg_d);
void spec_f(opt *opt, va_list arg, ld *arg_f);
void spec_u(opt *opt, va_list arg, ul *arg_u);
int num_digs(lli n, int radix);
void s21d_itoa(opt *opt, char **memory_str, va_list arg);
void str_to_int(opt *opt, int *error, cch *format, s21_size_t *i,
                s21_size_t *digit, int width_accur);
int s21d_atoi(char *s);
void init_struct(opt *opt);
void decimal_to_hexa(opt *opt, lli decimal, char **buf);
void write_p_simb(opt *opt, s21_size_t *simbol_n, char *str);
void spec_o(opt *opt, va_list arg, ul *arg_o);
void spec_x(opt *opt, va_list arg, ull *arg_x);
void s21_itoa_e(opt *opt, ld double1);
void e_part(opt *opt, char **memory_str, ld double2, ld double3);
int find_e(ld x);
void round_d(opt *opt, ld *acc_tmp, s21_size_t max, int sign);
int how_many_cifer(long double a);
void s21f2_itoa(opt *opt, char **memory_str, ld int1);
void decimal_to_hexa_ull(opt *opt, ull decimal, char **buf);
void null(opt *opt, ld val);
// SPRINTF

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);

#endif  // S21_STRING_H
