#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree {
    int val;
    int lvl;
    struct tree *left, *right;
} tree;


tree *generate_tree() {
    return (tree *) malloc(sizeof(tree));
}

void push(tree *root, int val) {

    int cmp = root->val - val;
    if (cmp == 0) return;
    else if (cmp > 0) {
        if (root->left == NULL) {
            tree *new_node = generate_tree();
            new_node->val = val;
            new_node->left = NULL;
            new_node->right = NULL;
            root->left = new_node;
            new_node->lvl = root->lvl +1;
            return;
        }
        push(root->left, val);
    } else {
        if (root->right == NULL) {
            tree *new_node = generate_tree();
            new_node->val = val;
            root->right = new_node;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->lvl = root->lvl +1;
            return;
        }
        push(root->right, val);
    }
}


void cntHeight(tree *root, int *maxLevel) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL && root->lvl > *maxLevel) {
            *maxLevel = root->lvl;
        }
        cntHeight(root->left, maxLevel);
        cntHeight(root->right, maxLevel);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    tree *root = (tree *) malloc(sizeof(tree));
    _Bool is_first = 1;
    int a = 0;
    while (scanf("%d", &a) != EOF) {
        if (is_first) {
            root->val = a;
            root->right = NULL;
            root->left = NULL;
            root->lvl = 0;
            is_first = 0;
        } else
            push(root, a);
    }
    int lvl = 0;
    cntHeight(root, &lvl);
    printf("%d", lvl);

    return 0;
}