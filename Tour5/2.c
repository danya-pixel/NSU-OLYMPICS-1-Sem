#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    char str[13];
    scanf("%s", str);
    if (str[1] =='A' && str[3] =='.')
    {
        printf("FITS");
    }else printf("DOES NOT FIT");

    return 0;
}