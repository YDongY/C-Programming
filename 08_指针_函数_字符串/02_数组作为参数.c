#include <stdio.h>

void print(int arr[], int len); // 相当于 int *arr

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int len = sizeof(arr) / sizeof(int);
    print(arr, len);
}


void print(int arr[], int len) { // 相当于 int *arr
    for (int i = 0; i < len; i++) {
        printf("%d \t", arr[i]);
    }
}