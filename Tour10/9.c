#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ActorBio_s {
    char name[35];
    int BirthYear;
    char country[12];
} ActorBio;
typedef struct ActorInMovie_s {
    char name[32];
    char movie[22];
} ActorInMovie;



_Bool comp(const char *a, const char *b) {
    int l1 = (int) strlen(a);
    int l2 = (int) strlen(b);
    if (l1 != l2) return 0;
    for (int i = 1; i < l1; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d", &n);
    char buf[100];
    gets(buf);
    ActorBio *ab = malloc(sizeof(ActorBio) * n);
    for (int i = 0; i < n; i++) {
        gets(buf);
        int j = 0;
        for (; j < (int) strlen(buf); j++) {
            ab[i].name[j] = buf[j];
            if (j != 0 && buf[j] == '"') break;

        }
        ab[i].name[j] = 0;
        sscanf(&buf[j + 1], "%d", &ab[i].BirthYear);
        j++;
        while(buf[j] != '"') j++;
        int z = 0;
        for(;j<=(int)strlen(buf);j++)
        {
            ab[i].country[z]=buf[j];
            z++;
        }

    }
    scanf("%d", &m);
    gets(buf);
    ActorInMovie *am = malloc(sizeof(ActorInMovie) * m);
    for (int i = 0; i < m; i++) {
        gets(buf);
        int j = 0;
        for (; j < (int) strlen(buf); j++) {
            am[i].name[j] = buf[j];
            if (j != 0 && buf[j] == '"') break;
        }
        am[i].name[j] = 0;
        int z = 0;
        j += 2;
        for (; j < (int) strlen(buf); j++) {
            am[i].movie[z] = buf[j];
            z++;
        }
        am[i].movie[z] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (comp(ab[i].name, am[j].name)) {
                printf("%s\" %d %s %s\" %s\n",
                       ab[i].name, ab[i].BirthYear, ab[i].country, am[j].name, am[j].movie);
            }
        }
    }
    return 0;
}