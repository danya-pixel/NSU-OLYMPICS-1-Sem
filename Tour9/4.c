#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define size 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_chose(int *mas, int size_) {
    for (int i = 0; i < size_ - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < size_; j++) {
            if (mas[j] < mas[min_ind]) {
                min_ind = j;
            }
        }
        if (min_ind != i) {
            swap(mas + i, mas + min_ind);
            min_ind = i;
        }
    }
}


int main() {
    FILE *in = fopen("input.txt", "r");
    int x = 0, i = 0;
    int arr[size] = {0};
    while (fscanf(in, "%d", &x) != EOF) {
        arr[i] = x;
        i++;
    }
    fclose(in);
    sort_chose(arr,i);
    FILE *out = fopen("output.txt", "w");
    if (i <= 1)
    {
        fprintf(out, "NO");
        return 0;
    }
    int delt=arr[1]-arr[0];
    for(int j=1;j<i-1;j++)
    {
        if (delt != arr[j+1]-arr[j])
        {
            fprintf(out, "NO");
            return 0;
        }
    }
    fprintf(out, "%d", delt);
    fclose(out);
    return 0;
}