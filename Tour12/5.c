#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

#define StringSize 8
#define MaxSize 1000002


typedef struct key_st {
    char str[StringSize];
    struct node *next;
    struct node *prev;
} node;

void push_from(node *head, char *data) {
    if (head->str[0] == 0) {
        for (int i = 0; i < (int) strlen(data); i++) {
            head->str[i] = data[i];
        }
    } else {
        node *newNode = (node *) malloc(sizeof(node));
        for (int i = 0; i < (int) strlen(head->str); i++) {
            newNode->str[i] = head->str[i];
        }
        newNode->str[strlen(head->str)] = 0;
        newNode->prev = (struct node *) head;
        newNode->next = head->next;
        node *buf;
        if (newNode->next != NULL) {
            buf = (node *) newNode->next;
            buf->prev = (struct node *) newNode;
        }
        for (int i = 0; i < (int) strlen(data); i++) {
            head->str[i] = data[i];
        }
        for (int i = (int) strlen(data); i < StringSize; i++) {
            head->str[i] = 0;
        }
        head->next = (struct node *) newNode;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    node *Heads = (node *) malloc(sizeof(node) * MaxSize);
    for (int i = 0; i < MaxSize; i++) {
        Heads[i].prev = NULL;
        Heads[i].next = NULL;
    }
    int n = 0;
    int idx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char buf[StringSize];
        scanf("%d %s", &idx, buf);
        push_from(&Heads[idx], buf);
    }
    for (int i = 0; i < MaxSize; i++) {
        if (Heads[i].str[0] != 0) {
            node *buf = &Heads[i];
            while (buf->next != NULL) {
                buf = (node *) buf->next;
            }
            while (buf->prev != NULL) {
                printf("%d %s\n", i, buf->str);
                buf = (node *) buf->prev;
            }
            printf("%d %s\n", i, buf->str);
        }
    }
    return 0;
}