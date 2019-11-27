#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	long int n = 0;
	double x, e, new_x = 0, all=0, step=1, znak = 1;
	char flag = 1;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%lf%lf", &x, &e);
	new_x =  pow(x, step) / step;	
	while (new_x >= e) {
		all += znak * new_x;
		step += 2;
		znak *= -1;
		new_x = pow(x, step) / step;
	}
	all += znak * new_x;
	printf("%.5lf", all);
	return 0;
}