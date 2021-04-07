#include "stdio.h"


void printText(void *data, void(*callback)(void *)) {
    // 回调函数：万能打印
    callback(data);
}

void MyPrint(void *data) {
    int *num = data;
    printf("%d \n", *num);
}

void test01() {
    int a = 10;
    printText(&a, MyPrint);
}


int main(int argc, char const *argv[]) {
    // 回调函数即函数指针作为函数参数
    test01();
}