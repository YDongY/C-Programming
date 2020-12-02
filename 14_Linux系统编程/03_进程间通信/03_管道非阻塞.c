#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys/wait.h"
#include "fcntl.h"


int main(int argc, char const *argv[]) {
    int fd[2];
    int r = pipe(fd);
    if (r < 0) {
        perror("pipe error");
        return -1;
    }

    // 设置管道读端非阻塞
    int flag = fcntl(fd[0], F_GETFL); // 获取文件标识符 flag 属性
    flag = flag | O_NONBLOCK;
    fcntl(fd[0], F_SETFL, flag);// 设置　flag 属性非阻塞

    char buf[64];
    memset(buf, 0, sizeof(buf));
    int n = read(fd[0], buf, sizeof(buf));
    // n = -1 没有数据可读
    printf("read: n=[%d] buf=[%s]", n, buf); // n=-1

}
