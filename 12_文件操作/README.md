# 文件操作

## 系统文件

- 标准输入：stdin --- 0
- 标准输出：stdout --- 1
- 标准错误：stderr --- 2

应用程序启动时，自动被打开。程序执行结束时，自动被关闭

## 文件指针与普通指针区别

- 文件指针：`FILE *fp = fopen(filepath)`，fp 可以在堆空间找到文件的描述信息
- 函数指针：`int *p = &a;`

```c
                      heap (结构体保存文件描述信息)        memory                disk
                     ------------------------       -------------         -----------    
fopen(a.txt) ------> |  typedef struct {    |  -->  |  a.txt    |  <----  |  a.txt  |
                     |      .....           |  -->  |           |  ---->  |         |
                     |  } FILE;             |  -->  |           |         |         |
                     ------------------------       -------------         -----------
```

## 函数

- `fopen`：打开文件

```c
FILE *fp = fopen("../test2.txt","r"); // Linux r 和 rb 效果相同
if(fp==NULL){
    perror("fopen error");
    return -1;
}
```

- `fclose`：关闭文件`

```c
fclose(fp);
```

- `fputc`：按照字符写文件
    - 成功：返回对应字符 ASCII 码
    - 失败：返回 -1

```c
char buf[] = "hello world\n";
int i = 0;
while (buf[i]!='\0'){
    fputc(buf[i],fp);
    i++;
}
```

- `fgetc`：按照字符读文件
    - 成功：返回读取到字符的 ASCII 码
    - 失败：-1

```c
int ch;
while((ch = fgetc(fp))!=EOF){ // EOF 表示文件末尾，EOF 就是 -1
    printf("%c",ch);
}
```

- `feof`：判断文件结尾

```c
/**
 * int feof (FILE *__stream)
 * 非 0 值：已经读到文件尾
 * 0 ：没有读到文件为
 */
 while (!feof(fp)){     
    // ... 
}
```

- `fputs`：按行写，不加换行标记
    - 成功：0
    - 失败：-1

```c
char *buf[]={"hello\n","world\n","c/c++\n"};

int len = sizeof(buf) / sizeof(char *);
for(int i=0;i<len;i++){
    fputs(buf[i],fp);
}
```

- `fgets`：按行读，以 \n 作为结束标记或以读到 size-1 个字符为止，最后自动添加 \0 ，空间足够大会读 \n ，空间不足舍弃 \n
    - 成功：读到的字符串
    - 失败：NULL

```c
    char buf[1024]={0};
#if 0
    while (!feof(fp)){
        char *ret = fgets(buf,sizeof(buf)-1,fp);
        if(ret==NULL){
            break;
        }
        // 把 \n 换成 \0;
        buf[strlen(buf)-1]= '\0';
        printf("%s \n",buf);
    }
#else
    // 优化
    while (fgets(buf,sizeof(buf)-1,fp)){
        buf[strlen(buf)-1]= '\0';
        printf("%s \n",buf);
    }
#endif
```

- `fprintf`：格式化，成功写入返回字符数

```c
fprintf(fp,"%s-%d-%d\n","hello",10,20);
```

- `fscanf`：格式化读文件

```c
fscanf(fp,"a=%d,b=%d,c=%d\n",&a,&b,&c);
```

- `fwrite`：按块写
    - 成功：参数 3 的值
    - 失败：0

```c
FILE *fp = fopen("../test7.txt", "w");
if (fp == NULL) {
    return -1;
}
int arr[5] = {1, 2, 3, 4, 5};

int len = sizeof(arr) / sizeof(int);

for (int i = 0; i < len; i++) {
    // 参数:数据地址 块大小 块个数 文件指针
    fwrite(&arr[i], sizeof(int), 1, fp); // 直接写入结构体
}
fclose(fp);
```

- `fread`：按块读
    - 成功：参数 3 的值
    - 失败：0

```c
FILE * fp = fopen("../test4.txt","r");
if(fp==NULL){
    return;
}

int arr[5];
int len = sizeof(arr) / sizeof(int);
#if 0
    for (int i=0;i<len;i++){
        // 参数:数据地址 块大小 块个数 文件指针
        fread(&arr[i],sizeof(int),1,fp); // 一块一块读
    }
#else
    fread(arr,sizeof(int),len,fp); // 一次性读取
    // fread(arr,1,sizeof(arr),fp); // 一次性读取
#endif
    for(int j=0;j<len;j++){
        printf("%d\n",arr[j]);
    }
fclose(fp);
```

- `f_seek`：移动文件流的读写位置
    - whence:
        - SEEK_SET:从文件头移动 offset 个字节
        - SEEK_CUR:从当前位置移动 offset 个字节
        - SEEK_END:从文件末尾移动 offset 个字节
    - 返回值：
        - 成功：0
        - 失败：-1
```c
fseek(fp,0,SEEK_SET); // 移动文件指针位置到文件头
// rewind(fp); 将文件光标置首
```

- `ftell`：获取文件流读写位置

```c
ftell(fp); // 获取光标位置
```

- `stat`：文件信息

```c
#include "stdio.h"
#include "sys/stat.h"
#include "time.h"

int main(int argc, char const *argv[]) {
    struct stat MyStat;
    stat("../test5.txt",&MyStat);
    printf("文件大小:%ld\n",MyStat.st_size); // 1

    char *time = ctime((const time_t *) &MyStat.st_atim);

    printf("文件创建时间:%s\n",time); // 文件创建时间:Sat Nov 28 16:22:03 2020
}
```

- `remove`：删除文件

```c
remove("../test5-1.txt");
```

- `rename`：文件重命名

```c
rename("../test5.txt","../test5-1.txt");
```

## 文件缓冲区

```c
    ----------------------                                          ----------------------
    | fputc/fputs/fwrite |                                          |  fgetc/fgets/fread |
    ----------------------                                          ----------------------
              |                                                               ^
              |                                                               |
              V                                                               |
        ---------------     刷新         ---------------                ---------------
        |   输出缓冲区  |   ------------> |     磁盘     |   ---------->  |  输入缓冲区   |
        ---------------                 ---------------                ---------------
```

- 缓冲类型：
    - 全缓冲：缓冲区中的数据满了，向磁盘写数据，典型代表是对磁盘文件的读写
    - 行缓冲：遇到换行符，将缓冲数据写入磁盘，典型代表是标准输(stdin)和标准输出(stdout)
    - 无缓冲：不进行缓冲，标准错误文件(stderr)是典型代表，这使得出错信息可以直接尽快地显示出来。
- 刷新：
    - 手动刷新：`int fflush (FILE *__stream)`
    - 关闭刷新：fclose 关闭文件的时候，将缓冲区最后的剩余的数据写入磁盘