# 静态库

- `add.c`

```c
int add(int a, int b) {
return a + b;
}
```

- `sub.c`

```c
int sub(int a, int b) {
return a - b;
}
```

- 制作：静态库名以 `lib` 开头 `.a` 结尾

```shell
$ gcc -c add.c -o add.o
$ gcc -c sub.c -o sub.o
$ ar rsc libmymath.a add.o sub.o
```

- 使用

```c
// mymath.h
#ifndef
_MYMATH_H_
#define
_MYMATH_H_

int add(int a, int b);
int sub(int a, int b);

#endif
```

```c
#include
"stdio.h"
#include
"stdlib.h"

int main() {
printf("add:%d\n", add(10, 20));
printf("sub:%d\n", sub(10, 20));
}
```

```c
$ gcc test.c libmymath.a -o test
```

# 动态库

- `-fPIC`：生成与位置无关的代码

```shell
$ gcc -c add.c -o add.o -fPIC
```

- 使用 `-shared` 制作

```shell
$ gcc -shared -o libmymath.so add.o sub.o
```

- 编译可执行程序

```shell
$ export LD_LIBRARY_PATH=./lib
$ gcc test.c -o test -lmymath -L./lib 
$ ./test
```

或者

```shell
$ sudo vim /etc/ld.so.conf
# 写入动态库绝对路径保存
$ sudo ldconfig -v # 是配置文件生效
```


```shell
|------------------------|
|      kernel            |
|------------------------|
|    环境变量,main参数     |
|------------------------|
|                        |   |
|      stack             |   |
|                        |   V
|------------------------|
|                        |
|       .so              |
|                        |
|------------------------|
|                        |   ^
|        heap            |   |
|                        |   |
|------------------------|
|        .bss            | <---------|
|------------------------|          rw
|        .data           | <---------|
|------------------------|
|        .rodata         | <---------|
|------------------------|           ro
|        .txt            | <---------|
|------------------------|
```