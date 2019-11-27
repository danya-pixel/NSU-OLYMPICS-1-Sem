#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

long long comp(const DateTime *i, const DateTime *j) {
    if (i->year - j->year != 0) return i->year - j->year;
    if (i->month - j->month != 0) return i->month - j->month;
    if (i->day - j->day != 0) return i->day - j->day;
    if (i->hours - j->hours != 0) return i->hours - j->hours;
    if (i->minutes - j->minutes != 0) return i->minutes - j->minutes;
    return i->seconds - j->seconds;
}

DateTime minimum(const DateTime *arr, int cnt) {
    int minId = 0;

    for (int i = 1; i < cnt; i++) {
        if (comp(&arr[i], &arr[minId]) < 0) {
            minId = i;
        }
    }
    return arr[minId];
}

int main() {
    FILE *in = fopen("input.txt", "r");
    int n = 0;
    DateTime *date = malloc(sizeof(DateTime) * 50000);
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(in, "%d %d %d %d %d %d", &date[i].year, &date[i].month, &date[i].day, &date[i].hours, &date[i].minutes,
               &date[i].seconds);
    }
    fclose(in);
    DateTime min = minimum(date, n);
    FILE *out = fopen("output.txt", "w");
    fprintf(out, "%d %d %d %d %d %d", min.year, min.month, min.day, min.hours, min.minutes, min.seconds);
    fclose(out);
    return 0;
}