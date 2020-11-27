#include "stdio.h"
#include "string.h"

void test_memset() {
    // memset 内存设置
    char buf[32] = "hello world";
    memset(buf, 'a', 31); // 不包含 \0
    printf("%s \n", buf); // aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

    // 主要用途：内存清空
    memset(buf, 0, 32);
    printf("%s \n", buf);
}

void test_memcpy() {
    char dest[64] = {0};
    char src[64] = "hello\0world";
    memcpy(dest, src, sizeof(dest)); // 拷贝整个字符串，遇到 \0 不会结束
    for (int i = 0; i < sizeof(dest); i++) {
        printf("%c", dest[i]);
    }

    // 主要用途：直接给数组赋值
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5];

    memcpy(arr2, arr, sizeof(arr));

    for (int i = 0; i < 5; i++) {
        printf("%d", arr2[i]);
    }
    printf("\n");
}

void test_memmove() {
    int arr[5] = {1, 2, 3, 4, 5};
    memmove(arr + 2, arr + 1, 3 * sizeof(int));
    // 内存移动，把 2,3,4 移动到 3,4,5
    // 1,2,3,4,5 ---> 1,2,2,3,4

    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
    }
}

void test_memcmp() {
    char str1[32] = "hello\0world";
    char str2[32] = "hello\0aaa";

    if (strcmp(str1, str2) == 0) { // 遇到 \0 结束
        printf("str1==str2 \n");
    } else {
        printf("str1!=str2 \n");
    }

    if (memcmp(str1, str2, sizeof(str1)) == 0) { // 遇到 \0 不会结束
        printf("str1==str2 \n");
    } else {
        printf("str1!=str2 \n");
    }

}

int main(int argc, char const *argv[]) {
    test_memset(); // memset 内存设置
    test_memcpy(); // memcpy 内存拷贝
    test_memmove(); // memmove 内存移动
    test_memcmp(); // memcpy 内存比较
}

