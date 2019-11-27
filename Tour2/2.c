#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	int n = 0, sum =0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i+=1) {
		int buf = 0;
		scanf("%d", &buf);
		if (buf % 2 == 0) {
			sum += buf;
		}
	}
	printf("%d", sum);
}