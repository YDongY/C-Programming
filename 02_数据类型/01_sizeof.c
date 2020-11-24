#include <stdio.h>

int main(int argc, char const *argv[])
{

    int i1 = 10;
    int i2 = 20;
    int size = sizeof(i1);
    printf("%d \n", size); // 4
    printf("%d \n", sizeof i1); // 4，不推荐
    printf("%d \n", sizeof(int)); // 4


    // 查看内存地址
    printf("%p \n",&i1); // 0x7fffb3da3468
    printf("%p \n",&i2); // 0x7fffb3da3464


    printf("sizeof(char) = %u \n", sizeof(char)); // sizeof(char) = 1
    int a;
    printf("sizeof(a) = %u \n", sizeof(a)); // sizeof(a) = 4
    return 0;
}
