#include <stdio.h>

struct Student {
    int age;
    int id;
    char name[32];
    double score;
} stu; // 结构体变量

int main(int argc, char const *argv[]) {
    struct Student arr[5] = {
            {20, 1, "张三", 100.0},
            {22, 2, "李四", 99.0},
            {23, 3, "王五", 88.0},
    };

    int len = sizeof(arr) / sizeof(struct Student);
    for (int i = 0; i < len; i++) {
        printf("%d %d %s %f \n", arr[i].age, arr[i].id, arr[i].name, arr[i].score);
    }
}
