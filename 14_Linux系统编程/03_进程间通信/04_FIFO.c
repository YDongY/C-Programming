#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys/stat.h"
#include "fcntl.h"

void test_fifo() {

    // 判断文件是否存在，存在返回 0
    int r = access("../myfifo", F_OK);
    if (r != 0) {
        // 创建 FIFO 文件
        int ret = mkfifo("../myfifo", 0777);
        if (ret < 0) {
            perror("mkfifo error");
            return;
        }
    }

    // 打开文件
    int fd = open("../myfifo", O_RDWR);
    if (fd < 0) {
        perror("open error");
        return;
    }
    // 写
    write(fd, "hello world", sizeof("hello world"));

    // 关闭文件
    close(fd);

}

void test_fifo2() {
    // 打开文件
    int fd = open("../myfifo", O_RDWR);
    if (fd < 0) {
        perror("open error");
        return;
    }
    // 读
    char buf[64];
    memset(buf, 0, sizeof(buf));
    int n = read(fd, buf, sizeof(buf));
    printf("read n=[%d] , buf=[%s] \n", n, buf);

    close(fd);

    // 关闭文件
    close(fd);
}

int main(int argc, char const *argv[]) {
    //test_fifo();
    //test_fifo2();
    return 0;
}

