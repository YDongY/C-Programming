#include "stdlib.h"
#include "stdio.h"

int main() {
  FILE *fp = NULL;
  fp = fopen("test.txt", "w");
  if (fp == NULL) {
    perror("fopen()");
    return EXIT_FAILURE;
  }

  char ch = 'a';
  while (ch <= 'z') {
    int ret = fputc(ch, fp);
    if (ret == EOF) {
      return EXIT_FAILURE;
    }
    ch++;
  }

  fclose(fp);
  return EXIT_SUCCESS;
}