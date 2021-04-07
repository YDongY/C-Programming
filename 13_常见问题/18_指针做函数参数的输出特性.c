#include "stdlib.h"
#include "stdio.h"
#include "string.h"
/**
 * 输出特性：被调函数分配内存，主调函数使用
 */

void allocate(char **p) {
  char *temp = malloc(sizeof(char) * 64);
  memset(temp, 0, 64);
  strcpy(temp, "hello world");

  *p = temp;
}

int main() {
  char *p = NULL;
  allocate(&p);
  printf("%s\n", p); // hello world

  free(p);
  p = NULL;

  return EXIT_SUCCESS;
}