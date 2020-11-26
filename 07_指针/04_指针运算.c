#include "stdio.h"

int main(int argc, char const *argv[]) {
    int a = 12345678;
    int *p = &a;
    printf("%d \n",*p); // 12345678

    char *p3 = &a;
    printf("%d \n",*p3); // 78

    printf("%p \n",p3); // 0x7fff5bff399c
    printf("%p \n",p3+1); // 0x7fff5bff399d



}

