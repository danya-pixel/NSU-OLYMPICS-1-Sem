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
	int last = 0, cnt_dif = 0;
	
	for (int i = 0; i < n; ++i) {
		if (a[i] != last) {
			cnt_dif += 1;
			last = a[i];
		}
	}
	printf("%d", cnt_dif);

	return 0;
}