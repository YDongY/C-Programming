#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys//stat.h"
#include "fcntl.h"

void test_stat(){
    struct stat st;
    /** 获取文件信息
     * int stat (const char *__restrict __file,
		 struct stat *__restrict __buf)
     */
    stat("../test.log", &st);
    printf("[%ld]-[%d]-[%d] \n", st.st_size, st.st_uid, st.st_gid);

    // 文件类型
    if ((st.st_mode & S_IFMT) == S_IFREG) {
        printf("普通文件 \n");
    } else if ((st.st_mode & S_IFMT) == S_IFDIR) {
        printf("目录文件 \n");
    } else if ((st.st_mode & S_IFMT) == S_IFLNK) {
        printf("连接文件 \n"); // 获取的是所连接文件的信息
    }

    // 使用宏
    if (S_ISREG(st.st_mode)) {
        printf("普通文件 \n");
    }

    // 文件权限
    if (st.st_mode & S_IROTH) {
        printf("其他人 R \n");
    }
    if (st.st_mode & S_IWOTH) {
        printf("其他人 W \n");
    }
    if (st.st_mode & S_IXOTH) {
        printf("其他人 X \n");
    }
}

void test_lstat(){
    struct stat st;
    /** 获取文件信息
     * int stat (const char *__restrict __file,
		 struct stat *__restrict __buf)
     */
    lstat("../test.log", &st);
    printf("[%ld]-[%d]-[%d] \n", st.st_size, st.st_uid, st.st_gid);

    // 文件类型
    if ((st.st_mode & S_IFMT) == S_IFREG) {
        printf("普通文件 \n");
    } else if ((st.st_mode & S_IFMT) == S_IFDIR) {
        printf("目录文件 \n");
    } else if ((st.st_mode & S_IFMT) == S_IFLNK) {
        printf("连接文件 \n"); // 获取的是所连接文件的信息
    }

    // 使用宏
    if (S_ISREG(st.st_mode)) {
        printf("普通文件 \n");
    }

    // 文件权限
    if (st.st_mode & S_IROTH) {
        printf("其他人 R \n");
    }
    if (st.st_mode & S_IWOTH) {
        printf("其他人 W \n");
    }
    if (st.st_mode & S_IXOTH) {
        printf("其他人 X \n");
    }
}

int main(int argc, char const *argv[]) {
    test_stat(); // 测试 stat
    test_lstat(); // 测试 lstat

    // 区别：
    //      - 对于普通文件，二者一样
    //      - 对于软连接而言，lstat 获取的连接文件，stat 获取的是链接文件指向的文件

}
