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


int getHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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

    printf("%d", getHeight(root));
    freeNode(root);
    return 0;
}