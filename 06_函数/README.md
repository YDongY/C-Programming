# 函数

## 字符串函数

- `fgets()`:获取一个字符串 【安全】

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    //char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
    // 参数一：存储字符串空间地址
    // 参数二：描述空间大小
    // 参数三；读取字符串位置,stdin 标准输入
    // 空间足够会读取回车的 \n
    printf("获取输入字符串：%s",fgets(str2,sizeof(str2),stdin));
}
```

- `puts()`：输出字符串到屏幕

```c
char str3[] = "hello world C";
int ret = puts(str3); // 成功：字符串长度，失败:-1，默认输出带上 \n
printf("返回值：%d \n", ret);
```

- `fputs()`：输出字符串

```c
char str3[] = "hello world C";
int ret2 = fputs(str3, stdout); // 默认输出不带 \n
printf("返回值：%d \n", ret2); // 1
```

- `strlen()`：获取字符串有效长度，不包含 \0 ，遇到 \0 结束

```c
printf("sizeof(str) = %lu\n", sizeof("hello world")); // 12
printf("strlen(str) = %lu\n", strlen("hello world")); // 11
printf("strlen(str) = %lu\n", strlen("hello\0world")); // 5
```

## 系统库函数

```c
#include <stdio.h> // 引入头文件，声明函数
int main(int argc, char const *argv[])
{
   
    char arr1[] = "bit";
    printf("%s\n", arr1);
    return 0;
}

```

## 用户自定义函数

```c
int add(int x, int y) // 返回值类型 函数名(形参列表)
{
    return x + y; // 返回值
}

add(10,20); // 函数调用
```

## 函数声明

> 函数定义在函数调用之后，需要提前函数声明，如果不手动声明，编译器只会隐式声明返回值为 int

```c
#include <stdio.h>
void func(int arr[]); // 函数声明

int main(int argc, char const *argv[])
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10}
    func();    
}

void func(int arr[]) { // 函数定义
    for (int i = 0; i < 10; i++) {
        printf("%d \t",arr[i]);
    }
}
```

## 函数头文件

```
.
├── add.c
├── main.c
├── head.h
```

- `add.c`：函数定义
- `head.h`：头文件
- `main.c`:程序入口，函数调用

```c
int add(int x, int y) {
    return x + y;
}
```

```c
#include "head.h"

int main(int argc, char const *argv[]) {
    printf("%d \n",add(10,20));
}
```

```c
#ifndef _HEAD_H
#define _HEAD_H

// include 头文件

#include <stdio.h>
#include <string.h>

// 函数声明
int add(int a,int b);

// 宏定义
#define MAX 100
#define PI 3.14

#endif
```