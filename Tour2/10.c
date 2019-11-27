#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int k = 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &k);
	int cur_ch = 0, cnt = 0, buf_ch = 0, answer = 0;
	while (cnt < k) {
		cur_ch += 1;
		buf_ch = cur_ch;

		while (buf_ch > 0) {
			buf_ch /= 10;
			cnt += 1;
		}

	}
	while (cnt >= k) {
		cnt -= 1;
		answer = cur_ch % 10;
		cur_ch /= 10;
	}
	printf("%d ", answer);
	return 0;
}