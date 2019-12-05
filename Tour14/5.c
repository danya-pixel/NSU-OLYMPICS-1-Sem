#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_size 101
typedef struct tree{
    char data[max_size];
    struct tree *left, *right;
}tree;
void prefix(tree *root)
{
    if(!root)
        return;
    prefix(root->left);
    printf("%s", root->data);
    prefix(root->right);
}
tree * generate_tree()
{
    return (tree *) malloc(sizeof(tree));
}
void push(tree *root, char *data)
{

    int cmp = strcmp(root->data, data);
    if(cmp == 0) return;
    else if(cmp > 0)
    {
        if(root->left == NULL)
        {
            tree* new_node = generate_tree();
            strcpy(new_node->data, data);
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
            strcpy(new_node->data, data);
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
        print(root->left);
        printf("%s\n", root->data);
        print(root->right);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    tree *root = generate_tree();
    root->data[0]=0;
    char buf[max_size];
    while (scanf("%s", buf) != EOF) {
        if(root->data[0] == 0)
        {
            strcpy(root->data, buf);
            root->right=NULL;
            root->left=NULL;
        }else
            push(root, buf);
    }
    print(root);
    return 0;
}