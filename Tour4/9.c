#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_chose(int *mas, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < size; j++) {
            if (mas[j] < mas[min_ind]) {
                min_ind = j;
            }
        }
        if (min_ind != i) {
            swap(mas + i, mas + min_ind);
        }
    }
}

int *x, *y, size = 0, n = 0, *sorted_array;

_Bool check_fun() {
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; ++j) {
            if (x[i] == x[j] && y[i] != y[j]) return (_Bool) 0;
        }
    return (_Bool) 1;
}

_Bool check_x() {
    sorted_array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) sorted_array[i] = x[i];
    sort_chose(sorted_array, size);
    if (sorted_array[0] != 1 || sorted_array[size - 1] != n) return (_Bool) 0;
    for (int i = 0; i < size; ++i) {
        if (y[i] > n || y[i] < 1 || (i != size - 1 && sorted_array[i + 1] - sorted_array[i] > 1)) return (_Bool) 0;
    }
    return (_Bool) 1;
}

_Bool check_injection() {
    for (int i = 0; i < size - 1; ++i)
        for (int j = i + 1; j < size; ++j) {
            if (y[i] == y[j] && x[i] != x[j]) return (_Bool) 0;
        }
    return (_Bool) 1;
}

_Bool check_sur() {
    for (int i = 0; i < size; ++i) sorted_array[i] = y[i];
    sort_chose(sorted_array, size);
    if (sorted_array[0] != 1 || sorted_array[size - 1] != n) return (_Bool) 0;
    for (int i = 0; i < size - 1; ++i) {
        if (sorted_array[i + 1] - sorted_array[i] > 1) return (_Bool) 0;
    }
    return (_Bool) 1;
}

int main() {
    scanf("%d %d", &n, &size);
    x = (int *) malloc(size * sizeof(int));
    y = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    if (!check_fun()) {
        printf("0");
        return 0;
    }
    printf("1");
    if (check_x())
        printf(" 2");

    _Bool inj = check_injection();
    if (inj)
        printf(" 3");
    _Bool sur = check_sur();
    if (sur)
        printf(" 4");

    if (inj && sur)
        printf(" 5");
    return 0;
}