#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
    int n = 0, b;
    int src[300];
    for (int i = 0; i < 30; i++) src[i] = -1;
    scanf("%d%d", &b, &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    int i = 299;
    while (n > 0) {
        src[i] = n % b;
        n = n / b;
        i--;
    }
    for (int j = i + 1; j < 300; ++j) {
        if (src[j] > 9) printf("%c", (char) (src[j] - 10 + 'a'));
        else printf("%d", src[j]);
    }
    return 0;
}