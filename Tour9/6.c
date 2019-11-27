#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define size 3*1000*1000

int main() {
    FILE *in = fopen("input.txt", "r");
    int i = 0;
    unsigned char *str=(unsigned char*)malloc(size* sizeof(unsigned char));
    while (fscanf(in, "%c", &str[i]) != EOF) {
        i++;
    }
    fclose(in);
    FILE *out = fopen("output.txt", "w");
    int last_i = i;
    _Bool first = 1;
    for (i-=1; i >= 0; i--) {
        if (str[i] == '\n') {
            for (int j = i + 1; j < last_i; j++) {

                fprintf(out, "%c", str[j]);
                first = 0;
            }
            fprintf(out, "\n");
            last_i = i;
        }
    }

    for (int j = 0; j < last_i; j++) {

        fprintf(out, "%c", str[j]);
    }
    fclose(out);
    return 0;
}