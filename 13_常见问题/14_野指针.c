#include "stdlib.h"
#include "stdio.h"

int *DoWork() {
  int a = 10;
  printf("%p\n", &a);
  return &a;
}

int main() {
  // 1. 声明未初始化指针
  // int *p;
  // *p = 1000; // 操作野指针
  // printf("%d\n", *p);

  // 2. malloc 后 free

  // int *p = malloc(sizeof(int));
  // *p = 100;
  // printf("%d\n", *p); // 100
  // free(p);
  // printf("%d\n", *p); // 野指针

  // 3. 指针变量超出作用域
  // int *p = DoWork();
  // printf("%d\n", *p);

  // 4. 空指针可以重复释放，野指针不能重复释放

}