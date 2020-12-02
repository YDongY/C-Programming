#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"


int main(int argc, char const *argv[]) {
    // fork
    // extern __pid_t fork (void)
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork error");
        return -1;
    } else if (pid > 0) { // fork 会返回两个值，一个值(子进程id)由父进程返回，另一个值(0)由子进程返回
        printf("父进程：pid = [%d] ppid = [%d]\n", getpid(), getppid());
        // sleep(1);
    } else if (pid == 0) {
        printf("子进程：pid = [%d] ppid = [%d] \n", getpid(), getppid());
    }
    printf("exit [%d]\n", getpid());

}