#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long int h, m, s, k;
	scanf("%d%d%d%ld", &h, &m, &s, &k);
	s += k;
	m += s / 60;
	s %= 60;
	h += m / 60;
	m %= 60;
	h %= 24;
	printf("%d %d %d", h, m, s);
	return 0;
}