#include "stdlib.h"
#include "stdio.h"
#include "string.h"
/**
 * 输入特性：主调函数分配内存，被调函数使用
 */

void func(char p[]) { // char *p
  // 栈上分配内存
  strcpy(p, "hello world");
}

void func2(char *p) {
  printf("%s\n", p);
}

int main() {
  // 1.
  char buf[1024] = {0};
  func(buf);
  printf("%s\n", buf); // hello world

  // 2. 在堆区分配内存
  char *p = malloc(sizeof(char) * 64);
  memset(p, 0, 64);
  strcpy(p, "hello wolrd");
  func2(p);
}