#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

#define StringSize 8
#define MaxSize 1000001


typedef struct node_st {
    char str[StringSize];
    int next;
} node;

node generate_node(char *data) {
    node *buf = malloc(sizeof(node));
    strcpy(data, buf->str);
    return *buf;
}

void push(node *arr, int id, int *f, int *max_id) {
    *max_id += 1;
    char str[StringSize];
    scanf("%s", str);
    if (id == -1) {
        arr[*max_id] = generate_node(str);
        arr[*max_id].next = *f;
        *f = *max_id;
    } else {
        arr[*max_id] = generate_node(str);
        arr[*max_id].next = arr[id].next;
        arr[id].next = *max_id;
    }
    printf("%d\n", *max_id);
}

void del(node *arr, int id, int *f, int *max_id) {
    int buf = *f;
    if (id == -1) {
        *f = arr[*f].next;
    } else {
        buf = arr[id].next;
        arr[id].next = arr[buf].next;
    }
    printf("%s\n", arr[buf].str);
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int n, f, q, max_id;
        node *arr = (node *) malloc(sizeof(node) * MaxSize);
        scanf("%d%d%d", &n, &f, &q);
        for (int i = 0; i < n; i++) {
            char str[StringSize];
            int next = 0;
            scanf("%s %d", str, &next);
            arr[i] = generate_node(str);
            arr[i].next = next;
        }
        max_id = n - 1;
        for (int i = 0; i < q; i++) {
            int action, id;
            scanf("%d %d", &action, &id);
            if (action == 0) {
                push(arr, id, &f, &max_id);
            } else if (action == 1) {
                del(arr, id, &f, &max_id);
            }
        }
        printf("===\n");
        while(f != -1)
        {
            printf("%s\n", arr[f].str);
            f = arr[f].next;
        }

        printf("===\n");

        free(arr);  
    }
    return 0;
}