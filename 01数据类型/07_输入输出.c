#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%s\n", "fjafjlajfa");

    int a = 123;

    printf("a1 = '%d' \n", a);   // a1 = '123'
    printf("a2 = '%05d' \n", a); // a2 = '00123'
    printf("a3 = '%-5d' \n", a); // a3 = '123  ' 左对齐

    double b = 3.14;

    printf("b = %lf \n", b);      // b = 3.140000 ，默认小数点后面六位
    printf("b = '%8.3lf' \n", b); //b = '   3.140'
    printf("b = '%.4lf' \n", b);  //b = '3.1400'

    char ch = 'a';

    putchar(ch); // 把 ch 内容输出


    // --------------------------------输入---------------------

    int c;
    printf("请输入(char):");
    // scanf("%d", &c);
    c = getchar();
    printf("c = %c \n", c);

    int i;
    int j;
    printf("请输入 i,j:");
    scanf("%d %d", &i, &j);
    printf("i=%d,j=%d\n", i, j);

    return 0;
}
