# 数组

> 数组是多个相同类型数据的集合

## 一维数组初始化

```C
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int a[5]; // 声明

    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", a[i]); // 数组声明，但是未初始化，内部数据是不确定的（垃圾数据）
    }

    int b[5] = {11, 22, 33}; // {11,22,33,0,0}
    int c[5] = {0};          // {0,0,0,0,0}
    int d[5] = {};           // {0,0,0,0,0} C 标准不支持，但是 gcc 支持
    int s[] = {11, 22, 33};  // {11,22,33}

    int e[5] = {[4] = 55,
            [0] = 11,
            22,
            33,
            44}; // {11,22,33,44,55}

    // 计算数组元素个数
    int len = sizeof(e) / sizeof(int);
    printf("len:%d", len); // len:5

    char arr1[] = "abc";           // {'a','b','c','\0'} ,末尾 \0 表示字符串结束标志
    char arr2[] = {'a', 'b', 'c'};
    printf("%d \n", strlen(arr1)); // 3
    printf("%d \n", strlen(arr2)); // 随机值，遇到 \0 结束

    return 0;
}
```

## 数组元素内存分布

```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[5] = {20, 18, 19, 17, 21};

    for (int i = 0; i < 5; i++)
    {
        printf("%p \n", &a[i]); // 查看内存地址
    }
    printf("内存大小：%d", sizeof(a)); // 内存大小：20
    printf("数组元素个数：%d \n", sizeof(age) / sizeof(int) - 1); // 4

    return 0;
}

// -------------- 内存分布 ------------------
// 数组的地址值，就是数组首元素的地址
----------------------------------------------
| 变量 |   内存地址    |         字节           |
----------------------------------------------
|     |0x7fffc65be170|  |  |  |  |  |  |  |  |  \
|     |0x7fffc65be171|  |  |  |  |  |  |  |  |   \
|a[0] |0x7fffc65be172|  |  |  |  |  |  |  |  |   / 32bit
|     |0x7fffc65be173|  |  |  |  |  |  |  |  |  /
----------------------------------------------
|     |0x7fffc65be174|  |  |  |  |  |  |  |  |  \
|     |0x7fffc65be175|  |  |  |  |  |  |  |  |   \
|a[1] |0x7fffc65be176|  |  |  |  |  |  |  |  |   / 32bit
|     |0x7fffc65be177|  |  |  |  |  |  |  |  |  /
----------------------------------------------
|     |0x7fffc65be178|  |  |  |  |  |  |  |  |  \
|     |0x7fffc65be179|  |  |  |  |  |  |  |  |   \
|a[2] |0x7fffc65be17a|  |  |  |  |  |  |  |  |   / 32bit
|     |0x7fffc65be17b|  |  |  |  |  |  |  |  |  /
----------------------------------------------
|     |0x7fffc65be17c|  |  |  |  |  |  |  |  |  \
|     |0x7fffc65be17d|  |  |  |  |  |  |  |  |   \
|a[3] |0x7fffc65be17e|  |  |  |  |  |  |  |  |   / 32bit
|     |0x7fffc65be17f|  |  |  |  |  |  |  |  |  /
----------------------------------------------
|     |0x7fffc65be180|  |  |  |  |  |  |  |  |  \
|     |0x7fffc65be181|  |  |  |  |  |  |  |  |   \
|a[4] |0x7fffc65be182|  |  |  |  |  |  |  |  |   / 32bit
|     |0x7fffc65be183|  |  |  |  |  |  |  |  |  /
----------------------------------------------
```

## 二维数组

```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10][3];
    printf("数组大小:%d \n", sizeof(arr));              // 数组大小:120
    printf("数组一行大小:%d \n", sizeof(arr[0]));       // 数组一行大小:12
    printf("行数:%d \n", sizeof(arr) / sizeof(arr[0])); // 行数:10
    printf("列数:%d \n", sizeof(arr[0]) / sizeof(int)); // 3

    printf("数组首地址：%p \n", arr);          // 0x7ffe434135c0
    printf("数组首元素地址：%p \n", arr[0]);   // 0x7ffe434135c0
    printf("数组首行地址：%p \n", &arr[0][0]); // 0x7ffe434135c0

    // 初始化
    int array1[2][3] = {{1, 2}, {3, 4, 5}}; // 未被初始化的数值为 0
    int array2[2][3] = {0};                      // 初始化全 0
    int array3[2][3] = {1, 2, 3, 4, 5, 6};       // 系统自动分配行列
    int array4[][2] = {1, 2, 3, 4};
}
```

## 字符数组

```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str2[] = "world"; // {'w', 'o', 'r', 'l', 'd', '\0'}
}
```