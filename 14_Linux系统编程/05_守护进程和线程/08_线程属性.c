#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/time.h"
#include "time.h"
#include "signal.h"
#include "pthread.h"


void *mythread(void *arg) {
    printf("child thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());
    sleep(2);
    return 0;
}


int main(int argc, char const *argv[]) {
    // 创建分离属性的线程

    // 定义变量
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    // 设置分离属性
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_t thread;
    int ret = pthread_create(&thread, &attr, mythread, NULL);
    if (ret != 0) {
        printf("pthread create error [%s] \n", strerror(ret));
    }

    printf("main thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());
    // 释放线程属性
    pthread_attr_destroy(&attr);

    // 验证分离属性
    // 子线程设置分离属性，将不在阻塞
    ret = pthread_join(thread, NULL);
    if (ret != 0) {
        printf("pthread_join error:[%s] \n", strerror(ret)); // pthread_join error:[Invalid argument]
    }

}