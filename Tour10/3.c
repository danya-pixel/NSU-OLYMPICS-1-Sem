#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 1000002

char *concat(char *pref, char *suff) {
    for (int i = 0; i < (int) strlen(suff); i++) {
        pref[i] = suff[i];
    }
    pref[(int) strlen(suff)] = 0;
    return &pref[(int) strlen(suff)];
}

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    char *str = (char *) malloc(sizeof(char) * size);
    char *first = str;
    char buf[101];
    str[0] = 0;
    int n;
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++) {
        if (fgets(buf, 126, in))
            fscanf(in, "%s", buf);
        str = concat(str, buf);
    }
    fprintf(out, "%s", first);
    fclose(in);
    fclose(out);
    return 0;
}