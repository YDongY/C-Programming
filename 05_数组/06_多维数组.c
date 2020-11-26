#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 层，行，列
    int arr[2][3][4] = {
        {{1, 2, 3, 4},
         {1, 2, 3, 4},
         {1, 2, 3, 4}},
        {{5, 6, 7, 8},
         {5, 6, 7, 8},
         {5, 6, 7, 8}}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                printf("%d \t", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return 0;
}
