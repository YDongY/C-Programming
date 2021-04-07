#include "stdio.h"
#include "stdlib.h"

void printArray(int **pArray, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d:%d\n", i + 1, *(pArray[i]));
  }
}

/**
 * 二级指针输入特性，堆区申请内存
 */

void test() {
  int **pArray = malloc(sizeof(int *) * 5);
  int a1 = 100;
  int a2 = 200;
  int a3 = 300;
  int a4 = 400;
  int a5 = 500;

  pArray[0] = &a1;
  pArray[1] = &a2;
  pArray[2] = &a3;
  pArray[3] = &a4;
  pArray[4] = &a5;

  printArray(pArray, 5);
  if (pArray != NULL) {
    free(pArray);
    pArray = NULL;
  }
}

/**
 * 在栈上申请内存
 */

void test02() {
  int *pArray[5];
  for (int i = 0; i < 5; ++i) {
    pArray[i] = malloc(sizeof(int *));
    *(pArray[i]) = (i + 1) * 100;
  }
  int len = sizeof(pArray) / sizeof(int *);
  printArray(pArray, len);
}

int main() {
  test02();
}