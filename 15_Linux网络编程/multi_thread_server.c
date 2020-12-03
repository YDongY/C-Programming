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
#define MAXLINE 8192

struct s_info {
    struct sockaddr_in client_addr;
    int connfd;
};

int Socket(int domain, int type, int protocol) {
    /**
     * 成功返回 fd 失败 -1
     */
    int fd;
    fd = socket(domain, type, protocol);
    if (fd == -1) {
        perror("socket error");
        exit(-1);
    }
    return fd;
}

int Bind(int fd, const struct sockaddr *addr, socklen_t len) {
    /**
     * 成功返回 0 失败 -1
     */
    int ret = bind(fd, addr, len);
    if (ret == -1) {
        perror("bind error");
        exit(-1);
    }
    return ret;
}

int Listen(int fd, int n) {
    /**
     * 成功返回 0 失败 -1
     */
    int ret = listen(fd, n);
    if (ret == -1) {
        perror("listen error");
        exit(-1);
    }
    return ret;
}

int Accept(int fd, struct sockaddr *addr, socklen_t *addr_len) {
    int c_fd;
    again:
    if ((c_fd = accept(fd, addr, addr_len)) < 0) {
        if ((errno == ECONNABORTED) || (errno == EINTR)) { // 拦截信号
            goto again;
        } else {
            perror("accept error");
            exit(-1);
        }

    }
    return c_fd;
}

ssize_t Read(int fd, void *buf, size_t nbytes) {
    ssize_t n;
    again:
    if ((n = read(fd, buf, nbytes)) == -1) {
        if (errno == EINTR)
            goto again;
        else
            return -1;
    }
    return n;
}

ssize_t Write(int fd, const void *buf, size_t n) {
    ssize_t i;
    again:
    if ((i = write(fd, buf, n)) == -1) {
        if (errno == EINTR)
            goto again;
        else
            return -1;
    }
    return i;
}

// -------------------------------------------------------------------------------------------//
void *handler(void *arg) {
    struct s_info *ts = (struct s_info *) arg;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int ret;
    while (1) {
        ret = Read(ts->connfd, buf, MAXLINE); // 封装 read
        if (ret == 0) {
            close(ts->connfd); // 关闭cfd
            break;
        }
        printf("received from [%s]-[%d] \n", inet_ntop(AF_INET, &(*ts).client_addr.sin_addr, str, sizeof(str)),
               ntohs((*ts).client_addr.sin_port));

        for (int i = 0; i < ret; i++) {
            buf[i] = toupper(buf[i]);
        }
        Write(STDOUT_FILENO, buf, ret);
        Write(ts->connfd, buf, ret);

    }

    return (void *) 0;
}

int main(int argc, char const *argv[]) {

    struct sockaddr_in serv_addr, client_addr;
    int lfd, cfd;
    pthread_t thread;
    socklen_t client_addr_len;

    struct s_info ts[256];
    int i = 0;

    // memset(&serv_addr, 0, sizeof(serv_addr));
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // 创建套接字
    lfd = Socket(AF_INET, SOCK_STREAM, 0);
    // 绑定
    Bind(lfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    // 限制同时监听数量
    Listen(lfd, 128);

    printf("Accept client connect ...... \n");


    while (1) {
        client_addr_len = sizeof(client_addr);
        // 等待连接
        cfd = Accept(lfd, (struct sockaddr *) &client_addr, &client_addr_len);
        ts[i].client_addr = client_addr;
        ts[i].connfd = cfd;
        pthread_create(&thread, NULL, handler, (void *) &ts[i]);
        // 设置线程为分离属性
        pthread_detach(thread); // 子线程分离，防止僵尸线程
        i++;
    }
    return 0;
}