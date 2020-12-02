#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "signal.h"


int main(int argc, char const *argv[]) {
    kill(getpid(), SIGKILL); // 杀死自己，给自己发送信号
    printf("hello world");
    return -1;
}