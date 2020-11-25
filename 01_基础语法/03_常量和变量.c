#include <stdio.h>

// ------- 标识符常量
#define MAX 100
#define PI 3.1415 // 定义宏，没有分号

// ------- 枚举常量
enum Sex
{
    MALE,
    FEMALE,
    SECRET
};

int main(int argc, char const *argv[])
{
    // 变量定义，会开辟空间
    int age = 20;

    // 变量声明，不会开辟空间。
    int price;
    extern int price2;

    // 编译器编译程序时，在变量使用之前，会将变量声明提升为定义，例如默认:int price = 0;
    // 如果该变量的声明有 extern 关键字，则无法提升


    // ------- 常变量
    const int num = 4;
    // num = 8; 不能修改 num

    int arr[MAX] = {0};
    printf("%d \n", arr);
    printf("%d \n", MAX);

    enum Sex s = FEMALE;
    // s = "aaa"; // 枚举类型只能修改为枚举常量
    printf("%d \n", MALE);   // 0
    printf("%d \n", FEMALE); // 1
    printf("%d \n", SECRET); // 2


    printf("%d \n",sizeof(MAX)); // 4
    printf("%d \n",sizeof(enum Sex)); // 4

    return 0;
}
