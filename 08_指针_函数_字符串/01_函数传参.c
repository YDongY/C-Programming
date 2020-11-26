#include <stdio.h>

void swap(int a, int b);

void swap2(int *a, int *b);

int main(int argc, char const *argv[]) {
    int m = 10;
    int n = 20;

    swap(m, n); // 实参 --> 形参，值拷贝

    printf("%d %d \n", m, n); // 10 20

    swap2(&m, &n); // 地址拷贝

    printf("%d %d \n", m, n); // 20 10
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

