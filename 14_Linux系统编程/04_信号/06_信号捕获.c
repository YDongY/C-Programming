#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "signal.h"
#include "sys/time.h"

void sighandler(int signo) {
    printf("%d \n", signo);
    sleep(3);
}

int main(int argc, char const *argv[]) {
    /**
     * 当信号处理函数执行期间，若信号再次多次产生，则信号处理不会被打断，
     * 当信号函数处理完毕，之前产生的信号只会处理一次
     *
     */
    struct sigaction act;
    act.sa_handler = sighandler; // 信号处理函数
    sigemptyset(&act.sa_mask); // 阻塞信号
    sigaddset(&act.sa_mask, SIGQUIT); // 在信号处理函数处理期间阻塞　SIGQUIT 信号
    act.sa_flags = 0;

    // 捕获 Ctrl+c 信号
    sigaction(SIGINT, &act, NULL);

    signal(SIGQUIT, sighandler); // 信号处理函数，会被阻塞　【sigaddset(&act.sa_mask, SIGQUIT);】

    while (1) {
        sleep(1);
    }
    return 0;
}

