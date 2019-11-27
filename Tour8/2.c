#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define max_len 10


int main() {
    int n = 0, m = 0, array[max_len][max_len];

    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }

    }
    _Bool is_print = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = 0; j < m; j++) {
            if (array[i][j]) {
                cnt++;
                is_print = 0;
            } else if (!is_print && cnt > 0) {
                printf("%d ", cnt);
                is_print = 1;
                cnt = 0;
            }
        }
        if (!is_print && cnt > 0) printf("%d ", cnt);
        printf("\n");
    }
    for (int j = 0; j < m; j++) {
        cnt = 0;
        is_print = 1;
        for (int i = 0; i < n; i++) {
            if (array[i][j]) {
                cnt++;
                is_print = 0;
            } else if (!is_print && cnt > 0) {
                printf("%d ", cnt);
                is_print = 1;
                cnt = 0;
            }
        }
        if (!is_print && cnt > 0) {
            printf("%d ", cnt);
        }
        printf("\n");
    }
    return 0;

}