#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/wait.h"
#include "sys/mman.h"

int main(int argc, char const *argv[]) {
    // 使用 mmap
    /**
     * void *mmap (void *__addr, size_t __len, int __prot,
		   int __flags, int __fd, __off_t __offset)
     */
    int fd = open("../test1.log", O_RDWR);
    if (fd < 0) {
        perror("open error");
        return -1;
    }

    int len = lseek(fd, 0, SEEK_END);

    // void *addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    void *addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0); // MAP_PRIVATE 不修改文件
    if (addr == MAP_FAILED) {
        perror("mmap error");
        return -1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork error");
        return -1;
    } else if (pid > 0) {
        memcpy(addr, "hello world", strlen("hello world"));
        wait(NULL);
    } else if (pid == 0) {
        sleep(1);
        char *p = (char *) addr;
        printf("%s", p);
    }
}