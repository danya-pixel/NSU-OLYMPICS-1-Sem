#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int comp(const int* i, const int* j)
{
	return *i - *j;
}
int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n,x;
	scanf("%d%d", &n, &x);
	int* a = (int*)malloc((n+1) * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d",  &a[i]);
	}
	int l = 0, r = n, mid;
	while (l <= r) {
		mid = (r + l) / 2 ;
		if (a[mid] > x) {
			r = mid - 1;
		}
		else if (a[mid] < x) {
			l = mid + 1;
		}
		else
		{
			printf("%d", mid);
			return 0;
		}
	}
	printf("-1");
	return 0;
}