#include "stdio.h"

void test01() {
    /**
     *  数组指针：是指针，指向一个数组的指针
     */



    // 1. 先定义数组类型，再通过类型定义指针变量
    int arr[5] = {1, 2, 3, 4, 5};

    typedef int (ARRAY_TYPE)[5]; // ARRAY_TYPE 表示存放 5 个 int 类型的数组的数组类型，本质是数组类型
    /**
    ARRAY_TYPE arr2;
    for (int i = 0; i < 5; i++) {
        arr2[i] = 100 + i;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    */
    ARRAY_TYPE *p = &arr; // p 就是数组指针类型变量
    printf("p = %p,p+1=%p \n", p, p + 1); // p = 0x7ffda27b2680,p+1=0x7ffda27b2694 ，步长为 sizeof(int)*5
    // *p = arr = 数组名
    for (int i = 0; i < 5; i++) {
        printf("%d ", (*p)[i]);
    }

}


void test02() {
    // 先定义数组指针类型，在通过类型定义数组指针

    int arr[5] = {1, 2, 3, 4, 5};
    typedef int (*ARRAY_TYPE)[5];

    ARRAY_TYPE p = &arr;
    for (int i = 0; i < 5; i++) {
        printf("%d ", (*p)[i]);
    }

}

void test03() {
    int arr[5] = {1, 2, 3, 4, 5};
    int (*p)[5] = &arr;
    for (int i = 0; i < 5; i++) {
        printf("%d ", (*p)[i]);
    }
}

int main(int argc, char const *argv[]) {

    test01();

}