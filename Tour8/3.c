#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_len 200

void main_el(int k, double** mas, int n, int* ans);
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	double mas[max_len][max_len + 1], x[max_len];
	int order[max_len], n = 0;


	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++)
			scanf("%lf", &mas[i][j]);
	for (int i = 0; i < n + 1; i++)
		order[i] = i;
	for (int k = 0; k < n; k++) {
		main_el(k, (double**)mas, n, order);
		for (int j = n; j >= k; j--)
			mas[k][j] /= mas[k][k];
		for (int i = k + 1; i < n; i++)
			for (int j = n; j >= k; j--)
				mas[i][j] -= mas[k][j] * mas[i][k];
	}
	for (int i = 0; i < n; i++)
		x[i] = mas[i][n];
	for (int i = n - 2; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
			x[i] -= x[j] * mas[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == order[j]) {
				printf("%lf\n", x[j]);
				break;
			}
	return (0);
}

void main_el(int k, double mas[][max_len+1], int n, int* ans) {
	int max_i = k, j_max = k;
	for (int i = k; i < n; i++)
		for (int j = k; j < n; j++)
			if (fabs(mas[max_i][j_max]) < fabs(mas[i][j])) {
				max_i = i;
				j_max = j;
			}
	for (int j = k; j < n + 1; j++) {
		double buf = mas[k][j];
		mas[k][j] = mas[max_i][j];
		mas[max_i][j] = buf;
	}
	for (int i = 0; i < n; i++) {
		double buf = mas[i][k];
		mas[i][k] = mas[i][j_max];
		mas[i][j_max] = buf;
	}
	swap(&ans[k], &ans[j_max]);
}