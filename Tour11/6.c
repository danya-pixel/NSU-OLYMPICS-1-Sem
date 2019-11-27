#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comp(const int *a, const int *b) {
    return *a - *b;
}
int main() {
    int n_1 = 0, n_2 = 0;
    scanf("%d", &n_1);
    int *arr1 = malloc(sizeof(int) * n_1);
    for (int i = 0; i < n_1; i++)
        scanf("%d", &arr1[i]);
    qsort(arr1, n_1, sizeof(int), (int (*)(const void *, const void *)) comp);
    scanf("%d", &n_2);
    int *arr2 = malloc(sizeof(int) * n_2);
    for (int i = 0; i < n_2; i++)
        scanf("%d", &arr2[i]);
    int *answer = malloc(sizeof(int) * n_1);
    qsort(arr2, n_2, sizeof(int), (int (*)(const void *, const void *)) comp);
    int cnt = 0;
    int last_el = 0;
    for (int i = 0; i < n_1; i++) {
        _Bool is_exist = 0;
        for (int j = last_el; j < n_2; j++) {
            if (arr2[j] > arr1[i]) {
                break;
            } else if (arr2[j] == arr1[i]) {
                is_exist = 1;
                last_el = j;
            } else if (arr2[j] < arr1[i]) {
                last_el = j;
            }
        }
        if (cnt != 0 && answer[cnt - 1] == arr1[i]) is_exist = 1;
        if (!is_exist) {
            answer[cnt] = arr1[i];
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d ", answer[i]);
    return 0;
}