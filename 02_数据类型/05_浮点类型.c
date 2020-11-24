#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a = 3.14f;
    float b = 1.;
    float c = 1.f;

    printf("%f \n", a); // 3.140000
    printf("%f \n", b); // 1.000000
    printf("%f \n", c); // 1.000000

    double d;

    d = 3.14;

    double e = .1;

    printf("%lf \n", d); // 3.140000
    printf("%lf \n", e); // 0.100000


    // 十进制小数
    // 1.2 * 10^3
    float f4 = 1.2e3f;
    float d4 = 1.2e3;
    printf("%f \n", f4); // 1200.000000
    printf("%f \n", d4); // 1200.000000

    // 十六进制小数
    // 1.125 * 2^10
    float f5 = 0x1.2p10;
    printf("%f \n", f5); // 1152.000000
    printf("%.2f \n", f5); // 1152.00

    // 1.875 * 2^3
    printf("%f \n", 0x1.ep+3); // 15.000000
    printf("%f \n", 0x1.ep-2); // 0.468750

    return 0;
}
