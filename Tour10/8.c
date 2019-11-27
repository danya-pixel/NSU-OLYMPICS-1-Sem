#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LongNum_s {
    int len; //сколько цифр в числе
    unsigned char arr[500]; //массив десятичных цифр числа
} LongNum;

void init(LongNum *a) {
    a->arr[0] = 1;
    a->len = 1;
}


// b > a
LongNum sum(LongNum *a, LongNum *b) {
    LongNum buf;
    unsigned new = 0;
    for (int i = 0; i < b->len; i++) {
        buf.arr[i] = b->arr[i] + new + (i < a->len ? a->arr[i] : 0);
        new = buf.arr[i] / 10;
        buf.arr[i] %= 10;
    }
    buf.len = b->len;
    if (new != 0) {
        buf.arr[b->len] = new;
        buf.len += 1;
    }
    return buf;
}
void print(LongNum *a)
{
    for(int i=a->len-1;i>=0;i--)
        printf("%d",a->arr[i]);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LongNum a, b, temp;
    init(&a);
    init(&b);
    int n = 0;
    scanf("%d", &n);
    if (n == 1 || n == 2) {
        printf("1");
        return 0;
    }
    for (int i = 2; i < n; i++) {
        temp = sum(&a, &b);
        a = b;
        b = temp;
    }
    print(&b);
    return 0;
}