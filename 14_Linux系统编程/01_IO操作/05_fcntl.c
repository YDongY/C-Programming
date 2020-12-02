#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "dirent.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"

void test_fcntl_dupfd() {
    // 打开文件
    int fd = open("../test1.log", O_RDWR | O_CREAT);
    if (fd < 0) {
        perror("open error");
        return;
    }
    // ---------- fcntl 函数复制 -----------------
    int newfd = fcntl(fd, F_DUPFD, 0);
    printf("newfd:[%d],fd:[%d] \n", newfd, fd);

    write(newfd, "hello world c", strlen("hello world c"));

    lseek(newfd, 0, SEEK_SET);

    char buf[64];
    memset(buf, 0, sizeof(buf));

    int n = read(fd, buf, sizeof(buf));
    printf("n=%d,buf=%s \n", n, buf);

    close(newfd);
    close(fd);
}

void test_fcntl() {
    int fd = open("../test1.log", O_RDWR);
    if (fd < 0) {
        perror("open error");
        return;
    }

    // 获取 fd 的 flag 属性
    int flags = fcntl(fd, F_GETFL, 0);

    // 追加属性
    flags = flags | O_APPEND;

    // 设置
    fcntl(fd, F_SETFL, flags);

    write(fd, "hello world c", strlen("hello world c"));

    close(fd);
}

int main(int argc, char const *argv[]) {
    // test_fcntl_dupfd(); // 文件描述符复制
    test_fcntl(); // 文件描述符 flag
}

