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
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int maxValue(Node* root)
{

    if (root == NULL) return -1000000;

    int maxLeft=maxValue(root->left);
    int maxRight=maxValue(root->right);
    int max=root->data;
    if (maxLeft > max) max = maxLeft;
    if (maxRight > max) max = maxRight;
    return max;
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
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    int max = maxValue(root);
    printf("%d\n", max);
    freeNode(root);
    return 0;
}