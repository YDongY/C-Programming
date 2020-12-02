#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "signal.h"

void sighandler(int signo) {
    printf("%d \n", signo);
}

void test() {
    /**
     * extern unsigned int alarm (unsigned int __seconds)
     * 每个进程只有一个时钟
     *
     * 返回值：0 或者上一个 alarm剩余的秒数
     * alarm(0):取消定时器
     * alarm 函数发送的是 14 号　SIGALRM　信号
     */
    // 注册信号函数
    signal(SIGALRM, sighandler);

    //
    unsigned int r = alarm(5);
    printf("%d \n", r);
    sleep(2);
    r = alarm(2);
    printf("%d \n", r);

    r = alarm(0); // 取消时钟
    printf("%d \n", r);
    sleep(10);
}

void test02() {
    // 测试一秒数数
    alarm(1);
    int i = 0;
    while (1) {
        printf("%d \n", i++);
    }
    return;
}

int main(int argc, char const *argv[]) {
    test02();
    return -1;
}
