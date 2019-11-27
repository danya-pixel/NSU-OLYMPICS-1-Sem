#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comp(const int *a, const int *b) {
    return *a - *b;
}


int main() {
    freopen("input.txt", "r", stdin);
    int n = 0;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), (int (*)(const void *, const void *)) comp);
    _Bool *states = malloc(sizeof(_Bool) * n);
    int last = arr[0], cnt = 1;
    states[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != last) {
            last = arr[i];
            states[i] = 1;
            cnt++;
        } else {
            states[i] = 0;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        if (states[i])
            printf("%d\n", arr[i]);
    }
    return 0;
}