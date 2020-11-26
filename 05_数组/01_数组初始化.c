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
    printf("len:%d \n", len); // len:5

    char arr1[] = "abc";           // {'a','b','c','\0'} ,末尾 \0 表示字符串结束标志
    char arr2[] = {'a', 'b', 'c'};
    printf("%d \n", strlen(arr1)); // 3
    printf("%d \n", strlen(arr2)); // 6 ,随机值

    return 0;
}