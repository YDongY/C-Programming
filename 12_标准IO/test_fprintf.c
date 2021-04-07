#include "stdlib.h"
#include "stdio.h"

int main() {
  printf("%d = %d%c%d\n", 10 + 5, 10, '+', 5); // ---> 屏幕
  char but[1024];
  sprintf(but, "%d = %d%c%d\n", 10 + 5, 10, '+', 5); // ---> buf
  FILE *fp = fopen();
  fprintf(fp, "%d = %d%c%d\n", 10 + 5, 10, '+', 5); // ---> 文件
}