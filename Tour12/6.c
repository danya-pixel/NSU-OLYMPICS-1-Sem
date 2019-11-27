#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} node;

node *generate_node() {
    return (node *) malloc(sizeof(node));
}

void push(node *p, int data) {
    node *new_el = generate_node();
    if (p != NULL) {
        while (p->next != NULL)
            p = p->next;
        p->next = new_el;
    }
    p = new_el;
    p->data = data;
    p->next = NULL;
}

int main() {
    freopen("input.txt", "r", stdin);
    node *head = NULL;
    int buf, sum = 0, cnt = 0;
    while (scanf("%d", &buf) != EOF) {
        if (head == NULL) {
            head = generate_node();
            head->data = buf;
            head->next = NULL;
        } else
            push(head, buf);
    }
    node *p = head;
    while (p != NULL) {
        node *b = p;
        if (p->data < 0 && p->data % 7 == 0)
            cnt++;
        p = p->next;
        free(b);
    }
    printf("%d", cnt);
    return 0;
}