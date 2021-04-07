#include "stdio.h"
#include "stdlib.h"

int main() {
  /***
   * 正数：用 0 填充高位
   */
  // 左移：i * (2^n)
  printf("%d\n", 3 << 1); // 2
  printf("%d\n", 1 << 2); // 4

  // 右移：i / (2^n)
  printf("%d\n", 3 >> 1); // 1
  printf("%d\n", 4 >> 2); // 1

  /**
   * 负数：用 1 填充填充高位
   */
}