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
    int i = *(int *) arg;
    printf("child thread  pid=[%d] id =[%lu] i = [%d] \n", getpid(), pthread_self(), i);
    return 0;
}


int main(int argc, char const *argv[]) {
    // 循环创建子线程
    int n = 5;
    pthread_t thread[5];
    for (int i = 0; i < n; i++) {
        int ret = pthread_create(&thread[i], NULL, mythread, &i); // 传递参数
        if (ret != 0) {
            printf("pthread create error [%s] \n", strerror(ret));
        }
        sleep(1);
    }

    printf("main thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());

    // 让子线程执行起来
    sleep(1);
    return 0;


}

