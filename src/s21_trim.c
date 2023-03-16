#include "s21_string.h"

void logic_trim_chars_S21_NULL(s21_size_t *f_i, s21_size_t *s_i,
                               const char *src);
void logic_trim_chars_standart(s21_size_t *f_i, s21_size_t *s_i,
                               const char *src, const char *trim_chars);

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t s_i = 0;
  char *new_str = S21_NULL;
  if (!(S21_NULL == src || S21_NULL == trim_chars)) {
    s21_size_t f_i = s21_strlen(src);
    new_str = (char *)calloc(f_i, sizeof(char));
    if (s21_strlen(trim_chars) == 0) {
      logic_trim_chars_S21_NULL(&f_i, &s_i, src);
    } else {
      logic_trim_chars_standart(&f_i, &s_i, src, trim_chars);
    }
    for (int i = 0; s_i < f_i; s_i++, i++) {
      new_str[i] = src[s_i];
    }
  }
  return new_str;
}

void logic_trim_chars_S21_NULL(s21_size_t *f_i, s21_size_t *s_i,
                               const char *src) {
  s21_size_t i = 0;
  int OPERATOR_START = 0;
  if ((src[i] == ' ' || src[i] == '\t' || src[i] == '\n') && src[i] != '\0') {
    OPERATOR_START = 1;
    *s_i = 1;
  }
  for (; OPERATOR_START; i++) {
    if ((src[i] == ' ' || src[i] == '\t' || src[i] == '\n') && src[i] != '\0') {
      OPERATOR_START = 1;
      *s_i = i + 1;
    } else {
      break;
    }
  }
  s21_size_t j = 0;
  j = s21_strlen(src) - j - 1;
  int OPERATOR_FINISH = 0;
  if (src[j] == ' ' || src[j] == '\t' || src[j] == '\n') {
    OPERATOR_FINISH = 1;
  }

  for (; OPERATOR_FINISH; j = j - 1) {
    OPERATOR_FINISH = 0;
    if ((src[j] == ' ' || src[j] == '\t' || src[j] == '\n') && src[j] != '\0') {
      OPERATOR_FINISH = 1;
      *f_i = j;
    } else {
      break;
    }
  }
}

void logic_trim_chars_standart(s21_size_t *f_i, s21_size_t *s_i,
                               const char *src, const char *trim_chars) {
  s21_size_t COUNT_trim_chars = s21_strlen(trim_chars);
  int s_b = 1;
  int f_b = 1;
  for (s21_size_t i = 0; i < s21_strlen(src) && s_b + f_b > 0; i++) {
    s_b = 0;
    f_b = 0;
    for (s21_size_t j = 0; j < COUNT_trim_chars && *s_i == i; j++) {
      if (src[i] == trim_chars[j] && src[i] != '\0') {
        s_b = 1;
      }
    }
    if (s_b == 1) {
      *s_i = *s_i + 1;
    }
    for (s21_size_t j = 0; j < COUNT_trim_chars && *f_i == s21_strlen(src) - i;
         j++) {
      if (src[s21_strlen(src) - (i + 1)] == trim_chars[j]) {
        f_b = 1;
      }
    }
    if (f_b == 1) {
      *f_i = *f_i - 1;
    }
    if (*s_i == *f_i) {
      break;
    }
  }
}
