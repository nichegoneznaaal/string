#include "../s21_sprintf.h"
#define MAX_WIDTH_D 2000
#define MIN_WIDTH_D -10
#define MAX_ACC_F 15
#define MIN_ACC_F -10
#define MAX_INT_D 2147483647
#define MIN_INT_D -2147483648
#define MIN_F_L (long double)-100.100
#define MAX_F_L (long double)100.100
#define MIN_F -100.100
#define MAX_F 100.100
#define FLOAT 50.1234567890
#define FLOAT2 0.999
#define SIZE_STR 1000000
int main(void) {
  char *s21 = (char *)calloc(10000000, sizeof(char));
  char *std = (char *)calloc(10000000, sizeof(char));
  char test_str[] = "test=%15.10Le=%10.1Le=test";
  long double test_1 = -0.000001, test_2 = 0.999;
  int a = 44;
  int x = s21_sscanf("123", "%a", &a);
  printf("%d\n", x);
  sprintf(std, test_str, test_1, test_2);
  LOG_INFO("sprintf std :%s, len %ld", std, STR_LEN(std));
  s21_sprintf(s21, test_str, test_1, test_2);
  LOG_INFO("sprintf s21 :%s, len %ld", s21, STR_LEN(s21));
  free(std);
  free(s21);
  return 0;
}
