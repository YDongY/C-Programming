#include <stdio.h>
#include "string.h"

struct Hero{
    char name[64];
    int atk;
    int def;
};

void f_printf(){
    /**
     * int fprintf (FILE *__restrict __stream,const char *__restrict __format, ...)
     * 返回值：
     * 成功：成功写入的字符数，本案例中，一个中文占 3 个字节
     */
    // 格式化写文件
    struct Hero arr[5]={
            {"刘备",1000,1000},
            {"关羽",1800,1200},
            {"张飞",1600,1500},
            {"吕布",2000,2000},
            {"曹操",1300,1100}
    };

    FILE * fp = fopen("../test3.txt","w");
    if(fp==NULL){
        return;
    }

    int len = sizeof(arr) / sizeof(struct Hero);

    for(int i=0;i<len;i++){
        int l = fprintf(fp,"%s-%d-%d\n",arr[i].name,arr[i].atk,arr[i].def);
         printf("%d \n",l); // 17
    }

    fclose(fp);

}

void f_scanf(){
    // 格式化读文件
    FILE * fp = fopen("../test3.txt","r");
    if(fp==NULL){
        return;
    }

    struct Hero arr[5];
    memset(arr,0,sizeof(arr));

    int i = 0;
    while (!feof(fp)){
        fscanf(fp,"%s-%d-%d\n",arr[i].name,&arr[i].atk,&arr[i].def);
        i++;
    }
    int len = sizeof(arr) / sizeof(struct Hero);
    for(int j=0;j<len;j++){
        printf("%s-%d-%d\n",arr[j].name,arr[j].atk,arr[j].def);
    }

    fclose(fp);

}

int main(int argc, char const *argv[]) {
    f_printf();
    f_scanf();
    return 0;
}