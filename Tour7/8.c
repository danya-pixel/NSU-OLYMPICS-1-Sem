#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size_char sizeof(unsigned char)*8
#define char_len 8
_Bool need_clear = 0;
typedef struct {
    unsigned char *arr;
    unsigned char *cnt;
} bitset;

int my_ceil(double n) {
    return (n - (int) n > 0) ? (int)n + 1 : (int)n;
}
int my_floor(double n)
{
    return (int)n;
}

int mypow(int n) {
    switch (n) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 8;
        case 4:
            return 16;
        case 5:
            return 32;
        case 6:
            return 64;
        case 7:
            return 128;
        default:
            return (int) pow((double) 2, n);
    }

}

void bitsetZero(bitset *p, int num) {
    int arr_size = my_ceil((double) ((double) num / char_len));
    if (need_clear) {
        free(p->arr);
        free(p->cnt);
    }
    p->arr = (unsigned char *) malloc(arr_size * size_char / 8);
    p->cnt = (unsigned char *) malloc(arr_size * size_char / 8);
    need_clear = 1;
    for (int i = 0; i < arr_size; i++) {
        p->arr[i] = 0;
        p->cnt[i] = 0;
    }
}

int bitsetGet(bitset *p, int idx) {
    int arr_idx = idx / char_len, bit_pos = idx % char_len;
    int buf = p->arr[arr_idx];
    buf >>= char_len - bit_pos - 1;
    return buf & 1 ? 1 : 0;
}

void bitsetSet(bitset *p, int idx, int newval) {
    //if (newval == bitsetGet(p, idx)) return;
    int arr_idx = idx / char_len, bit_pos = idx % char_len;
    int delt = (int) pow(2, char_len - bit_pos - 1);
    int buf = p->arr[arr_idx];
    buf >>= char_len - bit_pos - 1;
    if (buf & 1) {
        if (newval == 0) {
            p->arr[arr_idx] -= delt;
            p->cnt[arr_idx] -= 1;
        }
    } else if (newval == 1) {
        p->arr[arr_idx] += delt;
        p->cnt[arr_idx] += 1;
    }
}

int bitsetAny(bitset *p, int left, int right) {
    int arr_idx_left = left / char_len, start_bit = left % char_len;
    int arr_idx_right = my_ceil((double) right / char_len), end_bit = right % char_len;
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

void bitsetSetSeg(bitset *p, int left, int right, int newval) {
    int arr_idx_left = left / char_len, start_bit = left % char_len;
    int arr_idx_right = my_floor((double) right / char_len), end_bit = right % char_len;
    for (int i = arr_idx_left + 1; i < arr_idx_right; i++) {
        p->arr[i] = newval * 255;
        p->cnt[i] = char_len * newval;
    }
    unsigned char buf = p->arr[arr_idx_left], delt = 0;
    unsigned char buf2 = p->arr[arr_idx_right];
    buf <<= start_bit;
    buf2 >>= char_len - end_bit;
    _Bool run1 = 1, run2 = 1;
    for (int i = 0; i < char_len && (run1 || run2); i++) {
        if (run1
            && i < char_len - start_bit
            && (arr_idx_left != arr_idx_right || i < end_bit - start_bit)) {
            delt = mypow(char_len - i - 1 - start_bit);
            if (buf & 128) {
                if (newval == 0) {
                    p->arr[arr_idx_left] -= delt;
                    p->cnt[arr_idx_left] -= 1;
                }
            } else if (newval == 1) {
                p->arr[arr_idx_left] += delt;
                p->cnt[arr_idx_left] += 1;
            }
            buf <<= 1;
        } else run1 = 0;
        if (run2 && arr_idx_left != arr_idx_right && i < end_bit) {
            delt = mypow(char_len - end_bit + i);
            if (buf2 & 1) {
                if (newval == 0) {
                    p->arr[arr_idx_right] -= delt;
                    p->cnt[arr_idx_right] -= 1;
                }
            } else if (newval == 1) {
                p->arr[arr_idx_right] += delt;
                p->cnt[arr_idx_right] += 1;
            }
            buf2 >>= 1;
        } else run2 = 0;
    }
/*
    for (int i = 0; i < char_len - start_bit && (arr_idx_left != arr_idx_right || i < end_bit - start_bit); i++) {
        delt = mypow(char_len - i - 1 - start_bit);
        if (buf & 128) {
            if (newval == 0)
                p->arr[arr_idx_left] -= delt;
        } else if (newval == 1)
            p->arr[arr_idx_left] += delt;
        buf <<= 1;
    }

    if (arr_idx_left != arr_idx_right) {
        buf = p->arr[arr_idx_right];
        buf >>= char_len - end_bit;
        for (int i = 0; i < end_bit; i++) {
            delt = mypow(char_len - end_bit + i);
            if (buf & 1) {
                if (newval == 0)
                    p->arr[arr_idx_right] -= delt;
            } else if (newval == 1)
                p->arr[arr_idx_right] += delt;
            buf >>= 1;
        }
    }*/


}

int bitsetCount(bitset *p, int left, int right) {
    int arr_idx_left = left / char_len, start_bit = left % char_len;
    int arr_idx_right = my_floor((double) right / char_len), end_bit = right % char_len;
    int cnt = 0;
    for (int i = arr_idx_left + 1; i < arr_idx_right; i++) {
        /*unsigned char buf = p->arr[i];
        for (int bit = 0; bit < char_len; bit++) {
            if (buf == 0) break;
            if (buf & 1) cnt++;
            buf >>= 1;
        }*/
        cnt += p->cnt[i];
    }
    unsigned char buf = p->arr[arr_idx_left];
    unsigned char buf2 = p->arr[arr_idx_right];
    _Bool run1 = 1, run2 = 1;
    if (buf == 0) run1 = 0;
    else buf <<= start_bit;
    if (buf2 == 0) run2 = 0;
    else buf2 >>= char_len - end_bit;
    for (int i = 0; i < char_len && (run1 || run2); i++) {
        if (run1) {
            if (i < char_len - start_bit
                && (arr_idx_left != arr_idx_right || i < end_bit - start_bit)) {
                if (buf == 0) run1 = 0;
                else {
                    if (buf & 128) cnt++;
                    buf <<= 1;
                }
            } else run1 = 0;
        }
        if (run2) {
            if (arr_idx_left != arr_idx_right) {
                if (buf2 == 0) run2 = 0;
                else {
                    if (buf2 & 1) cnt++;
                    buf2 >>= 1;
                }
            } else run2 = 0;
        }

    }
    return cnt;
}

int main() {
    int n = 0, t = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    bitset b;
    int len = 0, idx = 0, val = 0, left = 0, right = 0;
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
                scanf("%d%d%d", &left, &right, &val);
                bitsetSetSeg(&b, left, right, val);
                break;
            case 4:
                scanf("%d%d", &left, &right);
                printf("%d\n", bitsetCount(&b, left, right));
            default:
                break;
        }
    }
    return 0;
}