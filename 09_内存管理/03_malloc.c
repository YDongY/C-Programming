#include "stdio.h"
#include "stdlib.h"

void test_malloc() {
    int *p;
    p = malloc(sizeof(int));

    if (p == NULL) {
        printf("申请失败\n");
        return;
    }

    printf("%d \n", *p);
    printf("%p \n", p); // 0x1075260

    free(p);
}


int main(int argc, char const *argv[]) {
    int *p = (int *) malloc(4); // 堆区申请 4 个字节空间，里面内容是随机的
    // char *s = (char *) malloc(64);
    // int **i = malloc(sizeof(int*)*10);

    if (p == NULL) {
        // 判断申请的内存是否失败
        return -1;
    }

    // 申请的内存空间，会在整个程序结束，才会被系统释放

    // 通常由手动释放
    free(p); // 参数为首地址

    test_malloc();
}
