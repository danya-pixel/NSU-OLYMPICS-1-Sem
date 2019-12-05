#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_size 101
typedef struct tree {
    char data;
    struct tree *left, *right;
} tree;

void prefix(tree *root) {
    if (!root)
        return;
    prefix(root->left);
    prefix(root->right);
    printf("%d ", root->data);
}

tree *generate_tree() {
    return (tree *) malloc(sizeof(tree));
}

_Bool push(tree *root, char data) {
    if (root->data >= '0' && root->data <= '9') {
        return 0;
    }
    int a = 0;
    if (root->left == NULL) {
        root->left = generate_tree();
        root->left->left = NULL;
        root->left->right = NULL;
        root->left->data = data;
        return 1;
    } else {
        a = push(root->left, data);
    }
    if (a == 1)return 1;
    if(root->right == NULL)
    {
        root->right = generate_tree();
        root->right->left = NULL;
        root->right->right = NULL;
        root->right->data = data;
        return 1;
    }else return push(root->right, data);
}

void print(tree *root) {
    if (root == NULL)return;
    else {
        printf("%c ", root->data);
        print(root->left);
        print(root->right);
    }
}

int sum(tree *root) {
    if (root->data >= '0' && root->data <= '9') {
        return root->data - '0';
    }
    int a = sum(root->left);
    int b = sum(root->right);
    switch (root->data) {
        case '+':
            return a + b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                printf("NO");
                exit(0);
            } else
                return a / b;
        case '-':
            return a - b;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    tree *root = generate_tree();
    _Bool is_first = 1;
    char data;
    while (scanf("%c", &data) != EOF) {
        if (is_first) {
            root->data = data;
            root->right = NULL;
            root->left = NULL;
            is_first = 0;
        } else
            push(root, data);
    }
    printf("%d", sum(root));
    return 0;
}