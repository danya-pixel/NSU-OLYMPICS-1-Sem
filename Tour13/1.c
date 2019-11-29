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

node* push(node *p, int data) {
    node *new_el = generate_node();
    if (p != NULL) {
        if (p->data == data)
            return p;
        p->next = new_el;
    }
    p = new_el;
    p->data = data;
    p->next = NULL;
    return p;
}


int main() {
    freopen("input.txt", "r", stdin);
    node *head = NULL, *p= NULL;
    int buf, sum = 0, cnt = 0;
    while (scanf("%d", &buf) != EOF) {
        if (head == NULL) {
            head = generate_node();
            head->data = buf;
            head->next = NULL;
            p = head;
        } else
            p = push(p, buf);
    }
    p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}