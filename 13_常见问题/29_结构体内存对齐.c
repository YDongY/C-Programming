#include "stdio.h"
#include "stdlib.h"
// #pragma pack (show) 对齐模数 8
#pragma pack (1) // 对齐模数能够改为 2 的 n 次方

/**
 * 1. 第一个属性开始，从 0 开始计算
 * 2. 第二个属性要放在 min(该属性大小,对齐模数) 的整数倍上，例如：4 < 8 就取 4，8，12....
 * 3. 所有整数计算完毕，整体做二次偏移，将上面的计算结果扩充到这个结构体中 min(最大数据类型,对齐模数) 的整数倍
 */
typedef struct Student {
  int a; // 0~3
  char b; // 4~7
  double c; // 8~15
  float d; // 16~19
} Stu;

int main() {
  printf("%lu\n", sizeof(struct Student)); // 24
}