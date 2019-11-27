#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	long int n = 0, cnt_plus = 0, cnt_minus = 0, cnt_zero = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int buf;
		scanf("%d", &buf);
		if (buf == 0) {
			cnt_zero += 1;
		}
		else if (buf < 0) 
		{
			cnt_minus += 1;
		}
		else
		{
			cnt_plus += 1;
		}
		
	}
	printf("%.5lf %.5lf %.5lf", (double)cnt_minus/n, (double)cnt_zero/n, (double)cnt_plus/n  );
	return 0;
}