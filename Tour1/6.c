#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	if (x <= 0)
	{
		printf("-1");
		return 0;
	}
	else if (y<=0)
	{
		printf("-2");
		return 0;
	}
	else if (z <= 0)
	{
		printf("-3");
		return 0;
	}
	
	printf("%d", x * y * 2 + z * y * 2 + x * z * 2);
	return 0;
}