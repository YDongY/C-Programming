#include "stdio.h"
#include "stdlib.h"

int main() {
  int a, b, c;
  scanf("%d+%d=%d", &a, &b, &c);       // ---> 屏幕

  char buf[] = "10+20=30";
  sscanf(buf, "%d+%d=%d", &a, &b, &c); // ---> buf

  FILE *fp = fopen();
  fscanf(fp, "%d+%d=%d", &a, &b, &c); // ---> 文件
}