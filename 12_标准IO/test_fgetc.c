#include "stdio.h"
#include "stdlib.h"

int main() {
  FILE *fp = NULL;
  fp = fopen("test.txt", "r");
  if (fp == NULL) {
    perror("fopen()");
    return EXIT_FAILURE;
  }

  int ch;
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}