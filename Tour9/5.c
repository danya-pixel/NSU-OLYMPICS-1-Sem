#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define size 1001

int main() {
	FILE* in = fopen("input.txt", "r");
	int i = 0, j = 0;
	unsigned char str[size + 1][size + 1];
	unsigned char x;
	while (fscanf(in, "%c", &x) != EOF) {
		if (x == '\n') {
			str[i][j] = 0;
			i++;
			j = 0;
			continue;
		}
		str[i][j] = x;
		j++;
	}
	str[i][j] = 0;
	fclose(in);
	FILE* out = fopen("output.txt", "w");
	_Bool first = 1;
	for (; i >= 0; i--) {
		if (!first) fprintf(out, "\n");
		for (j = 0; j < size; j++) {
			if (str[i][j] == 0) break;
			fprintf(out, "%c", str[i][j]);
		}
		first = 0;
	}
	fclose(out);
	return 0;
}