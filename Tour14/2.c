#define _CRT_SECURE_NO_WARNINGS
#define GENERATE (tree *)malloc(sizeof(tree))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree {
    int val;
    int lvl;
    struct tree *left, *right;
} tree;


void push(tree *root, int val) {
    if (root->val == val) return;
    if (root->val > val) {
        if (root->left == NULL) {
            tree *new_node = GENERATE;
            new_node->val = val;
            new_node->left = NULL;
            new_node->right = NULL;
            root->left = new_node;
            new_node->lvl = root->lvl + 1;
            return;
        }
        push(root->left, val);
    } else {
        if (root->right == NULL) {
            tree *new_node = GENERATE;
            new_node->val = val;
            root->right = new_node;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->lvl = root->lvl + 1;
            return;
        }
        push(root->right, val);
    }
}


void cntHeight(tree *root, int *maxLevel) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL && root->lvl > *maxLevel) {
            *maxLevel = root->lvl;
            return;
        }
        cntHeight(root->left, maxLevel);
        cntHeight(root->right, maxLevel);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    tree *root = GENERATE;
    int a = 0;
    scanf("%d", &a);
    root->val = a;
    root->right = NULL;
    root->left = NULL;
    root->lvl = 0;
    while (scanf("%d", &a) != EOF) {
        push(root, a);
    }
    int lvl = 0;
    cntHeight(root, &lvl);
    printf("%d", lvl);
    return 0;
}