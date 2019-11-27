#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#define n 31
int main() {
    char str[n];
    scanf("%s", str);
    int size = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '.') {
            size = i;
            break;
        }
    }
    for (int i = 0; i <= size - 2; i++) {
        printf("%c", str[i]);
    }
    if (str[size - 1] == 'e') {

        printf("%cr", str[size - 1]);
    } else if (str[size - 1] == 'r' && str[size - 2] == 'e') {
        printf("st");
    } else {
        printf("%cer", str[size - 1]);
    }
}