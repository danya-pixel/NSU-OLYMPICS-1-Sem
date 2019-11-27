#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
    int n = 0;
    unsigned long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= ceil(pow(n, 1.0 / 3)); i++) {
        for (int j = i; j <= sqrt((int) (n / i)); j++) {
            ans += n / i / j - j + 1;
        }
    }
    printf("%llu", ans);
    return 0;
}