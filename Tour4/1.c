#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

long int NOD(long int a, long int b) {
	while (a != b)
	{
		if (a <= 0 || b <= 0) break;
		if (a < b) b %= a;
		else if (a > b) a %= b;
		
	}
	return max(a, b);
}
int main() {
	freopen("input.txt", "r", stdin);
	long int a, b;
	scanf("%ld%ld", &a, &b);
	printf("%ld", NOD(a, b));
	return 0;
}