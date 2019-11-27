#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define n 27
void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void shakerSort(char* mas, int size)
{
    int left_idx = 0, right_idx = size - 1, flag = 1;
    while (left_idx < right_idx && flag > 0)
    {
        flag = 0;
        for (int i = left_idx; i < right_idx; i++)
        {
            if (mas[i] > mas[i+1]) {
                swap(&mas[i + 1], &mas[i]);
                flag = 1;
            }
        }
        right_idx--;
        for (int i = right_idx; i > left_idx; i--) {
            if (mas[i-1] > mas[i]) {
                swap(&mas[i - 1], &mas[i]);
                flag = 1;
            }
        }
        left_idx++;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    char first[n], second[n];
    _Bool flag = 0;
    scanf("%s%s", first, second);
    shakerSort(first, (int) strlen(first));
    for (int i = 0; i < (int) strlen(first); i++) {
        if(strchr(second, first[i]) == NULL)
        {
            printf("%c", first[i]);
            flag = 1;
        }
    }
    if (!flag) printf("Empty Set");
    return 0;
}