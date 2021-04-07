#include "stdlib.h"
#include "stdio.h"

/***
 * 按位取反
 */
void test() {
  int num = 2;
  printf("%d\n", ~num); // -3

  /***
   *      0000 0000 0000 0000 0000 0000 0000 0010 取反
   * 原码：1111 1111 1111 1111 1111 1111 1111 1101
   * 补码：1000 0000 0000 0000 0000 0000 0000 0011 -3
   */
}

/**
 * 按位与：求奇偶性
 */

void test2() {
  int num = 122;
  if ((num & 1) == 0) {
    printf("偶数\n");
  } else
    printf("奇数");
}

/***
 * 按位或
 */

void test3() {
  int num1 = 5;          // 0000 0101
  int num2 = 3;          // 0000 0011
  int num3 = num1 | num2;// 0000 0111

  printf("%d\n", num3);
}

/***
 * 按位异或：两个数字交换
 *
 * A：0010 1110
 * B：1100 0111  ^
 * R：1111 1000
 *
 * A ^ B = R
 * A ^ R = B
 * B ^ R = A
 */

void test4() {

}

int main() {
  test3();
}