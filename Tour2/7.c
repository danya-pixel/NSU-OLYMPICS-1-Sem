#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	long int n = 0, min_ = 10001, max_ = -10001, min_indx=-1, max_indx=-1;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int buf = 0;
		scanf("%d", &buf);
		if (buf > max_)
		{
			max_ = buf;
			max_indx = i + 1;
		}
		if (buf < min_) {
			min_ = buf;
			min_indx = i + 1;
		}
	}
	printf("%d %d %d %d", min_, min_indx, max_, max_indx);
	return 0;
}