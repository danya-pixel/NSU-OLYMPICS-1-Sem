#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int parse(char* str_)
{
    switch (str_[0])
    {
        case 'M':
            return 1;
            break;
        case 'T':
            if (str_[1] == 'u') return 2;
            else return 4;
            break;
        case 'W':
            return 3;
            break;
        case 'F':
            return 5;
            break;
        case 'S':
            if (str_[1] == 'u') return 7;
            else return 6;
            break;
    }
    return 1;
}

int main() {
    char str[3];
    scanf("%s", &str);
    printf("%d", parse(str));
    return 0;
}