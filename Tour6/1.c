#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *a, char *b) {
    int cnt = (b - a);
    for (int i = 0; i <= (b - a) / 2; i++)swap(a + i, b - i);
}

void next_step(char *mas, int size) {
    int i = size - 1, j = i;
    while (i > 0 && mas[i - 1] >= mas[i]) i--;
    while (mas[j] <= mas[i - 1]) j--;
    swap(&mas[i - 1], &mas[j]);
    reverse(&mas[i], &mas[size - 1]);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n = 0;
    scanf("%d", &n);
    char *a = (char *) malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        char buf;
        scanf("%c ", &buf);
        if (buf == '\n' || buf == ' ') {
            i--;
            continue;
        }
        a[i] = buf;
    }


    next_step(a, n);
    for (int i = 0; i < n; i++) printf("%c ", a[i]);

    return 0;
}