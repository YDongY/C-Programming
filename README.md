# C 语言从放弃到入门

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

1. 预处理:宏定义展开，头文件展开，不做语法检查
2. 编译：检查语法，生成汇编文件
3. 汇编：将汇编文件生成目标文件（二进制文件）
4. 链接：链接依赖库生成最终可执行程序（`ldd xxx`可以查看动态库）

```shell
$ ldd a.out
linux-vdso.so.1 (0x00007ffc76193000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007efc786e1000)
/lib64/ld-linux-x86-64.so.2 (0x00007efc788c3000)
```

**分部编译**

- 预处理：`gcc -E hello.c -o hello.i`
- 编译：`gcc -S hello.i -o hello.s`
- 汇编目标代码：`gcc -c hello.s -o hello.o`
- 链接：`gcc hello.o -o hello`

**反汇编**

```shell
$ gcc -S hello.c -o hello.s
```

## 数据类型

### 整型

| 类型           | 存储大小    | 值范围                                      |
| :------------- | :---------- | :------------------------------------------ |
| char           | 1 字节      | -128 - 127 或 0 - 255                       |
| unsigned char  | 1 字节      | 0 - 255                                     |
| signed char    | 1 字节      | -128 - 127                                  |
| int            | 2 或 4 字节 | -32768 - 32767 或 -2147483648  - 2147483647 |
| unsigned int   | 2 或 4 字节 | 0 - 65535 或 0 - 4294967295                 |
| short          | 2 字节      | -32768 - 32767                              |
| unsigned short | 2 字节      | 0 - 65535                                   |
| long           | 4 字节      | -2147483648 - 2147483647                    |
| unsigned long  | 4 字节      | 0 - 4294967295                              |

### 浮点数

| 类型        | 存储大小 | 值范围                | 精度      |
| :---------- | :------- | :-------------------- | :-------- |
| float       | 4 字节   | 1.2E-38  - 3.4E+38    | 6 位小数  |
| double      | 8 字节   | 2.3E-308 - 1.7E+308   | 15 位小数 |
| long double | 16 字节  | 3.4E-4932 - 1.1E+4932 | 19 位小数 |

### 输入输出

| 打印格式          | 含义                                                    |      |
| ----------------- | ------------------------------------------------------- | ---- |
| `%d`              | 输出一个有符号的 10 进制 int 类型                       |      |
| `%o`              | 输出 8 进制的 int 类型                                  |      |
| `%x`              | 输出 16 进制的 int 类型，字母小写                       |      |
| `%X`              | 输出 16 进制的 int 类型，字母大写                       |      |
| `%u`              | 输出 unsigned int 类型                                  |      |
| `%l` 或者 `%ll`   | 输出 long 类型 或者 输出 unsigned  long 类型            |      |
| `%lu` 或者 `%llu` | 输出 long  long 类型 或者 输出 unsigned long  long 类型 |      |
| `%hd` 或者 `%hu`  | 输出 short 类型 或者 输出 unsigned short 类型           |      |
| `%f`              | float 输出单精度浮点数                                  |      |
| `%lf`             | double 输出双精度浮点数                                 |      |
| `%e`或者`%E`      | double 科学计数法                                       |      |
| `%s`              | 字符串，输出字符串中的字符直到字符串中的空字符          |      |
| `%c`              | 字符型                                                  |      |
| `%p`              | 以 16 进制形式输出指针                                  |      |
| `%%`              | 输出一个百分号                                          |      |

## 运算符

> [https://www.runoob.com/cprogramming/c-operators.html](https://www.runoob.com/cprogramming/c-operators.html)

## 类型转换

> 类型小的往类型大的转换，否则出现越界

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    double a;
    int b = 10;

    a = b;               // 隐式转换
    printf("%lf \n", a); // 10.000000

    double n;

    printf("%d \n", 1 / 2); // 0

    n = (double)1 / 2; // 强制类型装换

    printf("%lf \n", n); // 0.500000

    return 0;
}
```

## 流程控制

