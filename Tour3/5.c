#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	_Bool* a = (_Bool*)malloc((n+1) * sizeof(_Bool));
	for (int i = 2; i <= n; i++) {
		a[i] = 1;
	}
	for (int j = 2; j <= n; j++)
	{
		if (a[j] == (_Bool)0) continue;
		int k = j;
		for (int i = k; i <= n; i+=k) {
			a[i] = (_Bool)0;
		}
		printf("%d ", k);
	}
	return 0;
}