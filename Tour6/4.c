#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

int to_10(char *str, int size, int from) {
    int sum = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
            sum += (int) pow(from, size - i - 1) * (str[i] - '0');
        } else {
            sum += (int) pow(from, size - i - 1) * (str[i] - 'a' + 10);
        }
    }
    return sum;
}

void from_10(int sum, int to) {
    int src[300];
    int i = 299;
    while (sum > 0) {
        src[i] = sum % to;
        sum = sum / to;
        i--;
    }
    for (int j = i + 1; j < 300; ++j) {
        if (src[j] > 9) printf("%c", (char) (src[j] - 10 + 'a'));
        else printf("%d", src[j]);
    }
}

int main() {
    int from = 0, to = 0;
    int sum = 0;
    char str[200];
    scanf("%d%d%s", &from, &to, str);
    from_10(to_10(str, (int) strlen(str), from), to);
    return 0;
}