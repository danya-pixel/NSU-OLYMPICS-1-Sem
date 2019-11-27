#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int _err() {
	printf("ERROR");
	return 0;
}
const int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
_Bool is_vis(int year)
{
	return (_Bool)((year % 4 == 0 && year % 100) || (year % 400 == 0));
}
int day_in_month(int year, int month)
{
	return months[month - 1] + (int)(month == 2 && is_vis(year));
}
int date_to_day(int y, int m, int d)
{
	if (m < 3)
	{
		y--;
		m += 12;
	}
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
int main() {
	const int days_vis = 366, days_ne_vis = 365;
	freopen("input.txt", "r", stdin);
	int day1, month1, year1, day2, month2, year2;
	scanf("%d%d%d%d%d%d", &day1, &month1, &year1, &day2, &month2, &year2);
	if (day1 > day_in_month(year1, month1) 
		|| day2 > day_in_month(year2, month2) 
		|| month1 <=0 || month1 > 12
		|| month2 <=0 || month2 > 12
		|| year1 <=0  || year1 > 2050
		|| year2 <=0  || year2 > 2050) {
		return _err();
	}
	long int days = date_to_day(year2, month2, day2) - date_to_day(year1, month1, day1);

	printf("%d", abs(days));
	return 0;
}