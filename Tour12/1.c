#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct element_st {
    double val;
    int next_idx;
} Node;

int main() {
    int n = 0, f = 0;
    freopen("input.txt","r",stdin);
    scanf("%d %d", &n, &f);
    Node *arr = malloc(sizeof(Node)*n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %d", &arr[i].val, &arr[i].next_idx);
    }
    while (1) {
        if (arr[f].next_idx == -1){
            printf("%0.3lf", arr[f].val);
            return 0;
        }
        printf("%0.3lf\n", arr[f].val);
        f = arr[f].next_idx;
    }
}