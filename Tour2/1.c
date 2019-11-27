#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	int n = 0, sum =0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		sum += i;
	}
	printf("%d", sum);
}