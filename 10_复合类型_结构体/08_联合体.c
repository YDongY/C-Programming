#include "stdio.h"
#include "stdlib.h"
#include "string.h"

union Person { // 联合体中的成员，共用同一块内存空间，按照最大的数据类型分配内存空间
    int a;
    short b;
    char c;
};


void func(){
    union Person p;
    p.a = 0x01020304;
    p.b = 0x0102;
    p.c = 0x01;

    printf("%#x \n", p.a + p.b + p.c); // 0x1020203
}

int main(int argc, char const *argv[]) {
    printf("%lu \n", sizeof(union Person)); // 4

    union Person p;
    p.a = 10;
    p.b = 20;
    p.c = 30;

    printf("%d \n", p.a + p.b + p.c); // 30+30+30 = 90

    func();
}