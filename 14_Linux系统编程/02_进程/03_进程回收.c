#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys/wait.h"

void test_wait() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork error");
        return;
    } else if (pid > 0) {
        printf("父进程:pid=[%d] ppid=[%d]\n", getpid(), getppid());
        // 等待子进程结束
        /**
         * pid_t wpid = wait(NULL);
         * printf("wpid = %d \n", wpid);
         *  wpid > 0:回收的子进程 pid
         *  wpid = -1:没有子进程
         */
        int status;
        pid_t wpid = wait(&status);
        printf("wpid = %d \n", wpid);
        if (WIFEXITED(status)) {
            printf("子进程正常退出 %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("子进程被信号杀死 %d\n", WTERMSIG(status));
        }

    } else if (pid == 0) {
        printf("子进程:pid [%d] ppid=[%d]\n", getpid(), getppid());
        sleep(5);
        // return 9;
    }
}


void test_waitpid() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork error");
        return;
    } else if (pid > 0) {
        int status;
        /** extern __pid_t waitpid (__pid_t __pid, int *__stat_loc, int __options);
         *  pid 参数：
         *      >0 ：等待指定 pid 子进程退出
         *      -1 : 等待任意子进程
         *  status：同 wait 函数
         *  options：
         *      0: 阻塞，不会产生僵尸进程，但是会阻塞父进程
         *      WNOHANG : 非阻塞，可能产生僵尸进程，可以通过 while 循环不断的 waitpid
         *
         *  返回值：
         *      >0:回收的子进程的 pid
         *      =0:若options 为 WNOHANG ，表示子进程还在运行
         *      -1：表示没有子进程了
         *  调用一次 waitpid 或者　wait 函数只能回收一个子进程
         */
        // pid_t wpid = waitpid(pid, &status, 0);
        pid_t wpid = waitpid(-1, &status, WNOHANG);
        printf("wpid = %d \n", wpid);
        if (wpid > 0) {
            if (WIFEXITED(status)) {
                printf("子进程正常退出 %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("子进程被信号杀死 %d\n", WTERMSIG(status));
            }
        } else if (wpid == 0) { // 子进程还在运行
            printf("子进程还在运行：%d \n", wpid);
        } else if (wpid == -1) {
            printf("没有子进程运行：%d \n", wpid);
        }

    } else if (pid < 0) {
        printf("子进程:pid [%d] ppid=[%d]\n", getpid(), getppid());
        sleep(5);
    }
}

int main(int argc, char const *argv[]) {
    test_waitpid();

    return 0;
}