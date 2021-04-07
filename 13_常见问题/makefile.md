# 命名

- `makefile`
- `Makefile`

# 规则

```
目标:依赖条件
    命令
```

```
hello:hello.c
    gcc hello.c -o hello

# 改进
hello:hello.o
    gcc hello.o -o hello

hello.o:hello.c
    gcc -c hello.c -o hello.o
```

```
a.out:hello.c add.c sub.c
    gcc hello.c add.c sub.c -o a.out
    
# 优化：防止其中一个文件改动，导致其他文件都需要重新编译

a.out:hello.o add.o sub.o
    gcc helle.o add.o sub.o -o a.out
hello.o:hello.c
    gcc -c hello.c -o hello.o
add.o:add.c
    gcc -c add.c -o add.o
sub.o:sub.c
    gcc -c sub.c -o sub.o    
```

## all

```
ALL:a.out # 指定 makefile 的终极目标
```

## clean

```
...
clean:
    -rm -rf $(obj) a.out # 前面的 - 表示删除出错仍然执行
```

```shell
$ make clean -n # 查看清除的命令
```

# 函数

```
src = $(wildcard *.c) # 找到当前目录下所有 .c 的文件，作为列表赋值给 src
obj = $(patsubst %.c,%.o,$(src)) # 把 src 变量里的所有 .c 文件替换成 .o 文件
```

```
src = $(wildcard *.c) # add.c sub.c hello.c
obj = $(patsubst %.c,%.o,$(src)) # add.o sub.o hello.o

a.out:$(obj)
    gcc $(obj) -o a.out # 使用 obj
hello.o:hello.c
    gcc -c hello.c -o hello.o
add.o:add.c
    gcc -c add.c -o add.o
sub.o:sub.c
    gcc -c sub.c -o sub.o  
```

# 自动变量

- `$@`：在规则的命令中，表示规则中的目标
- `$<`：在规则的命令中，表示第一个依赖条件。如果将该变量应用在模式中，它可将依赖条件列表中的依赖依次取出，套用模式规则。
- `$^`：在规则的命令中，表示所有依赖条件

```
src = $(wildcard *.c) # add.c sub.c hello.c
obj = $(patsubst %.c,%.o,$(src)) # add.o sub.o hello.o

a.out:$(obj)
    gcc $^ -o $@
hello.o:hello.c
    gcc -c $< -o $@
add.o:add.c
    gcc -c $< -o $@
sub.o:sub.c
    gcc -c $< -o $@ 
```

# 模式规则

```
hello.o:hello.c
    gcc -c $< -o $@
add.o:add.c
    gcc -c $< -o $@
sub.o:sub.c
    gcc -c $< -o $@ 
    
# 替换

%.o:%.c
    gcc -c $< -o $@
```

# 静态模式规则

```
a.out:$(obj)
    gcc $^ -o $@
$(obj):%.o:%.c
    gcc -c $< -o $@
```

# 伪目标

```
.PHONY:clean ALL
```

# 变量

```
myArgs = -Wall -g

a.out:$(obj)
    gcc $^ -o $@ $(myArgs)
```