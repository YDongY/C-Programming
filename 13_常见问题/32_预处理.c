#include <stdio.h>
#include <stdlib.h>

/**
 * "xxx.h" 自定义头文件
 * <xxx.h> 系统头文件
 * @return
 */

#define MAX 1024

#define MIN 1
#undef MIN // 卸载宏

#define SUM(a, b) ((a)+ (b)) // 宏函数

void test01() {
  printf("%d\n", MAX); // 1024
  // printf("%d\n", MIN); // error: ‘MIN’ undeclared
}

// 条件编译
#define DEBUG
#ifdef DEBUG

#if 1
void func() {
  printf("Debug-1\n");
}
#else
void func(){
  printf("Debug-2\n");
}
#endif

#else
void func() {
  printf("Release\n");
}
#endif

// 特殊的宏
void test02(const char *p) {
  if (p == NULL) {
    // Apr  6 2021 16:34:04 >>> /home/ydongy/Github/CDev/13_常见问题/32_预处理.c 46 Error
    printf("%s %s >>> %s %d Error\n", __DATE__, __TIME__, __FILE__, __LINE__);
  }
}

int main() {
  test01();
  func();
  test02(NULL);
}