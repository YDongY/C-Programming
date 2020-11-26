#include <stdio.h>

int m = 100;

int *func() {
    // printf("%p \n", &m);
    // return &m;

    // int a = 1000;
    // return &a; // 不能返回局部变量
}

int main(int argc, char const *argv[]) {
    int *p;

    p = func();

    printf("%p \n", p);
}
