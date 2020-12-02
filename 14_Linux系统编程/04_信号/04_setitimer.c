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
    printf("%d \n", signo); // 14
}

int main(int argc, char const *argv[]) {
    /**
     * extern int setitimer (__itimer_which_t __which,
		      const struct itimerval *__restrict __new,
		      struct itimerval *__restrict __old)
     */

    // 注册信号
    signal(SIGALRM, sighandler);
    struct itimerval tm;
    // 周期性时间，1 秒产生一个信号
    tm.it_interval.tv_sec = 1;
    tm.it_interval.tv_usec = 0;

    // 第一次触发的时间
    tm.it_value.tv_sec = 3;
    tm.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &tm, NULL);

    while (1) {
        sleep(1);
    }
    return 0;
}

