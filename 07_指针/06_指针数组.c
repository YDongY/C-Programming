#include "stdio.h"

int main(int argc, char const *argv[]) {
    int a = 10;
    int b = 20;
    int c = 30;

    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;

    int *arr[] = {p1, p2, p3}; // 整型指针数组

    printf("%d \n", *(arr[0])); // 10
    printf("%d \n", *(*(arr + 0))); // 10
    printf("%d \n", *(*arr)); // 10
    printf("%d \n", **arr); // 10

}