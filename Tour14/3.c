#define _CRT_SECURE_NO_WARNINGS
#define GENERATE (tree *) malloc(sizeof(tree))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree {
    int val;
    struct tree *left, *right;
} tree;


void push(tree *root, int val) {

    int cmp = root->val - val;
    if (cmp == 0) return;
    else if (cmp > 0) {
        if (root->left == NULL) {
            tree *new_node = GENERATE;
            new_node->val = val;
            new_node->left = NULL;
            new_node->right = NULL;
            root->left = new_node;
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
            return;
        }
        push(root->right, val);
    }
}



void cntLeaves(tree *root, int *cnt) {

    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            *cnt += 1;
        }
        cntLeaves(root->left, cnt);
        cntLeaves(root->right, cnt);
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    tree *root = (tree *) malloc(sizeof(tree));
    int a = 0;
    scanf("%d", &a);
    root->val = a;
    root->right = NULL;
    root->left = NULL;
    while (scanf("%d", &a) != EOF) {
        push(root, a);
    }
    int cnt = 0;
    cntLeaves(root, &cnt);
    printf("%d", cnt);

    return 0;
}