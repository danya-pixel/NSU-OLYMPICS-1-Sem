#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
    int val;
    int nextIdx;
    int prevIdx;
} node;

void push_top(node *set, int *first, int *last, int *n, int id, int data) {
    if (id == -1) {
        set[*n].nextIdx = *first;
        set[*n].prevIdx = -1;
        set[*first].prevIdx = *n;
        *first = *n;
        if(*last == -1)
            *last = *n;
    } else {
        set[*n].nextIdx = set[id].nextIdx;
        set[*n].prevIdx = id;
        set[id].nextIdx = *n;
        if (set[*n].nextIdx != -1) {
            set[set[*n].nextIdx].prevIdx = *n;
        } else
            *last = *n;
    }
    set[*n].val = data;
    printf("%d\n", *n);
    *n += 1;
}

void push_back(node *set, int *first, int *last, int *n, int id, int data) {
    if (id == -1) {
        set[*n].nextIdx = -1;
        set[*n].prevIdx = *last;
        set[*last].nextIdx = *n;
        *last = *n;
        if(*first == -1)
            *first = *n;
    } else {
        set[*n].prevIdx = set[id].prevIdx;
        set[*n].nextIdx = id;
        set[id].prevIdx = *n;
        if (set[*n].prevIdx != -1) {
            set[set[*n].prevIdx].nextIdx = *n;
        } else
            *first = *n;
    }
    set[*n].val = data;
    printf("%d\n", *n);
    *n += 1;
}

void pop(node *set, int *last, int *first, int id) {
    printf("%d\n", set[id].val);
    if(*last == id)
        *last = set[id].prevIdx;
    if(*first == id)
        *first = set[id].nextIdx;
    if (set[id].prevIdx != -1)
    {
        set[set[id].prevIdx].nextIdx = set[id].nextIdx;
    }
    if (set[id].nextIdx != -1) {
        set[set[id].nextIdx].prevIdx = set[id].prevIdx;
    }
    if (set[id].nextIdx == -1)	
        *last = set[id].prevIdx;	
    if (set[id].prevIdx == -1)	
        *first = set[id].nextIdx;
}


int main() {
    
    int t = 0;
    scanf("%d", &t);
    for (int k = 0; k < t; k++) {
        int first = 0, n = 0, q = 0, last = 0;
        scanf("%d %d %d %d", &n, &first, &last, &q);
        node *arr = (node *)malloc(sizeof(node) * (n + q) + 2);
        for (int i = 0; i < n; i++) {
            scanf("%d ", &arr[i].val);
            scanf("%d %d", &arr[i].nextIdx, &arr[i].prevIdx);
        }
        for (int i = 0; i < q; i++) {
            int id = 0, action = 0;
            scanf("%d %d", &action, &id);
            if (action == 1) {
                int data = 0;
                scanf("%d", &data);
                push_top(arr, &first, &last, &n, id, data);
            } else if (action == -1) {
                int data = 0;
                scanf("%d", &data);
                push_back(arr, &first, &last, &n, id, data);
            } else if (action == 0) {
                pop(arr, &last, &first, id);
            }
        }
        printf("===\n");

        while (first != -1) {
            printf("%d\n", arr[first].val);
            first = arr[first].nextIdx;
        }
        printf("===\n");
    }
}