#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	double sum = a * b * c;
	printf("%f", sum);
	return 0;
}