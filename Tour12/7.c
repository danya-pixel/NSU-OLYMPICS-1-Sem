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
        if (p->data == data)
            return head;
        if (p->data > data) {
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
        sum += p->data;
        cnt++;
        p = p->next;
        free(b);
    }
    printf("%d", sum / cnt);
    return 0;
}