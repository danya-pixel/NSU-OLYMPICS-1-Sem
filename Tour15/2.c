#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define max_n 10000

int convert(uint32_t num)
{
    uint32_t b0,b1,b2,b3;

    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;

    return (int)(b0 | b1 | b2 | b3);
}

int main() {
    int sum = 0;
    unsigned int n = 0;
    FILE *in_file, *out_file;
    in_file = fopen("input.bin", "rb");
    out_file = fopen("output.bin", "wb");
    fread(&n, sizeof(n), 1, in_file);
    _Bool is_little = 0;
    if(n > max_n)
    {
        n = convert(n);
        is_little = 1;
    }
    unsigned int *buf = (unsigned int *)malloc(sizeof(unsigned int)*n);
    fread(buf, sizeof(buf), n, in_file);
    for(int i =0;i<(int)n;i++)
    {
        if(is_little) buf[i]= convert(buf[i]);
        sum+=buf[i];
    }
    if(is_little)
        sum = convert(sum);
    fwrite(&sum, sizeof(sum), 1, out_file);
    fclose(in_file);
    fclose(out_file);
    return 0;
}