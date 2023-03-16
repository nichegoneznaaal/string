#include "s21_string.h"

unsigned long s21_strtoul(char *str, int base) {
  s21_size_t res = 0;
  char c = 0;
  unsigned long cutoff = 0;
  int neg = 0;
  int cutlim = 0;
  int any = 0;

  c = *str++;
  if (c == '-') {
    neg = 1;
    c = *str++;
  } else {
    neg = 0;
    if (c == '+') c = *str++;
  }
  if ((base == 0 || base == 16) && c == '0' && (*str == 'x' || *str == 'X') &&
      ((str[1] >= '0' && str[1] <= '9') || (str[1] >= 'A' && str[1] <= 'F') ||
       (str[1] >= 'a' && str[1] <= 'f'))) {
    c = str[1];
    str += 2;
    base = 16;
  }

  if (base == 0) base = c == '0' ? 8 : 10;

  cutoff = S21_LONG_MAX;
  cutlim = cutoff % base;
  cutoff /= base;

  for (;; c = *str++) {
    if (c >= '0' && c <= '9')
      c -= '0';
    else if (c >= 'A' && c <= 'Z')
      c -= 'A' - 10;
    else if (c >= 'a' && c <= 'z')
      c -= 'a' - 10;
    else
      break;
    if (c >= base) break;
    if (any < 0 || res > cutoff || (res == cutoff && c > cutlim))
      any = -1;
    else {
      any = 1;
      res *= base;
      res += c;
    }
  }

  if (any < 0) {
    res = S21_LONG_MAX;
  } else if (neg) {
    res = S21_LONG_MAX - res + 1UL;
  }
  return res;
}

long s21_strtol(char *str, int base) {
  s21_size_t res = 0;
  char c = 0;
  unsigned long cutoff = 0;
  int neg = 0;
  int cutlim = 0;
  int any = 0;

  c = *str++;
  if (c == '-') {
    neg = 1;
    c = *str++;
  } else {
    neg = 0;
    if (c == '+') c = *str++;
  }
  if ((base == 0 || base == 16) && c == '0' && (*str == 'x' || *str == 'X') &&
      ((str[1] >= '0' && str[1] <= '9') || (str[1] >= 'A' && str[1] <= 'F') ||
       (str[1] >= 'a' && str[1] <= 'f'))) {
    c = str[1];
    str += 2;
    base = 16;
  }

  if (base == 0) base = c == '0' ? 8 : 10;

  cutoff = neg ? (unsigned long)-(LONG_MIN + LONG_MAX) + LONG_MAX : LONG_MAX;
  cutlim = cutoff % base;
  cutoff /= base;

  for (;; c = *str++) {
    if (c >= '0' && c <= '9')
      c -= '0';
    else if (c >= 'A' && c <= 'Z')
      c -= 'A' - 10;
    else if (c >= 'a' && c <= 'z')
      c -= 'a' - 10;
    else
      break;
    if (c >= base) break;
    if (any < 0 || res > cutoff || (res == cutoff && c > cutlim))
      any = -1;
    else {
      any = 1;
      res *= base;
      res += c;
    }
  }

  if (any < 0)
    res = neg ? LONG_MIN : LONG_MAX;
  else if (neg)
    res = -res;

  return res;
}

double s21_atof(const char *str) {
  double result = 0;
  const char *p = str;
  int base = 10;
  double c = 0;
  int was_dot = 0;
  int neg = 0;

  if (*p == '-') {
    neg = 1;
    p++;
  } else if (*p == '+') {
    p++;
    neg = 0;
  } else {
    neg = 0;
  }

  for (long double i = 10; (*p >= '0' && *p <= '9') || *p == '.';) {
    c = *p;
    if (c >= '0' && c <= '9') {
      c -= '0';
    } else if (c == '.' && !was_dot) {
      was_dot = 1;
      p++;
      continue;
    } else {
      break;
    }

    if (!was_dot) {
      result *= base;
      result += c;
      p++;
    } else {
      result += c / i;
      i *= 10;
      p++;
    }
  }

  if (neg) result = -result;

  return result;
}
