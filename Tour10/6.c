#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define err if (oHours != NULL) *oHours = -1;\
if (oMinutes != NULL) *oMinutes = -1;\
if (oSeconds != NULL) *oSeconds = -1;\
return 0;
#define size 101

_Bool validate(char *str) {
    for (int i = 0; i < (int)strlen(str); i++) {
        if (str[i] == 124) return 0;
    }
    return 1;
}

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds) {
    if (oHours != NULL) *oHours = -1;
    if (oMinutes != NULL) *oMinutes = -1;
    if (oSeconds != NULL) *oSeconds = -1;
    if (!validate(iStr)) { err }
    if (oMinutes != NULL) {
        if (oSeconds != NULL)
            sscanf(iStr, "%d:%d:%d", oHours, oMinutes, oSeconds);
        else
            sscanf(iStr, "%d:%d", oHours, oMinutes);
    } else sscanf(iStr, "%d", oHours);
    if ((oHours == NULL || *oHours == -1)
        && (oMinutes == NULL || *oMinutes == -1)
        && (oSeconds == NULL || *oSeconds == -1)) { err }

    if (oHours != NULL && *oHours == -1) *oHours = 0;
    if (oMinutes != NULL && *oMinutes == -1) *oMinutes = 0;
    if (oSeconds != NULL && *oSeconds == -1) *oSeconds = 0;
    if (oHours != NULL && (*oHours >= 24 || *oHours < 0)) { err }
    if (oMinutes != NULL && (*oMinutes >= 60 || *oMinutes < 0)) { err }
    if (oSeconds != NULL && (*oSeconds >= 60 || *oSeconds < 0)) { err }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int h = -1, m = -1, s = -1;
    char str[size];
    gets(str);
    int stat = readTime(str, &h, &m, &s);
    printf("%d %d %d %d\n", stat, h, m, s);
    if (stat == 0)
    {
        printf("0 -1 -1\n0 -1");
        return 0;
    }
    stat = readTime(str, &h, &m, NULL);
    printf("%d %d %d\n", stat, h, m);
    if(stat == 0)
    {
        printf("0 -1");
        return 0;
    }

    stat = readTime(str, &h, NULL, NULL);
    printf("%d %d\n", stat, h);
    return 0;
}