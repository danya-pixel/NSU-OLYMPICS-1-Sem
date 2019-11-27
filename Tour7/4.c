#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long n = 0, ch = 0;
    freopen("input.txt", "r", stdin);
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &ch);
        for (int j = 0; j < (int) (8*sizeof(long long int)); j++) {
            if (ch & 1) {
                printf("%d\n", (int) pow(2, j));
                break;
            }
            ch >>= 1;
        }
    }

    return 0;
}