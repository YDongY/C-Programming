#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int getFileLines(FILE *fp) {
  if (fp == NULL) {
    return -1;
  }
  char buf[1024];
  int lines = 0;
  while (fgets(buf, 1024, fp) != NULL) {
    // printf("%s\n", buf);
    lines++;
  }
  fseek(fp, 0, SEEK_SET); // 文件置首，以后继续使用 fp
  return lines;
}

void readFileData(FILE *fp, char **pArray, int len) {
  if (fp == NULL) {
    return;
  }

  if (pArray == NULL) {
    return;
  }

  if (len <= 0) {
    return;
  }

  char buf[1024] = {0};
  int index = 0;

  while (fgets(buf, 1024, fp) != NULL) {
    // 计算每个字符串大小
    unsigned long current_len = strlen(buf) + 1;
    // 字符串最后一个字符 \n 改为 \0
    buf[strlen(buf) - 1] = '\0';
    char *current_p = malloc(sizeof(char) * current_len);
    strcpy(current_p, buf);
    pArray[index++] = current_p;

    memset(buf, 0, 1024);
  }

}

void showFileData(char **pArray, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%s\n", pArray[i]);
  }
}

void freeSpace(char **pArray, int len) {
  for (int i = 0; i < len; ++i) {
    if (pArray[i] != NULL) {
      free(pArray[i]);
      pArray[i] = NULL;
    }
  }

  free(pArray);
  pArray = NULL;
}

int main() {
  FILE *fp = fopen("test.txt", "r");
  if (fp == NULL) {
    perror("fopen()");
    return EXIT_FAILURE;
  }
  int len = getFileLines(fp);

  char **pArray = malloc(sizeof(char *) * len);

  readFileData(fp, pArray, len);

  showFileData(pArray, len);

  freeSpace(pArray, len);

  fclose(fp);
  fp = NULL;
}