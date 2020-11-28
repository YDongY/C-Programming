#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct Student {
    int age;
    int id;
    char *name;
    double score;
};

void func() {
    struct Student s1 = {20, 1, "张三", 99.9};
    printf("%d %d %s %lf \n", s1.age, s1.id, s1.name, s1.score);

    // s1.name 是常量，不能修改

    // 不过可以在堆上申请内存存放 name
    struct Student s2 = {20, 1, NULL, 99.9};

    s2.name = malloc(sizeof(char) * 64);

    strcpy(s2.name, "Tom");
    printf("%d %d %s %lf \n", s2.age, s2.id, s2.name, s2.score);

    if (s2.name != NULL) {
        free(s2.name);
        s2.name = NULL;
    }
}

void func2() {
    // 结构体成员创建在堆区，结构体本身也创建在堆区
    struct Student *p = NULL;
    p = malloc(sizeof(struct Student));

    if (p == NULL) {
        return;
    }

    memset(p, 0, sizeof(struct Student));

    p->age = 22;
    p->id = 2;
    p->name = malloc(sizeof(char) * 32);
    p->score = 99.9;
    strcpy(p->name, "Jack");
    printf("%d %d %s %lf \n", p->age, p->id, p->name, p->score);

    if (p->name != NULL) {
        free(p->name);
        p->name = NULL;
    }

    if (p != NULL) {
        free(p);
        p = NULL;
    }

}

int main(int argc, char const *argv[]) {
    func();
    func2();
}