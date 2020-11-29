#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void test01(){
    // 字符串结束标志 \0
    char str1[] = {'h','e','l','l','o','\0'};
    printf("%s \n",str1);
    printf("sizeof = %lu \n",sizeof(str1)); // 6
    printf("strlen = %lu \n",strlen(str1)); // 5

    // 字符数组剩余补 0
    char str2[20] = {'h','e','l','l','o'};
    printf("%s \n",str2);
    printf("sizeof = %lu \n",sizeof(str2)); // 20
    printf("strlen = %lu \n",strlen(str2)); // 5

    // 字符串初始化，编辑器默认补 \0
    char str3[] = "hello";
    printf("%s \n",str3);
    printf("sizeof = %lu \n",sizeof(str3)); // 6
    printf("strlen = %lu \n",strlen(str3)); // 5


    char str4[] = "hello\0world";
    printf("%s \n",str4);  // hello
    printf("sizeof = %lu \n",sizeof(str4)); // 12
    printf("strlen = %lu \n",strlen(str4)); // 5

    char str5[] = "hello\012world";
    // 转义字符：
    // - \012 是八进制，ASCII 表示换行
    // - \x41 是十六进制
    printf("%s \n",str5);  // hello \n world
    printf("sizeof = %lu \n",sizeof(str5)); // 12
    printf("strlen = %lu \n",strlen(str5)); // 11
}

void test02(){
    char *str = "hello world";
    char buf[1024];

    // 字符串拷贝

    // 方式一
    for(int i=0;i<strlen(str);i++){
        buf[i] = str[i];
    }
    buf[strlen(str)]='\0';
    printf("%s\n",buf);

    // 方式二
    char buf2[1024];
    char *p = buf2; // 用一个指针临时接收
    while (*str!='\0'){
        *p = *str;
        str++;
        p++;
    }
    *p = '\0';
    printf("%s\n",buf2);
}

void test03(){
    char str[] = "abcdefg";

    // 字符串反转
#if 0
    int start =0;
    unsigned long end = strlen(str)-1;
    while (start<end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    printf("%s \n",str);
#else
    // 方式二
    unsigned  long len = strlen(str);
    char *start = str;
    char *end = str+len-1;
    while (start<end){
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("%s \n",str);
#endif
}

int main(int argc,char const *argv[]){
    // test01();
    // test02();
    test03();
}

