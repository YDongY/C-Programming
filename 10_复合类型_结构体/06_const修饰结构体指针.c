#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct Student {
    int age;
    int id;
    char *name;
    double score;
};

int main(int argc, char const *argv[]) {
    struct Student s1 = {20, 1, "张三", 99.9};
    struct Student s2 = {20, 2, "李四", 99.9};

    const struct Student *p = &s1;

    // p->id = 20; // const 修饰 *p 则不能改值
    p = &s2; // p 可以修改指针

    struct Student *const p2 = &s2;
    p2->id = 20; // const 修饰 p2 可以修改值
    // p2 = &s1; // const 修饰 p2 不能修改指针


    const struct Student *const p3 = &s2;

    // p3->id = 20，p3=&s1 都不能修改

}
