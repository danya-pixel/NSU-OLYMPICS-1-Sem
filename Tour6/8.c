#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>


int main() {
	freopen("input.txt", "r", stdin);
	char buf[1001], buf2[1001];
	long long  first[1001], second[1001], answer[3000];
	scanf("%s", buf);
	int size_first = (int)strlen(buf);
	for (int i = (int)strlen(buf) - 1; i >= 0; i--)
		first[size_first - 1 - i] = (int)(buf[i] - '0');
	scanf("%s", buf2);
	int size_second = (int)strlen(buf2);
	for (int i = (int)strlen(buf2) - 1; i >= 0; i--)
		second[size_second - 1 - i] = (int)(buf2[i] - '0');
	int length = size_first + size_second + 1;
	for (int first_i = 0; first_i < size_first; first_i++)
		for (int second_i = 0; second_i < size_second; second_i++)
			answer[first_i + second_i] += first[first_i] * second[second_i];
	for (int i = 0; i < length; i++) {
		answer[i + 1] += answer[i] / 10;
		answer[i] = (answer[i]) % 10;
	}
	while (answer[length] == 0)
		length--;
	for (int i = length; i >= 0; i--)printf("%lld", answer[i]);
	return 0;
}