#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size_char sizeof(unsigned char)*8
#define char_len 8
_Bool need_clear = 0;
typedef struct {
    int size;
    unsigned char *arr;
    int arr_size;
} bitset;

void bitsetZero(bitset *p, int num) {
    p->size = num;
    p->arr_size = (int) ceil((double) ((double) num / char_len));
    if (need_clear) free(p->arr);
    p->arr = (unsigned char *) malloc(p->arr_size * size_char / 8);
    need_clear = 1;
    for (int i = 0; i < p->arr_size; i++) p->arr[i] = 0;
}

int bitsetGet(bitset *p, int idx) {
    int arr_idx = idx / char_len, bit_pos = idx % char_len;
    int buf = p->arr[arr_idx];
    buf >>= char_len - bit_pos - 1;
    return buf & 1 ? 1 : 0;
}

void bitsetSet(bitset *p, int idx, int newval) {
    if (newval == bitsetGet(p, idx)) return;
    int arr_idx = idx / char_len, bit_pos = idx % char_len;
    int delt = (int) pow(2, char_len - bit_pos - 1);
    if (newval == 0) p->arr[arr_idx] -= delt;
    else p->arr[arr_idx] += delt;
}

int bitsetAny(bitset *p, int left, int right) {
    int arr_idx_left = left / char_len, start_bit = left % char_len;
    int arr_idx_right = (int) ceil((double) right / char_len), end_bit = right % char_len;
    for (int i = arr_idx_left; i <= arr_idx_right; i++) {
        int buf = p->arr[i];

        if (buf == 0) {
            start_bit = 0;
            continue;
        }
        for (int z = start_bit + (i) * 8; z < right; z++)
            if (bitsetGet(p, z) == 1) return 1;
        start_bit = 0;
    }
    return 0;
}

int main() {
    int n = 0, t = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    bitset b;
    int len = 0, idx = 0, val = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        switch (t) {
            case 0:
                scanf("%d", &len);
                bitsetZero(&b, len);
                break;
            case 1:
                scanf("%d", &idx);
                printf("%d\n", bitsetGet(&b, idx));
                break;
            case 2:
                scanf("%d%d", &idx, &val);
                bitsetSet(&b, idx, val);
                break;
            case 3:
                scanf("%d%d", &idx, &val);
                if (bitsetAny(&b, idx, val) == 1) printf("some\n");
                else printf("none\n");
                break;
            default:
                break;
        }
    }
    return 0;
}