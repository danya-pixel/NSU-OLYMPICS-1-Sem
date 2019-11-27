#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void reverse(int* a, int* b) {
	int cnt = (b - a);
	for (int i = 0; i <= (b - a) / 2; i++)swap(a + i, b - i);
}
void next_step(int* mas, int size) {
	int i = size - 1, j = i;
	while (i > 0 && mas[i - 1] >= mas[i]) i--;
	while (mas[j] <= mas[i-1]) j--;
	swap(&mas[i-1], &mas[j]);
	reverse(&mas[i], &mas[size - 1]);
}
int main() {
	freopen("input.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	next_step(a, n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	
	return 0;
}