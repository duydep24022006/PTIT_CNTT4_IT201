#include <stdio.h>
#include <stdlib.h>

 typedef struct Node
 {
     int data;
     struct Node* next;
 }Node;
typedef struct Stack
{
    Node* top;
} Stack;

int isEmpty(Stack* myStack)
{
     return myStack->top == NULL;
}


Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Stack* createStack()
{
    Stack* myStack = (Stack*)malloc(sizeof(Stack));
    myStack->top = NULL;
    return myStack;
}

void push(Stack* myStack, int value)
{

    Node* newNode=createNode(value);
    newNode->next = myStack->top;
    myStack->top=newNode;
}
int pop(Stack* myStack)
{
    if (isEmpty(myStack)) return-1;
    Node* temp = myStack->top;

    int data = temp->data;
    myStack->top = temp->next;
    free(temp);
    return data;
}

int peek(Stack* myStack)
{
    if (isEmpty(myStack)) return -1;
    return myStack->top->data;
}
void printStack(Stack* myStack) {
    if (isEmpty(myStack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = myStack->top;

    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void freeStack(Stack* myStack)
{
    if (isEmpty(myStack)) return;
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
    Stack* myStack = createStack();

    push(myStack, 50);
    push(myStack, 40);
    push(myStack, 30);
    push(myStack, 20);
    push(myStack, 10);


    printStack( myStack);

    int value;
    printf("value: ");
    scanf("%d", &value);
    push(myStack, value);
    printStack( myStack);
    freeStack(myStack);
    return 0;
}