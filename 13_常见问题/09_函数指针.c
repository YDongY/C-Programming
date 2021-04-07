#include "stdio.h"

void test01(int a) {
    printf("hello world %d \n", a);
}

void func(int a, char c) {
    printf("hello world %d %c\n", a, c);
}

void test02() {
    // 1. 先定义函数类型，再通过类型定义函数指针
    typedef void(FUNC_TYPE)(int, char);
    FUNC_TYPE *p = func;
    p(10, 'a');

    // 2. 定义函数指针类型，通过类型定义函数指针
    typedef void(*FUNC_TYPE2)(int, char);
    FUNC_TYPE2 p2 = func;
    p2(10, 'b');

    // 3.
    void (*p3)(int, char) = func;
    p3(10, 'c');

    // 函数指针与指针函数？
    // 函数指针：指向函数的指针
    // 指针函数：函数返回是指针的函数
}

void func1() {
    printf("func1 \n");
}

void func2() {
    printf("func2 \n");
}

void func3() {
    printf("func3 \n");
}

void test03() {
    // 函数指针数组
    void(*pArray[3])();
    pArray[0] = func1;
    pArray[1] = func2;
    pArray[2] = func3;

    for (int i = 0; i < 3; i++) {
        pArray[i]();
    }
}

int main(int argc, char const *argv[]) {
    // 函数名本质就是一个函数指针，可以利用函数指针调用函数
    // printf("%p \n", main);
    // printf("%p \n", test01); // 0x401122

    // void (*p_func)(int) = (void *) 0x401122; // 地址
    // void (*p_func)(int) = test01; // 地址
    // p_func(10); // hello world 10

    // 函数指针定义
    // test02();

    // 函数指针数组
    test03();
}
