#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 101

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt) {
    *oDigitsCnt = 0;
    *oLowerCnt = 0;
    *oUpperCnt = 0;
    for (int i = 0; i < (int) strlen(iStr); i++) {
        if (iStr[i] >= '0' && iStr[i] <= '9') *oDigitsCnt += 1;
        else if (iStr[i] >= 'a' && iStr[i] <= 'z') *oLowerCnt += 1;
        else if (iStr[i] >= 'A' && iStr[i] <= 'Z') *oUpperCnt += 1;
    }
    return (int) strlen(iStr);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char str[size];
    int line = 0, lower_cnt = 0, upper_cnt = 0, digit_cnt = 0, len = 0;
    while (gets(str) != NULL) {
        len = calcLetters(str, &lower_cnt, &upper_cnt, &digit_cnt);
        line++;
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n",
               line,
               len,
               lower_cnt + upper_cnt, lower_cnt, upper_cnt, digit_cnt);
    }

    return 0;
}