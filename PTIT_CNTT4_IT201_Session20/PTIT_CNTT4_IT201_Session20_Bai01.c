#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed for Node");
        return 0;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void freeNode(Node* root)
{
    if(root == NULL) return;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}
void postorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}



int main(){
    Node* root = NULL;
    int n;
    scanf("%d",&n);
    root = createNode(n);
    freeNode(root);
    return 0;
}