#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10][3];
    printf("数组大小:%d \n", sizeof(arr));              // 数组大小:120
    printf("数组一行大小:%d \n", sizeof(arr[0]));       // 数组一行大小:12
    printf("行数:%d \n", sizeof(arr) / sizeof(arr[0])); // 行数:10
    printf("列数:%d \n", sizeof(arr[0]) / sizeof(int)); // 3

    printf("数组首地址：%p \n", arr);          // 0x7ffe434135c0
    printf("数组首元素地址：%p \n", arr[0]);   // 0x7ffe434135c0
    printf("数组首行地址：%p \n", &arr[0][0]); // 0x7ffe434135c0

    // 初始化
    int array1[2][3] = {{1, 2}, {3, 4, 5}}; // 未被初始化的数值为 0
    int array2[2][3] = {0};                      // 初始化全 0
    int array3[2][3] = {1, 2, 3, 4, 5, 6};       // 系统自动分配行列
    int array4[][2] = {1, 2, 3, 4};              // 二维数组定义必须指定列值,自动分配，不足补 0 

    int arr3[2][3] = {{1, 2, 3}, {4, 5, 6}}; // 2行3列

    for (int i = 0; i < 2; i++) // 二维数组遍历
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d \t", arr3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
