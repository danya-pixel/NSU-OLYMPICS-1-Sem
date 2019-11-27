#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define size 100000

int main() {
    FILE *in = fopen("input.txt", "r");
    int cnt =0;
    unsigned char x;
    while (fscanf(in, "%c", &x) != EOF) 
        if(x == '\n') cnt++;
    fclose(in);
    FILE *out = fopen("output.txt", "w");
    fprintf(out, "%d", cnt);
    fclose(out);
    return 0;
}