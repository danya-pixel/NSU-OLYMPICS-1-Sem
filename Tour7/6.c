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
    int n = 0, t = 0, m = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    bitset b;
    int idx = 0, val = 0;
    bitsetZero(&b, n * (int) sizeof(int) * 8);
    for (int id = 0; id < n; id++) {
        int buf = 0;
        scanf("%d", &buf);
        for (int i = (int) sizeof(int) * 8 - 1; i >= 0; i--) {
            bitsetSet(&b, i+(id*(int)sizeof(int) * 8) , buf & 1);
            buf >>= 1;
        }
    }
    for (int id = 0; id < m; id++) {
        scanf("%d%d", &val, &idx);
        bitsetSet(&b, idx, val);
    }
    int ch=0;
    for (int i = 0; i < (int)b.arr_size; i++) {
        if(i % sizeof(int) == 0)
        {
            if (i!=0) printf("%d ", ch);
            ch = 0;
        }
        ch<<=char_len;
        ch+=b.arr[i];
    }
    printf("%d", ch);
    return 0;
}