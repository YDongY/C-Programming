#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void setArray(int *arr, int num) {
    for (int i = 0; i < num; i++) {
        arr[i] = i + 10;
    }
}

void printArray(int *arr, int num) {
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
}

int main(int argc, char const *argv[]) {
    int num = 10;

    int *arr = malloc(sizeof(int) * num); // 数组放在读取

    if (arr == NULL) {
        printf("申请失败 \n");
        return -1;
    }

    // 清空内存
    memset(arr, 0, sizeof(int) * num);

    // 设置元素
    setArray(arr, num);

    // 输出数组
    printArray(arr, num);

    // 释放内存
    free(arr);
}

