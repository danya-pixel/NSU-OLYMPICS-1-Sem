#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>


int main()
{
	long int k=0, x=0;
	scanf("%d %d", &k, &x);
	if (k <= x || !(x>=0)){
		printf("out of bounds");
	}
	else {
		printf("legal");
	}
	return 0;
}