#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // strlen 字符串长度
    // strcpy 字符串拷贝
    char arr1[] = "bit";
    char arr2[20] = "####";

    strcpy(arr2, arr1);
    printf("%s\n", arr2);
    return 0;
}
