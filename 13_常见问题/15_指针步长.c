#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stddef.h"

// 1. 指针变量 +1 后跳跃的字节数

void test() {
  char *p = NULL;
  printf("%d\n", p); // 0
  printf("%d\n", p + 1); // 1

  double *p2 = NULL;
  printf("%d\n", p2); // 0
  printf("%d\n", p2 + 1); // 8
}

void test2() {
  char buf[1024] = {0};
  int a = 1000;
  memcpy(buf, &a, sizeof(int));

  char *p = buf;

  // char * 强转 int * ，一次取 4 个字节
  printf("%d\n", *(int *) p); // 1000

}

struct Person {
  char a; // 0~3
  int b;  // 4~7
  char buf[64]; // 8~71
  int d; // 72 ~ 75
};

void test3() {
  printf("%lu \b", sizeof(struct Person)); // 76

  struct Person p = {'a', 10, "hello world", 1000};
  printf("属性 d 的偏移量：%lu\n", offsetof(struct Person, d)); // 72
  printf("通过偏移量获取属性 d 的值：%d\n", *(int *) ((char *) &p + offsetof(struct Person, d)));
}

int main() {
  test3();
}