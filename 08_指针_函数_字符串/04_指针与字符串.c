#include "stdio.h"

int compare(const char str1[], const char str2[]); // 比较字符串大小

void copy(char *dest, const char *src); // 字符串拷贝
void copy2(char *dest, const char *src); // 字符串拷贝-指针版

void strip(char *dest, const char *src); // 取出空格
void strip2(char *dest, const char *src); // 取出空格-指针版

int main(int argc, char const *argv[]) {
    char str1[] = {'h','e','l','l','o','\0'};
    char str11[] = "hello"; // {'h','e','l','l','o','\0'}

    char *str2 = "hello"; // 字符串常量
    char *str22 = "hello";


    printf("%p\n", str1); // 0x7ffdc0991e5a
    printf("%p\n", str11); // 0x7ffdc0991e54

    // 地址相等
    printf("%p\n", str2); // 0x402004
    printf("%p\n", str22); // 0x402004

    char s1[] = "hello";
    char s2[] = "hello world";

    printf("%d \n", compare(s1, s2));

    char *src = "hello";
    char dest[100] = {0};

    copy(dest, src);
    // copy2()
    printf("%s \n", dest);

    char *src2 = "ni hao a ,ni hello world";
    char dest2[100] = {0};
    strip(dest2, src2);
    printf("%s \n", dest2);
}

int compare(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0') {
            return 0;
        }
        i++;
    }
    return str1[i] > str2[i] ? 1 : -1;
}

void copy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void copy2(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

void strip(char *dest, const char *src) {
    int i = 0;
    int j = 0;

    while (src[i] != '\0') {
        if (src[i] != ' ') {
            dest[j] = src[i];
            j++;
        }
        i++;
    }
    dest[j] = '\0';
}

void strip2(char *dest, const char *src) {
    while (*src) {
        if (*src != ' ') {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}