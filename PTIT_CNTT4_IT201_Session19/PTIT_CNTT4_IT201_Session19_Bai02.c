#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("Memory allocation failed for node.\n");
        return 0;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void freeNode(Node* root)
{
    if(root == NULL) return;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}
int main()
{
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    printf("preorder: ");
    preOrder(root);
    freeNode(root);
    return 0;
}