#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 30;
    switch (a){
    case 20:
        printf("20");
        break;
    case 30:
        printf("30");
        break;
    default:
        break;
    }

    int month;
    scanf("%d", &month);

    switch (month)
    {
    case 3:
    case 4:
    case 5:
        printf("春季");
        break;
    case 6:
    case 7:
    case 8:
        printf("夏季");
        break;
    case 9:
    case 10:
    case 11:
        printf("秋季");
        break;
    case 12:
    case 1:
    case 2:
        printf("冬季");
        break;
    default:
        printf("非法输入");
        break;
    }

    return 0;
}
