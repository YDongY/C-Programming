#include "stdio.h"
#include "ctype.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"
#include "pthread.h"

#define SERV_PORT 9527

int main(int argc, char const *argv[]) {
    int cfd;
    int count = 10;
    char buf[BUFSIZ];

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr.s_addr);

    cfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cfd == -1) {
        perror("socket error");
        exit(-1);
    }

    int ret = connect(cfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (ret != 0) {
        perror("connect error");
        exit(-1);
    }

    while (--count) {
        write(cfd, "hello\n", 6);
        ret = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
        sleep(1);
    }
    close(cfd);

    return 0;
}