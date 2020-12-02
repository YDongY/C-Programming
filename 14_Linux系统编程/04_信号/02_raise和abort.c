#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "signal.h"

void test_raise(){
    /**
     * 给当前进程发送指定信号，即自己给自己发
     */
    raise(SIGKILL);
    printf("hello world");
}

void test_abort(){
    /**
     * 给自己发送异常终止信号 6 SIGABRT ，并产生 core 文件
     */
    abort(); // abort() 等价于 kill(getpid(),SIGABRT);
    printf("hello world");
}

int main(int argc, char const *argv[]) {
    test_abort();
    return -1;
}
