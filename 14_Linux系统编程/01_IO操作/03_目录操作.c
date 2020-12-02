#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys//stat.h"
#include "fcntl.h"
#include "dirent.h"


int main(int argc, char const *argv[]) {
    // 打开目录
    DIR *pdir = opendir("../");
    if (pdir == NULL) {
        perror("opendir error");
        return -1;
    }

    // 读取目录
    struct dirent *pdent = NULL;
    while ((pdent = readdir(pdir)) != NULL) {
        // 过滤 . ..
        if (strcmp(pdent->d_name, ".") == 0 || strcmp(pdent->d_name, "..") == 0) {
            continue;
        }
        printf("%s--", pdent->d_name);
        // 判断文件类型
        switch (pdent->d_type) {
            case DT_REG:
                printf("普通文件");
                break;
            case DT_DIR:
                printf("目录文件");
                break;
            case DT_LNK:
                printf("链接文件");
                break;
            default:
                printf("未知");
        }
        printf("\n");
    }

    // 关闭目录
    closedir(pdir);
}

