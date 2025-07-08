#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int maxSize)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack==NULL)
    {
        return NULL;
    }

    stack->arr = (int*)malloc(maxSize*sizeof(int));
    if (stack->arr==NULL)
    {
        free(stack);
        return NULL;
    }
    stack->top=-1;
    stack->capacity=maxSize;
    return stack;
}

int isFull(Stack* stack)
{
    if (stack->top==stack->capacity-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Stack* stack)
{
    if (stack->top==-1) return 1;

    return 0;
}

int push(Stack* stack, int value)
{
    if (isFull(stack))
    {
        return 0;
    }

    stack->top++;
    stack->arr[stack->top]=value;
    return 1;
}

int pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}
int peek(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;

    }
    return stack->arr[stack->top];

}

int  isMatchingPair(char* str)
{
    int len=strlen(str);
    if (len==0) return 0;
    Stack* stack = createStack(len);

    for (int i=0; i<len; i++)
    {
        push(stack, str[i]);
    }
    int parentheses=0,squareBrackets=0,Braces=0;
    for (int i=0; i<len; i++)
    {
        char popValue=pop(stack);
        if (popValue=='('||popValue==')') parentheses++;
        if (popValue=='['||popValue==']') squareBrackets++;
        if (popValue=='{'||popValue=='}') Braces++;
    }
    return squareBrackets+parentheses+Braces;

}
int main()
{
    char str[1000];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (isMatchingPair( str)%2==0) printf("true\n");
    else printf("false\n");
    return 0;
}