#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    code:
        printf("%d", n);
        n++;
        if (n <= 5)
            goto code;
    return 0;
}
