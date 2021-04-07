#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"
struct Teacher {
  char a; // 0~3
  int b; // 4~7
};

void test01() {
  struct Teacher t1;
  struct Teacher *p = &t1;

  // printf("%d\n", (int) &(p->b) - (int) p);

  printf("%lu\n", offsetof(struct Teacher, b));
}

/**
 * 通过偏移量访问内存
 */
void test02() {
  struct Teacher t1 = {'a', 1000};
  struct Teacher *p = &t1;

  printf("%s-%d\n", (char *) p, *(int *) ((char *) p + offsetof(struct Teacher, b)));
  printf("%s-%d\n", (char *) p, *(int *) ((int *) p + 1));

}

struct Teacher2 {
  char a;
  int b;
  struct Teacher c;
};

void test03() {
  struct Teacher2 t1 = {'a', 10, 'b', 20};

  struct Teacher2 *p = &t1;

  int offset = offsetof(struct Teacher2, c);
  int offset2 = offsetof(struct Teacher, b);

  printf("%d\n", *(int *) ((char *) p + offset + offset2));
  printf("%d\n", ((struct Teacher *) ((char *) p + offset))->b);

}

int main() {
  test03();
}