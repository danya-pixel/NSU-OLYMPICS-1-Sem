#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

unsigned long NOD(long int a, long int b) {
	while (a != b)
	{
		if (a <= 0 || b <= 0) break;
		if (a < b) b %= a;
		else if (a > b) a %= b;

	}
	return max(a, b);
}
int main() {
	freopen("input.txt", "r", stdin);
	int n;
	unsigned long long a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%llu%llu", &a, &b);
		printf("%llu\n", a / NOD(a, b) * b);
	}
	return 0;
}