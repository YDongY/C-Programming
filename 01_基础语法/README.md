# 基础语法

## 变量和常量

```C
#define MAX 100

#define PI 3.1415 // 定义宏，没有分号

// 枚举常量
enum Sex
{
    MALE,   // 0，默认值
    FEMALE, // 1
    SECRET  // 2
};

int main(int argc, char const *argv[])
{
    int age; // 变量声明,不会开辟空间。
    int price = 100; // 变量定义,会开辟空间

    extern int price2;
    // 编译器编译程序时，在变量使用之前，会将变量声明提升为定义
    // 如果该变量的声明有 extern 关键字，则无法提升
    // price2 = 10; 会报错，且 int price2 = 10;也会重复定义

    // 常变量，只读变量
    const int num = 4;
}
```

## 输入输出

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


```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    int j;

    scanf("%d %d", &i, &j);

    printf("i=%d,j=%d\n", i, j);


    // 输出一个字符
    putchar('a'); // a
    putchar(97);  // a

    // 接收输入一个字符
    char ch = getchar();
    putchar(ch);
}

```