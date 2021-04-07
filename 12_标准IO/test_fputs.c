#include "stdlib.h"
#include "stdio.h"

int main() {
  FILE *fp = NULL;
  fp = fopen("test2.txt", "w");
  if (fp == NULL) {
    perror("fopen()");
    return EXIT_FAILURE;
  }

  char *buf[] = {"hello\n", "world\n", "c/c++\n"};

  int len = sizeof(buf) / sizeof(char *);
  for (int i = 0; i < len; i++) {
    int ret = fputs(buf[i], fp);
    if (ret == EOF) {
      break;
    }
  }

  fclose(fp);
  return EXIT_SUCCESS;
}