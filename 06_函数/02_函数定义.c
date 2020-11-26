#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int main(int argc, char const *argv[]) {
    int a = 10;
    int b = 20;
    int sum = add(a, b);
    printf("%d", sum); // 30

    return 0;
}
