#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int main() {
	freopen("input.txt", "r", stdin);
	int n,x;
	scanf("%d%d", &n, &x);
	int* a = (int*)malloc((n+1) * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d",  &a[(i+x)%n]);
	}
	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
	return 0;
}