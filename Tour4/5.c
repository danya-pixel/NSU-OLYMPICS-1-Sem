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
void shakerSort(int* mas, int size)
{
	int left_indx = 0, right_indx = size - 1, flag = 1;
	while (left_indx < right_indx && flag>0)
	{
		flag = 0;
		for (int i = left_indx; i < right_indx; i++)
		{
			if (mas[i] > mas[i+1]) {
				swap(&mas[i + 1], &mas[i]);
				flag = 1;
			}
		}
		right_indx--;
		for (int i = right_indx; i > left_indx; i--) {
			if (mas[i-1] > mas[i]) {
				swap(&mas[i - 1], &mas[i]);
				flag = 1;
			}
		}
		left_indx++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int n=0;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	if (n > 1) shakerSort(a, n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	
	return 0;
}