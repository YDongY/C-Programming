#include <stdio.h>

int main(int argc, char const *argv[])
{
    double a;
    int b = 10;

    a = b;               // 隐式转换
    printf("%lf \n", a); // 10.000000

    double n;

    printf("%d \n", 1 / 2); // 0

    n = (double)1 / 2; // 强制类型装换

    printf("%lf \n", n); // 0.500000

    return 0;
}
