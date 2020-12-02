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
#include "semaphore.h"

typedef struct node {
    int data;
    struct node *next;

} NODE;

NODE *head = NULL;

// 信号量
sem_t sem_producer;
sem_t sem_consumer;


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

        // --------- 值为 0 阻塞 -------------
        sem_wait(&sem_producer);

        pNode->next = head;
        head = pNode;

        // ---------- 通知消费者 -------------
        sem_post(&sem_consumer);

        sleep(rand() % 3);
    }
}

void *consumer(void *arg) {
    NODE *pNode = NULL;
    while (1) {

        // ----------- 值为 0 阻塞 ------------
        sem_wait(&sem_consumer);

        printf("c: [%d] \n", head->data);
        pNode = head;
        head = head->next;

        // ------------- 通知 --------------
        sem_post(&sem_producer);

        free(pNode);
        pNode = NULL;
        sleep(rand() % 3);
    }
}

int main(int argc, char const *argv[]) {
    int ret;

    // 初始化
    sem_init(&sem_producer, 0, 5);
    sem_init(&sem_consumer, 0, 0);

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

    //释放
    sem_destroy(&sem_producer);
    sem_destroy(&sem_consumer);

    return 0;
}
