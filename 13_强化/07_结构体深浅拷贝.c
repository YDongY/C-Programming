#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Person {
    char name[64];
    int age;
};

void test01() {
    struct Person p1 = {"tom", 22};
    struct Person p2 = {"jack", 20};

    p1 = p2; // 浅拷贝，逐字节拷贝

    printf("%s %d \n", p1.name, p1.age); // jack 20
    printf("%s %d \n", p2.name, p2.age); // jack 20
}

struct Person2 {
    char *name;
    int age;
};

void test02() {
    struct Person2 p1;
    p1.name = malloc(sizeof(char) * 64);
    strcpy(p1.name, "tom");
    p1.age = 22;

    struct Person2 p2;
    p2.name = malloc(sizeof(char) * 128);
    strcpy(p2.name, "jack");
    p2.age = 20;

    // p1 = p2; // 浅拷贝,有问题

    // 解决方案，手动赋值，深拷贝
    // 1. 释放
    if(p1.name!=NULL){
        free(p1.name);
        p1.name = NULL;
    }

    // 2. 重新创建内存
    p1.name = malloc(strlen(p2.name)+1);
    strcpy(p1.name,p2.name);
    p1.age = p2.age;

    printf("%s %d \n", p1.name, p1.age); // jack 20
    printf("%s %d \n", p2.name, p2.age); // jack 20

    // free(): double free detected in tcache 2
    // 1. 堆区内存重复释放
    // 2. 内存泄露
    if (p1.name) {
        free(p1.name); // p1=p2 浅拷贝 free
        p1.name = NULL;
    }
    if (p2.name) {
        free(p2.name); // p1=p2 上面已经 free 了，这块内存没人管
        p2.name = NULL;
    }


}


int main(int argc, char const *argv[]) {

    // test01();
    test02();
}