#include <stdio.h>
#include "string.h"

struct Student {
    int age;
    int id;
    char name[32];
    double score;
} stu; // 结构体变量

struct Student2 {
    int age;
    int id;
    char name[32];
    double score;
} stu2 = {22, 1, "王五", 99.9}; // 直接赋值

void func() {
    // 创建结构体
    struct Student s1 = {20, 1, "张三", 99.9};

    // 访问结构体
    printf("%d \n", s1.age);
    printf("%d \n", s1.id);
    printf("%s \n", s1.name);
    printf("%.1f \n", s1.score);

    // 或者
    stu.id = 2;
    strcpy(stu.name, "李四");
    stu.age = 22;
    stu.score = 100.0;

    printf("%d \n", stu.age);
    printf("%d \n", stu.id);
    printf("%s \n", stu.name);
    printf("%.1f \n", stu.score);


}

int main(int argc, char const *argv[]) {
    func();
}
