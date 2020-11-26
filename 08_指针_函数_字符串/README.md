# 指针与函数

## 函数传参

```c
void swap(int a, int b);

void swap2(int *a, int *b);

int main(int argc, char const *argv[]) {
    int m = 10;
    int n = 20;

    swap(m, n); // 实参 --> 形参，值拷贝
    printf("%d %d \n", m, n); // 10 20

    swap2(&m, &n); // 地址拷贝
    printf("%d %d \n", m, n); // 20 10
}
```

## 数组作为参数

数组做参数传递时，不是传递的整个数组，而传递的是一个**指针的大小**

```c
#include <stdio.h>

void print(int arr[]); // 相当于 int *arr

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    print(arr);
}

void print(int arr[]){ // 相当于 int *arr
    printf("%d \t",sizeof(arr)); // 8,即一个指针大小
}

// 改进 void print(int arr[], int len); 相当于 int *arr ,int len
```

## 指针做函数返回值

指针做函数返回值，不能返回局部变量地址

```c
#include <stdio.h>

int m = 100; // 全局变量

int *func() {
    int a = 100;
    return &a; // 不能返回局部变量地址，函数调用完毕，栈帧释放
    // return &m; 全局变量
}
int main(int argc, char const *argv[]) {
    int *p;
    p = func();
    printf("%p \n", *p); // nil
}
```

## 指针和字符串

```c
// -- 字符串变量，可读可写
char str1[] = {'h','e','l','l','o','\0'};
char str11[] = "hello"; // {'h','e','l','l','o','\0'}

// -- 字符串常量，只读
char *str2 = "hello"; // 字符串常量

// 字符串做参数
void func(char str[]);
void func(char *str);
```