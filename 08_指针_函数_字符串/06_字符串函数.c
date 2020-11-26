#include "stdio.h"
#include "string.h"

int substr_times(char *str, const char *substr);

void reverse(char *str);

int isPalindrome(char *str);

int main(int argc, char const *argv[]) {
    // ----- strstr：首次匹配的字符串
    char *ret = strstr("helloHello", "llo");
    printf("%s \n", ret); // lloHello

    char *ret2 = strstr("helloHello", "abc");
    printf("%s \n", ret2); // null

    // ----- 子串出现次数
    char str[] = "hellollollo";
    char substr[] = "llo";
    printf("%d \n", substr_times(str, substr));

    // ----- 字符串反转
    char s[] = "hello";
    printf("%s \n", s);
    reverse(s);
    printf("%s \n", s);

    // ----- 判断字符串回文
    char s2[] = "abcba";
    printf("%d \n", isPalindrome(s2)); // 1
    printf("%d \n", isPalindrome("hello")); // 0
}

int substr_times(char *str, const char *substr) {

    char *p = strstr(str, substr);
    int count = 0;
    while (p != NULL) {
        count++;
        p += strlen(substr);
        p = strstr(p, substr);
    }
    return count;
}

void reverse(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (start < end) {
        if (*start != *end) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}