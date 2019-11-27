#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int* create_inverse(int* mas, int size) {
	int* b = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i) b[i] = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < i; j++) {
			if (mas[j] > mas[i]) {
				b[mas[i] - 1]++;
			}
		}
	}
	return b;
}
int* recover_straight(int* mas, int size) {
	int* b = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i) b[i] = 0;
	int curr = 1;
	for (int i = 0; i < size; i++) {
		int j = 0;
		for (int k = 0; k < size; k++)
		{
			if (b[k] == 0)
			{
				if (j == mas[i]) {
					b[k] = curr;
					break;
				}
				else j++;
			}
		}
		curr++;
	}
	return b;
}
int main() {
	freopen("input.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int* b = recover_straight(a, n);
	int* c = create_inverse(b, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != c[i]) {
			printf("NO");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", b[i]);
	
	return 0;
}