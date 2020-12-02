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
        // 标准输出重定向写端
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
        perror("execlp error");
    } else if (pid == 0) {
        // 关闭写
        close(fd[1]);
        // 标准输入重定向读端
        dup2(fd[0], STDIN_FILENO);
        execlp("grep", "grep", "--color=auto", "zsh", NULL);
        perror("execlp error");
    }
}
