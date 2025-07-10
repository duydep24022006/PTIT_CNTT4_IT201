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
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

Stack* createStack()
{
    Stack* myStack = (Stack*)malloc(sizeof(Stack));
    myStack->top = NULL;
    return myStack;
}

int isStackEmpty(Stack* myStack)
{
    if (myStack->top == NULL) return 1;
    return 0;
}

int peek(Stack* myStack)
{
    return myStack->top->value;
}

int pop(Stack* myStack)
{
    if (myStack->top == NULL) return -1;
    Node* temp = myStack->top;
    myStack->top = myStack->top->next;
    free(temp);
    return myStack->top->value;
}

void push(Stack* myStack, int value)
{
    Node* newNode= createNode(value);
    newNode->next = myStack->top;
    myStack->top = newNode;
}

void printStack(Stack* myStack)
{
    if (myStack->top == NULL) return;
    Node* temp = myStack->top;
    while (temp != NULL)
    {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeStack(Stack* myStack)
{
    if (isStackEmpty(myStack)) return;
    Node* temp = myStack->top;
    while (temp != NULL)
    {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(myStack);
}

int main()
{
    Node* myStack = createStack();
    push(myStack, 50);
    push(myStack, 40);
    push(myStack, 30);
    push(myStack, 20);
    push(myStack, 10);

    printStack(myStack);
    pop(myStack);
    printStack(myStack);

    freeStack(myStack);

    return 0;
}