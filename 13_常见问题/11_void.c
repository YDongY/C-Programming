#include "stdio.h"
#include "stdlib.h"

// 1. void 使用
void test1() {
  // void a = 10; // 无类型，不可以通过无类型创建变量，原因是编译器不知道分配多少内存空间
}

// 2. 限定返回值，限定函数参数

void Func(void){
  return 10; // warning:
}


int main() {
  test1();
  Func();
}