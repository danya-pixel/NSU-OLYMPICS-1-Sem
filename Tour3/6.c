#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc((n+1) * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d",  &a[i]);
	}
	int result = a[0], result_l = 0, result_r = 0, buf_sum = 0, pos = -1;
	for (int r = 0; r < n; ++r) {
		buf_sum += a[r];
		if (buf_sum > result) {
			result = buf_sum;
			result_l = pos + 1;
			result_r = r;
		}
		if (buf_sum < 0) {
			buf_sum = 0;
			pos = r;
		}
	}
	printf("%d %d %d", result_l, result_r, result);
	return 0;
}