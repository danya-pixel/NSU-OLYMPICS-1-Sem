#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node *next;
} node;

node *generate_node() {
    return (node *) malloc(sizeof(node));
}

void del_node(node *prev) {
    node *buf = prev->next;
    prev->next = buf->next;
    free(buf);
}

node *push(node *p, int val) {
    node *new_node = generate_node();
    new_node->val = val;
    new_node->next = p;
    return new_node;
}

node *push_back(node *p, int val) {
    node *new_node = generate_node();
    new_node->val = val;
    new_node->next = NULL;
    if (p == NULL) return new_node;
    node *buf = p;
    while (buf->next != NULL) buf = buf->next;
    buf->next = new_node;
    return p;
}

int main() {
    freopen("input.txt", "r", stdin);
    node *head_f = NULL, *head_s = NULL, *p = NULL;
    int n, m = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        head_f = push(head_f, val);
    }
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        head_s = push(head_s, val);
    }
    while (head_f != NULL || head_s != NULL) {
        if (head_f == NULL) {
            p = push_back(p, head_s->val);
            head_s = head_s->next;
        } else if (head_s == NULL) {
            p = push_back(p, head_f->val);
            head_f = head_f->next;
        } else if (head_f->val > head_s->val) {
            p = push_back(p, head_f->val);
            head_f = head_f->next;
        } else {
            p = push_back(p, head_s->val);
            head_s = head_s->next;
        }
    }
    for (node *buf = p; buf!=NULL;buf = buf->next)
        printf("%d ", buf->val);
    return 0;
}