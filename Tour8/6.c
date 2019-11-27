#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

int grid[250][250];
char slovo[250][250];
int is_checked[250][250];

void print(int len) {
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (grid[i][j]) printf("%c", slovo[i][j]);
}

void turn90(int len) {
    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
            int buf = grid[i][j];
            grid[i][j] = grid[len - 1 - j][i];
            grid[len - 1 - j][i] = grid[len - 1 - i][len - 1 - j];
            grid[len - 1 - i][len - 1 - j] = grid[j][len - 1 - i];
            grid[j][len - 1 - i] = buf;
        }
    }
}

_Bool check(int len) {
    for (int n = 1; n <= 4; n++) {
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                is_checked[i][j] += grid[i][j];
        turn90(len);
    }
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (is_checked[i][j] > 1) return 0;
    return 1;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < 2 * n; j++) {
            scanf("%d", &grid[i][j]);
            is_checked[i][j] = 0;
        }
    for (int i = 0; i < 2 * n; i++) {
        scanf("%s", slovo[i]);
    }
    if (!check(2 * n)) {
        printf("No");
        return 0;
    }
    print(2 * n);
    turn90(2 * n);
    print(2 * n);
    turn90(2 * n);
    print(2 * n);
    turn90(2 * n);
    print(2 * n);
    return 0;

}