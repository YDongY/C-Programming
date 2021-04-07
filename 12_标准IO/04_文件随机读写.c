#include <stdio.h>
#include "string.h"
#include "stdlib.h"

void f_seek(){
    /** 移动文件流的读写位置
     * int fseek (FILE *__stream, long int __off, int __whence)
     *  whence:
     *      SEEK_SET:从文件头移动 offset 个字节
     *      SEEK_CUR:从当前位置移动 offset 个字节
     *      SEEK_END:从文件末尾移动 offset 个字节
     *  返回值：
     *      成功：0
     *      失败：-1
     */
    FILE * fp = fopen("../test5.txt","w+");
    if(fp==NULL){
        return;
    }
    fputs("hello world",fp);

    // 写入完成，想要再次读取，此时文件指针移动移动到文件末尾，有两种方式解决：
#if 0
    // 1. 关闭文件指针，重新打开读文件指针
    fclose(fp);
    fp = fopen("../test5.txt","r");
#else
    // 2. 移动文件指针位置到文件头
    fseek(fp,0,SEEK_SET);
    // rewind(fp); 将文件光标置首
#endif
    char buf[32];
    fgets(buf,sizeof(buf),fp);
    printf("%s \n",buf);

    fclose(fp);
}

void f_tell(){
    /** 获取文件流读写位置
     * long int ftell (FILE *__stream)
     * 返回值：
     *  成功：返回光标位置
     *  失败：-1
     */
    FILE * fp = fopen("../test5.txt","r");
    if(fp==NULL){
        return;
    }
    fseek(fp,0,SEEK_END); // 移动光标到末尾
    long ret = ftell(fp); // 获取光标位置
    printf("%ld \n",ret); // 11，等于字符串长度

    // 把数据放在堆区数组
    char *p = malloc(ret+1);

    // 清空内存
    memset(p,0,ret+1);
    // 重置光标到文件首
    rewind(fp);

    // 按块读
    fread(p,ret,1,fp);

    printf("%s \n",p);

    // 释放数组
    if(p!=NULL){
        free(p);
        p=NULL;
    }

    fclose(fp);
}

int main(int argc, char const *argv[]) {
    f_seek();
    f_tell();
}

