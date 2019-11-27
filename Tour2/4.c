#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	int n = 0, cnt = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		cnt = 0;
		for (int j = 2; j <= sqrt(i); ++j) {
			if (i % j == 0)
			{
				cnt += 1;
				break;
			}
		}
		if (cnt == 0) printf("%d ", i);
	}

	return 0;
}