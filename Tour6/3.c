#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int  b;
    int sum = 0;
    char str[200];
    scanf("%d%s", &b, str);
    for (int i = (int) strlen(str) -1 ; i >= 0 ; i--) {
        if (str[i] - '0' >=0 && str[i] - '0' <=9)
        {
            sum += (int) pow(b, (int)strlen(str)-i-1) * (str[i]-'0');
        }else
        {
            sum += (int) pow(b, (int)strlen(str)-i-1) * (str[i]-'a' + 10);
        }
    }
    printf("%d", sum);
    return 0;
}