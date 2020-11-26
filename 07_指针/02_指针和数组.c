#include "stdio.h"

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3};

    printf("%p \n", arr); // 0x7fff48cf3bbc 数组名是地址

    for (int i = 0; i < 3; i++) {
        printf("%d \t", *(arr + i)); // arr[i]
    }

    int *p = arr;
    for (int i = 0; i < 3; i++) {
        printf("%d \t", p[i]);
    }

    printf("\n-----\n");
    for (int i = 0; i < 3; i++) {
        printf("%d \t", *p);
        p++;
    }

}