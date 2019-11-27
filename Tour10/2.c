#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *a, char *b) {
    for (int i = 0; i <= (b - a) / 2; i++)
        swap(a + i, b - i);
}

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    char str[101];
    int n;
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++) {
        if (fgets(str, 126, in))
            fscanf(in, "%s", str);
        reverse(&str[0], &str[strlen(str) - 1]);
        for (int j = 0; j < (int) strlen(str); j++)
            fprintf(out, "%c", str[j]);
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);
    return 0;
}