#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x1, x2, x3, y1, y2, y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	long double l1 = sqrt(((double)x1-x2)*(x1-x2) + (y1 - y2) * (y1 - y2)), 
    l2 = sqrt(((double)x1 - x3)*(x1-x3)+(y1-y3)* (y1 - y3)), 
    l3 = sqrt(((double)x2-x3)*(x2-x3)+ (y2 - y3) * (y2 - y3));
	long double P = l1 + l2 + l3, p=P/2, s = sqrt(p*(p-l1)*(p-l2)*(p-l3));
	printf("%.3lf\n%.3lf", P, s);
	return 0;
}