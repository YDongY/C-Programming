#include "stdlib.h"
#include "stdio.h"

#define PI 3.14 // 宏常量

#define MAX(x, y) ((x)>(y)?(x):(y)) // 宏函数，为了运算完整性，最好加上括号

#define MAX_2(x, y) ({typeof(x) X=x,Y=y; ((X) > (Y)? (X):(Y));}) // 使用变量

int main() {
  int a = 10;
  int b = 20;

  // 预编译宏替换: printf("%d\n", ((a)>(b)?(a):(b)));
  printf("%d\n", MAX(a, b)); // 20

  // printf("%d\n", ((a++)>(b++)?(a++):(b++)));
  printf("%d\n", MAX(a++, b++)); // 21

  // a 和 b 各 ++ 一次，然后较大的在 ++ 一次，最终 b = 22
  printf("%d %d\n", a, b); // 11 22

  // printf("%d\n", ({int X=a++,Y=b++; ((X) > (Y)? (X):(Y));}));
  printf("%d\n", MAX_2(a++, b++)); // 22
  printf("%d %d\n", a, b); // 12 23
}