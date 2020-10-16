#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 内存中没有字符，只有数字
    // 利用 ascii 进行存储，一个字符对应一个数字
    char ch = 'a';
    printf("ch = %d\n", ch); // ch = 97

    char a = 'a';
    char A = 'A';

    printf("ch= %d \n", a); // ch = 97
    printf("ch= %d \n", A); // ch = 65

    // 转移字符

    char c = '\\';

    printf("ch = %c \n", c); // \

    char n = '\n';

    printf("ch = %c \n", n); // 换行

    char r = '\r';

    // 光标回到句首
    printf("aaa%cbbb", r); // bbb

    return 0;
}
