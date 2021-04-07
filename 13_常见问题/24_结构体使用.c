#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Person {
  char name[64];
  int age;
  // int age = 18; 不能给结构体赋初始值
  // void func(); 不能放函数
};

void test01() {
  struct Person p1 = {"Jack", 20};
}

struct Person2 {
  char name[64];
  int age;
} p2; // 结构体变量

void test02() {
  strcpy(p2.name, "jack");
  p2.age = 20;
}

// ============================================================================================

typedef struct Person3 {
  char name[64];
  int age;
} MyPerson; // 结构体别名

void test03() {
  MyPerson p3 = {"jack", 20};
}

// ============================================================================================


struct Person4 {
  char name[64];
  int age;
} p4 = {"jack", 20}; // 结构体变量默认值

// ============================================================================================


struct {
  char name[64];
  int age;
} p5; // 匿名结构体变量


struct {
  char name[64];
  int age;
} p6 = {"jack", 20}; // 匿名结构体变量默认值

// ============================================================================================

void test04() {

  // 栈上分配内存
  struct Person p1 = {"Jack", 20};

  // 堆上分配内存
  struct Person *p2 = malloc(sizeof(struct Person));
  strcpy(p2->name, "tom");

  free(p2);
}

// 结构体变量数组
void test05() {
  struct Person pArray[] = {
      {"aaa", 10},
      {"bbb", 20},
      {"ccc", 30},
      {"ddd", 40},
      {"eee", 50},
  };

  int len = sizeof(pArray) / sizeof(struct Person);

  for (int i = 0; i < len; ++i) {
    printf("%s--%d\n", pArray[i].name, pArray[i].age);
  }

  // 堆区分配

  struct Person *pArray2 = malloc(sizeof(struct Person) * 4);
  for (int i = 0; i < 4; ++i) {
    sprintf(pArray2[i].name, "name_%d", i + 1);
    pArray2[i].age = i + 10;
  }

  for (int i = 0; i < 4; ++i) {
    printf("%s--%d\n", pArray2[i].name, pArray2[i].age);
  }
}

int main() {
  test05();
}