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

int number = 0;


//
pthread_rwlock_t rwlock;

void *thread_write(void *arg) {
    int i = *(int *) arg;

    int cur;

    while (1) {
        // 加写锁
        pthread_rwlock_wrlock(&rwlock);
        cur = number;
        cur++;
        number = cur;
        printf("[%d]-W [%d] \n", i, cur);
        // 释放锁
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}

void *thread_read(void *arg) {
    int i = *(int *) arg;

    int cur;

    while (1) {
        pthread_rwlock_rdlock(&rwlock);
        cur = number;
        printf("[%d]-R [%d] \n", i, cur);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}


int main(int argc, char const *argv[]) {

    // 读写锁初始化
    pthread_rwlock_init(&rwlock, NULL);

    // 创建子线程
    int n = 8;
    int i = 0;
    int arr[8];
    pthread_t thread[8];

    // 三个写线程
    for (i = 0; i < 3; i++) {
        arr[i] = i;
        pthread_create(&thread[i], NULL, thread_write, &arr[i]);
    }

    // 5 个读线程
    for (i = 3; i < 8; i++) {
        arr[i] = i;
        pthread_create(&thread[i], NULL, thread_read, &arr[i]);
    }


    // 回收子线程
    for (int j = 0; j < 8; j++) {
        pthread_join(thread[j], NULL);
    }


    // 释放锁
    pthread_rwlock_destroy(&rwlock);

    return 0;
}