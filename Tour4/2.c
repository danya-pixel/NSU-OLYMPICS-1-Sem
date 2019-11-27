#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

void Sort_insert(int* mas, int size) {
	for (int i = 0; i < size; ++i) {
		int x = mas[i], j = i;
		while (j > 0 && mas[j - 1] > x) {
			mas[j] = mas[j - 1];
			j--;
		}
		mas[j] = x;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int n=0;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	Sort_insert(a, n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}