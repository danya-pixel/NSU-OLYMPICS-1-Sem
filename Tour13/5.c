#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int idx;
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

node *push(node *p) {
    if (p == NULL) {
        p = generate_node();
        p->idx = 1;
        p->next = p;
        return p;
    }
    node *new_node = generate_node();
    new_node->idx = p->idx + 1;
    new_node->next = p->next;
    p->next = new_node;
    return new_node;
}

int main() {
    freopen("input.txt", "r", stdin);
    node *head = NULL, *p = NULL;
    int n, del = 0;
    scanf("%d %d", &n, &del);
    for (int i = 0; i < n; i++) {
        head = push(head);
    }
    while (head->next != head) {
        for (int i = 0; i < del - 1; i++) head = head->next;
        del_node(head);
    }
    printf("%d", head->idx);
    free(head);
    head=NULL;
    return 0;
}
