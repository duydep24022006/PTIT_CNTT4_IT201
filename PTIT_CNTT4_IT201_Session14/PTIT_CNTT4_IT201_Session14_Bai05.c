#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
}Node;
typedef struct Stack
{
    Node* top;
}Stack;

Node* createNode(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}
Stack* createStack()
{
    Stack* myStack = (Stack*)malloc(sizeof(Stack));
    myStack->top = NULL;
    return myStack;
}

int push(Stack* myStack, int value)
{
    Node* newNode = createNode(value);
    newNode->next = myStack->top;
    myStack->top = newNode;
}
int peek(Stack* myStack)
{
    if (myStack->top == NULL) return 0;
    return myStack->top->value;
}
int isEmpty(Stack* myStack)
{
    if (myStack->top == NULL) return 1;
    return 0;
}
void printStack(Stack* myStack) {
    if (isEmpty(myStack)) {
        printf("Ngan xep trong\n");
        return;
    }
    Node* temp = myStack->top;

    while (temp != NULL) {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL \n");
}
void freeStack(Stack* myStack)
{
    if (myStack->top == NULL) return;
    Node* temp = myStack->top;
    while (temp != NULL)
    {
        int value = temp->next;
        free(temp);
        temp = value;
    }
}
int main()
{
    Node* myStack = createStack();

    printStack( myStack);
    int top=peek(myStack);
    if(top!=0) printf("%d\n", top);
    freeStack(myStack);
    return 0;
}