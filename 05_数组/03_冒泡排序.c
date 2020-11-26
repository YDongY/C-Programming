#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10] = {12, 4, 56, 34, 77, 60, 19, 20, 43, 10};
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", arr[i]);
    }

    return 0;
}
