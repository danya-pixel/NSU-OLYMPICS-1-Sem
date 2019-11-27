#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a <= b) {
		if (a <= c) {
			printf("%d", a);
		}
		else
		{
			printf("%d", c);
		}
	}
	else if (b < a) {
		if (b <= c) {
			printf("%d", b);
		}
		else
		{
			printf("%d", c);
		}
	}
	return 0;
}