#include "stdio.h"

int main(int argc, char const *argv[]) {
    // ------- 修改变量

    const int a = 20;
    //  a = 10; // 不能修改

    int *p = &a;
    *p = 10;
    printf("%d\n", a); // 10

    // --------- 修改指针
    const int *p2; // *p2 不能修改，可以修改 p2

    int const *p3; // *p3 不能修改，可以修改 p3

    int * const p4; // 可以修改 *p4 ，不能修改 p4

    const int * const p5; // 不可以修改 *p4 ，也不能修改 p4

    // 总结：const 向右修饰，被修饰的只读
}
