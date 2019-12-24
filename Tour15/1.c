#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a = 0, b = 0;
    FILE *in_file, *out_file;
    in_file=fopen("input.bin","rb");
    out_file=fopen("output.bin","wb");
    fread(&a, sizeof(int),1,in_file);
    fread(&b, sizeof(int),1,in_file);
    int ans = (int)floor((double)((long long)a + (long long)b) / 2);
    fwrite(&ans, sizeof(ans),1,out_file);
    fclose(in_file);
    fclose(out_file);
    return 0;
}