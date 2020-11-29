#include "stdio.h"

void printArray(int arr[],int len){ // int arr[] 等价于 int * arr
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}

int main(int argc,char const *argv[]){
    // 一维数组名是不是指针？有两种情况，一维数组名不是指向第一个元素的指针
    // 1. sizeof
    // 2. 对数组名取地址

    int arr[5] = {1,2,3,4,5};
    printf("%p \n",&arr); // 0x7ffe1365ff70
    printf("%p \n",&arr+1); // 0x7ffe1365ff84，数组指针步长是整个数组

    int *p = arr; // 指向数组首元素

    printArray(arr,5);


    // arr 数组名是一个指针常量，指针的指向不可以修改，指针指向的值可以修改
    // int * const a; 指针常量
    // int const *a ; 常量指针

    // 数组索引
    p = p+3;
    printf("%d \n",p[-1]); // 3，p[-1] 等价于 *(p-1)
}

