#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
int main() {
    unsigned __int32 len = 0, cnt = 0;
    unsigned __int32 n = 0;
    FILE *in_file, *out_file;
    setlocale(0,""); 
    setlocale(LC_NUMERIC,"C");//чтобы выводилась . в качестве разделителя
    in_file = fopen("input.bin", "rb");
    freopen("output.txt", "w", stdout);
    fread(&len, sizeof(len), 1, in_file);
    cnt += sizeof(len);
    printf("{\n");
    _Bool is_first = 1;
    while (1) {
        unsigned char T;
        fread(&T, sizeof(T), 1, in_file);
        if (T == 0) {
            printf("\n}\n");
            fclose(in_file);
            return 0;
        }
        if (!is_first)printf(",\n    \"");
        else printf("    \"");
        is_first = 0;
        unsigned char buf = 1;
        while (1) {
            fread(&buf, sizeof(buf), 1, in_file);
            if (buf == 0) {
                printf("\": ");
                break;
            }
            printf("%c", buf);
        }
        switch (T) {
            case 1: {
                double t;
                fread(&t, sizeof(t), 1, in_file);
                printf("%0.15g", t);
                break;
            }
            case 2: {
                __int32 l;
                fread(&l, sizeof(l), 1, in_file);
                int cnt_ = 0;
                printf("\"");
                while (cnt_ < l)
                {
                    fread(&buf, sizeof(char), 1, in_file);
                    cnt += sizeof(char);
                    if (buf==0)
                        break;
                    printf("%c", buf);
                }
                printf("\"");
                break;
            }
            case 8: {
                unsigned char bool;
                fread(&bool, sizeof(bool), 1, in_file);
                if (bool)
                    printf("true");
                else
                    printf("false");
                break;
            }
            case 10: {
                printf("null");
                break;
            }
            case 16: {
                __int32 a;
                fread(&a, sizeof(a), 1, in_file);
                printf("%d", a);
                break;
            }
            case 18: {
                __int64 a;
                fread(&a, sizeof(a), 1, in_file);
                printf("%lld", a);
                break;
            }
        }
    }
    fclose(in_file);
    return 0;
}