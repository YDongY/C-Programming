#include "stdio.h"


int main(int argc, char const *argv[]) {
    // argc : 参数的总个数
    // argv : 每个元素都是字符串 char *

    // --- 编译: gcc xx.c -o main

    // --- 执行: ./main hello world 1 2

    printf("%d \n", argc); // 5，参数包含 ./main
    while (*argv) {
        printf("%s \n", *argv); // ./main hello world 1 2
        argv++;
    }

}