#include <stdio.h>

int main(int argc, char const *argv[])
{
    int age[5] = {20, 18, 19, 17, 21};

    for (int i = 0; i < 5; i++)
    {
        printf("%p \n", &age[i]); // 查看内存地址
    }
    printf("数组大小：%d \n", sizeof(age));                       // 内存大小：20
    printf("数组元素个数：%d \n", sizeof(age) / sizeof(int) - 1); // 4

    int a[5];

    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", a[i]); // 0
    }
    return 0;
}
