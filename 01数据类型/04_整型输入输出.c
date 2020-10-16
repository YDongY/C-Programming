#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a; // 4字节
    printf("请输入a:");
    scanf("%d", &a);
    printf("a=%d\n", a);

    short b; // 2 个字节
    printf("请输入b:");
    scanf("%hd", &b);
    printf("b=%hd\n", b);

    // long long c;
    long long int c; // 8字节
    printf("请输入c:");
    scanf("%d", &c);
    printf("c=%d\n", c);
    return 0;
}
