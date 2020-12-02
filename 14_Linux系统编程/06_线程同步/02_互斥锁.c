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

#define NUM 5000

int number = 0;

// 定义一把互斥锁
pthread_mutex_t mutex;

void *mythread(void *arg) {
    for (int i = 0; i < NUM; i++) {
        // 加锁
        pthread_mutex_lock(&mutex);
        number++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char const *argv[]) {
    // 初始化锁
    pthread_mutex_init(&mutex, NULL);


    pthread_t thread1;
    int ret1 = pthread_create(&thread1, NULL, mythread, NULL);
    if (ret1 != 0) {
        printf("pthread create error [%s] \n", strerror(ret1));
    }

    pthread_t thread2;
    int ret2 = pthread_create(&thread2, NULL, mythread, NULL);
    if (ret2 != 0) {
        printf("pthread create error [%s] \n", strerror(ret2));
    }


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("main [%d] \n", number);

    // 释放锁
    pthread_mutex_destroy(&mutex);
}

