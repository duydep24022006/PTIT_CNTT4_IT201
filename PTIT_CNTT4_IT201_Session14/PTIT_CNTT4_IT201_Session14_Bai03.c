#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int value;
    struct Node *next;
}Node;
typedef struct Stack
{
    Node *top;
}Stack;
Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
Stack* createStack()
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;

}

int isEmpty(Stack* myStack)
{
    return myStack->top == NULL ? 1 : 0;

}
void push(Stack* myStack, int value)
{
    Node* newNode = createNode(value);
    newNode->next = myStack->top;
    myStack->top = newNode;
}
int pop(Stack* myStack)
{
    if (isEmpty(myStack)) return -1;
    Node* temp = myStack->top;

    int data = temp->value;
    myStack->top = temp->next;
    free(temp);
    return data;
}
int peek(Stack* myStack)
{
    if (isEmpty(myStack)) return -1;
    return myStack->top->value;
}

void printStack(Stack* myStack) {
    if (isEmpty(myStack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = myStack->top;

    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

void freeStack(Stack* myStack)
{
    if (isEmpty(myStack))
    {
        printf("ngan xep trong.\n");
        return;
    }
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
    freeStack( myStack);
    return 0;
}