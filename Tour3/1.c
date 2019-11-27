#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int mas[101];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &mas[i]);
	}
	for (int i = 0; i < n-1; ++i) {
		int cnt=0;
		for (int j = i + 1; j < n; ++j) {
			if (mas[i] > mas[j]) cnt ++;
		}
		printf("%d ", cnt);
	}
	printf("%d", 0);
	return 0;
}