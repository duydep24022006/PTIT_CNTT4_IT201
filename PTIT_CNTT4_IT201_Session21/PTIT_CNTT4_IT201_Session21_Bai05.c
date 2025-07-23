#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addNode(Node* graph[], int startNode,int endNode)
{
    Node* newNode=createNode(endNode);
    newNode->next=graph[startNode];
    graph[startNode] = newNode;

    newNode=createNode(startNode);
    newNode->next=graph[endNode];
    graph[endNode] = newNode;
}
void printGraph(Node* graph[], int vertices) {
    for (int i = 0; i < vertices; i++) {

        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int V=3;
    Node* graph[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = NULL;
    }
    addNode(graph,1,2);
    addNode(graph,0,1);
    printGraph(graph,V);
    return 0;
}