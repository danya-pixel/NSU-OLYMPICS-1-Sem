#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	long int n = 0,  min_indx=-1;
	double min_ = 10001;
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double buf = 0, min_razn = 0;
		scanf("%lf", &buf);

		if (buf - round(buf) <= 0) {
			min_razn = round(buf) - buf;
		}
		else min_razn = buf - round(buf);
		if (min_razn < min_) {
			min_ = min_razn;
			min_indx = i + 1;
		}
	}
	printf("%d", min_indx);
	return 0;
}