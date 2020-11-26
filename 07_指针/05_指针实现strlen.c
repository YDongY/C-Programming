#include "stdio.h"

int mystrlen(char str[]) {
    char *p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str; // 指针偏移
}

int main(int argc, char const *argv[]) {
    char str[] = "hello world";
    printf("%d \n", mystrlen(str));
}