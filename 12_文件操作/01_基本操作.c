#include <stdio.h>
#include "string.h"

void write(){
    /** 打开文件
     *  FILE *fopen (const char *__restrict __filename,const char *__restrict __modes)
     */
    FILE *fp = fopen("../test2.txt","wb"); // Linux r 和 rb 效果相同

    // 写文件：磁盘已满，返回空指针
    // 读文件：文件不存在，返回空文件
    if (fp==NULL){
        printf("文件打开失败");
        return;
    }
    // Linux 与 Windows 换行符区别：Linux -> \n ,Windows -> \r\n
    // printf("%p \n",fp); // 0xf70260

    /** 按照字符写文件
    * int fputc (int __c, FILE *__stream);
    */
    char buf[] = "hello world\n";
    int i = 0;
    while (buf[i]!='\0'){
        int ret = fputc(buf[i],fp);
        printf("%d ",ret);
        i++;
    }
    /** 关闭文件
    *  int fclose (FILE *__stream)
    *  成功：0
    *  失败：-1
    */
    // printf("%d",fclose(fp)); // 0
    fclose(fp);
}

void read(){
    FILE *fp = fopen("../test2.txt","r"); // Linux r 和 rb 效果相同

    if(fp==NULL){
        printf("文件打开失败");
        return;
    }

    /** 按照字符读文件
    * int fgetc (FILE *__stream);
    */
    // 读取到文件尾标识 EOF，EOF 就是 -1
    int ch;
    while((ch = fgetc(fp))!=EOF){
        printf("%c",ch);
    }
    fclose(fp);
}

void writeline(){
    // 按行写
    FILE *fp = fopen("../test3.txt","w");
    if (fp==NULL){
        printf("文件打开失败");
        return;
    }

    char *buf[]={"hello\n","world\n","c/c++\n"};

    int len = sizeof(buf) / sizeof(char *);
    for(int i=0;i<len;i++){
        fputs(buf[i],fp);
    }

    fclose(fp);

}

void readline(){
    // 按行读
    FILE *fp = fopen("../test3.txt","r");
    if (fp==NULL){
        printf("文件打开失败");
        return;
    }
    // 文件尾判断
    /**
     * int feof (FILE *__stream)
     * 非 0 值：已经读到文件尾
     * 0 ：没有读到文件为
     */
    char buf[1024]={0};
#if 0
    while (!feof(fp)){
        char *ret = fgets(buf,sizeof(buf)-1,fp);
        if(ret==NULL){
            break;
        }
        // 把 \n 换成 \0;
        buf[strlen(buf)-1]= '\0';
        printf("%s \n",buf);
    }
#else
    // 优化
    while (fgets(buf,sizeof(buf)-1,fp)){
        buf[strlen(buf)-1]= '\0';
        printf("%s \n",buf);
    }
#endif

    fclose(fp);
}

int main(int argc, char const *argv[]) {
    write();
    read();
    writeline();
    readline();
    return 0;
}