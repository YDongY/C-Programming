#include <stdlib.h>
#include <stdio.h>

void test1() {
  int a = 10;
  int *p = NULL;
  p = &a;
  *p = 1000;
  printf("%d\n", a); // 1000
}

void test2(int *p) {
  *p = 1000;
}

int main() {
  test1();

  int a = 10;
  test2(&a);
  printf("%d\n", a); // 1000
}