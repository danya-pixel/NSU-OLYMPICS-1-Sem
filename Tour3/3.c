#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int comp(const int* i, const int* j)
{
	return *i - *j;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	qsort(a, n ,sizeof(int),comp);
	int last = 0, sum_last = 0;
	
	for (int i = 0; i < n; ++i) {
		if (a[i] != last) {
			if (sum_last != 0) 	printf("%d: %d\n", last, sum_last);
			last = a[i];
			sum_last = 1;
		}
		else {
			sum_last += 1;
		}
	}
	printf("%d: %d", last, sum_last);

	return 0;
}