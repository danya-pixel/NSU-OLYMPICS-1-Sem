#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define CNT_BITS (int)(8 * sizeof(int))


int main() {
    int cur = 0;
    scanf("%d", &cur);

    int result = 0;
    int cur_inv = cur;

    for (int i = 0; i < CNT_BITS; i++) {

        result = (result << 1) | (cur & 1);
        cur >>= 1;
    }
    int res2 = result;
    for (int i = 0; i < CNT_BITS; i++) {
        printf("%d", (result & 1));
        result >>= 1;
    }
    printf("\n%d\n", res2);
    for (int i = 0; i < CNT_BITS; i++) {
        printf("%d", (cur_inv & 1));
        cur_inv >>= 1;
    }
    return 0;
}