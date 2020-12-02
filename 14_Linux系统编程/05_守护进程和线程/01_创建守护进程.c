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

void sighandler(int signo) {
    // 打开文件
    int fd = open("mydemon.log", O_RDWR | O_CREAT | O_APPEND, 0777);
    if (fd < 0) {
        return;
    }
    time_t t;
    time(&t);
    char *p = ctime(&t);

    // 时间写入文件
    write(fd, p, strlen(p));

    close(fd);
}


int main(int argc, char const *argv[]) {
    // 编写一个守护进程，每隔 2s 获取一次系统时间，写入文件

    // 父进程 fork 子进程
    pid_t pid = fork();
    if (pid < 0 || pid > 0) {
        exit(1);
    }

    // 子进程调用 setid
    setsid();

    // 改变当前目录
    chdir(".");

    // 改变文件掩码
    umask(0000);

    // 关闭文件描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // 主要逻辑
    struct sigaction act;
    act.sa_handler = sighandler; // 信号处理函数
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM, &act, NULL);

    struct itimerval tm;
    tm.it_interval.tv_sec = 2;
    tm.it_interval.tv_usec = 0;

    tm.it_value.tv_sec = 3;
    tm.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &tm, NULL);

    while (1) {
        sleep(1);
    }
}