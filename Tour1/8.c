#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
void main() {
	int n = 0, kv = 0, p = 0, et = 0, h = 0, kvPerEt = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d%d", &n, &kv, &p, &et, &h);

	et = et + (p - 1) * h;

	kvPerEt = kv / et;
	if (kv % et > 0) kvPerEt++;

	et = n / kvPerEt;
	if (n % kvPerEt > 0) et++;
	p = et / h;
	if (et % h > 0) p++;
	et = et % h;
	if (et == 0) et = h;
	printf("%d %d", p, et);
}