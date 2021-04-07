#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void test_calloc(){
    /** 分配 nmemb 块 size 大小的连续空间，并且重置为 0
     * void *calloc(size_t nmemb, size_t size);
     *  - 成功：分配空间起始地址
     *  - 失败：NULL
     */
    // int *p = malloc(sizeof(int)*10);

    int *p2 = calloc(10,sizeof(int)); // 分配 10 块 int 大小的内存，并且重置为 0

    for(int i=0;i<10;i++){
        printf("%d ",p2[i]);
    }
    if(p2!=NULL){
        free(p2);
        p2=NULL;
    }
}

void test_realloc(){
    /** 重新分配内存，即将 ptr 指向的内存块大小更改为 size 字节
     * void *realloc(void *ptr, size_t size);
     *
     *  小空间 -----> 大空间
     *  realloc 会先在原有空间后序查找空闲空间，如果足够，那么直接在后续申请，即：空间首地址不变
     *  如果后续空间不足，会重新找到一块内存，首先会将原内存中的数据拷贝新空间下，释放旧空间，然后返回新空间首地址。但是不会初始化新空间
     *
     *  大空间 -----> 小空间
     *  直接释放后序空间
     *
     *  realloc(Null,sizeof(int)*10) <==> malloc(sizeof(int)*10)
     *  realloc(p,0) <==> free(p)
     *
     */
     int *p = malloc(sizeof(int)*10);
    p = realloc(p,sizeof(int)*20);
}

int main(int argc,char const *argv[]){
    test_calloc();
}
