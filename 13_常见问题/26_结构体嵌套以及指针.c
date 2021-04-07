#include "stdio.h"
#include "stdlib.h"

struct Person {
  char *name;
  int age;
};

struct Person **allocate() {
  struct Person **temp = malloc(sizeof(struct Person *) * 3);

  for (int i = 0; i < 3; ++i) {
    // 给每个 Person 分配内存
    temp[i] = malloc(sizeof(struct Person));
    temp[i]->name = malloc(sizeof(char) * 64);
    sprintf(temp[i]->name, "name_%d", i + 1);
    temp[i]->age = i + 10;
  }

  return temp;
}

void printPerson(struct Person **arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%s-%d\n", arr[i]->name, arr[i]->age);
  }
}

void freeSpace(struct Person **arr, int len) {
  if (arr == NULL || len <= 0) {
    return;
  }

  for (int i = 0; i < len; ++i) {
    if (arr[i]->name != NULL) {
      free(arr[i]->name);
      arr[i]->name = NULL;
    }
    if (arr[i] != NULL) {
      free(arr[i]);
      arr[i] = NULL;
    }
  }

  free(arr);
  arr = NULL;
}

void test01() {
  // 结构体指针数组
  struct Person **arr = NULL;

  // 分配内存
  arr = allocate();

  // 打印输出
  printPerson(arr, 3);

  // 释放内存
  freeSpace(arr, 3);
  arr = NULL;

}

int main() {
  test01();
}