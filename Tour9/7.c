#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define size 3*1000*1000

int main() {
    FILE *in = fopen("input.txt", "r");
    int cnt[256] = {0};
    unsigned char max_idx = 0, min_idx = 255;
    unsigned char x;
    while (fscanf(in, "%c", &x) != EOF) {
        if (x != '\n') {
            max_idx = x > max_idx ? x : max_idx;
            min_idx = x < min_idx ? x : min_idx;
            cnt[x] += 1;
        }
    }
    fclose(in);
    FILE *out = fopen("output.txt", "w");
    for (unsigned char i = min_idx; i <= max_idx; i++) {
        if (cnt[i] != 0) {
            fprintf(out, "%c ", i);
            for (int j = 0; j < cnt[i]; j++) {
                fprintf(out, "#");
            }
            fprintf(out, "\n");
        }
    }
    fclose(out);
    return 0;
}