#include "s21_string.h"

int s21_sprintf(char *str, cch *format, ...) {
  opt *opt = malloc(sizeof(*opt));
  opt->chars = DOWN;
  init_struct(opt);
  opt->help.end_simb = DOWN;
  setlocale(LC_ALL, "");
  setlocale(LC_ALL, "en_US.UTF-8");
  va_list arg;
  va_start(arg, format);
  s21_size_t agr_len = STR_LEN(format);
  s21_size_t simbol_n = 0;
  for (s21_size_t i = 0; i < agr_len; i++) {
    if (format[i] == '%') {
      i++;
      up_flags(opt, format, &i);
      up_width(opt, format, &i, arg);
      up_accur(opt, format, &i, arg);
      up_modif(opt, format, &i);
      specifier(str, opt, format, &i, &simbol_n, arg);
      if (opt->conv == 's' && opt->modifiers.l) {
        str[opt->help.end_simb] = 0;
        simbol_n++;
      }
      init_struct(opt);
    } else {
      str[simbol_n++] = format[i];
      opt->chars++;
    }
    if (i == agr_len - 1) str[simbol_n] = 0;
  }
  int result = opt->chars;
  va_end(arg);
  free(opt);
  return result;
}
void specifier(char *str, opt *opt, cch *format, s21_size_t *i,
               s21_size_t *simbol_n, va_list arg) {
  if (!opt->error) {
    opt->conv = opt->conv2 = format[*i];
    char tmp[10] = {opt->conv};
    if (opt->conv == 'c') {
      opt->help.tmp = 1;
      opt->accuracy.size = DOWN;
    } else if (opt->conv == '%') {
      str[(*simbol_n)++] = '%';
      opt->chars++;
    }
    if (opt->conv == 'n') {
      *(va_arg(arg, int *)) = opt->chars;
    } else if (s21_strcspn(tmp, "diucoxXeEgGsfFp") - 1)
      write_d2(opt, str, simbol_n, arg);
    else if (opt->conv != '%')
      str[(*simbol_n)++] = opt->conv;
  }
}
void up_modif(opt *opt, cch *format, s21_size_t *i) {
  if (!opt->error) {
    if (format[(*i)] == 'h') {
      if (format[(*i) + 1] == 'h') {
        opt->modifiers.hh = UP;
        (*i)++;
      }
      opt->modifiers.h = UP;
      (*i)++;
    } else if (format[(*i)] == 'l') {
      if (format[(*i) + 1] == 'l') {
        opt->modifiers.ll = UP;
        (*i)++;
      }
      opt->modifiers.l = UP;
      (*i)++;
    } else if (format[(*i)] == 'L') {
      opt->modifiers.L = UP;
      (*i)++;
    }
  }
}
void up_accur(opt *opt, cch *format, s21_size_t *i, va_list arg) {
  if (!opt->error) {
    if (format[*i] == '.') {
      (*i)++;
      int accur = 0;
      opt->accuracy.flag = UP;
      if (format[*i] == '*') {
        accur = (int)va_arg(arg, int);
        opt->accuracy.size_float = accur;
      }
      str_to_int(opt, &(opt->error), format, i, &(opt->accuracy.size), accur);
      if (opt->accuracy.size == 0)
        opt->accuracy.size_g = 1;
      else
        opt->accuracy.size_g = opt->accuracy.size;
    } else
      opt->accuracy.size_g = 6;
    if (opt->accuracy.size_float < 0) opt->accuracy.size_g = 6;
  }
}
void up_width(opt *opt, cch *format, s21_size_t *i, va_list arg) {
  int width = 0;
  if (format[*i] == '*') {
    width = (int)va_arg(arg, int);
  }
  str_to_int(opt, &(opt->error), format, i, &(opt->width.size), width);
}
void up_flags(opt *opt, cch *format, s21_size_t *i) {
  int x = 1;
  while (x) {
    if (format[*i] == '-') {
      (*i)++;
      opt->flags.flags = opt->flags.minus = UP;
      continue;
    } else if (format[*i] == '+') {
      (*i)++;
      opt->flags.flags = opt->flags.plus = UP;
      continue;
    } else if (format[*i] == ' ') {
      (*i)++;
      opt->flags.flags = opt->flags.space = UP;
      continue;
    } else if (format[*i] == '#') {
      (*i)++;
      opt->flags.flags = opt->flags.grid = UP;
      continue;
    } else if (format[*i] == '0') {
      (*i)++;
      opt->flags.flags = opt->flags.zero = UP;
      continue;
    }
    x = 0;
  }
}
void write_d2(opt *opt, char *str, s21_size_t *simbol_n, va_list arg) {
  char *tmp = S21_NULL;
  if (opt->conv == 'd' || opt->conv == 'i' || opt->conv == 'u' ||
      opt->conv == 'o') {
    s21d_itoa(opt, &tmp, arg);
    opt->help.tmp = STR_LEN(tmp);
  } else if (opt->conv == 'f' || opt->conv == 'e' || opt->conv == 'E' ||
             opt->conv == 'g' || opt->conv == 'G' || opt->conv == 'F') {
    s21f_itoa(opt, &tmp, arg);
    opt->help.tmp = STR_LEN(tmp);
  } else if (opt->conv == 'c') {
    tmp = (char *)calloc(10, sizeof(char));
    if (tmp != S21_NULL) {
      tmp[0] = (int)va_arg(arg, int);
    } else
      opt->error = UP;
  } else if (opt->conv == 's' && !opt->modifiers.l) {
    char *temp = (char *)va_arg(arg, char *);
    tmp = (char *)calloc(STR_LEN(temp) + 1, sizeof(char));
    if (tmp != S21_NULL) {
      s21_strcpy(tmp, temp);
      if (opt->accuracy.flag && opt->accuracy.size < STR_LEN(tmp)) {
        opt->help.tmp = opt->accuracy.size;
        tmp[opt->accuracy.size] = 0;
      } else
        opt->help.tmp = STR_LEN(tmp);
    } else
      opt->error = UP;
  } else if (opt->conv == 'p') {
    long unsigned int p = (long unsigned int)va_arg(arg, void *);
    decimal_to_hexa(opt, p, &tmp);
    opt->help.tmp = STR_LEN(tmp);
    opt->help.tmp_p = opt->help.tmp + 2;
  } else if (opt->conv == 'x' || opt->conv == 'X') {
    ull p = 0;
    spec_x(opt, arg, &p);
    decimal_to_hexa_ull(opt, p, &tmp);
    opt->help.tmp = STR_LEN(tmp);
  } else
    opt->error = UP;
  if (opt->error != UP) {
    if (opt->flags.minus) {
      write_sign(opt, simbol_n, str);
      write_p_simb(opt, simbol_n, str);
      write_accur(opt, simbol_n, str);
      write_number(opt, simbol_n, &tmp, str);
      write_width(opt, simbol_n, str);
    } else {
      write_width(opt, simbol_n, str);
      write_p_simb(opt, simbol_n, str);
      write_accur(opt, simbol_n, str);
      write_sign(opt, simbol_n, str);
      write_number(opt, simbol_n, &tmp, str);
    }
    free(tmp);
  }
}
void write_p_simb(opt *opt, s21_size_t *simbol_n, char *str) {
  if (opt->conv == 'p' && !opt->help.stop_p) {
    str[(*simbol_n)++] = '0';
    str[(*simbol_n)++] = 'x';
    opt->chars += 2;
    opt->help.stop_p = UP;
  }
}
void write_accur(opt *opt, s21_size_t *simbol_n, char *str) {
  if (opt->error == DOWN) {
    if (opt->conv != 'c' && opt->conv != 's') {
      s21_size_t tmp = 0;
      if (opt->accuracy.size > opt->help.tmp && opt->conv2 != 'g' &&
          opt->conv2 != 'G') {
        tmp = opt->accuracy.size - opt->help.tmp;
        if (opt->conv != 'u' && opt->conv != 'p')
          write_sign(opt, simbol_n, str);
        for (s21_size_t i = 0; i < tmp; i++) {
          str[(*simbol_n)++] = '0';
          opt->chars++;
        }
      }
    }
  }
}
void write_width(opt *opt, s21_size_t *simbol_n, char *str) {
  s21_size_t size = opt->help.tmp;
  s21_size_t accur = opt->accuracy.size;
  if (opt->conv == 'p') {
    size = opt->help.tmp_p;
    accur += 2;
  }
  if (opt->flags.zero && opt->conv != 'u' && opt->conv != 's' &&
      opt->conv != 'p') {
    write_sign(opt, simbol_n, str);
  }
  s21_size_t tmp = 0;
  if (opt->width.size > size) {
    tmp = opt->width.size - size;
    if (accur > size) {
      if (opt->width.size > accur && opt->conv != 's' && opt->conv2 != 'g' &&
          opt->conv2 != 'G')
        tmp = opt->width.size - accur;
      else if (opt->conv2 == 'g' || opt->conv2 == 'G')
        tmp = opt->width.size - opt->help.tmp;
      else if (opt->conv != 's')
        tmp = 0;
    }
    if (opt->conv == 'd' || opt->conv == 'f' || opt->conv == 'i' ||
        opt->conv == 'e' || opt->conv == 'E' || opt->conv == 'g' ||
        opt->conv == 'G') {
      if ((opt->help.sign || opt->flags.plus || opt->flags.space) && tmp > 0)
        tmp--;
    }
    if (opt->conv == 'p' && opt->flags.zero) write_p_simb(opt, simbol_n, str);
    for (s21_size_t i = 0; i < tmp; i++) {
      str[(*simbol_n)++] = (!opt->flags.minus && opt->flags.zero) ? '0' : ' ';
      opt->chars++;
    }
  }
  opt->help.end_simb = *simbol_n;
}
void write_sign(opt *opt, s21_size_t *simbol_n, char *str) {
  if (opt->error == DOWN) {
    if (opt->conv == 'd' || opt->conv == 'f' || opt->conv == 'i' ||
        opt->conv == 'e' || opt->conv == 'E' || opt->conv == 'g' ||
        opt->conv == 'G') {
      if (!opt->help.width_zero &&
          (opt->flags.plus || opt->help.sign ||
           opt->accuracy.size > opt->help.tmp || opt->flags.space)) {
        if (opt->help.sign) {
          str[(*simbol_n)++] = '-';
          opt->chars++;
        } else if (opt->flags.plus && opt->conv != 'c') {
          str[(*simbol_n)++] = '+';
          opt->chars++;
        } else if (opt->flags.space) {
          str[(*simbol_n)++] = ' ';
          opt->chars++;
        }
        opt->help.width_zero = UP;
      }
    }
  } else if (opt->error == INF_SPR || opt->error == NAN_SPR) {
    if (opt->help.sign) str[(*simbol_n)++] = '-';
  }
}
void write_number(opt *opt, s21_size_t *simbol_n, char **tmp, char *str) {
  for (s21_size_t i = *simbol_n, v = 0; *simbol_n < i + opt->help.tmp;) {
    str[(*simbol_n)++] = (*tmp)[v++];
    opt->chars++;
  }
  opt->help.end_simb = *simbol_n;
}
void round_d(opt *opt, ld *acc_tmp, s21_size_t max, int sign) {
  for (s21_size_t i = 0; i < max; i++) {
    if (sign == DOWN) {
      *acc_tmp /= 10;
      opt->help.c_round++;
    } else {
      *acc_tmp *= 10;
      opt->help.c_round--;
    }
  }
}
void inf_nan(opt *opt, char **str) {
  if (opt->error == INF_SPR || opt->error == NAN_SPR) {
    char *tmp = calloc(10, sizeof(char));
    if (tmp == S21_NULL)
      opt->error = UP;
    else {
      opt->help.int_size = 3;
      opt->accuracy.size = 0;
      *str = tmp;
      (*str)[0] = 'i';
      (*str)[1] = 'n';
      (*str)[2] = 'f';
      if (opt->error == NAN_SPR) {
        (*str)[0] = (*str)[2] = 'n';
        (*str)[1] = 'a';
      }
    }
  }
}
void integer_part(opt *opt, char **memory_str, ld *int1, ld *double1,
                  ld *acc_tmp, ld double3) {
  if (!opt->error) {
    (void)double3;
    if (opt->accuracy.flag == DOWN) opt->accuracy.size = 6;
    if (!opt->help.g_exp_s) {
      *double1 += *acc_tmp;
    }
    modfl(*double1, int1);
    if (*int1 > 0) opt->help.num_step_e = opt->help.int_size - 1;
    char *temp = S21_NULL;
    temp = (char *)realloc(temp, (opt->help.int_size + 10) * sizeof(char));
    if (temp == S21_NULL)
      opt->error = UP;
    else {
      *memory_str = temp;
      s21f2_itoa(opt, memory_str, *int1);
      opt->help.tmp = STR_LEN(*memory_str);
    }
  }
}
ld roundVal_e(ld value, int decimalPlaces) {
  value = roundl(value * pow(10, decimalPlaces)) / pow(10, decimalPlaces);
  return value;
}
void e_part(opt *opt, char **memory_str, ld double2, ld double3) {
  if (!opt->error) {
    int tmp = abs(opt->help.g_exp);
    ld x3 = fabsl(roundl(double2) * 10);
    ld x2 = fabsl(fmodl(x3, 10));
    int x4 = fabsl(roundl(double2) / 10);
    if (opt->accuracy.size_g == 1 && x2 == 0 && tmp < 2) tmp--;
    if (tmp < 0) tmp = 0;
    if (opt->accuracy.size_g == 1 && x2 == 0 && x4 > 0 && tmp == 0) tmp++;
    s21_size_t len = STR_LEN(*memory_str);
    ld int1 = 0;
    // (void)tmp2;
    (void)double3;
    double2 = fabsl(double2);
    modfl(double2, &int1);
    if (int1 >= 1) {
      for (s21_size_t tchk = s21_strcspn(*memory_str, "."); 1 < tchk; tchk--)
        (*memory_str)[tchk] = (*memory_str)[tchk - 1];
      (*memory_str)[1] = '.';
      if ((*memory_str)[0] == '0') {
        for (s21_size_t tchk = 0; tchk < len; tchk++) {
          if (tchk == 0) (*memory_str)[tchk] = (*memory_str)[tchk + 2];
          if (1 < tchk) (*memory_str)[tchk] = (*memory_str)[tchk + 1];
        }
      }
    } else {
      s21_size_t i = 0, j = tmp + 1;
      while (i < opt->accuracy.size + 2 && j > 1) {
        if (i == 1) i++;
        (*memory_str)[i++] = j >= len ? '0' : (*memory_str)[j++];
      }
    }
    len = opt->accuracy.size + 2;
    len == 2 ? len = 1 : len;
    if (opt->conv2 == 'g' || opt->conv2 == 'G') {
      if (52 < (*memory_str)[len] && (*memory_str)[len] < 58) {
        if ((*memory_str)[len - 1] == '9')
          (*memory_str)[len - 1] = '0';
        else
          (*memory_str)[len - 1] = (*memory_str)[len - 1] + 1;
      }
      if (!opt->flags.grid) {
        for (int i = len; (*memory_str)[i - 1] == '0'; i--) {
          (*memory_str)[i - 1] = 0;
          len = STR_LEN(*memory_str);
        }
      }
    }
    if ((*memory_str)[len - 1] == '.') len--;
    (*memory_str)[len] = opt->conv;
    (*memory_str)[++len] = (int1 < 1 ? '-' : '+');
    if (tmp < 10) {
      (*memory_str)[++len] = '0';
      (*memory_str)[++len] = tmp + 48;
      if ((*memory_str)[len] == '0' && (*memory_str)[len - 1] == '0')
        (*memory_str)[len - 2] = '+';
    } else {
      len += num_digs(tmp, 10);
      for (s21_size_t i = num_digs(tmp, 10), j = 0; 0 < i; i--, j++) {
        (*memory_str)[len - j] = (tmp % 10) + 48;
        tmp = tmp / 10;
      }
    }
    (*memory_str)[++len] = 0;
  }
}
int intwrite(ld x, int i) {
  ld y = fmodl(x, (ld)pow(10, i));
  y /= (ld)pow(10, i - 1);
  return y;
}
void s21f2_itoa(opt *opt, char **memory_str, ld int1) {
  if (!opt->error) {
    int i = how_many_cifer(int1);
    if (int1 < 0) int1 *= -1;
    (*memory_str)[i--] = '\0';
    for (int j = 0, x = 1; i > -1; i--, x++) {
      j = intwrite(int1, x);
      (*memory_str)[i] = j + 48;
    }
  }
}
void s21_itoa_e(opt *opt, ld double1) {
  if (!opt->error) {
    long double double2 = double1;
    int i = 1;
    if (double2 != 0) {
      if (double2 < 0) double2 *= -1;
      int x = double2;
      for (; x == 0; i++) {
        double2 *= 10;
        x = double2 * 10;
      }
    }
    opt->help.num_step_e = --i;
  }
}
void fractional_part(opt *opt, char **memory_str, ld *int1, ld *double1,
                     ld *acc_tmp) {
  if (!opt->error) {
    int for_e = 0;
    if (*int1 < 1 && opt->conv != 'f' && opt->conv != 'F')
      s21_itoa_e(opt, *double1);
    s21_size_t x = STR_LEN(*memory_str);
    (*memory_str)[x] = '.';
    (*memory_str)[x + 1] = 0;
    opt->help.tmp = x;
    char *tmp = S21_NULL;
    tmp = calloc(10, sizeof(char));
    char *temp2 = S21_NULL;
    *double1 = modfl(*double1, int1);
    // *double1 -= *int1;
    if (*int1 == 0 && (opt->conv == 'e' || opt->conv == 'E')) for_e++;
    int for_acc = (int)opt->accuracy.size + for_e;
    if ((opt->help.g_exp_s || opt->help.c_round) && opt->conv != 'f' &&
        opt->conv != 'F') {
      for_acc = 308;
      int acc_g = (int)opt->accuracy.size + 1;
      if (opt->modifiers.L) acc_g -= 1;
      int tmp33 = round(*double1 * pow(10, acc_g));
      if (tmp33 == 0 && for_acc != 308) *double1 -= *acc_tmp;
    }
    for (int i = 0; i < for_acc; i++) {
      temp2 = (char *)realloc(
          *memory_str, (STR_LEN(*memory_str) + for_acc + 5) * sizeof(char));
      if (temp2 == S21_NULL || tmp == S21_NULL)
        opt->error = UP;
      else {
        *memory_str = temp2;
        *double1 *= 10;
        opt->accuracy.size_double += 1;
        int int2 = *double1;
        *double1 -= int2;
        if (i < for_acc + 1) {
          s21f2_itoa(opt, &tmp, int2);
          int2 = 0;
          s21_strcat(*memory_str, tmp);
          opt->help.tmp++;
        }
      }
    }
    free(tmp);
    if (opt->conv == 'g' || opt->conv == 'G')
      opt->help.tmp =
          (int)opt->accuracy.size + opt->help.sign + opt->help.int_size;
    (*memory_str)[opt->help.tmp++ + 1] = 0;
    if ((opt->conv2 == 'g' || opt->conv2 == 'G')) {
      if (!opt->flags.grid) {
        if (opt->accuracy.size_g > opt->help.int_size &&
            (*memory_str)[0] != '0')
          (*memory_str)[opt->accuracy.size_g + 1] = 0;
        while ((*memory_str)[STR_LEN(*memory_str) - 1] == '0')
          (*memory_str)[STR_LEN(*memory_str) - 1] = 0;
        if (opt->accuracy.size > opt->help.int_size && (*memory_str)[0] != '0')
          (*memory_str)[opt->accuracy.size + 1] = 0;
      } else {
        if (*int1 != 0 && opt->accuracy.size < 7)
          (*memory_str)[opt->accuracy.size + 1] = 0;
        else if (*int1 != 0)
          (*memory_str)[opt->accuracy.size_g + 1] = 0;
      }
    }
  }
  if ((*memory_str)[STR_LEN(*memory_str) - 1] == '.')
    (*memory_str)[STR_LEN(*memory_str) - 1] = 0;
  // }
}
void s21f_itoa(opt *opt, char **memory_str, va_list arg) {
  if (!opt->error) {
    if (opt->accuracy.size_float < 0 ||
        (!opt->accuracy.flag && !opt->accuracy.size))
      opt->accuracy.size = 6;
    ld int1 = 0;
    ld double1 = 0;
    spec_f(opt, arg, &double1);
    ld double2 = double1;
    ld double3 = 0;
    ld acc_tmp = 0.5000000001;
    if (!(opt->error == INF_SPR || opt->error == NAN_SPR)) {
      round_d(opt, &acc_tmp, opt->accuracy.size, DOWN);
      opt->help.int_size = how_many_cifer(double1);
      opt->help.g_exp = find_e(double2);
      int p = (int)opt->accuracy.size - 1 < 1 ? 1 : (int)opt->accuracy.size - 1;
      double3 = modfl(double1, &int1);
      if (opt->conv == 'g' || opt->conv == 'G') {
        opt->help.c_round = DOWN;
        if (p > find_e(double2) && find_e(double2) >= -4 &&
            opt->help.int_size <= opt->accuracy.size_g) {
          p = (p - find_e(double2)) < 0 ? 1 : p - find_e(double2);
          acc_tmp = 0.5000000001;
          int max = opt->accuracy.size - opt->help.int_size;
          if (max < 0) max = 0;
          if (int1 == 0)
            round_d(opt, &acc_tmp, max + 1, DOWN);
          else
            round_d(opt, &acc_tmp, max, DOWN);
          opt->accuracy.size = p;
        } else {
          acc_tmp = 0.5000000001;
          opt->accuracy.size = p;
          round_d(opt, &acc_tmp, opt->accuracy.size, DOWN);
          if (opt->conv == 'g') opt->conv = 'e';
          if (opt->conv == 'G') opt->conv = 'E';
        }
      } else if (opt->conv2 == 'e' || opt->conv2 == 'E') {
        if (opt->help.int_size == 1) {
          round_d(opt, &acc_tmp, opt->help.int_size, DOWN);
        } else
          round_d(opt, &acc_tmp, opt->help.int_size - 1, UP);
      }
      if (double1 < 0) {
        double1 *= -1;
        opt->help.sign = UP;
      }
      integer_part(opt, memory_str, &int1, &double1, &acc_tmp, double3);
      if (opt->conv != 'g' && opt->conv != 'G') {
        fractional_part(opt, memory_str, &int1, &double1, &acc_tmp);
        if (opt->accuracy.size == 0 && opt->accuracy.flag &&
            opt->help.int_size == 1 && opt->width.size > 0) {
          (*memory_str)[STR_LEN(*memory_str) + 1] = 0;
          (*memory_str)[STR_LEN(*memory_str)] = '.';
        }
      } else if (opt->accuracy.size_g > opt->help.int_size)
        fractional_part(opt, memory_str, &int1, &double1, &acc_tmp);
      else if (opt->flags.grid && opt->accuracy.size_g == 1) {
        (*memory_str)[STR_LEN(*memory_str) + 1] = 0;
        (*memory_str)[STR_LEN(*memory_str)] = '.';
      }
      if (opt->conv == 'e' || opt->conv == 'E')
        e_part(opt, memory_str, roundVal_e(double2, (int)opt->accuracy.size),
               double3);
    } else
      inf_nan(opt, memory_str);
  }
}
void spec_d(opt *opt, va_list arg, lli *arg_d) {
  if (!opt->error) {
    if (opt->modifiers.hh) {
      *arg_d = (lli)(char)va_arg(arg, int);
    } else if (opt->modifiers.h) {
      *arg_d = (lli)(short int)va_arg(arg, int);
    } else if (opt->modifiers.ll) {
      *arg_d = (lli)va_arg(arg, lli);
    } else if (opt->modifiers.l) {
      *arg_d = (lli)va_arg(arg, long int);
    } else {
      *arg_d = (lli)(int)va_arg(arg, int);
    }
  }
}
void null(opt *opt, ld val) {
  if (val < (double)0.000001 && val != 0) {
    ld tmp = val;
    if (tmp < 0) tmp *= -1;
    int x = 0;
    while (tmp < (double)1.) {
      tmp *= 10;
      x++;
    }
    opt->help.g = x;
  }
}
ld roundValue(opt *opt, ld value, int decimalPlaces) {
  null(opt, value);
  int step = find_e((ld)value);
  if (step < 0) step *= -1;
  if (step > decimalPlaces && value > 1)
    decimalPlaces = step;
  else if (decimalPlaces < 1)
    decimalPlaces = 6;
  else if (decimalPlaces > 20)
    decimalPlaces = 20;
  if (find_e((ld)value) < (int)opt->accuracy.size)
    value = roundl(value * pow(10, decimalPlaces)) / pow(10, decimalPlaces);
  return value;
}
void spec_f(opt *opt, va_list arg, ld *arg_f) {
  if (!opt->error) {
    if (opt->modifiers.L) {
      *arg_f = (ld)va_arg(arg, ld);
      opt->help.long_f = UP;
    } else {
      ld tmp = (ld)va_arg(arg, double);
      ld tmp2 = (ld)roundValue(opt, tmp, opt->accuracy.size);
      *arg_f = tmp2;
      if (fabsl(tmp) > fabsl(tmp2)) {
        *arg_f = tmp;
        opt->help.g_exp_s = UP;
      }
      if (isnan(*arg_f))
        opt->error = NAN_SPR;
      else if (-INFINITY == *arg_f) {
        opt->error = INF_SPR;
        opt->help.sign = UP;
      } else if (INFINITY == *arg_f)
        opt->error = INF_SPR;
      opt->help.g = find_e(*arg_f);
    }
  }
}
void spec_u(opt *opt, va_list arg, ul *arg_u) {
  if (!opt->error) {
    if (opt->modifiers.h) {
      *arg_u = (unsigned short)va_arg(arg, unsigned int);
    } else if (opt->modifiers.l) {
      *arg_u = va_arg(arg, unsigned long);
    } else {
      *arg_u = va_arg(arg, unsigned int);
    }
  }
}
void spec_o(opt *opt, va_list arg, ul *arg_o) {
  if (!opt->error) {
    if (opt->modifiers.h) {
      *arg_o = (unsigned short)va_arg(arg, unsigned int);
    } else if (opt->modifiers.l) {
      *arg_o = (unsigned long)va_arg(arg, unsigned long);
    } else {
      *arg_o = va_arg(arg, unsigned int);
    }
  }
}
void spec_x(opt *opt, va_list arg, ull *arg_x) {
  if (!opt->error) {
    if (opt->modifiers.hh) {
      *arg_x = (ull)(unsigned char)va_arg(arg, unsigned int);
    } else if (opt->modifiers.h) {
      *arg_x = (ull)(unsigned short)va_arg(arg, unsigned int);
    } else if (opt->modifiers.ll) {
      *arg_x = (ull)va_arg(arg, ull);
    } else if (opt->modifiers.l) {
      *arg_x = (ull)(unsigned long)va_arg(arg, unsigned long);
    } else {
      *arg_x = (ull)va_arg(arg, unsigned int);
    }
  }
}
int num_digs(lli n, int radix) {
  if (n < 0) n *= -1;
  int c = 0;
  do {
    c++;
    n /= radix;
  } while (n > 0);
  return c;
}
void s21d_itoa(opt *opt, char **memory_str, va_list arg) {
  if (!opt->error) {
    if (opt->conv == 'd' || opt->conv == 'i') {
      long long int arg_d = 0;
      spec_d(opt, arg, &arg_d);
      if (arg_d < 0) {
        arg_d *= -1;
        opt->help.sign = UP;
      }
      int i = num_digs(arg_d, 10);
      *memory_str = calloc(i + 10, sizeof(char));
      if (*memory_str == S21_NULL)
        opt->error = UP;
      else {
        (*memory_str)[i--] = '\0';
        for (; i > -1; i--) {
          (*memory_str)[i] = (arg_d % 10) + 48;
          arg_d = arg_d / 10;
        }
      }
    } else if (opt->conv == 'u') {
      unsigned long arg_u = 0;
      spec_u(opt, arg, &arg_u);
      int i = num_digs(arg_u, 10);
      *memory_str = calloc(i + 10, sizeof(char));
      if (*memory_str == S21_NULL)
        opt->error = UP;
      else {
        (*memory_str)[i--] = '\0';
        for (; i > -1; i--) {
          (*memory_str)[i] = (arg_u % 10) + 48;
          arg_u = arg_u / 10;
        }
      }
    } else if (opt->conv == 'o') {
      unsigned long arg_o = 0;
      spec_o(opt, arg, &arg_o);
      int i = num_digs(arg_o, 8);
      *memory_str = calloc(i + 8, sizeof(char));
      if (*memory_str == S21_NULL)
        opt->error = UP;
      else {
        (*memory_str)[i--] = '\0';
        for (; i > -1; i--) {
          (*memory_str)[i] = (arg_o % 8) + 48;
          arg_o = arg_o / 8;
        }
      }
    }
  }
}
void str_to_int(opt *opt, int *error, cch *format, s21_size_t *i,
                s21_size_t *digit, int width_accur) {
  if (!opt->error) {
    if (format[*i] == '*') {
      int tmp = width_accur;
      if (tmp < 0) {
        if (!opt->help.stop_star) {
          *digit = (s21_size_t)tmp * -1;
          opt->flags.minus = UP;
        } else
          *digit = 1;
      } else
        *digit = (s21_size_t)tmp;
      (*i)++;
      if (*digit > MAX_INT_D) {
        *error = UP;
      }
    } else {
      if ('0' <= format[*i] && format[*i] <= '9') {
        char ch[LEN_LONG_LONG_INT] = {0};
        for (int k = 0; '0' <= format[*i] && format[*i] <= '9'; (*i)++, k++) {
          if (k < LEN_LONG_LONG_INT) {
            ch[k] = format[(*i)];
            ch[k + 1] = 0;
          } else if (k > LEN_LONG_LONG_INT && *error != UP) {
            *error = UP;
          }
        }
        if (s21d_atoi(ch) <= MAX_INT_D) {
          *digit = s21d_atoi(ch);
        } else {
          *error = UP;
        }
      }
    }
    opt->help.stop_star = UP;
  }
}
int s21d_atoi(char *s) {
  int n = 0;
  while (*s >= '0' && *s <= '9') {
    n *= 10;
    n += *s++;
    n -= '0';
  }
  return n;
}
void init_struct(opt *opt) {
  opt->accuracy.size = DOWN;
  opt->accuracy.size_double = DOWN;
  opt->accuracy.size_float = DOWN;
  opt->accuracy.flag = DOWN;
  opt->conv = DOWN;
  opt->flags.grid = DOWN;
  opt->flags.minus = DOWN;
  opt->flags.plus = DOWN;
  opt->flags.space = DOWN;
  opt->flags.zero = DOWN;
  opt->flags.flags = DOWN;
  opt->modifiers.h = DOWN;
  opt->modifiers.hh = DOWN;
  opt->modifiers.l = DOWN;
  opt->modifiers.ll = DOWN;
  opt->modifiers.L = DOWN;
  opt->width.size = DOWN;
  opt->error = DOWN;
  opt->help.sign = DOWN;
  opt->help.tmp = DOWN;
  opt->help.tmp_p = DOWN;
  opt->help.size = DOWN;
  opt->help.width_zero = DOWN;
  opt->help.stop_star = DOWN;
  opt->help.stop_p = DOWN;
  opt->help.num_step_e = DOWN;
  opt->help.long_f = DOWN;
  opt->help.g = DOWN;
  opt->help.g_exp = DOWN;
  opt->help.g_exp_s = DOWN;
  opt->help.c_round = DOWN;
  opt->help.int_size = DOWN;
  opt->help.g = DOWN;
  for (int i = 0; i < STR; i++) {
    opt->help.tmp_str[i] = DOWN;
  }
}
void decimal_to_hexa(opt *opt, lli decimal, char **buf) {
  int grid = 0;
  if (opt->flags.grid) grid = 2;
  int i = num_digs(decimal, 16) + 1 + grid;
  *buf = (char *)calloc(i--, sizeof(char));
  if (opt->flags.grid && opt->conv == 'x')
    s21_strcat(*buf, "0x");
  else if (opt->flags.grid && opt->conv == 'X')
    s21_strcat(*buf, "0X");
  long long int rem = 0;
  while (decimal > 0) {
    i--;
    rem = decimal % 16;
    if (rem < 10) {
      (*buf)[i] = 48 + rem;
    } else {
      (*buf)[i] = rem + (opt->conv == 'X' ? 55 : 87);
    }
    decimal = decimal / 16;
  }
}
void decimal_to_hexa_ull(opt *opt, ull decimal, char **buf) {
  int grid = 0;
  if (opt->flags.grid) grid = 2;
  int i = num_digs(decimal, 16) + 1 + grid;
  *buf = (char *)calloc(i--, sizeof(char));
  if (opt->flags.grid && opt->conv == 'x')
    s21_strcat(*buf, "0x");
  else if (opt->flags.grid && opt->conv == 'X')
    s21_strcat(*buf, "0X");
  long long int rem = 0;
  while (decimal > 0) {
    i--;
    rem = decimal % 16;
    if (rem < 10) {
      (*buf)[i] = 48 + rem;
    } else {
      (*buf)[i] = rem + (opt->conv == 'X' ? 55 : 87);
    }
    decimal = decimal / 16;
  }
}
int find_e(ld x) {
  int tmp = x;
  int res = 0;
  if (x < 0) {
    x = x * (-1);
  }
  if (x >= 10 && res == 0 && x != INFINITY && x != NAN) {
    for (; x >= 10;) {
      x = x / 10;
      res = res + 1;
    }
  } else if (x > 0 && x < 1 && res == 0) {
    for (; x < 1;) {
      x = x * 10;
      res = res - 1;
    }
  }
  if (1 < tmp) res *= -1;
  return res;
}
int how_many_cifer(ld a) {
  if (a < 0) {
    a = a * (-1);
  }
  ld res = a;
  modfl(res, &res);
  int count = 1;
  while (res >= 10) {
    res = res / 10;
    count++;
  }
  return count;
}