#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
int main() {
	int a = 0, b = 0, c = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &a, &b, &c);

	if (a != 0) {
		int d = b * b - 4 * a * c;
		if (d < 0) printf("NO");
		else if (d == 0) {
			double ans = (-1) * (double)b / (2 * (double)a);
			printf("1\n%.5lf", ans);
		}
		else {
			double ans1 = ((-1) * b + sqrt(d)) / (2 * (double)a);
			double ans2 = ((-1) * b - sqrt(d)) / (2 * (double)a);
			if (ans1 < ans2) printf("2\n%.5lf %.5lf", ans1, ans2); 
			else printf("2\n%.5lf %.5lf", ans2, ans1);
		}
	}
	else if (b != 0) {
		double ans = (double)c / (double)b * (-1);
		printf("1\n%.5lf", ans);
	}
	else if (c == 0) {
		printf("MANY");
	}
	else printf("ERROR");
	return 0;
}