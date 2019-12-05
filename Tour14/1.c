#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_size 101
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;
void prefix(tree *root)
{
    if(!root)
        return;
    prefix(root->left);
    prefix(root->right);
    printf("%d ", root->data);
}
tree * generate_tree()
{
    return (tree *) malloc(sizeof(tree));
}
void push(tree *root, int data)
{

    int cmp = root->data - data;
    if(cmp == 0) return;
    else if(cmp > 0)
    {
        if(root->left == NULL)
        {
            tree* new_node = generate_tree();
            new_node->data = data;
            new_node->left=NULL;
            new_node->right=NULL;
            root->left = new_node;
            return;
        }
        push(root->left, data);
    } else
    {
        if(root->right == NULL)
        {
            tree* new_node = generate_tree();
            new_node->data = data;
            root->right = new_node;
            new_node->left=NULL;
            new_node->right=NULL;
            return;
        }
        push(root->right, data);
    }
}
void print(tree* root)
{
    if(root==NULL)return;
    else
    {
        printf("%d ", root->data);
        print(root->left);
        print(root->right);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    tree *root = generate_tree();
    _Bool is_first = 1;
    int data ;
    while (scanf("%d", &data) != EOF) {
        if(is_first)
        {
            root->data = data;
            root->right=NULL;
            root->left=NULL;
            is_first = 0;
        }else
            push(root, data);
    }
    print(root);
    printf("\n");
    prefix(root);
    return 0;
}