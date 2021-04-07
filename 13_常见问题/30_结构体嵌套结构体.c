#include "stdlib.h"
#include "stdio.h"

typedef struct Student {
  int a; // 0~3
  char b; // 4~7
  double c; // 8~15
  float d; // 16~19
} Stu;

typedef struct Student2 {
  char a; // 0 ~ 7
  struct Student b; // 8 ~ 31
  double c; // 32 ~ 39
} Stu2;

int main() {
  printf("%lu\n", sizeof(Stu2)); // 40
}