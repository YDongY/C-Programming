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
    int lfd, cfd;
    int ret;
    char buf[BUFSIZ], client_ip[BUFSIZ];


    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_addr_len;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1) {
        perror("socket error");
        exit(-1);
    }

    bind(lfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    listen(lfd, 128);

    client_addr_len = sizeof(client_addr);

    cfd = accept(lfd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (cfd == -1) {
        perror("accept error");
        exit(-1);
    }

    printf("client: [%s] [%d] \n",
           inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, client_ip, sizeof(client_ip)),
           ntohs(client_addr.sin_port));

    while (1) {
        memset(&buf, 0, sizeof(buf));
        ret = read(cfd, buf, sizeof(buf));
        if (ret == -1) {
            perror("read error");
            exit(-1);
        }

        if (ret == 0) {
            break;
        }

        write(STDOUT_FILENO, buf, ret);
        for (int i = 0; i < ret; i++) {
            buf[i] = toupper(buf[i]);
        }

        write(cfd, buf, ret);
    }

    close(lfd);
    close(cfd);

    return 0;

}