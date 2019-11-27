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
void sort_chose(int* mas, int size)
{
	for (int i = 0; i < size - 1; i++) {
		int min_ind = i;
		for (int j = i + 1; j < size; j++) {
			if (mas[j] < mas[min_ind]) {
				min_ind = j;
			}
		}
		if (min_ind != i) {
			swap(mas+i, mas + min_ind);
			min_ind = i;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int n=0;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort_chose(a, n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	
	return 0;
}