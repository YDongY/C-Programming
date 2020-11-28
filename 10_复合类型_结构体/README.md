# 结构体

## 结构体定义

```c
struct Student {
    int age;
    int id;
    char name[32];
    double score;
} stu; // 结构体变量，可写可不写

struct Student2 {
    int age;
    int id;
    char name[32];
    double score;
} stu2 = {22, 1, "王五", 99.9}; // 直接赋值

// 创建结构体
struct Student s1 = {20, 1, "张三", 99.9};

// 使用结构体变量赋值
stu.id = 2;
strcpy(stu.name, "李四");
stu.age = 22;
stu.score = 100.0;
```

## 结构体赋值

```c
struct Student s1;
struct Student s2 = {20, 1, "张三", 99.9};

// 1. 逐个复制
s1.id = 2;
strcpy(s1.name, "李四");
s1.age = 22;
s1.score = 100.0;

// 2. 相同类型整体复制
s1 = s2;

// 3. 内存拷贝
memcpy(&s1,&s2,sizeof(struct Student));
```

## 结构体变量交换

```c
struct Student s1 = {22, 1, "李四", 100.0};
struct Student s2 = {20, 2, "张三", 99.9};

// 1. 逐个交换

// 2. 临时变量

struct Student temp;
temp = s1;
s1 = s2;
s2 = temp
```

## 结构体数组

```c
struct Student arr[5] = {
            {20, 1, "张三", 100.0},
            {22, 2, "李四", 99.0},
            {23, 3, "王五", 88.0},
    };

int len = sizeof(arr) / sizeof(struct Student);
for (int i = 0; i < len; i++) {
    printf("%d %d %s %f \n", arr[i].age, arr[i].id, arr[i].name, arr[i].score);
}
```

## 结构体嵌套

```c
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
    // 访问学生姓名
    printf("%s \n",t1.stu.name);
}
```

## 结构体与指针

```c
struct Student {
    int age;
    int id;
    char name[32];
    double score;
} stu; // 结构体变量


int main(int argc, char const *argv[]) {
    struct Student s1 = {20, 1, "张三", 99.9};

    // 结构体指针
    struct Student *p = &s1;

    printf("%d %d %s %lf \n", p->age, p->id, p->name, p->score);
    printf("%d %d %s %lf \n", (*p).age, (*p).id, (*p).name, (*p).score);

    // 取地址
    printf("%d %d %s %lf \n", (&s1)->age, (&s1)->id, (&s1)->name, (&s1)->score);
}
```

## 结构体数组

```c
void func() {
    // 结构体数组创建在堆区
    struct Student *arr = malloc(sizeof(struct Student) * 3);
    
    // 清空内存
    memset(arr, 0, sizeof(struct Student) * 3);
    
    // 赋值
    for (int i = 0; i < 3; i++) {
        arr[i].id = i; // (arr+i)->id
        arr[i].age = 20 + i; // (arr+i)->age
        char buf[32];
        sprintf(buf, "张三-%d", i); // 用做字符串拼接 xxx-x
        strcpy(arr[i].name, buf); // (arr+i)->name
        arr[i].score = i * 99.9; // (arr+i)->score
    }
    
    // 输出
    for (int i = 0; i < 3; i++) {
        printf("%d %d %s %lf \n", arr[i].age, arr[i].id, arr[i].name, arr[i].score);
    }
    
    // 释放内存
    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }
}

int main(int argc, char const *argv[]) {
    func();
}
```

## 结构体指针做函数参数

```c
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
    func2(s1);
    func3(&s1);
}
```

## 结构体成员创建在堆区

```c
struct Student {
    int age;
    int id;
    char *name; // 指针
    double score;
};

void func() {
    struct Student s1 = {20, 1, "张三", 99.9};
    printf("%d %d %s %lf \n", s1.age, s1.id, s1.name, s1.score);

    // s1.name 是常量，不能修改

    // 不过可以在堆上申请内存，存放 name
    struct Student s2 = {20, 1, NULL, 99.9};
    
    // 申请内存
    s2.name = malloc(sizeof(char) * 64); 
    
    // 赋值
    strcpy(s2.name, "Tom");
    printf("%d %d %s %lf \n", s2.age, s2.id, s2.name, s2.score);

    // 释放内存
    if (s2.name != NULL) {
        free(s2.name);
        s2.name = NULL;
    }
}
```

## 联合体

```c
union Person { // 联合体中的成员，共用同一块内存空间，按照最大的数据类型分配内存空间
    int a;
    short b;
    char c;
};
printf("%lu \n", sizeof(union Person)); // 4

void func(){
    union Person p;
    p.a = 0x01020304;
    p.b = 0x0102;
    p.c = 0x01;

    printf("%#x \n", p.a + p.b + p.c); // 0x1020203
}

------------------------------------------
|  04     |    03    |    02   |    01   |   a = 0x01020304
------------------------------------------
|  02     |    01    |    02   |    01   |   b = 0x00000102
------------------------------------------
|  01     |    01    |    02   |    01   |   c = 0x00000001
------------------------------------------
                    (4 字节)     (2 字节)      (1 字节)
p.a + p.b + p.c = 0x01020101 + 0x00000101 + 0x00000001 = 0x1020203
```

