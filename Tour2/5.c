#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	long int n = 0, new_n = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	while (n != 0) {
		new_n = new_n * 10 + n % 10;
		n = n / 10;
	}
	printf("%d", new_n);
	return 0;
}