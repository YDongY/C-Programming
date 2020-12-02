#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys/wait.h"
#include "fcntl.h"


int main(int argc, char const *argv[]) {
    /**
     * extern int pipe (int __pipedes[2])
     */
    int fd[2];
    // fd[0]:读　fd[1]:写
    memset(fd, 0, sizeof(fd));
    int ret = pipe(fd);
    if (ret < 0) {
        perror("pipe error");
        return -1;
    }
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork error");
        return -1;
    } else if (pid > 0) {
        // 关闭读
        close(fd[0]);
        write(fd[1], "hello world", strlen("hello world"));
        wait(NULL);
    } else if (pid == 0) {
        close(fd[1]);
        char buf[64];
        memset(buf, 0, sizeof(buf));
        // read 没有数据可读会阻塞
        int n = read(fd[0], buf, sizeof(buf));
        printf("read over n=[%d] buf=[%s]", n, buf);
    }
}