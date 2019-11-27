#include <stdlib.h>
#include <stdio.h>

#define SIZE 1000

int main() {
    int cnt = 0, n = 0, k = 0;
    double **c = (double **) malloc(sizeof(double *) * (SIZE + 1));
    for (int i = 0; i < SIZE + 1; i++)
        c[i] = (double *) malloc(sizeof(double) * (SIZE + 1));
    for (int i = 0; i <= SIZE; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d %d", &n,&k);
        printf("%0.10g\n", c[n][k]);
    }
    return 0;
}