#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * 读取文件，四则运算
 */

void arithmetic() {
  FILE *fr = NULL;
  fr = fopen("work.txt", "r");
  if (fr == NULL) {
    perror("fopen()");
    return;
  }

  FILE *fw = NULL;
  fw = fopen("answer.txt", "w");
  if (fw == NULL) {
    perror("fopen()");
    return;
  }
  char buf[4096] = {0};
  char result[4096] = {0};
  int a, b, res;
  char c;
  while (fgets(buf, sizeof(buf), fr)) {
    sscanf(buf, "%d%c%d=\n", &a, &c, &b);
    switch (c) {
      case '/':res = a / b;
        break;
      case '*':res = a * b;
        break;
      case '+':res = a + b;
        break;
      case '-':res = a - b;
        break;
      default:printf("文件格式异常");
        return;
    }
    sprintf(buf, "%d%c%d=%d\n", a, c, b, res);
    strcat(result, buf);
  }
  int fw_ret = fputs(result, fw);
  if (fw_ret == EOF) {
    return;
  }
  fclose(fw);
  fclose(fr);
}

int main() {
  arithmetic();
}