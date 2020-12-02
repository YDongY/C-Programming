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
    while (1) {

        int a;
        int b;
        // printf("child thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());
        // pthread_testcancel(); // 设置取消点
    }

    return 0;
}

int main(int argc, char const *argv[]) {
    // 创建子线程
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread, NULL);
    if (ret != 0) {
        printf("pthread create error [%s] \n", strerror(ret));
    }


    // 取消线程,不是实时的，需要设置取消点，能够进入内核的都有取消点，所以 printf 不要用
    pthread_cancel(thread);

    while (1) {
        printf("main thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());
        sleep(2);
    }

    return 0;
}
