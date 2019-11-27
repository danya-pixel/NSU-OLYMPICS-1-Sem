#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sort_shell(int *arr, int size) {
    int j;
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = step; i < size; i++) {
            int tmp = arr[i];
            for (j = i; j >= step; j -= step) {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
}


int main() {
    int n = 0;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort_shell(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}