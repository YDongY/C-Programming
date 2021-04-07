#include "stdlib.h"
#include "stdio.h"
#include "string.h"
/**
typedef struct student {
  int age;
  char name[10];
  int num;
} stu_t;

int main() {

  stu_t stu[4] = {
      {18, "jack", 1},
      {20, "tom", 2},
      {23, "jerry", 3},
      {24, "mike", 4},
  };
  FILE *fp = fopen("fwrite.txt", "w");
  if (fp == NULL) {
    perror("fopen()");
    return EXIT_FAILURE;
  }

  int ret = fwrite(&stu[0], sizeof(stu_t), 1, fp);
  if (ret == 0) {
    perror("fwrite()");
    return EXIT_FAILURE;
  }
  fclose(fp);
  return EXIT_SUCCESS;
}
 */


//
//int main() {
//  FILE *fp = fopen("fwrite.txt", "w");
//  if (fp == NULL) {
//    perror("fopen()");
//    return EXIT_FAILURE;
//  }
//
//  struct Hero arr[5] = {
//      {"刘备", 1000, 1000},
//      {"关羽", 1800, 1200},
//      {"张飞", 1600, 1500},
//      {"吕布", 2000, 2000},
//      {"曹操", 1300, 1100}
//  };
//
//  int len = sizeof(arr) / sizeof(struct Hero);
//
//  for (int i = 0; i < len; i++) {
//    // 参数:数据地址 块大小 块个数 文件指针
//    int ret = fwrite(&arr[i], sizeof(struct Hero), 1, fp); // 直接写入结构体
//    if (ret == 0) {
//      perror("fwrite()");
//      return EXIT_FAILURE;
//    }
//  }
//
//  fclose(fp);
//  return EXIT_SUCCESS;
//}

struct Hero {
  char name[64];
  int atk;
  int def;
};

int main() {
  FILE *fp = fopen("fwrite.txt", "r");
  if (fp == NULL) {
    perror("fwrite()");
    return EXIT_FAILURE;
  }

  struct Hero arr[5];
  memset(arr, 0, sizeof(arr));

  int len = sizeof(arr) / sizeof(struct Hero);
#if 0
  for (int i=0;i<len;i++){
        // 参数:数据地址 块大小 块个数 文件指针
        fread(&arr[i],sizeof(struct Hero),1,fp); // 直接读出结构体
    }
#else
  fread(arr, sizeof(struct Hero), len, fp); // 一次性读取
#endif
  for (int j = 0; j < len; j++) {
    printf("%s-%d-%d\n", arr[j].name, arr[j].atk, arr[j].def);
  }

  fclose(fp);
}