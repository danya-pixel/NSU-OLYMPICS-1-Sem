#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define n 10001
#define base_ch 0
int main() {
    freopen("input.txt", "r", stdin);
    char ch = 0, last_char=base_ch;
    _Bool flag = 0;
    int cnt=0;
    while(1)
    {
        scanf("%c", &ch);
        if(ch == '\r' || ch == '\n') break;
        if (ch =='.')
        {
            if (flag){
                cnt++;
                flag = 0;
            }
            continue;
        }
        flag = 1;
    }
    if(flag) cnt++;
    printf("%d", cnt);
}