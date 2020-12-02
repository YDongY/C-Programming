#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "dirent.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"

void test_dup() {
    // 打开文件
    int fd = open("../test.log", O_RDWR);
    if (fd < 0) {
        perror("open error");
        return;
    }
    // dup 函数复制 fd
    int newfd = dup(fd);
    printf("newfd:[%d],fd:[%d] \n", newfd, fd);

    write(fd, "hello world c", strlen("hello world c"));

    // 移动文件指针
    lseek(newfd, 0, SEEK_SET);

    char buf[64];
    memset(buf, 0, sizeof(buf));

    int n = read(newfd, buf, sizeof(buf));
    printf("n=%d,buf=%s \n", n, buf);

    // 关闭，需要关闭两个文件描述符，才能真正关闭文件
    close(fd);
    close(newfd);
}


void test_dup2() {
    // 打开文件
    int fd = open("../test1.log", O_RDWR | O_CREAT);
    if (fd < 0) {
        perror("open error");
        return;
    }
    int newfd = open("../test2.log", O_RDWR | O_CREAT);
    if (newfd < 0) {
        perror("open error");
        return;
    }
    // dup2 函数复制
    dup2(fd, newfd);
    printf("newfd:[%d],fd:[%d] \n", newfd, fd);

    write(newfd, "hello world c", strlen("hello world c"));

    // 移动文件指针
    lseek(newfd, 0, SEEK_SET);

    char buf[64];
    memset(buf, 0, sizeof(buf));

    int n = read(fd, buf, sizeof(buf));
    printf("n=%d,buf=%s \n", n, buf);

    // 关闭，需要关闭两个文件描述符，才能真正关闭文件
    close(newfd);
    close(fd);
}


void test_dup22() {
    // dup2 函数实现标准输出重定向操作
    int fd = open("../test3.log", O_RDWR | O_CREAT, 0755);
    if (fd < 0) {
        perror("open error");
        return;
    }

    // 标准输出到文件
    dup2(fd, STDOUT_FILENO);

    printf("hello");
}

int main(int argc, char const *argv[]) {
    // test_dup();
    // test_dup2();
    test_dup22();

    return 0;
}