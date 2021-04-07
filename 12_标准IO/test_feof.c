#include "stdio.h"
#include "stdlib.h"

int main() {
  FILE *fp = NULL;
  fp = fopen("test.txt", "r");
  if (fp == NULL) {
    perror("fopen()");
    return EXIT_FAILURE;
  }

  while (1) {
    int ch = fgetc(fp);
    if (feof(fp))
      break;
    printf("%c", ch);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}