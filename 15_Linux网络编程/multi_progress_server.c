#include "stdio.h"
#include "ctype.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"
#include "pthread.h"
#include "wait.h"
#include "signal.h"

#define SERV_PORT 9527

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

// -------------------------------------------------------------------------------------------//
void handler(int cfd) {
    char buf[BUFSIZ];
    int ret;
    for (;;) {
        memset(&buf, 0, sizeof(buf));
        ret = read(cfd, buf, sizeof(buf));
        if (ret == 0) {
            close(cfd);
            exit(1);
        }
        write(STDOUT_FILENO, buf, ret);
        for (int i = 0; i < ret; i++) {
            buf[i] = toupper(buf[i]);
        }
        write(cfd, buf, ret);
        write(STDOUT_FILENO, buf, ret);
    }
}

void catch_child(int signum) {
    while (waitpid(0, NULL, WNOHANG) > 0);
}


int main(int argc, char const *argv[]) {
    int lfd, cfd;
    pid_t pid;

    char client_ip[BUFSIZ];

    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_addr_len;
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

    client_addr_len = sizeof(client_addr);
    while (1) {
        // 等待连接
        cfd = Accept(lfd, (struct sockaddr *) &client_addr, &client_addr_len);
        pid = fork(); // 创建子进程
        if (pid < 0) {
            perror("fork error");
            exit(-1);
        } else if (pid == 0) {
            close(lfd);
            handler(cfd); // 处理函数
            break;
        } else {
            struct sigaction act;
            act.sa_handler = catch_child;
            sigemptyset(&act.sa_mask);
            act.sa_flags = 0;
            int ret = sigaction(SIGCHLD, &act, NULL);
            if (ret != 0) {
                perror("sigaction error");
                exit(-1);
            }
            close(cfd);
            continue;
        }
    }

    return 0;
}