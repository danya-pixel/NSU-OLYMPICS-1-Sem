#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int min_(int a, int b) {
	return (int)(a > b) * b + (int)(!(a > b)) * a;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, x;
	scanf("%d%d", &n, &x);
	double* a = (double*)malloc((n) * sizeof(double));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	if (x <= a[0])
	{
		printf("%d", 0);
		return 0;
	}
	else if (x >= a[n - 1])
	{
		printf("%d", n-1);
		return 0;
	}
	int l = 0, r = n-1, mid, last_l = -1, last_r = -1;

	while (l <= r) {
		mid = (r + l) / 2;
		double t_m = a[mid] - x;
		if (t_m > 0) {
			r = mid - 1;
		}
		else if (t_m < 0) {
			l = mid + 1;
		}
		else
		{
			printf("%d", mid);
			return 0;
		}

	}
	if (fabs(a[l] - x) > fabs(a[r] - x)) {
		printf("%d", r);
	}
	else if (fabs(a[l] - x) < fabs(a[r] - x)) {
		printf("%d", l);
	}
	else {
		printf("%d", min_(l, r));
	}

	return 0;
}