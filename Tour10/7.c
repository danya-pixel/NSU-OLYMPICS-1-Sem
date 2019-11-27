#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define size 100

void double_to_bits(double n, char *ret) {
    for (int i = 0; i < size; i++) ret[i] = 0;
    unsigned char arr[sizeof(n)];
    memcpy(arr, &n, sizeof(n));
    int i = 0;
    for (unsigned idx = CHAR_BIT * sizeof(n); idx--;) {
        ret[i] = (arr[idx / CHAR_BIT] & (1u << (idx % CHAR_BIT))) ? 1 : 0;
        i++;
    }
}

void xor(long long m, char *arr) {
    for (int j = 63; j >= 0; j--) { //XOR
        char mBit = m & 1;
        m >>= 1;
        if (mBit == 1) {
            if (arr[j] == 1) arr[j] = 0;
            else arr[j] = 1;
        }
    }
}

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int n = 0;
    fscanf(in, "%d", &n);
    for (int idx = 0; idx < n; idx++) {
        int p = 0, q = 0;
        double x = 0;
        long long m = 0;
        fscanf(in, "%d/%d xor %llx", &p, &q, &m);
        x = (double) p / (double) q;
        char *arr = malloc(sizeof(char) * size);
        double_to_bits(x, arr);
        xor(m, arr);
        char buf[19] = {0};
        for (int i = 0; i < 64; i += 4) {
            buf[i / 4] += arr[i] * 8 + arr[i + 1] * 4 + arr[i + 2] * 2 + arr[i + 3];
        }
        for (int i = 0; i < 16; i++) {
            buf[i] += buf[i] > 9 ? 'a' - 10 : '0';
        }
        for (int i = 17; i >= 1; i--)
            buf[i] = buf[i - 2];
        buf[0] = '0';
        buf[1] = 'x';
        buf[18] = '\0';
        sscanf(buf, "%llx", &m);
        x = *((double *) &m);
        fprintf(out, "%0.15g\n", x);
    }
    fclose(in);
    fclose(out);
    return 0;
}