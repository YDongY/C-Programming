#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * 字符读写
 */
void test01() {
  FILE *fw = fopen("test.txt", "w");
  if (fw == NULL) {
    return;
  }

  char buf[] = "hello world";
  for (int i = 0; i < strlen(buf); ++i) {
    fputc(buf[i], fw);
  }

  fclose(fw);

  FILE *fr = fopen("test.txt", "r");
  if (fw == NULL) {
    return;
  }

  int ch;
  while ((ch = fgetc(fr)) != EOF) {
    printf("%c", ch);
  }

  fclose(fr);

}

// 配置信息结构体
struct ConfigInfo {
  char key[64];
  char value[64];
};

/**
 * 判断有效行
 */

int isValidLine(char *str) {
  if (str[0] == '\n' || strchr(str, ':') == NULL) {
    return 0;
  }
  return 1;
}

/**
 * 获取文件有效行
 */

int getFileLine(const char *filePath) {
  FILE *file = fopen(filePath, "r");
  if (file == NULL) {
    return -1;
  }

  char buf[1024] = {0};
  int line = 0;
  while (fgets(buf, 1024, file)) {
    if (isValidLine(buf))
      line++;
  }

  return line;
}

/**
 * 文件解析
 */

void allocate(const char *filePath, int lines, struct ConfigInfo **ci) {
  struct ConfigInfo *config = malloc(sizeof(struct ConfigInfo) * lines);
  if (config == NULL) {
    return;
  }

  FILE *file = fopen(filePath, "r");
  if (file == NULL) {
    return;
  }

  char buf[1024] = {0};
  int index = 0;
  while (fgets(buf, 1024, file) != NULL) {
    if (isValidLine(buf)) {
      // heroId:1
      memset(config[index].key, 0, 64);
      memset(config[index].value, 0, 64);
      // ------- 此处可以使用 sscanf() -----------------



      char *pos = strchr(buf, ':'); // : 号地址
      // 截取 key
      strncpy(config[index].key, buf, pos - buf);

      // 截取 value
      strncpy(config[index].value, pos + 1, strlen(pos + 1) - 1); // -1 是为了不要文件中的 \n

      // ---------------------------------------------
      // printf("key = %s\n", config[index].key);
      // printf("value = %s\n", config[index].value);
      index++;

    }
    memset(buf, 0, 1024);
  }

  *ci = config;
}

/**
 * 根据 key 获取 value
 */

char *getValueByKey(char *key, struct ConfigInfo *configInfo, int lines) {
  for (int i = 0; i < lines; ++i) {
    if (strcmp(configInfo[i].key, key) == 0) {
      return configInfo[i].value;
    }
  }
  return NULL;
}

/**
 * 释放内存
 */

void freeSpace(struct ConfigInfo *configInfo) {
  if (configInfo == NULL) {
    return;
  }

  free(configInfo);
  configInfo = NULL;
}

/**
 * 配置文件读写
 */
void test02() {
  int lines = getFileLine("config.txt");
  printf("%d\n", lines);

  struct ConfigInfo *config = NULL;

  allocate("config.txt", lines, &config);

  char *value = getValueByKey("HeroId", config, lines);
  if (value == NULL)
    printf("没有\n");
  else
    printf("%s\n", value);

  freeSpace(config);
  config = NULL;
}

int main() {
  test02();
}