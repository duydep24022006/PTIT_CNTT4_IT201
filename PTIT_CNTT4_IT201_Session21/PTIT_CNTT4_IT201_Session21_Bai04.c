#include <stdio.h>
#define MAX_V 3

void addEdge(int graph[MAX_V][MAX_V],int starNode,int endNode)
{
    graph[starNode][endNode] = 1;
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
    addEdge(n,1,0);
    addEdge(n,1,2);
    addEdge(n,2,0);
    displayGraph(n);
    return 0;
}