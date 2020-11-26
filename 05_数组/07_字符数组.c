#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

    for (int i = 0; i < 10; i++)
    {
        printf("%c", str[i]);
    }

    printf("\n");

    char str2[] = "world"; // {'w', 'o', 'r', 'l', 'd', '\0'}

    printf("%s \n", str2); // 遇到 \0 结束

    return 0;
}