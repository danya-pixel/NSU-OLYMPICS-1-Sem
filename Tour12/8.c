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

node *push_into(node *head, int data) {
    node *p = head, *last = NULL;
    if (p == NULL) {
        node *new_el = generate_node();
        new_el->data = data;
        new_el->next = NULL;
        head = new_el;
        return new_el;
    }

    while (1) {
        if(p->data == data)
            return head;
        if (p->data > data)
        {
            break;
        }
        last = p;
        p = p->next;
        if (p == NULL) break;
    }

    node *new_el = generate_node();
    new_el->data = data;
    new_el->next = p;
    if (last != NULL)
        last->next = new_el;
    else
        head = new_el;
    return head;
}

int main() {
    freopen("input.txt", "r", stdin);
    node *head = NULL;
    int buf;
    while (scanf("%d", &buf) != EOF) {
        head = push_into(head, buf);
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}