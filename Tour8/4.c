#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#define max_len 12

int main() {
    int r = 0, c = 0, start = 0;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &r, &c, &start);
    char steps[max_len][max_len];
    for (int i = 0; i <= c + 1; i++) {
        steps[0][i] = 'f';
        steps[r + 1][i] = 'f';
    }
    for (int i = 0; i <= r + 1; i++) {
        steps[i][0] = 'f';
        steps[i][c + 1] = 'f';
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%c", &steps[i][j]);
            if (steps[i][j] < 65 || steps[i][j] > 90)
                j--;
        }
    }
    int was[max_len][max_len];
    for (int i = 0; i < max_len; i++)
        for (int j = 0; j < max_len; j++) was[i][j] = 0;


    int j = start, k = 1, i = 1;

    while (1) {

        was[i][j] = k;

        switch (steps[i][j]) {
            case 'N':
                i--;
                break;
            case 'S':
                i++;
                break;
            case 'E':
                j++;
                break;
            case 'W':
                j--;
                break;
        }
        if (steps[i][j] == 'f') {
            printf("%d step(s) to exit", k);
            return 0;
        }
        if (was[i][j] > 0) {
            printf("%d step(s) before a loop of %d step(s)", was[i][j] - 1, k - was[i][j] + 1);
            return 0;
        }
        k++;
    }
}