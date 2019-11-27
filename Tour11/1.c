#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *mas, int left, int right) {
    int osn = mas[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (mas[j] < osn) {
            i += 1;
            swap(&mas[i], &mas[j]);
        }
    }
    swap(&mas[i + 1], &mas[right]);
    return (i + 1);
}

void quickSort(int *mas, int left, int right) {
    if (left < right) {
        int mid = partition(mas, left, right);
        quickSort(mas, left, mid - 1);
        quickSort(mas, mid + 1, right);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}