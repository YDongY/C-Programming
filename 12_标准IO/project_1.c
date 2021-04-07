#include "stdlib.h"
#include "stdio.h"
#include "string.h"
/**
 * 获取用户键盘输入，写入文件
 * @return
 */
void write_with_buffer() {
  FILE *fw = NULL;
  fw = fopen("user.txt", "w+");
  if (fw == NULL) {
    perror("fopen()");
    return;
  }
  char buf[4096] = {0};
  while (1) {
    char *ret = fgets(buf, sizeof(buf), stdin);
    if (ret == NULL || strcmp(buf, ":wq\n") == 0) {
      break;
    }
    int r = fputs(buf, fw);
    if (r == EOF) {
      break;
    }
  }
  fclose(fw);
}

int main() {
  write_with_buffer();
}