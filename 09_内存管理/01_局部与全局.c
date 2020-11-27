#include <stdio.h>

int a = 10; // 全局变量
static int b = 20; // 静态全局变量

void func(){
    int c = 100; // 局部变量
    static int d = 200; // 静态局部变量
}

static void func2(){
    // ...
}

int main(int argc, char const *argv[]) {
    func();
}
