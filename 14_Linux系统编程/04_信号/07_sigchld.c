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
    struct sigaction act;
    act.sa_handler = sighandler;
    sigemptyset(&act.sa_mask);

}
