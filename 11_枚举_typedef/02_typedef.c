#include <stdio.h>

typedef int MYINT; // 起比别名

struct Student {
    int age;
    int id;
};
typedef struct Student stu1; // 起别名

// 上面简化
typedef struct Student2 {
    int age;
    int id;
} stu2;


void func() {
    // typedef 区分数据类型

    char *p1, p11;
    printf("p1=%lu ,p11=%lu", sizeof(p1), sizeof(p11)); // p1=8 ,p11=1

    // p1 是 char *
    // p11 是 char

    typedef char *PCHAR; // 区分数据类型

    PCHAR p2, p22;

    // p2 是 char *
    // p22 是 char *

    printf("p2=%lu ,p22=%lu", sizeof(p2), sizeof(p22)); // p2=8 ,p22=8
}

int main(int argc, char const *argv[]) {
    MYINT a = 10;
    printf("%d \n", a);

    struct Student s1 = {20, 1};

    stu1 s2 = {20, 1};
    stu2 s3 = {20, 1};

    func();
}
