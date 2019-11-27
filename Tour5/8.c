#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
    freopen("input.txt", "r", stdin);
    char ch, last_ch = (char) NULL;

    int b = scanf("%c", &ch), last_n = 0, sum = 0;
    while (b == 1) {
        if ('0' <= ch && ch <= '9') {
            last_n *= 10;
            last_n += ch - '0';
        } else {
            sum += last_n;
            last_n = 0;
        }
        b = scanf("%c", &ch);
        if (ch == '.')break;
    }
    if (last_n) sum += last_n;
    printf("%d", sum);
    return 0;
}