#include <stdio.h>
#include "string.h"

struct Hero{
    char name[64];
    int atk;
    int def;
};

void f_write(){

    /**
     * size_t fwrite (const void *__restrict __ptr, size_t __size,
		      size_t __n, FILE *__restrict __s)
     */

    FILE * fp = fopen("../test4.txt","w");
    if(fp==NULL){
        return;
    }

    struct Hero arr[5]={
            {"刘备",1000,1000},
            {"关羽",1800,1200},
            {"张飞",1600,1500},
            {"吕布",2000,2000},
            {"曹操",1300,1100}
    };

    int len = sizeof(arr) / sizeof(struct Hero);

    for (int i=0;i<len;i++){
        // 参数:数据地址 块大小 块个数 文件指针
        fwrite(&arr[i],sizeof(struct Hero),1,fp); // 直接写入结构体
    }

    fclose(fp);
}

void f_read(){
    FILE * fp = fopen("../test4.txt","r");
    if(fp==NULL){
        return;
    }

    struct Hero arr[5];
    memset(arr,0,sizeof(arr));

    int len = sizeof(arr) / sizeof(struct Hero);
#if 0
    for (int i=0;i<len;i++){
        // 参数:数据地址 块大小 块个数 文件指针
        fread(&arr[i],sizeof(struct Hero),1,fp); // 直接读出结构体
    }
#else
    fread(arr,sizeof(struct Hero),len,fp); // 一次性读取
#endif
    for(int j=0;j<len;j++){
        printf("%s-%d-%d\n",arr[j].name,arr[j].atk,arr[j].def);
    }

    fclose(fp);
}

int main(int argc, char const *argv[]) {
    f_write();
    f_read();
}