# GDB

## 基础指令

- `-g`：使用该参数编译可执行那个文件

```shell
$ gcc hello.c -o a.out -g
$ gdb a.out
```

- `l`：列出源码

```gdb
(gdb) l
(gdb) list
(gdb) l 1
```

- `b`：根据行号设置断点

```gdb
(gdb) b 20
(gdb) break 20
(gdb) b 20 if==5 # 条件断点
```

- `d`：删除断点

```gdb
(gdb) delete breakpoints num
(gdb) d breakpoints num
```

- `run`：运行程序，停留在断点

```gdb
(gdb) run
(gdb) r
```

- `n`：下一条指令，会越过函数

```gdb
(gdb) n
(gdb) next
```

- `s`：下一条指令，进入函数

```gdb
(gdb) s
(gdb) step
```

- `p`：查看变量的值

```gdb
(gdb) p i
(gdb) print i
```

- `continue`：继续执行后续指令
- `quit`：退出当前调试

## 其他指令

- 使用 run 查看段错误行号
- `start`：直接启动调试
- `finish`：结束当前函数调用
- `set args`：设置 main 函数命令行参数，在 start 之前使用
    - `run xx_1 xx_2 xx_3`
```gdb
(gdb) set args 1 2 3
```
- `info b`：查看断点信息
- `display i`：跟踪变量的值
- `undisplay 编号`：取消变量跟踪
- `ptype i`：查看变量 i 的类型
- `bt`：查看函数的调用的栈帧和层级关系

```gdb
(gdb) bt
(gdb) backtrace
```

- `frame`：切换函数栈帧

```gdb
(gdb) frame
```
