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
    return 0;
}

int main(int argc, char const *argv[]) {
    // 创建子线程
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread, NULL);
    if (ret != 0) {
        printf("pthread create error [%s] \n", strerror(ret));
    }
    printf("main thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());

    // 设置线程为分离属性
    pthread_detach(thread);

    // 子线程设置分离属性，将不在阻塞
    ret = pthread_join(thread, NULL);
    if (ret != 0) {
        printf("pthread_join error:[%s] \n", strerror(ret)); // pthread_join error:[Invalid argument]
    }
    return 0;
}
