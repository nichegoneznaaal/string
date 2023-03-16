#include "s21_string.h"

void *s21_insert(const char *str1, const char *str2, s21_size_t start_index) {
  int flag = 0;
  char *p_s21_null = S21_NULL;
  char *new_str = S21_NULL;
  if (!(str1 == S21_NULL || str2 == S21_NULL)) {
    size_t str1_l = s21_strlen(str1) + 1;
    size_t str2_l = s21_strlen(str2) + 1;
    s21_size_t SIZE_STR_SUB = str2_l + str1_l;
    new_str = (char *)calloc(SIZE_STR_SUB, sizeof(char));
    if (!(start_index >= str1_l)) {
      int flag_exit = 1;
      for (s21_size_t i = 0, k = 0, j = 0; flag_exit;) {
        flag_exit = 0;
        if (i < start_index) {
          new_str[i] = str1[j];
          flag_exit = 1;
          i++;
          j++;
          continue;
        }
        if (i < str2_l - 1 + j) {
          new_str[i] = str2[k];
          i++;
          k++;
          flag_exit = 1;
          continue;
        }
        if (i < (SIZE_STR_SUB - 1)) {
          new_str[i] = str1[j++];
          flag_exit = 1;
          i++;
        }
      }
    } else {
      flag = 1;
    }
  } else if (str1 == S21_NULL || str2 == S21_NULL) {
    p_s21_null = S21_NULL;
    flag = 1;
  }
  return flag == 1 ? p_s21_null : new_str;
}
