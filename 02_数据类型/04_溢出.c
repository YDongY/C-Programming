#include <stdio.h>
int main(int argc, char const *argv[])
{
    // -32768 - 32767
    short s = 32768;
    printf("%d \n", s); // -32768 ，溢出


    short s2 = 0b1111101100;
    printf("%d \n", s2);
    return 0;
}
