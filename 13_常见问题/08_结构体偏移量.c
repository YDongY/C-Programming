#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"

struct Teacher {
    char a; // 0~3
    int b; // 4~7
};

void test01() {
    struct Teacher t1;
    struct Teacher *p = &t1;
    printf("%ld \n", (int) &(p->b) - (int) p); // 4
    printf("b 属性的偏移量 %lu \n", offsetof(struct Teacher, b)); // 4
}

void test02() {
    // 偏移量操作内存
    struct Teacher t1 = {'a', 10};

    printf("b = %d \n", *(int *) ((char *) &t1 + offsetof(struct Teacher, b))); // 10
    printf("b = %d \n", *(int *) ((int *) &t1 + 1)); // 10
}

int main(int argc, char const *argv[]) {

    test02();
}