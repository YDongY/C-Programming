#include "stdio.h"

int main(int argc, char const *argv[]) {

    int a = 10;
    printf("%p \n", &a); // 打印内存地址

    int b = 10;
    printf("%p \n", &b); // 0x7ffd822cbe48

    // 指针类型的变量 p 存放 整型变量 b 的内存地址
    int *p = &b; // int * 表示指针类型，p 是变量名
    printf("%p\n", p); // 0x7ffd822cbe48
    printf("%d\n", *p); // 10

    // 打印指针 p 的内存地址
    printf("%p\n", &p); // 0x7fff7e7433e0

    // 指针类型大小 8 字节
    printf("%lu\n", sizeof(int *)); // 8 ,32位 4 字节，64 位　8 字节

    *p = 20;
    printf("%d \n", b);


    // -------- 野指针 ------
    /**
        int *c;
        c = 1000;
        printf("%d \n",*c);

        int *c = 10;
        *c = 1000;
        printf("%d \n",*c);
     */

    // ---------- 空指针 -------
    /**
        int *c = NULL;
        c = 1000;
        printf("%d \n",*c);
     */

    // -------- 万能指针、泛型指针 ---------
    int num = 345;
    void *c;

    c = &num;

    printf("%d \n",*(int *)c);

    return 0;
}