#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define n 300

_Bool find_ch(char *word, int size, char ch) {
    for (int i = 0; i < size; i++) {
        if (word[i] == ch) return (_Bool)1;
    }
    return (_Bool)0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char word[n], base[n], ch = 'a';
    int b = 1;
    _Bool first = 1;
    scanf("%s", base);
    b = scanf("%s", word);
    while (b == 1) {
        _Bool flag = 0;
        for (int i = 0; i < (int) strlen(base); i++) {
            if (find_ch(word, (int)strlen(word), base[i])) {
                flag = 1;
                break;
            }
        }
        if (!first && !flag)
            printf("\n");
        if (!flag) {
            printf("%s", word);
            first = 0;
        }
        b = scanf("%s", word);
    }
    if(first) printf("");
    return 0;
}