#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const int n = 501;
    char str[501];
    long long size = 0, sum = 0;
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        if (str[i] == '.') break;
        size++;
        sum += (int) (str[i] - '0');
    }
    if (sum % 3 == 0 && ((str[size - 1] == '5' || str[size - 1] == '0') && size > 1))
        printf("YES");
    else
        printf("NO");
    return 0;
}