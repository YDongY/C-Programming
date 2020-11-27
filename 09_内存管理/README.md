# 内存管理

## 全局变量

- 全局变量：定义函数外部，可以在其他文件通过声明使用
- 静态全局变量：定义函数外部，作用与本文件，不能再其他文件声明 `extren` 使用

```c
int a = 10; // 全局变量
static int b = 20; // 静态全局变量

int main(int argc, char const *argv[]) {
    func();
}
```

## 局部变量

- 局部变量：定义函数内部，仅在函数内部使用
- 静态局部变量：**只定义一次作用等同于全局变量**，但是作用域等同于局部变量

```c
void func(){
    int c = 100; // 局部变量
    static int d = 200; // 静态局部变量
}
int main(int argc, char const *argv[]) {
    func();
}
```

## 全局函数与静态函数

- 全局函数：可以在其他文件声明使用
- 静态函数：仅限于本文件声明使用

```c
void func(){
    // ...
}

static void func2(){
    // ...
}

int main(int argc, char const *argv[]) {
    func();
}
```

## 生命周期

- 局部变量：定义开始到函数调用完成
- 全局变量：程序启动开始到程序结束
- 静态局部变量：程序启动开始到程序结束
- 静态全局变量：程序启动开始到程序结束
- 全局函数：程序启动开始到程序结束
- 静态函数：程序启动开始到程序结束

## 内存布局

```
|---------------------| 高地址
|      Kernel         |
|---------------------|  |
|      stack          |  |
|---------------------|  V
|                     |
|                     |
|---------------------|
|                     |  ^
|       heap          |  |
|                     |  |
|---------------------|
|       bss           |
|---------------------|
|       data          |
|---------------------|
|       text          |
|---------------------| 低地址
```

- text：文本段或代码段，是目标文件或内存中程序的一部分，其中包含可执行指令，【只读】
- data：数据段，包含初始化的全局变量和静态变量
    - 只读区：例如定义 `const int a = 10` 常量，初始化只读区域
    - 读写区：`char s [] = "hello world"`，初始化在读写区域中
- bss：初始化为 0 、未初始化的全局变量和静态变量。例如:`int j;` 的全局变量。
- stack：自动存储变量，保存每次函数调用的信息。堆栈区传统上与堆区相邻，并且朝相反的方向生长。当堆栈指针遇到堆指针时，可用内存就用完了
- heap：堆是通常进行动态内存分配的段。堆区域从BSS段的末尾开始，堆区域由 malloc，realloc 和 free管理。堆区域由进程中的所有共享库和动态加载的模块共享。

**举例：**

- 检查以下简单的 C 程序

```c
#include <stdio.h> 

int main(void) 
{ 
	return 0; 
} 
```

```shell script
$ gcc memory-layout.c -o memory-layout
$ size memory-layout
text       data        bss        dec        hex    filename
960        248          8       1216        4c0    memory-layout
```

- 添加一个在程序中添加一个全局变量，现在检查 bss 的大小

```c
#include <stdio.h> 
  
int global; /* Uninitialized variable stored in bss*/
  
int main(void) 
{ 
    return 0; 
} 
```

```shell script
$ gcc memory-layout.c -o memory-layout
$ size memory-layout
text       data        bss        dec        hex    filename
 960        248         12       1220        4c4    memory-layout
```

- 添加一个静态变量，该变量也存储在 bss 中

```c
#include <stdio.h> 

int global; /* Uninitialized variable stored in bss*/

int main(void) 
{ 
    static int i; /* Uninitialized static variable stored in bss */
    return 0; 
} 
```

```shell script
$ gcc memory-layout.c -o memory-layout
$ size memory-layout
text       data        bss        dec        hex    filename
 960        248         16       1224        4c8    memory-layout
```

- 初始化静态变量，然后将其存储在数据段（DS）中

```c
#include <stdio.h> 
  
int global; /* Uninitialized variable stored in bss*/
  
int main(void) 
{ 
    static int i = 100; /* Initialized static variable stored in DS*/
    return 0; 
} 
```

```shell script
$ gcc memory-layout.c -o memory-layout
$ size memory-layout
text       data        bss        dec        hex    filename
960         252         12       1224        4c8    memory-layout
```

- 初始化全局变量，然后将其存储在数据段（DS）中

```c
#include <stdio.h> 

int global = 10; /* initialized global variable stored in DS*/

int main(void) 
{ 
    static int i = 100; /* Initialized static variable stored in DS*/
    return 0; 
} 
```

```shell script
$ gcc memory-layout.c -o memory-layout
$ size memory-layout
text       data        bss        dec        hex    filename
960         256          8       1224        4c8    memory-layout
```

## 内存操作

- memset：内存设置
- memcpy：内存拷贝
- memmove：内存移动
- memcpy：内存比较
- malloc：堆区内存申请
- free：释放内存