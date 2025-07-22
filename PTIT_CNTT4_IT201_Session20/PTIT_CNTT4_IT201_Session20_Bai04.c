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

int countLeafs(Node* root)
{

    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
    {

        return 1;
    }

    return countLeafs(root->left)+ countLeafs(root->right);
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
    int count = countLeafs(root);
    printf("%d\n", count);
    freeNode(root);
    return 0;
}