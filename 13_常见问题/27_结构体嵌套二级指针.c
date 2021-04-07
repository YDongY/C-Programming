#include "stdlib.h"
#include "stdio.h"

struct Teacher {
  char *name;
  char **students; // 学生数组
};

void allocate(struct Teacher ***arr) {
  if (arr == NULL) {
    return;
  }

  struct Teacher **ts = malloc(sizeof(struct Teacher *) * 3);

  // 给老师分配内存
  for (int i = 0; i < 3; ++i) {
    ts[i] = malloc(sizeof(struct Teacher));

    // 给姓名分配内存
    ts[i]->name = malloc(sizeof(char) * 64);
    sprintf(ts[i]->name, "Teacher_%d", i + 1);

    // 学生数组分配内存
    ts[i]->students = malloc(sizeof(char *) * 4);

    // 给学生姓名分配内存并赋值
    for (int j = 0; j < 4; ++j) {
      ts[i]->students[j] = malloc(sizeof(char) * 64);
      sprintf(ts[i]->students[j], "%s_student_%d", ts[i]->name, j + 1);
    }
  }

  // 建立关系
  *arr = ts;
}

void printTeacherArray(struct Teacher **arr) {
  for (int i = 0; i < 3; ++i) {
    printf("%s\n", arr[i]->name);
    for (int j = 0; j < 4; ++j) {
      printf("  %s\n", arr[i]->students[j]);
    }
  }
}

void freeSpace(struct Teacher **arr) {
  if (arr == NULL) {
    return;
  }

  for (int i = 0; i < 3; ++i) {
    if (arr[i]->name != NULL) {
      free(arr[i]->name);
      arr[i]->name = NULL;
    }

    for (int j = 0; j < 4; ++j) {
      if (arr[i]->students[j] != NULL) {
        free(arr[i]->students[j]);
        arr[i]->students[j] = NULL;
      }
    }
    free(arr[i]->students);
    arr[i]->students = NULL;
    free(arr[i]);
    arr[i] = NULL;
  }

  free(arr);
  arr = NULL;

}

void test01() {
  // 老师数组
  struct Teacher **tArray = NULL;

  // 分配内存
  allocate(&tArray);

  // 打印
  printTeacherArray(tArray);

  // 释放内存
  freeSpace(tArray);
  tArray = NULL;
}

int main() {
  test01();
}