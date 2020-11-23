#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("start \n");
    printf("%d\n",system("pwd")); // 调用系统命令 pwd，返回值为 0
    printf("end \n");
    return 0;
}