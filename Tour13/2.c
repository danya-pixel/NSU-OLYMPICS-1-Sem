#define _CRT_SECURE_NO_WARNINGS
#define GENERATE (node *) malloc(sizeof(node))
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} node;


node *push(node *p, int data, int cur) {
    node *new_el = p;
    new_el = GENERATE;
    new_el->data = data;
    new_el->next = p;
    return new_el;
}


int main() {
    freopen("input.txt", "r", stdin);
    node *head = NULL, *p = NULL;
    int buf, cur = 0;
    scanf("%d", &cur);
    while (scanf("%d", &buf) != EOF) {
        if (head == NULL) {
            head = GENERATE;
            head->data = buf;
            head->next = NULL;
            p = head;
        } else
            p = push(p, buf, cur);
    }
    while (p != NULL) {
        node *b = p;
        if (!(p->next != NULL && p->next->data == cur))
            printf("%d ", p->data);
        p = p->next;
        free(b);
    }
    return 0;
}
