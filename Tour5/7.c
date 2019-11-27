#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define n 7
#define size_r 27

int main() {
    freopen("input.txt", "r", stdin);
    char color[n], balloon[size_r];
    unsigned int cnt = 0;
    scanf("%s%s", color, balloon);
    for (int i = 0; i <= (int) strlen(balloon); i++) {
        switch (color[0]) {
            case 'p':
                if (balloon[i] == 'B' || balloon[i] == 'R') {
                    printf("%d ", i + 1);
                    cnt++;
                }
                break;
            case 'g':
                if (balloon[i] == 'B' || balloon[i] == 'Y') {
                    printf("%d ", i + 1);
                    cnt++;
                }
                break;
            case 'o':
                if (balloon[i] == 'Y' || balloon[i] == 'R') {
                    printf("%d ", i + 1);
                    cnt++;
                }
                break;

        }
        if (cnt == 2) break;
    }
    return 0;
}