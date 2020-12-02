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

typedef struct node {
    int data;
    struct node *next;

} NODE;

NODE *head = NULL;

// 定义一把锁
pthread_mutex_t mutex;

// 定义条件变量
pthread_cond_t cond;



// 生产者
void *producer(void *arg) {
    NODE *pNode = NULL;
    while (1) {
        pNode = (NODE *) malloc(sizeof(NODE));
        if (pNode == NULL) {
            perror("malloc error");
            exit(-1);
        }

        pNode->data = rand() % 1000;
        printf("p: [%d] \n", pNode->data);

        // 加锁
        pthread_mutex_lock(&mutex);

        pNode->next = head;
        head = pNode;


        // 解锁
        pthread_mutex_unlock(&mutex);

        // 通知
        pthread_cond_signal(&cond);

        sleep(rand() % 3);
    }
}

void *consumer(void *arg) {
    NODE *pNode = NULL;
    while (1) {
        // 加锁
        pthread_mutex_lock(&mutex);

        if (head == NULL) {
            // 阻塞等待
            // 若条件不满足，阻塞等待，并解锁
            // 若条件满足（被生产者线程调用pthread_cond_signal函数唤醒），解除阻塞并加锁
            pthread_cond_wait(&cond, &mutex);
        }

        if (head == NULL) {
            pthread_mutex_unlock(&mutex);
            continue;
        }

        printf("c: [%d] \n", head->data);
        pNode = head;
        head = head->next;

        // 解锁
        pthread_mutex_unlock(&mutex);

        free(pNode);
        pNode = NULL;
        sleep(rand() % 3);
    }
}

int main(int argc, char const *argv[]) {
    int ret;

    // 初始化互斥锁
    pthread_mutex_init(&mutex, NULL);
    // 初始化条件变量
    pthread_cond_init(&cond, NULL);

    pthread_t thread1;
    pthread_t thread2;
    ret = pthread_create(&thread1, NULL, producer, NULL);
    if (ret != 0) {
        printf("pthread producer error %s \n", strerror(ret));
        return -1;
    }

    ret = pthread_create(&thread2, NULL, consumer, NULL);
    if (ret != 0) {
        printf("pthread producer error %s \n", strerror(ret));
        return -1;
    }

    // 等待子线程结束
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 释放
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
