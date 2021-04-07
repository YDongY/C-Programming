#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void test01(){
    char buf[1024];
    memset(buf,0,sizeof(buf));
    sprintf(buf,"%d-%d-%d",2020,11,29);
    printf("%s \n",buf);

    // 拼接字符串
    memset(buf,0,sizeof(buf));
    char buf22[] ="hello";
    char buf222[] ="world";
    sprintf(buf,"%s %s",buf22,buf222);
    printf("%s \n",buf);

    // 数字转字符串
    memset(buf,0,sizeof(buf));
    int num = 100;
    sprintf(buf,"%d",num);
    printf("%s\n",buf);

    // 右对齐
    memset(buf,0,sizeof(buf));
    sprintf(buf,"%8d",num); // 宽度 8 ，数字右对齐
    printf("%s\n",buf);

    // 左对齐
    memset(buf,0,sizeof(buf));
    sprintf(buf,"%-8d",num); // 宽度 8 ，数字左对齐
    printf("%s\n",buf);

    // 转16进制
    memset(buf,0,sizeof(buf));
    sprintf(buf,"%x",num); // 64
    printf("%s\n",buf);

    // 转 8 进制
    memset(buf,0,sizeof(buf));
    sprintf(buf,"%o",num); // 144
    printf("%s\n",buf);
}

void test02(){
    // sscanf

    // %*s %*d 跳过数据

    char *str = "12345hello";
    char buf[1024]={0};
    sscanf(str,"%*d%s",buf);
    printf("%s \n",buf); // hello

    // 忽略指定字符
    char *str2 = "hello12345";
    char buf2[1024]={0};
    sscanf(str2,"%*[a-z]%s",buf2);
    printf("%s \n",buf2); // 12345

    // %[width]s 读取指定宽度
    char *str3 = "hello12345";
    char buf3[1024]={0};
    sscanf(str3,"%6s",buf3);
    printf("%s \n",buf3); // hello1

    // %[aBc]s 匹配 a B c，匹配任意一个
    char *str4 = "Hello12345";
    char buf4[1024]={0};
    int r = sscanf(str4,"%[H]s",buf4);
    printf("%d \n",r); // 1
    printf("%s \n",buf4); // H

    // %[^a] 匹配非a


}

int main(int argc,char const *argv[]){
    test02();
}