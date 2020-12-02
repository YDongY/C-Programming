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

int g_val = 9;

void *mythread(void *arg) {

    printf("child thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());
    pthread_exit(&g_val); // 子线程退出
    printf("====");
}

int main(int argc, char const *argv[]) {
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread, NULL);
    if (ret != 0) {
        printf("pthread create error [%s] \n", strerror(ret));
    }
    printf("main thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());

    // pthread_exit(NULL); 主线程调用，会称为僵尸线程

    // 阻塞等待，回收子线程
    void *p;
    pthread_join(thread, &p);
    int n = *(int *) p;
    printf("p = [%d] \n", n);
    return 0;
}

