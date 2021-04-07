#include "stdio.h"

// void printArray(int arr[][3], int row, int col) // row 可以省略
// void printArray(int (*arr)[3], int row, int col) // arr[3][3] 等价于一维数组指针 int (*arr)[3]
void printArray(int arr[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
            // printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {

    int arr[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    // 等价 int arr2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 等价 int arr3[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 二维数组名称,除了特殊情况情况，
    // 1. sizeof
    // 2. &arr , 获取的是二维数组的数组指针，步长为整个二维数组，int (*p)[3][3] = &arr;
    printf("%lu \n", sizeof(arr)); // 36

    // 二维数组名是指向第一个一维数组的数组指针，步长为二维数组中的一个一维数组大小
    int (*p)[3] = arr;

    printf("%d \n", arr[1][2]); // 6
    printf("%d \n", *(*(p + 1) + 2)); // 6
    // p+1：跳过一个一维数组
    // *(p+1)：解引用得到一维数组
    // *(p+1) + 2：在一维数组上跳过 2 个元素，得到 6 的地址
    // *(*(p+1) + 2)：对 6 解引用得到元素内容

    printArray(arr, 3, 3);
}