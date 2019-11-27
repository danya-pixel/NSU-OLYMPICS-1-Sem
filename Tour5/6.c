#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define n 21

int main() {
    freopen("input.txt", "r", stdin);
    char word[n], ch = 'a';
    int b = 1;
    b = scanf("%s", word);
    while (b == 1) {
        if (strchr(word, ch) == NULL) {
            if ((ch - 'a') % 2 == 0) printf("PLAYER 2");
            else printf("PLAYER 1");
            return 0;
        }
        ch++;
        b = scanf("%s", word);

    }
    printf("NO WINNER");
    return 0;
}