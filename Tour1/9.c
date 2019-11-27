#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long int k;
	scanf("%ld", &k);
	if (k == 1) {
		printf("%ld", 1);
		return 0;
	}
	long float n = floor((-1 + sqrt(1+8*k)) / (float) 2), s=n*(n+1)*0.5;
	if (k-s == 1)
	{
		printf("%ld", 1);
	}
	else
	{
		printf("%ld", 0);
	}
	
	

	return 0;
}