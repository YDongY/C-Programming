#include "stdio.h"
#include "stdlib.h"

void printArray(int *arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d:%d\n", i + 1, arr[i]);
  }
}

void printArray2(int **arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d:%d\n", i + 1, (*arr)[i]);
  }
}

void allocate(int **p) {
  int *pArray = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; ++i) {
    pArray[i] = (i + 1) * 100;
  }
  *p = pArray;
}

int main() {
  int *p = NULL;
  allocate(&p);

  printArray(p, 10);
  printArray2(&p, 10);

  if (p != NULL) {
    free(p);
    p = NULL;
  }
}