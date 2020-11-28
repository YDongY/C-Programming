#include "stdio.h"
#include "string.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "time.h"

int main(int argc, char const *argv[]) {
    struct stat MyStat;
    stat("../test5.txt",&MyStat);
    printf("文件大小:%ld\n",MyStat.st_size); // 1

    char *time = ctime((const time_t *) &MyStat.st_atim);

    printf("文件创建时间:%s\n",time); // 文件创建时间:Sat Nov 28 16:22:03 2020

}
