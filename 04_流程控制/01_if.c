#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 30;
    if (a > 30) {
        printf("a>30");
    } else {
        printf("a<30");
    }

    int b = 400;
    if (b == 100) {
        printf("b=100");
    } else if (b == 200) {
        printf("b=200");
    } else if (b == 300) {
        printf("b=300");
    } else {
        printf("%d", b);
    }

    return 0;
}
