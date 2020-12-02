#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "signal.h"
#include "sys/time.h"

void test() {
    // 定义信号集变量
    sigset_t set;

    // 初始化信号集
    sigemptyset(&set);

    // 将信号加入到信号集
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);

    // 将 set 集合中的信号加入到阻塞信号集
    sigprocmask(SIG_BLOCK, &set, NULL);


    sigset_t pend;
    while (1) {
        // 获的未决信号集
        sigemptyset(&pend);
        sigpending(&pend);

        //判断信号是否存在
        for (int i = 1; i < 32; i++) {
            if (sigismember(&pend, i) == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
        sleep(1);
    }
}


int main(int argc, char const *argv[]) {
    /**
     * 清空信号集，即所有位置为 0
     * extern int sigemptyset(sigset_t *__set);
     */

    /** 将集合中所有的位设置为 1
     * extern int sigfillset(sigset_t *__set);
     */

    /** 添加信号
     * extern int sigaddset(sigset_t *__set, int __signo);
     */

    /** 移除某个信号
     * extern int sigdelset(sigset_t *__set, int __signo);
     */

    /** 判断信号是否在集合中
     *  返回值：
     *      1 存在
     *      0 不存在
     * extern int sigismember(const sigset_t *__set, int __signo);
     */

    /** 阻塞和解阻塞信号
     *      how：
     *          - SIG_BLOCK ：阻塞，mask = mask | set
     *          - SIG_UNBLOCK ：解阻塞，mask = mask & ~set
     *          - SIG_SETMASK：
     *     set：信号集合
     *
    extern int sigprocmask (int __how, const sigset_t *__restrict __set,
                          sigset_t *__restrict __oset) __THROW;
     */

    /** 获取未决信号集
     * extern int sigpending (sigset_t *__set) __THROW __nonnull ((1));
     */


    test();

}

