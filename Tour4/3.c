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
				b[mas[i]-1]++;
			}
		}
	}
	return b;
}
int main() {
	freopen("input.txt", "r", stdin);
	int n=0;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int* b = create_inverse(a, n);
	for (int i = 0; i < n; i++) printf("%d ", b[i]);
	return 0;
}