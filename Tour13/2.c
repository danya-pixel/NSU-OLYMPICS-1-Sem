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

node *push(node *p, int data, int cur) {
    node *new_el = p;
    new_el = generate_node();
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
            head = generate_node();
            head->data = buf;
            head->next = NULL;
            p = head;
        } else
            p = push(p, buf, cur);
    }
    while (p != NULL) {
        if (p->next != NULL && p->next->data == cur)
        {
            node *b = p;
            p = p->next;
            free(b);
            continue;
        }
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}
