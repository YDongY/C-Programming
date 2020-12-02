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

struct Test {
    int data;
    char name[32];
};

void *mythread(void *arg) {
    // int n = *(int *) arg;
    // printf("arg = [%d] \n", n);
    struct Test *p = (struct Test *) arg;

    printf("data = [%d] name = [%s]\n", p->data, p->name);
    printf("child thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());
    return 0;
}

int main(int argc, char const *argv[]) {
    /**
     * extern int pthread_create (pthread_t *__restrict __newthread,
			   const pthread_attr_t *__restrict __attr,
			   void *(*__start_routine) (void *),
			   void *__restrict __arg) __THROWNL __nonnull ((1, 3));
     */

    // 基本类型参数参数
    int n = 99;
    // 结构体参数
    struct Test t = {20, "jack"};

    // 创建子线程
    pthread_t thread;
    // int ret = pthread_create(&thread, NULL, mythread, NULL);
    int ret = pthread_create(&thread, NULL, mythread, &t); // 传递参数
    if (ret != 0) {
        printf("pthread create error [%s] \n", strerror(ret));
    }
    printf("main thread  pid=[%d] id =[%lu] \n", getpid(), pthread_self());

    // 让子线程执行起来
    sleep(2);
    return 0;


    /**
     * 编译：gcc 02_线程.c -lpthread
     */
}

