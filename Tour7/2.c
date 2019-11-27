#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int max__(int a, int b) {
    return (a >= b) * a + (a < b) * b;
}

int main() {
    int n = 0, max_ = 0, cnt = 0;
    scanf("%d", &n);

    for (int j = 0; j < (int) (8 * sizeof(int)); j++) {
        if (n & 1)
            cnt++;
        else {
            max_ = max__(cnt, max_);
            cnt = 0;
        }
        n >>= 1;
    }
    max_ = max__(cnt, max_);
    printf("%d", max_);
    return 0;
}