# 运算符

## 算术运算符

```C
#include <stdio.h>
int main(int argc, char const *argv[])
{
    // --------------- 算术运算符 ----------------
    // + - * / %

    // 整数与整数运算结果为整数，浮点数与浮点数运算结果为浮点数
    printf("%d \n", 7 / 4);          // 1
    printf("%lf \n", (double)7 / 4); // 1.75000
    printf("%lf \n", 7.0 / 4);       // 1.75000

    printf("%d \n", 7 % 4);          // 3

    // 模运算结果的正负性跟随运算符左边的操作数
    printf("%d \n", 10 % 7);         // 3
    printf("%d \n", 10 % -7);        // 3
    printf("%d \n", -10 % 7);        // -3
    printf("%d \n", -10 % -7);       // -3
}
```

## 隐式类型转换

> 在一些运算过程中，小类型会被隐式转换成大类型
> char < short < int < long < long long < float < double < long double

```C
#include <stdio.h>
int main(int argc, char const *argv[])
{
    double d = 1.5;
    int i = 2;
    printf("%f \n",d+i); // i 会被隐式转换为 double 类型，所以结果为 double 类型

    // 注意
    char c = 97;
    short s = 10;

    printf("%zd %zd \n",sizeof(c),sizeof(s)); // 1,2
    printf("%zd %zd \n",sizeof(+c),sizeof(-s)); // 4,4
    printf("%zd %zd \n",sizeof(c + s),sizeof(c / s)); // 4,4

    // 任何小于 int 的整数类型，运算时都会隐式转换为 int 类型
}
```

## 比较运算符

```C
#include <stdio.h>
int main(int argc, char const *argv[])
{
    // 1 表示真， 0 表示假
    printf("%d \n", 4 == 3); // 0
    printf("%d \n", 4 > 3);  // 1
}
```

## 逻辑运算

```C
#include <stdio.h>
int main(int argc, char const *argv[])
{
    // &&:左右为真，结果为真，左边为假，右边不执行
    printf("%d \n", 1 && -1); // 1
    printf("%d \n", 1 && 0);  // 0

    // ||:只要有一边为真，结果就为真，左边为真右边不执行
    printf("%d \n", 1 || 0); // 1
    printf("%d \n", 0 || 0); // 0
}
```

## 条件运算符

```C
#include <stdio.h>
int main(int argc, char const *argv[])
{
    // ------------------ 条件运算符 ------------------

    int a = 5 ? 1 : 2;
    int b = 0 ? 1 : 2;
    printf("%d \n", a); // 1
    printf("%d \n", b); // 2

    return 0;
}
```

## 位运算

```C
#include <stdio.h>
int main(int argc, char const *argv[])
{
    // & | ~
    printf("%d \n", 10 ^ 10); // 0
    printf("%d \n", 10 ^ 0);  // 10
    printf("%d \n", -10 ^ 0); // -10

    return 0;
}
```