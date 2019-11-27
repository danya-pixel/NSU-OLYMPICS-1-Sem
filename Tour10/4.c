#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Label_s {
    char name[16];
    int age;
} Label;
typedef struct NameStats_s {
    int cntTotal;
    int cntLong;
} NameStats;
typedef struct AgeStats_s {
    int cntTotal;
    int cntAdults;
    int cntKids;
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges) {
    oAges->cntTotal = cnt;
    oNames->cntTotal = cnt;
    for (int i = 0; i < cnt; i++) {
        if (strlen(arr[i].name) > 10)
            oNames->cntLong += 1;
        if (arr[i].age >= 18)
            oAges->cntAdults += 1;
        else if (arr[i].age < 14)
            oAges->cntKids += 1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    Label arr[1000];
    NameStats Ns;
    AgeStats As;
    for (int i = 0; i < n; i++) {
        scanf("%s %d let", arr[i].name, &arr[i].age);
    }
    calcStats(arr, n , &Ns, &As);
    printf("names: total = %d\n", Ns.cntTotal);
    printf("names: long = %d\n", Ns.cntLong);
    printf("ages: total = %d\n", As.cntTotal);
    printf("ages: adult = %d\n", As.cntAdults);
    printf("ages: kid = %d\n", As.cntKids);
    return 0;
}