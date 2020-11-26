#include "string.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[]) {
    /** 字符串拷贝
     * char *strcpy (char *dest, const char *src)
     */

    char dest[100] = {0};
    char src[] = "hello world";
    strcpy(dest, src);
    printf("%s \n", dest);

    /** 拷贝 n 个字节,不会在字符串末尾加 \0
     * char *strncpy (char *dest,const char *src, size_t __n)
     */
    char dest2[50] = {0};
    char src2[] = "hello world";
    strncpy(dest2, src2, 50); // n > src 拷贝 src ,n < src 拷贝 n 个字节，不添加 \0
    printf("%s \n", dest2);

    /** 字符串拼接
     * char *strcat (char *__restrict __dest, const char *__restrict __src)
     */
    char dest3[10] = "dest";
    char src3[] = "src";
    strcat(dest3, src3);
    printf("%s \n", dest3); // destsr

    /** 字符串拼接前 n 个
     * char *strncat (char *__restrict __dest, const char *__restrict __src,size_t __n)
     */
    char dest4[10] = "dest";
    char src4[] = "src";
    strncat(dest4, src4, 2);
    printf("%s \n", dest4); // destsrc

    /** 比较两个字符串，相等返回 0 ,不相等返回
     * int strcmp (const char *__s1, const char *__s2)
     */
    printf("%d \n", strcmp("hello", "hello")); // 0
    printf("%d \n", strcmp("hell", "hello")); // -1
    printf("%d \n", strcmp("hello", "hell")); // 1

    /** 比较前 n 个字符
     * int strncmp (const char *__s1, const char *__s2, size_t __n)
     */
    printf("%d \n", strncmp("hello", "hello", 2)); // 0
    printf("%d \n", strncmp("hell", "hello", 2)); // 0
    printf("%d \n", strncmp("hello", "hell", 2)); // 0

    /** 格式化输出
     * int sprintf (char *__restrict __s,const char *__restrict __format, ...)
     */
    char buf[100];
    sprintf(buf, "%d%c%d=%d \n", 10, '+', 20, 10 + 20);
    printf("%s \n", buf); // 10+20=30

    /** 格式化输入
     * int sscanf (const char *__restrict __s,const char *__restrict __format, ...)
     */
    int a, b, c;
    char buf2[] = "10+20=30";
    sscanf(buf2, "%d+%d=%d", &a, &b, &c);
    printf("a=%d \n", a);
    printf("b=%d \n", b);
    printf("c=%d \n", c);

    /** 在字符串中查找字符位置，返回地址
     * char *strchr (const char *__s, int __c)
     */
    printf("%s \n", strchr("hello", 'e')); // ello
    printf("%s \n", strchr("hello", 'a')); // null

    /** 从右向左开始找，输出后面的内容
     * char *strrchr (const char *__s, int __c)
     */
    printf("%s \n", strrchr("hello", 'e')); // ello

    /** 在字符串中找子串第一次出现的位置，返回地址
     * char *strstr (const char *__haystack, const char *__needle)
     */
    printf("%s \n", strstr("hello", "el")); // ello

    /** 字符串切割，将拆分的字符用 \0 替换
     * char *strtok (char *__restrict __s, const char *__restrict __delim)
     */
    char str[80] = "www.baidu.com";

    /* 获取第一个子字符串 */
    char *token = strtok(str, ".");

    // char *token = strtok("www.baidu.com", "."); // 错误使用，参数一不能是常量

    printf("%s\n", token); // www

    /* 继续获取其他的子字符串 */
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "."); // 传递剩余的字符串
    }

    /**
     * 字符串转整数
     */
    char ss[] = "10";
    int num_ss = atoi(ss);
    printf("%d \n", num_ss);

    /**
     * 字符串转小数
     */
    char sss[] = "0.123";
    double num_sss = atof(sss);
    printf("%f \n", num_sss); //0.123000


    /**
     * 字符串转长整数
     */
    char ssss[] = "-10L";
    long num_ssss = atol(ssss);
    printf("%ld \n", num_ssss); // -10

}

