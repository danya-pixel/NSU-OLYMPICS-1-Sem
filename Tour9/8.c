#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define size 1001

int parseSize(int n) {
    if (n >= 1000000000) return 10;
    else if (n >= 100000000) return 9;
    else if (n >= 10000000) return 8;
    else if (n >= 1000000) return 7;
    else if (n >= 100000) return 6;
    else if (n >= 10000) return 5;
    else if (n >= 1000) return 4;
    else if (n >= 100) return 3;
    else if (n >= 10) return 2;
    else return 1;
}

void printPr(int n) {
    for (int p = 0; p < n; p++) printf(" ");
}

void printLine(int len_id, int len_cnt, int len_sum, int is_last) {
    printf("+");
    for (int p = 0; p < len_id + 2; p++)printf("-");
    printf("+");
    for (int p = 0; p < len_cnt + 2; p++)printf("-");
    printf("+");
    for (int p = 0; p < len_sum + 2; p++)printf("-");
    printf("+");
    if (is_last == 0)printf("\n");
}

int comp(const int *i, const int *j) {
    return *i - *j;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0, max_sum = 0, max_cnt = 0, max_id = 0, cnt_id = 0;
    scanf("%d", &n);
    int ids[size], sum[size], cnt[size];
    for (int i = 0; i < size; i++) {
        ids[i] = -1;
        sum[i] = 0;
        cnt[i] = 0;
    }
    int id = 0, len = 0, new_id = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &id, &len);
        for (int idx = 0; idx < size; idx++) {
            if (ids[idx] == id) break;
            if (ids[idx] == -1) {
                ids[idx] = id;
                cnt_id += 1;
                break;
            }
        }
        max_id = id > max_id ? id : max_id;
        sum[id] += len;
        cnt[id] += 1;
        max_sum = sum[id] > max_sum ? sum[id] : max_sum;
        max_cnt = cnt[id] > max_cnt ? cnt[id] : max_cnt;
    }
    int len_id = parseSize(max_id), len_sum = parseSize(max_sum), len_cnt = parseSize(max_cnt);
    qsort(ids, cnt_id, sizeof(int), (int (*)(const void *, const void *)) comp);
    for (int i = 0; i < cnt_id; i++) {
        printLine(len_id, len_cnt, len_sum, 0);
        printf("| ");
        int cur_id = ids[i];
        printPr(len_id - parseSize(cur_id));
        printf("%d | ", cur_id);
        printPr(len_cnt - parseSize(cnt[cur_id]));
        printf("%d | ", cnt[cur_id]);
        printPr(len_sum - parseSize(sum[cur_id]));
        printf("%d |\n", sum[cur_id]);
    }
    printLine(len_id, len_cnt, len_sum, 1);
    return 0;
}