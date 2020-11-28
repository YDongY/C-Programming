#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Student {
    int age;
    int id;
    char name[32];
    double score;
} stu; // 结构体变量


void func() {
    // 结构体数组创建在堆区
    struct Student *arr = malloc(sizeof(struct Student) * 3);

    // 清空内存
    memset(arr, 0, sizeof(struct Student) * 3);

    for (int i = 0; i < 3; i++) {
        arr[i].id = i; // (arr+i)->id
        arr[i].age = 20 + i; // (arr+i)->age
        char buf[32];
        sprintf(buf, "张三-%d", i); // 用做字符串拼接 xxx-x
        strcpy(arr[i].name, buf); // (arr+i)->name
        arr[i].score = i * 99.9; // (arr+i)->score
    }
    for (int i = 0; i < 3; i++) {
        printf("%d %d %s %lf \n", arr[i].age, arr[i].id, arr[i].name, arr[i].score);
    }

    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }

}

void func2(struct Student s1) { // 值传递，不能修改实参
    // 结构体指针做函数参数
    printf("%d %d %s %lf \n", s1.age, s1.id, s1.name, s1.score);
}

void func3(struct Student *s1) { // 地址传递，可以修改实参
    // 结构体指针做函数参数
    printf("%d %d %s %lf \n", s1->age, s1->id, s1->name, s1->score);
}

int main(int argc, char const *argv[]) {
    struct Student s1 = {20, 1, "张三", 99.9};

    // 结构体指针
    struct Student *p = &s1;

    printf("%d %d %s %lf \n", p->age, p->id, p->name, p->score);
    printf("%d %d %s %lf \n", (*p).age, (*p).id, (*p).name, (*p).score);

    // 取地址
    printf("%d %d %s %lf \n", (&s1)->age, (&s1)->id, (&s1)->name, (&s1)->score);

    func();

    func2(s1);
    func3(&s1);

}