#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strlen2(char str[]) {
    /**
     * 自定义 strlen 函数
     */
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int main(int argc, char const *argv[]) {
    // -------- scanf --------

    char str[100];
    /**
    scanf("%s", str); // 遇到空格和 \n 结束
    scanf("%[^\n]s", str); // 除去空格
    printf("%s", str);
    */
    // ------- gets():获取一个字符串，返回字符串首地址，gcc 异常 【不安全】--------

    // ------- fgets():获取一个字符串 【安全】-------
    char str2[100];
    // char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
    // 参数一：存储字符串空间地址
    // 参数二：描述空间大小
    // 参数三；读取字符串位置,stdin 标准输入
    // 空间足够会读取回车的 \n
    // printf("获取输入字符串：%s",fgets(str2,sizeof(str2),stdin));


    // --------- puts -----------
    char str3[] = "hello world C";
    int ret = puts(str3); // 成功：字符串长度，失败:-1，默认输出带上 \n
    printf("返回值：%d \n", ret);

    // ------- fputs() ----------
    int ret2 = fputs(str3, stdout); // 默认输出不带 \n
    printf("返回值：%d \n", ret2); // 1

    // ------- strlen()：获取字符串有效长度，不包含 \0 ，遇到 \0 结束---------
    printf("sizeof(str) = %lu\n", sizeof("hello world")); // 12
    printf("strlen(str) = %lu\n", strlen("hello world")); // 11
    printf("strlen(str) = %lu\n", strlen("hello\0world")); // 5

    printf("strlen2(str) = %d\n", strlen2("hello world")); // 11

    // ----------- 字符串拼接 -----------

    char s1[] = "hello";
    char s2[] = "world";
    char s3[100] = {0};

    int i = 0;
    while (s1[i] != '\0') {
        s3[i] = s1[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0') {
        s3[i + j] = s2[j];
        j++;
    }

    s3[i + j] = '\0'; // 手动添加 0

    printf("%s\n", s3);

}