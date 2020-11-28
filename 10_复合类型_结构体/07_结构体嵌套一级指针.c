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
    // 创建三个结构体指针在堆区
    struct Student **arr = malloc(sizeof(struct Student *) * 3);

    for (int i = 0; i < 3; i++) {
        arr[i] = malloc(sizeof(struct Student));
        arr[i]->name = malloc(sizeof(char) * 32);
        sprintf(arr[i]->name, "stu_%d", i);

        arr[i]->age = 20 + i;
        arr[i]->id = i;
        arr[i]->score = i * 55.5;
    }

    for (int i = 0; i < 3; i++) {
        printf("%d %d %s %lf \n", arr[i]->age, arr[i]->id, arr[i]->name, arr[i]->score);
    }

    // 释放
    for (int i = 0; i < 3; i++) {
        if (arr[i]->name != NULL) {
            free(arr[i]->name);
            arr[i]->name = NULL;
        }
        if (arr[i] != NULL) {
            free(arr[i]);
            arr[i] = NULL;
        }
    }

    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }
}
