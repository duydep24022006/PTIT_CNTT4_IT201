#include <stdio.h>
#define MAX_V 3

void addEdge(int graph[MAX_V][MAX_V],int firstNode,int secondNode)
{
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

int main()
{
    int n[MAX_V][MAX_V]={0};
    addEdge(n,1,2);

    return 0;
}