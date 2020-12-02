#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"

void test_excel() {
    // execl :子进程的代码段会被 ls 命名的代码段替换
    // 子进程的地址空间没有变化，子进程的 PID 页没有变化
    /**
     * path : 路径
     * arg ： 参数，参数写完之后添加 NULL
     */
    execl("/bin/ls", "ls", "-l", NULL);
    perror("execl error");
}

void test_excelp(const char *cmd, const char *arg) {
    // 自动搜索 PATH 环境变量，也可以指定路径
    // execlp("ls", "ls", "-l", NULL);
    execlp(cmd, cmd, arg, NULL);
    perror("execl error");
}


int main(int argc, char const *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n",argv[i]);
    }
    printf("------------------------");
    test_excelp(argv[1], argv[2]);
}

