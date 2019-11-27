#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	int n = 0, cnt = 0;

	scanf("%d", &n);
	if (n == 1)
	{
		printf("NO");
		return 0;
	}
	
	for (int i = 2; i <= sqrt(n); i+=1) {
		if (n % i == 0) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}