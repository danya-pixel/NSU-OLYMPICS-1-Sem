#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>

int main() {
    int n = 0, sum = 0;
    char buf;
    scanf("%d", &n);
    scanf("%c", &buf);
    for (int i = 0; i < n; i += 1) {
        if (i % 8 == 0 && i!=0) {
            printf("%d ", sum);
            sum = 0;
        }
        scanf("%c", &buf);
        sum += (int) pow(2, i%8) * (buf - '0');
    }
    printf("%d ", sum);
}