#include "stdio.h"
#include "stdlib.h"

int Func(int a, int b) {
  int t_a = a;
  int t_b = b;
  return a + b;
}

int __attribute__((cdecl)) Func2(int a, int b) {
  int t_a = a;
  int t_b = b;
  return a + b;
}

int main() {
  int ret = Func(10, 20);
  return EXIT_SUCCESS;
}

// 问题1：a、b 变量入栈，是从左往右还是从右往左
// 问题2：a、b 是由 main 函数（主调函数）管理释放还是由 Func 函数（被调函数）管理释放

// C 语言默认是 cdecl 惯例


/**
| 调用惯例   | 出栈方     | 参数传递                                     | 名字修饰 |
| ---------- | ---------- | -------------------------------------------- | -------- |
| `cdcel`    | 函数调用方 | 从右至左参数入栈                             | `_cdcel` |
| `stdcall`  | 函数本身   | 从右至左参数入栈                             |          |
| `fastcall` | 函数本身   | 前两个参数由寄存器传递，其余参数通过堆栈传递 |          |
| `pascal`   | 函数本身   | 从左至右参数入栈                             |          |
*/