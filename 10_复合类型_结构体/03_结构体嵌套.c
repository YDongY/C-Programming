#include <stdio.h>

struct Student {
    int age;
    int id;
    char name[32];
    double score;
} stu; // 结构体变量

struct Teacher {
    int id;
    struct Student stu;
};

int main(int argc, char const *argv[]) {
    struct Teacher t1 = {
            1, {20, 1, "张三", 99.9}
    };

    printf("%s \n",t1.stu.name);
}
