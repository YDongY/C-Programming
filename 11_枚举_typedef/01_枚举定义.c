#include <stdio.h>

enum POKER {
    HONGTAO, // 0
    HEITAO, // 1
    MEIHUA,  // 2
    FANGPIAN //3
};

enum POKER2 {
    HONGTAO2 = 2, // 2
    HEITAO2, // 3
    MEIHUA2,  // 4
    FANGPIAN2 //5
};

enum BOOL {
    False, // 0
    True  // 1
};

int main(int argc, char const *argv[]) {
    enum POKER poker;
    poker = HONGTAO;
    printf("%d \n", poker);

    // HONGTAO = 2 // error

    // 枚举真假

    enum BOOL flag;
    flag = True;

    if (flag)
        printf("真");

}