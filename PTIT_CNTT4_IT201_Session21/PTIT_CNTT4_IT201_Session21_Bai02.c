#include <stdio.h>
#define MAX_V 4

void addEdge(int graph[MAX_V][MAX_V],int firstNode,int secondNode)
{
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

void displayGraph(int graph[MAX_V][MAX_V])
{
    for(int i=0;i<MAX_V;i++)
    {
        for(int j=0;j<MAX_V;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n[MAX_V][MAX_V]={0};
    addEdge(n,0,1);
    addEdge(n,0,2);
    addEdge(n,1,2);
    addEdge(n,2,3);
    displayGraph(n);
    return 0;
}