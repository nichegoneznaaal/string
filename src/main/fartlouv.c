#include <stdio.h>

#include "../s21_string.h"

int main(void) {
  char src[80] = " spases ";
  char trim[80] = "";
  char *result = s21_trim(src, trim);
  printf("result = %s\n", result);
  free(result);
  return 0;
}
