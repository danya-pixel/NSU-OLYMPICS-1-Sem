#include <stdio.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int line[256] = {0};
    unsigned char x = 0;
    while (fscanf(in, "%c", &x) != EOF)
        line[x]++;
    for (int i = 13; i <= 255; i++) {
        if (line[i] != 0)
            fprintf(out, "%d : %c - %d\n", i, (char) i, line[i]);
    }
    fclose(in);
    fclose(out);
    return 0;
}