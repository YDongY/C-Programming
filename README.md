# [C 语言从放弃到入门](https://github.com/YDongY/NotesLibrary/tree/master/C%E8%AF%AD%E8%A8%80/C%20%E8%AF%AD%E8%A8%80%E4%BB%8E%E6%94%BE%E5%BC%83%E5%88%B0%E5%85%A5%E9%97%A8)

## C 语言标准

- 1989年 C89
- 1999年 C99
- 2011年 C11

## Hello World

```c
#include <stdio.h>

// 有且只有一个 main 函数，程序运行入口
int main()
{
    printf("hello world\n");
    return 0;
}
```

## 编译

```shell
$ gcc xxx.c -o xxx

# eg: gcc hello.c
# >>> a.out

# eg: gcc hello.c -o hello
# >>> hello
```

## 编译过程

1. 预处理：宏定义展开、头文件展开、条件编译、去除注释，不做语法检查
2. 编译：检查语法，生成汇编文件
3. 汇编：将汇编文件生成目标文件（二进制文件）
4. 链接：链接依赖库生成最终可执行程序（`ldd xxx`可以查看动态库）

```shell
$ ldd a.out
linux-vdso.so.1 (0x00007ffc76193000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007efc786e1000)
/lib64/ld-linux-x86-64.so.2 (0x00007efc788c3000)
```

**分步编译**

- 预处理：`gcc -E hello.c -o hello.i`
- 编译：`gcc -S hello.i -o hello.s`
- 汇编目标代码：`gcc -c hello.s -o hello.o`
- 链接：`gcc hello.o -o hello`

**反汇编**

```shell
$ gcc -S hello.c -o hello.s
```
