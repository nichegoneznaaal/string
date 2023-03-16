#include "s21_string.h"

void initOpt(Opt *opt) {
  s21_size_t len = s21_strlen(opt->tok.swidth);
  for (s21_size_t i = 0; i < len; i++) {
    opt->tok.swidth[i] = 0;
  }
  len = s21_strlen(opt->fmt.delim);
  for (s21_size_t i = 0; i < len; i++) {
    opt->fmt.delim[i] = 0;
  }
  opt->fmt.pdel = opt->fmt.delim;
  *(opt->tok.swidth) = '1';
  opt->tok.lenght = 0;
}

void case_decimal(Opt *opt, const char **fmt, int *success, const char **pb,
                  char **spb, int flags[], va_list ap, char *substring) {
  opt->tok.spec = *(*fmt);
  int res = pars_d(pb, spb, opt);
  if (res > 0 && !flags[SUPPRESS]) {
    if (opt->tok.lenght == 'h') {
      opt->hd = va_arg(ap, short *);
      if (opt->tok.spec == 'o')
        *opt->hd = (short)s21_strtol(substring, 8);
      else if (opt->tok.spec == 'x' || opt->tok.spec == 'X')
        *opt->hd = (short)s21_strtol(substring, 16);
      else if (opt->tok.spec == 'u')
        *opt->hd = (short)s21_strtoul(substring, 10);
      else
        *opt->hd = (short)s21_strtol(substring, 10);
    } else if (opt->tok.lenght == 'l') {
      opt->ld = va_arg(ap, s21_size_t *);
      if (opt->tok.spec == 'o') *opt->ld = (s21_size_t)s21_strtol(substring, 8);
      if (opt->tok.spec == 'x' || opt->tok.spec == 'X')
        *opt->ld = (s21_size_t)s21_strtol(substring, 16);
      else if (opt->tok.spec == 'u')
        *opt->ld = (s21_size_t)s21_strtoul(substring, 10);
      else
        *opt->ld = (s21_size_t)s21_strtol(substring, 10);
    } else if (opt->tok.lenght == 'L') {
      opt->Ld = va_arg(ap, long long int *);
      if (opt->tok.spec == 'o') *opt->Ld = s21_strtol(substring, 8);
      if (opt->tok.spec == 'x' || opt->tok.spec == 'X')
        *opt->Ld = s21_strtol(substring, 16);
      else if (opt->tok.spec == 'u')
        *opt->Ld = s21_strtoul(substring, 10);
      else
        *opt->Ld = s21_strtol(substring, 10);
    } else if (opt->tok.lenght == 's') {
      opt->sc = va_arg(ap, signed char *);
      if (opt->tok.spec == 'o')
        *opt->sc = (signed char)s21_strtol(substring, 8);
      if (opt->tok.spec == 'x' || opt->tok.spec == 'X')
        *opt->sc = (signed char)s21_strtol(substring, 16);
      else if (opt->tok.spec == 'u')
        *opt->sc = (signed char)s21_strtoul(substring, 10);
      else
        *opt->sc = (signed char)s21_strtol(substring, 10);
    } else {
      opt->d = va_arg(ap, int *);
      if (opt->tok.spec == 'o')
        *opt->d = (int)s21_strtol(substring, 8);
      else if (opt->tok.spec == 'x' || opt->tok.spec == 'X' ||
               (opt->tok.spec == 'i' && opt->tok.base == 16))
        *opt->d = (int)s21_strtol(substring, 16);
      else if (opt->tok.spec == 'o' ||
               (opt->tok.spec == 'i' && opt->tok.base == 8))
        *opt->d = (int)s21_strtol(substring, 8);
      else if (opt->tok.spec == 'u')
        *opt->d = (int)s21_strtoul(substring, 10);
      else
        *opt->d = (int)s21_strtol(substring, 10);
    }
    *success += res;
  }
  if (res < 0 && *success == 0) *success = res;

  res = 0;
  (*fmt)++;
}

void skip_spaces(const char **pb) {
  while (*(*pb) == ' ' || *(*pb) == '\t') (*pb)++;
}

int delimiter_check(Opt *opt, const char **pb) {
  int success = 1;
  int exit = 0;
  char *pdel = opt->fmt.delim;

  if (*opt->fmt.delim != 0) {
    if (*pdel == ' ') {
      pdel++;
      if (*(*pb) == ' ') {
        skip_spaces(pb);
      }
    } else if (*pdel != ' ' && *(*pb) == ' ') {
      success = 0;
      exit = 1;
    }

    while (*pdel && !exit) {
      if (*(*pb) == ' ') {
        skip_spaces(pb);
      }
      if (*pdel++ != *(*pb)++) {
        success = 0;
        exit = 1;
      }
    }
  }
  return success;
}

int pars_s(const char **pb, char **spb, Opt *opt, int flags[]) {
  int success = 1;
  if (*(*pb)) {
    success = delimiter_check(opt, pb);

    while ((*(*pb) == ' ' || *(*pb) == '\t') && opt->tok.spec == 's') (*pb)++;

    if ((opt->tok.spec == 's' || flags[WIDTH]) && success) {
      for (int i = 0; i < opt->tok.width && *(*pb) != ' ' && *(*pb) != '\0';
           i++) {
        success = 1;
        *(*spb) = *(*pb);
        (*pb)++;
        (*spb)++;
      }
    } else if (*(*pb) != '\0' && success && !flags[WIDTH]) {
      success = 1;
      *(*spb) = *(*pb);
      (*pb)++;
      (*spb)++;
    } else if (*(*pb) != '\0' && success && flags[WIDTH]) {
      for (int i = 0; i < opt->tok.width && *(*pb) != '\0'; i++) {
        success = 1;
        *(*spb) = *(*pb);
        (*pb)++;
        (*spb)++;
      }
    } else {
      success = 0;
    }
    *(*spb) = '\0';
    // if (*(*pb) == ' ' && opt->tok.spec == 's') (*pb)++;
  } else {
    success = -1;
  }
  return success;
}

void pars_d_fill(Opt *opt, const char **pb, char **spb, int *success,
                 int *exit) {
  for (int i = 0;
       i < opt->tok.width && *(*pb) != ' ' && *(*pb) != '\0' &&
       ((*(*pb) >= '0' && *(*pb) <= '9') || (*(*pb) >= 'a' && *(*pb) <= 'f') ||
        (*(*pb) >= 'A' && *(*pb) <= 'F'));
       i++) {
    if (*exit) break;

    if ((opt->tok.spec != 'x' && opt->tok.spec != 'X') &&
        ((*(*pb) >= 'a' && *(*pb) <= 'f') || (*(*pb) >= 'A' && *(*pb) <= 'F')))
      break;
    if (opt->tok.spec == 'o' && *(*pb) > '7') break;
    if (opt->tok.spec == 'u' && *(*pb) == '-') {
      (*pb)++;
      continue;
    }

    if ((*(*pb) >= 'a' && *(*pb) <= 'f') || (*(*pb) >= 'A' && *(*pb) <= 'F'))
      opt->tok.base = 16;

    *success = 1;
    *(*spb) = *(*pb);
    (*pb)++;
    (*spb)++;
  }
}

int pars_d(const char **pb, char **spb, Opt *opt) {
  int success = 0;
  int was_sign = 0;
  int exit = 0;

  opt->tok.base = 10;

  if (*(*pb)) {
    exit = !delimiter_check(opt, pb) ? 1 : 0;

    while (*(*pb) == ' ' || *(*pb) == '\t') (*pb)++;

    if (!*(*pb)) success = -1;

    if (*(*pb) == '-' || *(*pb) == '+') {
      if (was_sign) {
        success = 0;
        exit = 1;
      }
      opt->tok.width--;
      *(*spb) = *(*pb);
      (*pb)++;
      (*spb)++;
      was_sign = 1;
    }

    if (opt->tok.spec == 'x' || opt->tok.spec == 'X' || opt->tok.spec == 'o' ||
        opt->tok.spec == 'i') {
      if (*(*pb) == '0' && (*(*(pb) + 1) == 'x' || *(*(pb) + 1) == 'X') &&
          ((*(*pb + 2) >= '0' && *(*pb + 2) <= '9') ||
           (*(*pb + 2) >= 'a' && *(*pb + 2) <= 'f') ||
           (*(*pb + 2) >= 'A' && *(*pb + 2) <= 'F'))) {
        opt->tok.spec = 'x';
        opt->tok.base = 16;
        opt->tok.width -= 2;
        *(pb) += 2;
      } else if (*(*pb) == '0' && *(*(pb) + 1) >= '0' && *(*(pb) + 1) <= '7') {
        opt->tok.base = 8;
        opt->tok.width -= 1;
        *(pb) += 1;
      }
    }

    pars_d_fill(opt, pb, spb, &success, &exit);

    *(*spb) = '\0';
  } else {
    success = -1;
  }
  // if (*(*pb) == ' ') (*pb)++;

  return success;
}

void pars_f_fill(Opt *opt, const char **pb, char **spb, int *success, char *sub,
                 long double *result, int *was_e) {
  for (int i = 0;
       *success == 1 && i < opt->tok.width && *(*pb) != ' ' && *(*pb) != '\0' &&
       ((*(*pb) >= '0' && *(*pb) <= '9') || *(*pb) == '.' || *(*pb) == '+' ||
        *(*pb) == '-' || *(*pb) == 'e' || *(*pb) == 'E');
       i++) {
    if (*(*pb) == 'e' || *(*pb) == 'E') {
      *was_e = 1;
      (*pb)++;
      i++;
      *result = s21_atof(sub);
      if (*(*pb) == '+') {
        (*pb)++;
        i++;
        sub = (*spb);
        while (*(*pb) >= '0' && *(*pb) <= '9' && i < opt->tok.width) {
          *(*spb) = *(*pb);
          (*pb)++;
          (*spb)++;
          i++;
        }
        for (int j = 0; j < s21_strtol(sub, 10); j++) *result *= 10;
        break;
      } else if (*(*pb) == '-') {
        (*pb)++;
        i++;
        sub = (*spb);
        while (*(*pb) >= '0' && *(*pb) <= '9' && i < opt->tok.width) {
          *(*spb) = *(*pb);
          (*pb)++;
          (*spb)++;
          i++;
        }
        for (int j = 0; j < s21_strtol(sub, 10); j++) *result /= 10;
        break;
      } else {
        sub = (*spb);
        while (*(*pb) >= '0' && *(*pb) <= '9' && i < opt->tok.width) {
          *(*spb) = *(*pb);
          (*pb)++;
          (*spb)++;
          i++;
        }
        for (int j = 0; j < s21_strtol(sub, 10); j++) *result *= 10;
        break;
      }
    }
    *success = 1;
    *(*spb) = *(*pb);
    (*pb)++;
    (*spb)++;
  }
}

int pars_f(const char **pb, char **spb, Opt *opt, long double *result) {
  int success = 1;
  char *sub = (*spb);
  int was_e = 0;

  *result = 0;

  if (*(*pb)) {
    success = delimiter_check(opt, pb);

    while (*(*pb) == ' ' || *(*pb) == '\t') (*pb)++;

    if (!*(*pb)) success = -1;

    if ((*(*pb) < '0' || *(*pb) > '9') &&
        (*(*(pb) + 1) < '0' || *(*(pb) + 1) > '9'))
      success = 0;
    else if (*(*pb) == 'e' || *(*pb) == 'E')
      success = 0;

    pars_f_fill(opt, pb, spb, &success, sub, result, &was_e);
  } else {
    success = -1;
  }
  *(*spb) = '\0';
  if (*(*pb) == ' ') (*pb)++;
  if (!was_e) *result = (double)s21_atof(sub);
  return success;
}

void s21_width(const char **fmt, int flags[], Opt *opt) {
  if (*(*fmt) >= '0' && *(*fmt) <= '9') {
    flags[WIDTH] = 1;
    *opt->tok.swidth = 0;
    s21_strcat(opt->tok.swidth, (*fmt));
    (*fmt)++;
    while (*(*fmt) >= '0' && *(*fmt) <= '9') {
      s21_strcat(opt->tok.swidth, (*fmt));
      (*fmt)++;
    }
  } else {
    flags[WIDTH] = 0;
    opt->tok.width = SUB_BUF;
  }
}

void pars_fmt(const char **fmt, int flags[], Opt *opt) {
  if (*(*fmt) == '*') {
    flags[SUPPRESS] = 1;
    (*fmt)++;
  } else {
    flags[SUPPRESS] = 0;
  }

  s21_width(fmt, flags, opt);

  if (*(*fmt) == '*') {
    flags[SUPPRESS] = 1;
    (*fmt)++;
  }

  if (flags[WIDTH]) {
    opt->tok.width = s21_strtol(opt->tok.swidth, 10);
    if (opt->tok.width < 1) {
      flags[WIDTH] = 0;  // работает так, как если нет ширины
    }
  }

  if (*(*fmt) == 'h' || *(*fmt) == 'l' || *(*fmt) == 'L') {
    flags[LENGHT] = 1;
    opt->tok.lenght = *(*fmt);
    (*fmt)++;
  } else {
    flags[LENGHT] = 0;
    opt->tok.lenght = 0;
  }
  if (flags[LENGHT] && (*(*fmt) == 'h' || *(*fmt) == 'l')) {
    if (*(*fmt) == 'l')
      opt->tok.lenght = 'L';
    else
      opt->tok.lenght = 's';  // signed char
    (*fmt)++;
  }

  if (*(*fmt) == '.') {
    (*fmt)++;
  }
}

void p_case(Opt *opt, const char **fmt, int *success, const char **pb,
            char **spb, int flags[], va_list ap, char *substring) {
  opt->tok.spec = 'x';
  opt->address = va_arg(ap, void **);
  int res = pars_d(pb, spb, opt);
  if (res && !flags[SUPPRESS]) {
    if (res < 0 && *success == 0) {
      *success = -1;
    } else if (res > 0) {
      *success += res;
      unsigned long tmp = s21_strtoul(substring, 16);
      *opt->address = (void *)tmp;
    }
  }
  res = 0;
  (*fmt)++;
}

void s_case(Opt *opt, const char **fmt, int *success, const char **pb,
            char **spb, int flags[], va_list ap, char *substring) {
  opt->tok.spec = *(*fmt);
  int res = pars_s(pb, spb, opt, flags);

  if (res && !flags[SUPPRESS]) {
    if (opt->tok.spec == 's' || flags[WIDTH]) {
      if (opt->tok.lenght == 'l') {
        opt->ls = va_arg(ap, s21_wchar_t *);
        if (opt->tok.spec == 'c' && res > 0) {
          for (int i = 0; i < opt->tok.width; i++) {
            opt->ls[i] = substring[i];
          }
        } else if (res > 0) {
          s21_wchar_t *pls = opt->ls;
          char *psub = substring;
          while (*psub) {
            *pls++ = *psub++;
          }
        }
      } else {
        opt->s = va_arg(ap, char *);
        if (opt->tok.spec == 'c' && res > 0) {
          for (int i = 0; i < opt->tok.width; i++) {
            opt->s[i] = substring[i];
          }
        } else if (res > 0) {
          s21_strcpy(opt->s, substring);
        }
      }
    } else {
      if (opt->tok.lenght == 'l') {
        opt->lc = va_arg(ap, s21_wchar_t *);
        if (res > 0) *opt->lc = *substring;
      } else {
        opt->c = (char *)va_arg(ap, int *);
        if (res > 0) *opt->c = *substring;
      }
    }
    if (res < 0 && *success == 0)
      *success = res;
    else if (res > 0)
      *success += res;
  }
  res = 0;
  (*fmt)++;
}

void f_case(Opt *opt, const char **fmt, int *success, const char **pb,
            char **spb, int flags[], va_list ap, char *substring) {
  long double f_result = 0;
  int res = 1;

  if (!s21_strcmp(substring, "inf"))
    f_result = FLT_MAX * 2;
  else if (!s21_strcmp(substring, "-inf"))
    f_result = FLT_MAX * -2;
  else if (!s21_strcmp(substring, "nan"))
    f_result = NAN;
  else
    res = pars_f(pb, spb, opt, &f_result);

  if (res > 0 && !flags[SUPPRESS]) {
    if (opt->tok.lenght == 'l') {
      opt->lf = (double *)va_arg(ap, double *);
      *opt->lf = (double)f_result;
    } else if (opt->tok.lenght == 'L') {
      opt->Lf = va_arg(ap, long double *);
      *opt->Lf = f_result;
    } else {
      opt->f = (float *)va_arg(ap, double *);
      *opt->f = (float)f_result;
    }
  }
  if (res < 0 && *success == 0)
    *success = res;
  else if (res > 0)
    *success += res;
  res = 0;
  (*fmt)++;
}

void clean_sub(Opt *opt, char *substring, char **spb) {
  for (long unsigned int i = 0; i < sizeof(substring); i++) {
    substring[i] = 0;
  }
  (*spb) = substring;

  for (long unsigned int i = 0; i < sizeof(opt->fmt.delim); i++) {
    opt->fmt.delim[i] = 0;
  }
  opt->fmt.pdel = opt->fmt.delim;
}

void not_spec(Opt *opt, const char **fmt) {
  *opt->fmt.pdel++ = *(*fmt);
  (*fmt)++;
  while (*(*fmt) != '%' && *(*fmt) != '\0') {
    if (*(*fmt) == ' ') {
      (*fmt)++;
    } else {
      *opt->fmt.pdel++ = *(*fmt);
      (*fmt)++;
    }
  }
}

void spec(Opt *opt, const char **fmt, va_list ap, int *success, const char **pb,
          char **spb, int flags[], char *substring, const char *buf) {
  switch (*(*fmt)) {
    case 'n':
      opt->n = va_arg(ap, int *);
      if (*success > 0) *opt->n = (int)((*pb) - buf);
      fmt++;
      break;
    case 'p':
      p_case(opt, fmt, success, pb, spb, flags, ap, substring);
      break;
    case 'c':
    case 's': /* строка */
      s_case(opt, fmt, success, pb, spb, flags, ap, substring);
      break;
    case 'o':
    case 'x':
    case 'X':
    case 'u':
    case 'i':
    case 'd': /* целое */
      case_decimal(opt, fmt, success, pb, spb, flags, ap, substring);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      if (!s21_strcmp(s21_to_lower(buf), "inf") ||
          !s21_strcmp(s21_to_lower(buf), "+inf"))
        s21_strcpy(substring, "inf");
      else if (!s21_strcmp(s21_to_lower(buf), "-inf"))
        s21_strcpy(substring, "-inf");
      else if (!s21_strcmp(s21_to_lower(buf), "nan"))
        s21_strcpy(substring, "nan");

      f_case(opt, fmt, success, pb, spb, flags, ap, substring);
      break;
    default:
      fmt++;
      break;
  }
}

int s21_sscanf(const char *buf, const char *fmt, ...) {
  va_list ap;
  static Opt opt;  // static - задел на будущее, когда будет декомпозиция
  int success = 0;
  int argCount = 0;
  const char *pb = buf;
  char substring[SUB_BUF] = {};
  char *spb = substring;
  int flags[ALL] = {};

  initOpt(&opt);

  va_start(ap, fmt);
  for (s21_size_t i = 0; i < s21_strlen(fmt); i++) {  // s21_strlen
    if (fmt[i] == '%') argCount++;
  }

  while (*fmt) {
    if (*fmt == '%') {
      *opt.fmt.pdel = '\0';
      fmt++;
      if (*fmt == '\0') {
        break;
      }
      if (*fmt == '%') {  // если следующий знак тоже '%'
        int go = 0;
        for (; *pb != '\0';) {
          if (*pb == '%') {
            pb++;
            go = 1;
            break;
          } else if (*pb == ' ') {
            pb++;
            if (!success) success = -1;
            continue;
          } else {
            break;
          }
        }
        fmt++;
        if (go)
          continue;
        else
          break;
      }

      pars_fmt(&fmt, flags, &opt);  // разбираем строку buf
      spec(&opt, &fmt, ap, &success, &pb, &spb, flags, substring, buf);
      clean_sub(&opt, substring, &spb);
    } else if (*fmt) {
      not_spec(&opt, &fmt);
    }
  }
  va_end(ap);
  return success;
}
