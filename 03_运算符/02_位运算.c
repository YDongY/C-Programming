#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 左移
    int a = 1 << 1;
    // 右移
    int b = 1 >> 1;
    printf("%d \n", a); // 2
    printf("%d \n", b); // 0

    // ~
    printf("%d \n", ~0); // -1
    printf("%d \n", ~1); // -2

    // & | ^

    printf("%d \n", 10 ^ 10); // 0
    printf("%d \n", -10 ^ 0); // -10
    printf("%d \n", 10 ^ 0);  // 10
    printf("%d \n", -10 ^ 1); // -9
    printf("%d \n", 10 ^ 1);  // 11

    return 0;
}
