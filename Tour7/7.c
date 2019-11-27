#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
void multiply(int *array, int to) {
    int new_dis = 0;
    for (int i = 1; i <= array[0]; i++) {
        array[i] = array[i] * to + new_dis;
        new_dis = array[i] / 10;
        array[i] %= 10;
    }
    while (new_dis > 0) {
        array[0]++;
        array[array[0]] = new_dis % 10;
        new_dis /= 10;
    }
}

int main() {
    int array[3000];
    array[0] = 1;
    array[1] = 1;
    int n = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        multiply(array, i);
    }
    for (int i = array[0]; i >= 1; i--) {
        printf("%d", array[i]);
    }
    return 0;
}