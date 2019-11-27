#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int up(double res)
{
	if (res > 0 && res != (int)res) {
		return (int)res + 1;
	}
	else
		return (int)res;
}
int down(double res)
{
	if (res > 0 || res == (int)res) {
		return (int)res;
	}
	else
		return (int)res - 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	scanf("%d %d", &a, &b);
	double res = (double)a / b;
	int up_ = up(res);
	int down_ = down(res);
	int zero_ = 0;
	if (res > 0) {
		zero_ = down_;
	}
	else
	{
		zero_ = up_;
	}
	int cel = a%b;
	if (cel < 0)
	{
		cel += b;
	}
	printf("%d %d %d %d", down_, up_, zero_, cel);
	return 0;
}