# Linux 系统编程 - IO

## IO 基本操作

- open：`extern int open (const char *__file, int __oflag, ...)`

```c
int fd = open("../test.log", O_RDWR | O_CREAT, 0777); // mode & (~umask)
if (fd < 0) {
    perror("open error");
    return -1;
}
```

- read：`extern ssize_t read (int __fd, void *__buf, size_t __nbytes)`

```c
char buf2[1024];
memset(buf2, 0, sizeof(buf2));

// 参数：文件描述符，存储，最多读多少字节
int n = read(fd, buf2, sizeof(buf2));
```

- write：`extern ssize_t write (int __fd, const void *__buf, size_t __n)`

```c
char buf[] = "hello world";
write(fd, buf, strlen(buf));
```

- close：`extern int close (int __fd);`

```c
close(fd);
```

- lseek：`extern __off_t lseek (int __fd, __off_t __offset, int __whence)`
    - whence
        - SEEK_SET
        - SEEK_CUR
        - SEEK_END
```c
lseek(fd, 0, SEEK_SET);
```

## read 函数阻塞与非阻塞

- read 读取普通文件是非阻塞的
- read 读取设备文件是阻塞的

## 文件操作


## 目录操作


## dup 和 dup2

- dup

```c
// ---------------    dup 函数 --------------------------
 文件描述符表
------------
|    0     |
|    1     |             fd=open("test.txt",O_RDWR)
|    2     |      fd         --------------
|    3     | ------------->  |  test.txt  |  
|    4     | ------------->  --------------
|  ......  |     newfd        newfd = dup(fd)
|   1023   |
|   1024   |
------------
```

当调用 dup 函数之后，newfd 和 fd 都指向同一个文件，且该文件的内部计数 +1，当 close 一个 fd 是，计数 -1，当计数为 0 时，文件真正关闭

- dup2

```c
// ----------------------- dup2 函数 ---------------------

 文件描述符表
------------
|    0     |
|    1     |
|    2     |    fd
|    3     | -------------> test.txt   >>>    dup2(fd,newfd)   >>>      fd ----------> test.txt
|    4     | -------------                                                                ^
|  ......  |    newfd    |                                                                |
|   1023   |             V                                                              newfd
|   1024   |           test2.txt
------------
```
当调用 dup2 函数之后，如果 newfd 原本已经打开了一个文件，则先关闭文件，然后指向 fd 的文件，内部计数 +1，如果原本没有打开文件，则直接指向 fd 文件，内部计数 +1。


## fcntl 函数

```c
// ---------- fcntl 复制 fd-----------------
int newfd = fcntl(fd, F_DUPFD, 0);

// 获取 fd 的 flag 属性
int flags = fcntl(fd, F_GETFL, 0);

// 追加属性
flags = flags | O_APPEND;

// 设置，使得 fd 具有追加写文件的能力
fcntl(fd, F_SETFL, flags);
```