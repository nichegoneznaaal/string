#include <stdio.h>

#include "../s21_string.h"

int main() {
  char f = 'f';
  char *ptr = &f;
  printf("%lld\n", (unsigned long long int)ptr);
  char buf[15] = "0x000000000000";
  char *ptr2 = hexa_to_char(ptr, buf);
  // char *ptr2 = s21_to_upper(hexa_to_char(ptr, buf));
  // printf("%s\n", ptr2);
  // ptr2 = s21_to_lower(ptr2);
  printf("%s\n", ptr2);
}
