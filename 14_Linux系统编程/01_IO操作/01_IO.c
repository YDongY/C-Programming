#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys//stat.h"
#include "fcntl.h"

int main(int argc, char const *argv[]) {
    // 打开文件，读取并创建
    int fd = open("../test.log", O_RDWR | O_CREAT, 0777); // mode & (~umask)
    if (fd < 0) {
        perror("open error");
        return -1;
    }

    // 写文件
    char buf[] = "hello world";
    // ssize_t write (int __fd, const void *__buf, size_t __n)
    write(fd, buf, strlen(buf));

    // 移动文件指针
    // lseek (int __fd, __off_t __offset, int __whence)
    lseek(fd, 0, SEEK_SET);

    // 读文件
    char buf2[1024];
    memset(buf2, 0, sizeof(buf2));
    // ssize_t read (int __fd, void *__buf, size_t __nbytes)
    int n = read(fd, buf2, sizeof(buf2));
    printf("n = [%d]，buf = [%s] \n", n, buf2);

    // 关闭
    // int close (int __fd)
    close(fd);

    return 0;
}

