#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

int main() {
    freopen("input.txt", "r", stdin);
    int T = 0;
    scanf("%d", &T);
    char **array;
    array = (char **) malloc(sizeof(char *) * T);
    int n = 0;
    for (int k = 0; k < T; k++) {
        int action = 0;
        scanf("%d ", &action);
        switch (action) {
            case 0: {
                int len = 0;
                scanf("%d", &len);
                array[n] = (char *) malloc((len + 1) * sizeof(char));
                scanf("%s", array[n]);
                n++;
                break;
            }
            case 1: {
                int idx = 0;
                scanf("%d", &idx);
                free(array[idx]);
                break;
            }
            case 2: {
                int idx = 0;
                scanf("%d", &idx);
                printf("%s\n", array[idx]);
                break;
            }
            default: {
                char buf = 0;
                int id = 0;
                scanf("%d %c", &id, &buf);
                int cnt = 0;
                for (int i = 0; i < (int) strlen(array[id]); i++)
                    if (array[id][i] == buf)
                        cnt++;
                printf("%d\n", cnt);
            }
        }
    }
    return 0;
}